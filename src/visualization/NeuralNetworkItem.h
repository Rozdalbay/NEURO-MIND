#pragma once

#include <QQuickItem>
#include <QVariantList>
#include <QQmlEngine>

class NeuralNetworkItem : public QQuickItem
{
    Q_OBJECT
    QML_ELEMENT
    Q_PROPERTY(QVariantList neurons READ neurons WRITE setNeurons NOTIFY neuronsChanged)
    Q_PROPERTY(QVariantList synapses READ synapses WRITE setSynapses NOTIFY synapsesChanged)
    Q_PROPERTY(qreal zoom READ zoom WRITE setZoom NOTIFY viewChanged)
    Q_PROPERTY(qreal offsetX READ offsetX WRITE setOffsetX NOTIFY viewChanged)
    Q_PROPERTY(qreal offsetY READ offsetY WRITE setOffsetY NOTIFY viewChanged)
    Q_PROPERTY(int selectedNeuronId READ selectedNeuronId WRITE setSelectedNeuronId NOTIFY selectionChanged)
    Q_PROPERTY(int hoveredNeuronId READ hoveredNeuronId WRITE setHoveredNeuronId NOTIFY selectionChanged)

public:
    explicit NeuralNetworkItem(QQuickItem *parent = nullptr);

    QVariantList neurons() const { return m_neurons; }
    QVariantList synapses() const { return m_synapses; }
    qreal zoom() const { return m_zoom; }
    qreal offsetX() const { return m_offsetX; }
    qreal offsetY() const { return m_offsetY; }
    int selectedNeuronId() const { return m_selectedNeuronId; }
    int hoveredNeuronId() const { return m_hoveredNeuronId; }

    void setNeurons(const QVariantList &neurons);
    void setSynapses(const QVariantList &synapses);
    void setZoom(qreal zoom);
    void setOffsetX(qreal offsetX);
    void setOffsetY(qreal offsetY);
    void setSelectedNeuronId(int neuronId);
    void setHoveredNeuronId(int neuronId);

    Q_INVOKABLE int neuronAt(qreal x, qreal y) const;

signals:
    void neuronsChanged();
    void synapsesChanged();
    void viewChanged();
    void selectionChanged();

protected:
    QSGNode *updatePaintNode(QSGNode *oldNode, UpdatePaintNodeData *) override;

private:
    QVariantList m_neurons;
    QVariantList m_synapses;
    qreal m_zoom = 1.0;
    qreal m_offsetX = 0.0;
    qreal m_offsetY = 0.0;
    int m_selectedNeuronId = -1;
    int m_hoveredNeuronId = -1;
};
