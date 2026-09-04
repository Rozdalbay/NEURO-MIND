#pragma once

#include <QObject>
#include <QString>
#include <QQmlEngine>
#include <QTimer>
#include <QElapsedTimer>

class Logger : public QObject
{
    Q_OBJECT
    Q_PROPERTY(QString logText READ logText NOTIFY logTextChanged)
    Q_PROPERTY(int logCount READ logCount NOTIFY logTextChanged)

public:
    enum class Level {
        Debug,
        Info,
        Warning,
        Error
    };
    Q_ENUM(Level)

    explicit Logger(QObject *parent = nullptr);

    QString logText() const;
    int logCount() const;

    Q_INVOKABLE void log(const QString &message, Level level = Level::Info);
    Q_INVOKABLE void clear();

signals:
    void logTextChanged();

private:
    static QString levelToString(Level level);

    QString m_logText;
    int m_logCount = 0;
    static constexpr int kMaxLogEntries = 500;
};
