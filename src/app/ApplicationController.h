#pragma once

#include <QObject>
#include <QQmlEngine>
#include <QTimer>
#include <QVariantList>
#include <QVariantMap>
#include <QColor>
#include <random>
#include <vector>

#include "core/SimulationClock.h"
#include "core/Logger.h"

struct NeuronData {
    int id;
    double x;
    double y;
    double activation;
    double threshold;
    int type;
    bool active;
};

struct SynapseData {
    int id;
    int sourceId;
    int targetId;
    double weight;
    double activity;
};

struct EmotionData {
    QString name;
    double value;
    QColor color;
};

struct MemoryData {
    int id;
    QString name;
    QString description;
    QString category;
    double intensity;
    double strength;
    QStringList associatedNeuronIds;
};

class ApplicationController : public QObject
{
    Q_OBJECT

    Q_PROPERTY(SimulationClock* clock READ clock CONSTANT)
    Q_PROPERTY(Logger* logger READ logger CONSTANT)
    Q_PROPERTY(bool isOnline READ isOnline NOTIFY onlineChanged)
    Q_PROPERTY(bool isDreamMode READ isDreamMode NOTIFY dreamModeChanged)
    Q_PROPERTY(double simulationSpeed READ simulationSpeed WRITE setSimulationSpeed NOTIFY simulationSpeedChanged)
    Q_PROPERTY(int neuronCount READ neuronCount NOTIFY statsChanged)
    Q_PROPERTY(int synapseCount READ synapseCount NOTIFY statsChanged)
    Q_PROPERTY(int activeNeuronCount READ activeNeuronCount NOTIFY statsChanged)
    Q_PROPERTY(double networkActivity READ networkActivity NOTIFY statsChanged)
    Q_PROPERTY(QVariantList neurons READ neurons NOTIFY neuronsChanged)
    Q_PROPERTY(QVariantList synapses READ synapses NOTIFY synapsesChanged)
    Q_PROPERTY(QVariantList emotions READ emotions NOTIFY emotionsChanged)
    Q_PROPERTY(QVariantList memories READ memories NOTIFY memoriesChanged)
    Q_PROPERTY(int selectedNeuronId READ selectedNeuronId NOTIFY selectedNeuronChanged)
    Q_PROPERTY(int memoryCount READ memoryCount NOTIFY memoriesChanged)
    Q_PROPERTY(int dreamMemoryCount READ dreamMemoryCount NOTIFY dreamModeChanged)
    Q_PROPERTY(bool isPaused READ isPaused NOTIFY pausedChanged)

public:
    explicit ApplicationController(QObject *parent = nullptr);

    SimulationClock *clock() const;
    Logger *logger() const;

    bool isOnline() const;
    bool isDreamMode() const;
    bool isPaused() const;
    double simulationSpeed() const;
    void setSimulationSpeed(double speed);

    int neuronCount() const;
    int synapseCount() const;
    int activeNeuronCount() const;
    double networkActivity() const;

    QVariantList neurons() const;
    QVariantList synapses() const;
    QVariantList emotions() const;
    QVariantList memories() const;

    int selectedNeuronId() const;
    int memoryCount() const;
    int dreamMemoryCount() const;

    Q_INVOKABLE void initialize();
    Q_INVOKABLE void createDemoNetwork();
    Q_INVOKABLE void selectNeuron(int neuronId);
    Q_INVOKABLE void deselectNeuron();
    Q_INVOKABLE void stimulateNeuron(int neuronId, double amount);
    Q_INVOKABLE void stimulateRandom(double amount);

    Q_INVOKABLE void createMemory(const QString &name, const QString &description);
    Q_INVOKABLE void createMemoryWithOptions(const QString &name, const QString &description,
                                             const QString &category, double intensity,
                                             int associatedNeuronCount);
    Q_INVOKABLE void activateMemory(int memoryId);
    Q_INVOKABLE void deleteMemory(int memoryId);
    Q_INVOKABLE void renameMemory(int memoryId, const QString &newName);
    Q_INVOKABLE QVariantMap getMemoryDetails(int memoryId) const;

    Q_INVOKABLE void enterDreamMode();
    Q_INVOKABLE void exitDreamMode();

    Q_INVOKABLE void resetSimulation();
    Q_INVOKABLE void saveBrain(const QString &path);
    Q_INVOKABLE void loadBrain(const QString &path);

signals:
    void onlineChanged();
    void dreamModeChanged();
    void simulationSpeedChanged();
    void statsChanged();
    void neuronsChanged();
    void synapsesChanged();
    void emotionsChanged();
    void memoriesChanged();
    void selectedNeuronChanged();
    void pausedChanged();
    void neuronActivated(int neuronId, double activation);
    void dreamMemoryActivated(int memoryId, const QString &name);
    void errorOccurred(const QString &message);

private slots:
    void onSimulationTick();

private:
    void propagateSignals();
    void applyDecay();
    void updatePlasticity();
    void updateEmotions();
    void updateForgetting();
    void triggerNeurogenesis();
    void dreamTick();
    void createSynapse(int sourceId, int targetId, double weight);
    void removeWeakSynapses();
    NeuronData createNeuron(double x, double y, int type);

    static constexpr double kDecayRate = 0.05;
    static constexpr double kActivationThreshold = 0.6;
    static constexpr double kSynapseWeightDecay = 0.001;
    static constexpr double kSynapseStrengthIncrease = 0.02;
    static constexpr double kSynapseRemovalThreshold = 0.05;
    static constexpr int kMaxNeurons = 500;
    static constexpr int kMaxSynapses = 3000;
    static constexpr double kDreamRandomStimulusChance = 0.03;
    static constexpr double kNeurogenesisChance = 0.001;
    static constexpr double kForgettingRate = 0.0005;

    SimulationClock *m_clock = nullptr;
    Logger *m_logger = nullptr;
    QTimer m_simulationTimer;

    bool m_isOnline = false;
    bool m_isDreamMode = false;
    bool m_isPaused = false;
    double m_simulationSpeed = 1.0;
    int m_nextNeuronId = 1;
    int m_nextSynapseId = 1;
    int m_nextMemoryId = 1;
    int m_selectedNeuronId = -1;

    std::vector<NeuronData> m_neurons;
    std::vector<SynapseData> m_synapses;
    std::vector<EmotionData> m_emotions;
    std::vector<MemoryData> m_memories;

    double m_happiness = 50.0;
    double m_sadness = 20.0;
    double m_fear = 10.0;
    double m_anger = 5.0;
    double m_curiosity = 60.0;
    double m_calm = 70.0;

    std::mt19937 m_rng{std::random_device{}()};
};
