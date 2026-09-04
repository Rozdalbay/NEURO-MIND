#include "NeuralNetworkItem.h"

#include <QHash>
#include <QPointF>
#include <QSGGeometry>
#include <QSGGeometryNode>
#include <QSGVertexColorMaterial>
#include <QtMath>

namespace {
QSGGeometryNode *createGeometryNode(QSGGeometry::DrawingMode mode)
{
    auto *node = new QSGGeometryNode;
    auto *geometry = new QSGGeometry(QSGGeometry::defaultAttributes_ColoredPoint2D(), 0);
    geometry->setDrawingMode(mode);
    auto *material = new QSGVertexColorMaterial;
    material->setFlag(QSGMaterial::Blending);
    node->setGeometry(geometry);
    node->setMaterial(material);
    node->setFlag(QSGNode::OwnsGeometry);
    node->setFlag(QSGNode::OwnsMaterial);
    return node;
}

void setVertex(QSGGeometry::ColoredPoint2D &vertex, const QPointF &point,
               int red, int green, int blue, int alpha)
{
    vertex.set(static_cast<float>(point.x()), static_cast<float>(point.y()),
               static_cast<uchar>(red), static_cast<uchar>(green),
               static_cast<uchar>(blue), static_cast<uchar>(alpha));
}
}

NeuralNetworkItem::NeuralNetworkItem(QQuickItem *parent)
    : QQuickItem(parent)
{
    setFlag(ItemHasContents, true);
}

void NeuralNetworkItem::setNeurons(const QVariantList &neurons)
{
    m_neurons = neurons;
    emit neuronsChanged();
    update();
}

void NeuralNetworkItem::setSynapses(const QVariantList &synapses)
{
    m_synapses = synapses;
    emit synapsesChanged();
    update();
}

void NeuralNetworkItem::setZoom(qreal zoom)
{
    zoom = qBound(0.2, zoom, 5.0);
    if (qFuzzyCompare(m_zoom, zoom))
        return;
    m_zoom = zoom;
    emit viewChanged();
    update();
}

void NeuralNetworkItem::setOffsetX(qreal offsetX)
{
    if (qFuzzyCompare(m_offsetX, offsetX))
        return;
    m_offsetX = offsetX;
    emit viewChanged();
    update();
}

void NeuralNetworkItem::setOffsetY(qreal offsetY)
{
    if (qFuzzyCompare(m_offsetY, offsetY))
        return;
    m_offsetY = offsetY;
    emit viewChanged();
    update();
}

void NeuralNetworkItem::setSelectedNeuronId(int neuronId)
{
    if (m_selectedNeuronId == neuronId)
        return;
    m_selectedNeuronId = neuronId;
    emit selectionChanged();
    update();
}

void NeuralNetworkItem::setHoveredNeuronId(int neuronId)
{
    if (m_hoveredNeuronId == neuronId)
        return;
    m_hoveredNeuronId = neuronId;
    emit selectionChanged();
    update();
}

int NeuralNetworkItem::neuronAt(qreal x, qreal y) const
{
    for (auto it = m_neurons.crbegin(); it != m_neurons.crend(); ++it) {
        const QVariantMap neuron = it->toMap();
        const qreal nx = neuron.value("x").toReal() * m_zoom + m_offsetX;
        const qreal ny = neuron.value("y").toReal() * m_zoom + m_offsetY;
        const qreal radius = (6.0 + neuron.value("type").toInt() * 1.5
                              + neuron.value("activation").toReal() * 5.0) * m_zoom;
        const qreal dx = x - nx;
        const qreal dy = y - ny;
        if (dx * dx + dy * dy <= radius * radius)
            return neuron.value("id").toInt();
    }
    return -1;
}

QSGNode *NeuralNetworkItem::updatePaintNode(QSGNode *oldNode, UpdatePaintNodeData *)
{
    QSGNode *root = oldNode;
    if (!root) {
        root = new QSGNode;
        root->appendChildNode(createGeometryNode(QSGGeometry::DrawLines));
        root->appendChildNode(createGeometryNode(QSGGeometry::DrawTriangles));
    }

    auto *synapseNode = static_cast<QSGGeometryNode *>(root->firstChild());
    auto *neuronNode = static_cast<QSGGeometryNode *>(synapseNode->nextSibling());
    auto *synapseGeometry = synapseNode->geometry();
    auto *neuronGeometry = neuronNode->geometry();

    QHash<int, QPointF> positions;
    positions.reserve(m_neurons.size());
    for (const QVariant &value : m_neurons) {
        const QVariantMap neuron = value.toMap();
        positions.insert(neuron.value("id").toInt(),
                         {neuron.value("x").toReal() * m_zoom + m_offsetX,
                          neuron.value("y").toReal() * m_zoom + m_offsetY});
    }

    int validSynapseCount = 0;
    for (const QVariant &value : m_synapses) {
        const QVariantMap synapse = value.toMap();
        if (positions.contains(synapse.value("sourceId").toInt())
            && positions.contains(synapse.value("targetId").toInt())) {
            ++validSynapseCount;
        }
    }
    synapseGeometry->allocate(validSynapseCount * 2);
    auto *synapseVertices = synapseGeometry->vertexDataAsColoredPoint2D();
    int synapseVertex = 0;
    for (const QVariant &value : m_synapses) {
        const QVariantMap synapse = value.toMap();
        const auto source = positions.constFind(synapse.value("sourceId").toInt());
        const auto target = positions.constFind(synapse.value("targetId").toInt());
        if (source == positions.cend() || target == positions.cend())
            continue;

        const qreal activity = synapse.value("activity").toReal();
        const qreal weight = synapse.value("weight").toReal();
        const int alpha = qBound(18, static_cast<int>(35 + weight * 65 + activity * 130), 220);
        const int blue = activity > 0.1 ? 255 : 145;
        setVertex(synapseVertices[synapseVertex++], source.value(), 30, 130, blue, alpha);
        setVertex(synapseVertices[synapseVertex++], target.value(), 30, 130, blue, alpha);
    }
    constexpr int kSegments = 8;
    constexpr int kVerticesPerNeuron = kSegments * 3;
    neuronGeometry->allocate(m_neurons.size() * kVerticesPerNeuron);
    auto *neuronVertices = neuronGeometry->vertexDataAsColoredPoint2D();
    int neuronVertex = 0;
    for (const QVariant &value : m_neurons) {
        const QVariantMap neuron = value.toMap();
        const int id = neuron.value("id").toInt();
        const qreal activation = neuron.value("activation").toReal();
        const bool selected = id == m_selectedNeuronId || id == m_hoveredNeuronId;
        const QPointF center = positions.value(id);
        const qreal radius = (4.0 + neuron.value("type").toInt() * 1.4
                              + activation * 4.0 + (selected ? 2.0 : 0.0)) * m_zoom;
        const int red = selected ? 70 : 15;
        const int green = selected ? 225 : static_cast<int>(90 + activation * 165);
        const int blue = selected ? 255 : static_cast<int>(130 + activation * 110);

        for (int segment = 0; segment < kSegments; ++segment) {
            const qreal angle1 = (2.0 * M_PI * segment) / kSegments;
            const qreal angle2 = (2.0 * M_PI * (segment + 1)) / kSegments;
            setVertex(neuronVertices[neuronVertex++], center, red, green, blue, 255);
            setVertex(neuronVertices[neuronVertex++],
                      center + QPointF(qCos(angle1) * radius, qSin(angle1) * radius),
                      red, green, blue, 240);
            setVertex(neuronVertices[neuronVertex++],
                      center + QPointF(qCos(angle2) * radius, qSin(angle2) * radius),
                      red, green, blue, 240);
        }
    }

    synapseNode->markDirty(QSGNode::DirtyGeometry);
    neuronNode->markDirty(QSGNode::DirtyGeometry);
    return root;
}
