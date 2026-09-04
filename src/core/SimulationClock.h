#pragma once

#include <QObject>
#include <QTimer>

class SimulationClock : public QObject
{
    Q_OBJECT
    Q_PROPERTY(double speed READ speed WRITE setSpeed NOTIFY speedChanged)
    Q_PROPERTY(double elapsed READ elapsed NOTIFY elapsedChanged)
    Q_PROPERTY(bool running READ isRunning NOTIFY runningChanged)
    Q_PROPERTY(int tickCount READ tickCount NOTIFY tickCountChanged)

public:
    explicit SimulationClock(QObject *parent = nullptr);

    double speed() const;
    void setSpeed(double newSpeed);

    double elapsed() const;
    bool isRunning() const;
    int tickCount() const;

    Q_INVOKABLE void start();
    Q_INVOKABLE void stop();
    Q_INVOKABLE void toggle();
    Q_INVOKABLE void reset();

signals:
    void speedChanged();
    void elapsedChanged();
    void runningChanged();
    void tickCountChanged();
    void tick();

private slots:
    void onTimer();

private:
    static constexpr double kMinSpeed = 0.1;
    static constexpr double kMaxSpeed = 10.0;
    static constexpr int kBaseIntervalMs = 50;

    QTimer m_timer;
    double m_speed = 1.0;
    double m_totalElapsed = 0.0;
    bool m_running = false;
    int m_tickCount = 0;
};
