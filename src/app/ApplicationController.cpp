#include "ApplicationController.h"
#include "core/SimulationClock.h"
#include "core/Logger.h"

#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonArray>
#include <QFile>
#include <QRandomGenerator>
#include <QtMath>
#include <algorithm>
#include <numeric>
#include <unordered_map>

ApplicationController::ApplicationController(QObject *parent)
    : QObject(parent)
    , m_clock(new SimulationClock(this))
    , m_logger(new Logger(this))
{
    connect(m_clock, &SimulationClock::tick, this, &ApplicationController::onSimulationTick);

    m_emotions = {
        {"Happiness", m_happiness, QColor("#4ECDC4")},
        {"Sadness",   m_sadness,   QColor("#556270")},
        {"Fear",      m_fear,      QColor("#C7CEEA")},
        {"Anger",     m_anger,     QColor("#FF6B6B")},
        {"Curiosity", m_curiosity, QColor("#FFE66D")},
        {"Calm",      m_calm,      QColor("#95E1D3")}
    };
}

SimulationClock *ApplicationController::clock() const { return m_clock; }
Logger *ApplicationController::logger() const { return m_logger; }

bool ApplicationController::isOnline() const { return m_isOnline; }
bool ApplicationController::isDreamMode() const { return m_isDreamMode; }
bool ApplicationController::isPaused() const { return m_isPaused; }

double ApplicationController::simulationSpeed() const { return m_simulationSpeed; }

void ApplicationController::setSimulationSpeed(double speed)
{
    speed = qBound(0.1, speed, 10.0);
    if (qFuzzyCompare(m_simulationSpeed, speed))
        return;
    m_simulationSpeed = speed;
    m_clock->setSpeed(speed);
    emit simulationSpeedChanged();
}

int ApplicationController::neuronCount() const
{
    return static_cast<int>(m_neurons.size());
}

int ApplicationController::synapseCount() const
{
    return static_cast<int>(m_synapses.size());
}

int ApplicationController::activeNeuronCount() const
{
    return static_cast<int>(std::count_if(m_neurons.begin(), m_neurons.end(),
        [](const NeuronData &n) { return n.activation > 0.1; }));
}

double ApplicationController::networkActivity() const
{
    if (m_neurons.empty())
        return 0.0;
    double total = 0.0;
    for (const auto &n : m_neurons) {
        total += n.activation;
    }
    return (total / static_cast<double>(m_neurons.size())) * 100.0;
}

QVariantList ApplicationController::neurons() const
{
    QVariantList list;
    list.reserve(static_cast<int>(m_neurons.size()));
    for (const auto &n : m_neurons) {
        QVariantMap map;
        map["id"] = n.id;
        map["x"] = n.x;
        map["y"] = n.y;
        map["activation"] = n.activation;
        map["threshold"] = n.threshold;
        map["type"] = n.type;
        map["active"] = n.active;
        list.append(map);
    }
    return list;
}

QVariantList ApplicationController::synapses() const
{
    QVariantList list;
    list.reserve(static_cast<int>(m_synapses.size()));
    for (const auto &s : m_synapses) {
        QVariantMap map;
        map["id"] = s.id;
        map["sourceId"] = s.sourceId;
        map["targetId"] = s.targetId;
        map["weight"] = s.weight;
        map["activity"] = s.activity;
        list.append(map);
    }
    return list;
}

QVariantList ApplicationController::emotions() const
{
    QVariantList list;
    for (const auto &e : m_emotions) {
        QVariantMap map;
        map["name"] = e.name;
        map["value"] = e.value;
        map["color"] = e.color.name();
        list.append(map);
    }
    return list;
}

QVariantList ApplicationController::memories() const
{
    QVariantList list;
    for (const auto &m : m_memories) {
        QVariantMap map;
        map["id"] = m.id;
        map["name"] = m.name;
        map["description"] = m.description;
        map["category"] = m.category;
        map["intensity"] = m.intensity;
        map["strength"] = m.strength;
        map["neuronCount"] = m.associatedNeuronIds.size();
        list.append(map);
    }
    return list;
}

int ApplicationController::selectedNeuronId() const { return m_selectedNeuronId; }
int ApplicationController::memoryCount() const { return static_cast<int>(m_memories.size()); }

int ApplicationController::dreamMemoryCount() const
{
    return m_isDreamMode ? static_cast<int>(m_memories.size()) : 0;
}

void ApplicationController::initialize()
{
    if (m_isOnline)
        return;

    m_logger->log("NEURO//MIND Neural Core Initializing...");
    m_logger->log("Loading synaptic matrix...");
    m_logger->log("Initializing memory system...");
    m_logger->log("Starting consciousness simulation...");

    createDemoNetwork();

    m_isOnline = true;
    emit onlineChanged();
    m_clock->start();

    m_logger->log("Neural core ONLINE", Logger::Level::Info);
}

NeuronData ApplicationController::createNeuron(double x, double y, int type)
{
    NeuronData neuron;
    neuron.id = m_nextNeuronId++;
    neuron.x = x;
    neuron.y = y;
    neuron.activation = 0.0;
    neuron.threshold = 0.4 + (QRandomGenerator::global()->generateDouble() * 0.4);
    neuron.type = type;
    neuron.active = false;
    return neuron;
}

void ApplicationController::createSynapse(int sourceId, int targetId, double weight)
{
    if (m_synapses.size() >= kMaxSynapses)
        return;

    for (const auto &s : m_synapses) {
        if (s.sourceId == sourceId && s.targetId == targetId)
            return;
    }

    SynapseData synapse;
    synapse.id = m_nextSynapseId++;
    synapse.sourceId = sourceId;
    synapse.targetId = targetId;
    synapse.weight = weight;
    synapse.activity = 0.0;
    m_synapses.push_back(synapse);
}

void ApplicationController::createDemoNetwork()
{
    m_logger->log("Creating demo neural network...", Logger::Level::Info);

    static constexpr int kDemoNeuronCount = 60;
    static constexpr double kFieldWidth = 1600.0;
    static constexpr double kFieldHeight = 900.0;

    for (int i = 0; i < kDemoNeuronCount; ++i) {
        double x = QRandomGenerator::global()->generateDouble() * kFieldWidth;
        double y = QRandomGenerator::global()->generateDouble() * kFieldHeight;
        int type = QRandomGenerator::global()->bounded(3);
        m_neurons.push_back(createNeuron(x, y, type));
    }

    for (int i = 0; i < kDemoNeuronCount; ++i) {
        int connections = QRandomGenerator::global()->bounded(2, 5);
        for (int c = 0; c < connections; ++c) {
            int target = QRandomGenerator::global()->bounded(kDemoNeuronCount);
            if (target != i) {
                double weight = 0.3 + QRandomGenerator::global()->generateDouble() * 0.7;
                createSynapse(m_neurons[i].id, m_neurons[target].id, weight);
            }
        }
    }

    stimulateNeuron(m_neurons[0].id, 1.0);
    stimulateNeuron(m_neurons[10].id, 1.0);
    stimulateNeuron(m_neurons[25].id, 1.0);

    createMemory("First Contact", "Initialization of neural pathways");
    createMemory("Pattern Recognition", "Formation of visual processing network");
    createMemory("Emotional Response", "Limbic system activation sequence");

    activateMemory(1);
    activateMemory(2);
    activateMemory(3);

    m_logger->log(
        QString("Demo network created: %1 neurons, %2 synapses")
            .arg(m_neurons.size())
            .arg(m_synapses.size()),
        Logger::Level::Info);

    emit neuronsChanged();
    emit synapsesChanged();
    emit memoriesChanged();
    emit emotionsChanged();
    emit statsChanged();
}

void ApplicationController::selectNeuron(int neuronId)
{
    m_selectedNeuronId = neuronId;
    emit selectedNeuronChanged();
}

void ApplicationController::deselectNeuron()
{
    m_selectedNeuronId = -1;
    emit selectedNeuronChanged();
}

void ApplicationController::stimulateNeuron(int neuronId, double amount)
{
    for (auto &n : m_neurons) {
        if (n.id == neuronId) {
            n.activation = qMin(1.0, n.activation + amount);
            break;
        }
    }
}

void ApplicationController::stimulateRandom(double amount)
{
    if (m_neurons.empty())
        return;
    int idx = QRandomGenerator::global()->bounded(static_cast<int>(m_neurons.size()));
    m_neurons[idx].activation = qMin(1.0, m_neurons[idx].activation + amount);
}

void ApplicationController::createMemory(const QString &name, const QString &description)
{
    createMemoryWithOptions(name, description, "Semantic", 80.0, 5);
}

void ApplicationController::createMemoryWithOptions(const QString &name, const QString &description,
                                                    const QString &category, double intensity,
                                                    int associatedNeuronCount)
{
    const QString normalizedName = name.trimmed();
    if (normalizedName.isEmpty()) {
        emit errorOccurred("Memory name cannot be empty");
        return;
    }

    MemoryData memory;
    memory.id = m_nextMemoryId++;
    memory.name = normalizedName;
    memory.description = description.trimmed();
    memory.category = category.trimmed().isEmpty() ? "Semantic" : category.trimmed();
    memory.intensity = qBound(1.0, intensity, 100.0);
    memory.strength = memory.intensity / 100.0;

    const int count = qBound(0, associatedNeuronCount, static_cast<int>(m_neurons.size()));
    std::vector<int> indices(m_neurons.size());
    std::iota(indices.begin(), indices.end(), 0);
    std::shuffle(indices.begin(), indices.end(), m_rng);

    for (int i = 0; i < count; ++i) {
        memory.associatedNeuronIds.append(QString::number(m_neurons[indices[i]].id));
    }

    m_memories.push_back(memory);
    emit memoriesChanged();
    m_logger->log(QString("Memory created: '%1' [%2]").arg(memory.name, memory.category),
                  Logger::Level::Info);
}

void ApplicationController::activateMemory(int memoryId)
{
    for (auto &m : m_memories) {
        if (m.id == memoryId) {
            m.intensity = qMin(100.0, m.intensity + 15.0);
            m.strength = qMin(1.0, m.strength + 0.1);

            for (const QString &neuronIdStr : m.associatedNeuronIds) {
                int nid = neuronIdStr.toInt();
                stimulateNeuron(nid, 0.5);
            }

            m_logger->log(QString("Memory activated: '%1'").arg(m.name), Logger::Level::Info);
            emit memoriesChanged();
            return;
        }
    }
}

void ApplicationController::deleteMemory(int memoryId)
{
    auto it = std::remove_if(m_memories.begin(), m_memories.end(),
        [memoryId](const MemoryData &m) { return m.id == memoryId; });

    if (it != m_memories.end()) {
        m_memories.erase(it, m_memories.end());
        emit memoriesChanged();
        m_logger->log(QString("Memory deleted: ID %1").arg(memoryId), Logger::Level::Info);
    }
}

void ApplicationController::renameMemory(int memoryId, const QString &newName)
{
    for (auto &m : m_memories) {
        if (m.id == memoryId) {
            m.name = newName;
            emit memoriesChanged();
            return;
        }
    }
}

QVariantMap ApplicationController::getMemoryDetails(int memoryId) const
{
    for (const auto &m : m_memories) {
        if (m.id == memoryId) {
            QVariantMap map;
            map["id"] = m.id;
            map["name"] = m.name;
            map["description"] = m.description;
            map["category"] = m.category;
            map["intensity"] = m.intensity;
            map["strength"] = m.strength;
            map["neuronIds"] = m.associatedNeuronIds;
            map["neuronCount"] = m.associatedNeuronIds.size();
            return map;
        }
    }
    return {};
}

void ApplicationController::enterDreamMode()
{
    if (m_isDreamMode)
        return;

    m_isDreamMode = true;
    emit dreamModeChanged();

    m_logger->log("Entering DREAM mode...", Logger::Level::Info);

    for (auto &n : m_neurons) {
        n.activation *= 0.3;
    }
}

void ApplicationController::exitDreamMode()
{
    if (!m_isDreamMode)
        return;

    m_isDreamMode = false;
    emit dreamModeChanged();

    m_logger->log("Exiting DREAM mode.", Logger::Level::Info);

    for (auto &n : m_neurons) {
        n.activation *= 0.5;
    }
}

void ApplicationController::resetSimulation()
{
    m_clock->reset();
    m_isOnline = false;
    m_isDreamMode = false;
    m_isPaused = false;
    m_selectedNeuronId = -1;
    m_nextNeuronId = 1;
    m_nextSynapseId = 1;
    m_nextMemoryId = 1;

    m_neurons.clear();
    m_synapses.clear();
    m_memories.clear();

    m_happiness = 50.0;
    m_sadness = 20.0;
    m_fear = 10.0;
    m_anger = 5.0;
    m_curiosity = 60.0;
    m_calm = 70.0;

    m_emotions = {
        {"Happiness", m_happiness, QColor("#4ECDC4")},
        {"Sadness",   m_sadness,   QColor("#556270")},
        {"Fear",      m_fear,      QColor("#C7CEEA")},
        {"Anger",     m_anger,     QColor("#FF6B6B")},
        {"Curiosity", m_curiosity, QColor("#FFE66D")},
        {"Calm",      m_calm,      QColor("#95E1D3")}
    };

    emit onlineChanged();
    emit dreamModeChanged();
    emit pausedChanged();
    emit neuronsChanged();
    emit synapsesChanged();
    emit memoriesChanged();
    emit emotionsChanged();
    emit statsChanged();
    emit selectedNeuronChanged();

    m_logger->log("Simulation reset.", Logger::Level::Info);
}

void ApplicationController::saveBrain(const QString &path)
{
    QJsonObject root;
    root["version"] = 1;

    QJsonArray neuronsArr;
    for (const auto &n : m_neurons) {
        QJsonObject obj;
        obj["id"] = n.id;
        obj["x"] = n.x;
        obj["y"] = n.y;
        obj["activation"] = n.activation;
        obj["threshold"] = n.threshold;
        obj["type"] = n.type;
        neuronsArr.append(obj);
    }
    root["neurons"] = neuronsArr;

    QJsonArray synapsesArr;
    for (const auto &s : m_synapses) {
        QJsonObject obj;
        obj["id"] = s.id;
        obj["sourceId"] = s.sourceId;
        obj["targetId"] = s.targetId;
        obj["weight"] = s.weight;
        obj["activity"] = s.activity;
        synapsesArr.append(obj);
    }
    root["synapses"] = synapsesArr;

    QJsonArray memoriesArr;
    for (const auto &m : m_memories) {
        QJsonObject obj;
        obj["id"] = m.id;
        obj["name"] = m.name;
        obj["description"] = m.description;
        obj["category"] = m.category;
        obj["intensity"] = m.intensity;
        obj["strength"] = m.strength;
        obj["neuronIds"] = QJsonArray::fromStringList(m.associatedNeuronIds);
        memoriesArr.append(obj);
    }
    root["memories"] = memoriesArr;

    QJsonObject emotionsObj;
    emotionsObj["happiness"] = m_happiness;
    emotionsObj["sadness"] = m_sadness;
    emotionsObj["fear"] = m_fear;
    emotionsObj["anger"] = m_anger;
    emotionsObj["curiosity"] = m_curiosity;
    emotionsObj["calm"] = m_calm;
    root["emotions"] = emotionsObj;

    root["nextNeuronId"] = m_nextNeuronId;
    root["nextSynapseId"] = m_nextSynapseId;
    root["nextMemoryId"] = m_nextMemoryId;

    QFile file(path);
    if (!file.open(QIODevice::WriteOnly)) {
        m_logger->log(QString("Failed to save: %1").arg(file.errorString()), Logger::Level::Error);
        emit errorOccurred(QString("Save failed: %1").arg(file.errorString()));
        return;
    }

    file.write(QJsonDocument(root).toJson());
    m_logger->log(QString("Brain saved to %1").arg(path), Logger::Level::Info);
}

void ApplicationController::loadBrain(const QString &path)
{
    QFile file(path);
    if (!file.open(QIODevice::ReadOnly)) {
        m_logger->log(QString("Failed to load: %1").arg(file.errorString()), Logger::Level::Error);
        emit errorOccurred(QString("Load failed: %1").arg(file.errorString()));
        return;
    }

    QJsonParseError parseError;
    QJsonDocument doc = QJsonDocument::fromJson(file.readAll(), &parseError);
    if (parseError.error != QJsonParseError::NoError) {
        m_logger->log(QString("Parse error: %1").arg(parseError.errorString()), Logger::Level::Error);
        emit errorOccurred(QString("Invalid save file: %1").arg(parseError.errorString()));
        return;
    }

    QJsonObject root = doc.object();

    m_neurons.clear();
    m_synapses.clear();
    m_memories.clear();

    QJsonArray neuronsArr = root["neurons"].toArray();
    for (const auto &val : neuronsArr) {
        QJsonObject obj = val.toObject();
        NeuronData n;
        n.id = obj["id"].toInt();
        n.x = obj["x"].toDouble();
        n.y = obj["y"].toDouble();
        n.activation = obj["activation"].toDouble();
        n.threshold = obj["threshold"].toDouble();
        n.type = obj["type"].toInt();
        n.active = n.activation > 0.1;
        m_neurons.push_back(n);
    }

    QJsonArray synapsesArr = root["synapses"].toArray();
    for (const auto &val : synapsesArr) {
        QJsonObject obj = val.toObject();
        SynapseData s;
        s.id = obj["id"].toInt();
        s.sourceId = obj["sourceId"].toInt();
        s.targetId = obj["targetId"].toInt();
        s.weight = obj["weight"].toDouble();
        s.activity = obj["activity"].toDouble();
        m_synapses.push_back(s);
    }

    QJsonArray memoriesArr = root["memories"].toArray();
    for (const auto &val : memoriesArr) {
        QJsonObject obj = val.toObject();
        MemoryData m;
        m.id = obj["id"].toInt();
        m.name = obj["name"].toString();
        m.description = obj["description"].toString();
        m.category = obj["category"].toString("Semantic");
        m.intensity = obj["intensity"].toDouble();
        m.strength = obj["strength"].toDouble();
        QJsonArray nids = obj["neuronIds"].toArray();
        for (const auto &nid : nids) {
            m.associatedNeuronIds.append(nid.toString());
        }
        m_memories.push_back(m);
    }

    QJsonObject emotionsObj = root["emotions"].toObject();
    m_happiness = emotionsObj["happiness"].toDouble(50.0);
    m_sadness = emotionsObj["sadness"].toDouble(20.0);
    m_fear = emotionsObj["fear"].toDouble(10.0);
    m_anger = emotionsObj["anger"].toDouble(5.0);
    m_curiosity = emotionsObj["curiosity"].toDouble(60.0);
    m_calm = emotionsObj["calm"].toDouble(70.0);

    m_emotions = {
        {"Happiness", m_happiness, QColor("#4ECDC4")},
        {"Sadness",   m_sadness,   QColor("#556270")},
        {"Fear",      m_fear,      QColor("#C7CEEA")},
        {"Anger",     m_anger,     QColor("#FF6B6B")},
        {"Curiosity", m_curiosity, QColor("#FFE66D")},
        {"Calm",      m_calm,      QColor("#95E1D3")}
    };

    m_nextNeuronId = root["nextNeuronId"].toInt(1);
    m_nextSynapseId = root["nextSynapseId"].toInt(1);
    m_nextMemoryId = root["nextMemoryId"].toInt(1);

    emit neuronsChanged();
    emit synapsesChanged();
    emit memoriesChanged();
    emit emotionsChanged();
    emit statsChanged();

    m_logger->log(QString("Brain loaded from %1").arg(path), Logger::Level::Info);
}

void ApplicationController::onSimulationTick()
{
    if (!m_isOnline || m_isPaused)
        return;

    if (m_isDreamMode) {
        dreamTick();
    }

    propagateSignals();
    applyDecay();
    updatePlasticity();
    updateEmotions();
    updateForgetting();
    triggerNeurogenesis();

    bool changed = false;
    for (auto &n : m_neurons) {
        bool wasActive = n.active;
        n.active = n.activation > 0.05;
        if (wasActive != n.active)
            changed = true;
    }

    emit statsChanged();
    if (changed) {
        emit neuronsChanged();
    }
}

void ApplicationController::propagateSignals()
{
    std::vector<double> incoming(m_neurons.size(), 0.0);
    std::unordered_map<int, size_t> neuronIndices;
    neuronIndices.reserve(m_neurons.size());
    for (size_t i = 0; i < m_neurons.size(); ++i)
        neuronIndices.emplace(m_neurons[i].id, i);

    for (auto &s : m_synapses) {
        const auto srcIndex = neuronIndices.find(s.sourceId);
        const auto targetIndex = neuronIndices.find(s.targetId);
        if (srcIndex == neuronIndices.end() || targetIndex == neuronIndices.end())
            continue;

        const NeuronData &source = m_neurons[srcIndex->second];
        if (source.activation > source.threshold) {
            const double signal = source.activation * s.weight;
            incoming[targetIndex->second] += signal;
            s.activity = qMin(1.0, s.activity + 0.3);
        }
    }

    for (size_t i = 0; i < m_neurons.size(); ++i) {
        if (incoming[i] > 0.0) {
            m_neurons[i].activation = qMin(1.0, m_neurons[i].activation + incoming[i] * 0.1);
        }
    }
}

void ApplicationController::applyDecay()
{
    for (auto &n : m_neurons) {
        if (n.activation > 0.0) {
            n.activation = qMax(0.0, n.activation - kDecayRate);
        }
    }

    for (auto &s : m_synapses) {
        if (s.activity > 0.0) {
            s.activity = qMax(0.0, s.activity - 0.01);
        }
    }
}

void ApplicationController::updatePlasticity()
{
    std::unordered_map<int, size_t> neuronIndices;
    neuronIndices.reserve(m_neurons.size());
    for (size_t i = 0; i < m_neurons.size(); ++i)
        neuronIndices.emplace(m_neurons[i].id, i);

    for (auto &s : m_synapses) {
        const auto srcIndex = neuronIndices.find(s.sourceId);
        const auto targetIndex = neuronIndices.find(s.targetId);
        if (srcIndex == neuronIndices.end() || targetIndex == neuronIndices.end())
            continue;

        const NeuronData &source = m_neurons[srcIndex->second];
        const NeuronData &target = m_neurons[targetIndex->second];
        if (source.activation > source.threshold && target.activation > 0.1) {
            s.weight = qMin(1.0, s.weight + kSynapseStrengthIncrease * s.activity);
        } else {
            s.weight = qMax(0.0, s.weight - kSynapseWeightDecay);
        }
    }

    removeWeakSynapses();
}

void ApplicationController::removeWeakSynapses()
{
    auto it = std::remove_if(m_synapses.begin(), m_synapses.end(),
        [](const SynapseData &s) { return s.weight < kSynapseRemovalThreshold; });

    if (it != m_synapses.end()) {
        int removed = static_cast<int>(std::distance(it, m_synapses.end()));
        m_synapses.erase(it, m_synapses.end());
        if (removed > 0) {
            emit synapsesChanged();
        }
    }
}

void ApplicationController::updateEmotions()
{
    double activity = networkActivity();
    int activeCount = activeNeuronCount();

    m_curiosity = qBound(0.0, m_curiosity + (activity > 50.0 ? 0.1 : -0.05), 100.0);
    m_calm = qBound(0.0, m_calm + (activeCount < 10 ? 0.1 : -0.05), 100.0);
    m_happiness = qBound(0.0, m_happiness + (activity > 30.0 && activity < 70.0 ? 0.05 : -0.02), 100.0);

    if (activity > 80.0) {
        m_fear = qBound(0.0, m_fear + 0.1, 100.0);
        m_anger = qBound(0.0, m_anger + 0.05, 100.0);
    } else {
        m_fear = qBound(0.0, m_fear - 0.02, 100.0);
        m_anger = qBound(0.0, m_anger - 0.01, 100.0);
    }

    m_sadness = qBound(0.0, 100.0 - m_happiness - m_curiosity * 0.3, 100.0);

    m_emotions = {
        {"Happiness", m_happiness, QColor("#4ECDC4")},
        {"Sadness",   m_sadness,   QColor("#556270")},
        {"Fear",      m_fear,      QColor("#C7CEEA")},
        {"Anger",     m_anger,     QColor("#FF6B6B")},
        {"Curiosity", m_curiosity, QColor("#FFE66D")},
        {"Calm",      m_calm,      QColor("#95E1D3")}
    };

    static int emotionUpdateCounter = 0;
    if (++emotionUpdateCounter % 20 == 0) {
        emit emotionsChanged();
    }
}

void ApplicationController::updateForgetting()
{
    for (auto &m : m_memories) {
        m.intensity = qMax(0.0, m.intensity - kForgettingRate);
        m.strength = qMax(0.0, m.strength - kForgettingRate * 0.5);
    }

    auto it = std::remove_if(m_memories.begin(), m_memories.end(),
        [](const MemoryData &m) { return m.intensity < 1.0; });

    if (it != m_memories.end()) {
        m_memories.erase(it, m_memories.end());
        emit memoriesChanged();
    }
}

void ApplicationController::triggerNeurogenesis()
{
    if (m_neurons.size() >= kMaxNeurons)
        return;

    std::uniform_real_distribution<double> dist(0.0, 1.0);
    double chance = kNeurogenesisChance;
    if (m_isDreamMode)
        chance *= 3.0;
    if (m_curiosity > 70.0)
        chance *= 2.0;

    if (dist(m_rng) < chance) {
        NeuronData newNeuron = createNeuron(
            QRandomGenerator::global()->generateDouble() * 1600.0,
            QRandomGenerator::global()->generateDouble() * 900.0,
            QRandomGenerator::global()->bounded(3));
        m_neurons.push_back(newNeuron);

        int connections = QRandomGenerator::global()->bounded(1, 4);
        for (int c = 0; c < connections; ++c) {
            int targetIdx = QRandomGenerator::global()->bounded(static_cast<int>(m_neurons.size()));
            if (m_neurons[targetIdx].id != newNeuron.id) {
                double weight = 0.2 + QRandomGenerator::global()->generateDouble() * 0.5;
                createSynapse(newNeuron.id, m_neurons[targetIdx].id, weight);
            }
        }

        emit neuronsChanged();
        emit synapsesChanged();
    }
}

void ApplicationController::dreamTick()
{
    std::uniform_real_distribution<double> dist(0.0, 1.0);

    if (dist(m_rng) < kDreamRandomStimulusChance * 3.0) {
        stimulateRandom(0.4 + dist(m_rng) * 0.4);
    }

    if (dist(m_rng) < 0.01 && !m_memories.empty()) {
        int memIdx = QRandomGenerator::global()->bounded(static_cast<int>(m_memories.size()));
        activateMemory(m_memories[memIdx].id);
        emit dreamMemoryActivated(m_memories[memIdx].id, m_memories[memIdx].name);
    }

    if (dist(m_rng) < 0.005) {
        int idx = QRandomGenerator::global()->bounded(static_cast<int>(m_neurons.size()));
        auto &n = m_neurons[idx];
        std::vector<int> connected;
        for (const auto &s : m_synapses) {
            if (s.sourceId == n.id && s.weight > 0.1) {
                connected.push_back(s.targetId);
            }
        }
        if (!connected.empty()) {
            int targetId = connected[QRandomGenerator::global()->bounded(static_cast<int>(connected.size()))];
            stimulateNeuron(targetId, 0.6);
        }
    }
}
