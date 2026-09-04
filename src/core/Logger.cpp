#include "Logger.h"
#include <QDateTime>
#include <QDebug>

Logger::Logger(QObject *parent)
    : QObject(parent)
{
}

QString Logger::logText() const
{
    return m_logText;
}

int Logger::logCount() const
{
    return m_logCount;
}

void Logger::log(const QString &message, Level level)
{
    QString timestamp = QDateTime::currentDateTime().toString("hh:mm:ss.zzz");
    QString entry = QString("[%1] [%2] %3")
        .arg(timestamp)
        .arg(levelToString(level))
        .arg(message);

    m_logText.append(entry + "\n");
    m_logCount++;

    if (m_logCount > kMaxLogEntries) {
        int newlinePos = m_logText.indexOf('\n');
        if (newlinePos >= 0) {
            m_logText = m_logText.mid(newlinePos + 1);
        }
        m_logCount = kMaxLogEntries;
    }

    switch (level) {
    case Level::Debug:   qDebug().noquote() << entry; break;
    case Level::Info:    qInfo().noquote()  << entry; break;
    case Level::Warning: qWarning().noquote() << entry; break;
    case Level::Error:   qCritical().noquote() << entry; break;
    }

    emit logTextChanged();
}

void Logger::clear()
{
    m_logText.clear();
    m_logCount = 0;
    emit logTextChanged();
}

QString Logger::levelToString(Level level)
{
    switch (level) {
    case Level::Debug:   return "DEBUG";
    case Level::Info:    return "INFO ";
    case Level::Warning: return "WARN ";
    case Level::Error:   return "ERROR";
    }
    return "?????";
}
