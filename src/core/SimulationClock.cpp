#include "SimulationClock.h"

SimulationClock::SimulationClock(QObject *parent)
    : QObject(parent)
{
    connect(&m_timer, &QTimer::timeout, this, &SimulationClock::onTimer);
    m_timer.setTimerType(Qt::PreciseTimer);
}

double SimulationClock::speed() const
{
    return m_speed;
}

void SimulationClock::setSpeed(double newSpeed)
{
    newSpeed = qBound(kMinSpeed, newSpeed, kMaxSpeed);
    if (qFuzzyCompare(m_speed, newSpeed))
        return;

    m_speed = newSpeed;
    emit speedChanged();

    if (m_running) {
        m_timer.setInterval(static_cast<int>(kBaseIntervalMs / m_speed));
    }
}

double SimulationClock::elapsed() const
{
    return m_totalElapsed;
}

bool SimulationClock::isRunning() const
{
    return m_running;
}

int SimulationClock::tickCount() const
{
    return m_tickCount;
}

void SimulationClock::start()
{
    if (m_running)
        return;

    m_running = true;
    m_timer.setInterval(static_cast<int>(kBaseIntervalMs / m_speed));
    m_timer.start();

    emit runningChanged();
}

void SimulationClock::stop()
{
    if (!m_running)
        return;

    m_running = false;
    m_timer.stop();
    emit runningChanged();
}

void SimulationClock::toggle()
{
    if (m_running) {
        stop();
    } else {
        start();
    }
}

void SimulationClock::reset()
{
    stop();
    m_totalElapsed = 0.0;
    m_tickCount = 0;
    emit elapsedChanged();
    emit tickCountChanged();
}

void SimulationClock::onTimer()
{
    m_tickCount++;
    m_totalElapsed += kBaseIntervalMs / 1000.0;

    emit tick();
    emit elapsedChanged();
    emit tickCountChanged();
}
