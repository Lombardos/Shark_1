#ifndef DEBUGLOGGER_H
#define DEBUGLOGGER_H

#include <QObject>
#include <QtDebug>
#include <QFile>
#include <QMutex>

void logHandler(QtMsgType type, const QMessageLogContext &context, const QString &msg);

#define LOG_FILE_NAME "Shark_app.log"

class DebugLogger : public QObject
{
    Q_OBJECT
public:
    ~DebugLogger();
    static DebugLogger* getInstance();

    Q_PROPERTY(QString logText READ logText NOTIFY logTextChanged)
    QString logText() const { QMutexLocker locker(&m_mutex); return m_logText; }

    void msgHandler(QtMsgType type, const QMessageLogContext &context, const QString &msg);
    Q_INVOKABLE void clearLog();

public slots:

signals:
    void logTextChanged(QString);

private:
    explicit DebugLogger();
    static DebugLogger* m_instance;

    QFile  m_outFile;
    mutable QMutex m_mutex;
    QString m_logText;
};

#endif // DEBUGLOGGER_H
