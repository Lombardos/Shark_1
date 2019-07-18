#include <QtCore>
#include <QTextStream>
#include <QQmlEngine>
#include <QJSEngine>

#include "DebugLogger.h"

DebugLogger* DebugLogger::m_instance = nullptr;

void logHandler(QtMsgType type, const QMessageLogContext &context, const QString &msg)
{
    DebugLogger::getInstance()->msgHandler(type, context, msg);
}

DebugLogger::DebugLogger() : m_outFile(LOG_FILE_NAME)
{
    m_outFile.open(QIODevice::WriteOnly | QIODevice::Text | QIODevice::Append);
}

DebugLogger::~DebugLogger()
{
    m_outFile.close();
}

DebugLogger* DebugLogger::getInstance()
{
    if (m_instance == nullptr)
    {
        m_instance = new DebugLogger();
    }
    return m_instance;
}

void DebugLogger::clearLog()
{
    {
        QMutexLocker locker(&m_mutex);
        QString record = QDateTime::currentDateTime().toString("dd.MM.yyyy hh:mm:ss.zzz") + " Log cleared";
        m_logText = record + "\n";
    }
    emit logTextChanged(m_logText);
}

void DebugLogger::msgHandler(QtMsgType type, const QMessageLogContext &context, const QString &msg)
{
    QByteArray localMsg = msg.toLocal8Bit();

    Q_UNUSED(type);
    Q_UNUSED(context);

    //const char *file = context.file ? context.file : "";
    //const char *function = context.function ? context.function : "";
//    switch (type) {
//        case QtDebugMsg:
//            //fprintf(stderr, "Debug: %s (%s:%u, %s)\n", localMsg.constData(), file, context.line, function);
//            break;
//        case QtInfoMsg:
//            fprintf(stderr, "Info: %s (%s:%u, %s)\n", localMsg.constData(), file, context.line, function);
//            break;
//        case QtWarningMsg:
//            fprintf(stderr, "Warning: %s (%s:%u, %s)\n", localMsg.constData(), file, context.line, function);
//            break;
//        case QtCriticalMsg:
//            fprintf(stderr, "Critical: %s (%s:%u, %s)\n", localMsg.constData(), file, context.line, function);
//            break;
//        case QtFatalMsg:
//            fprintf(stderr, "Fatal: %s (%s:%u, %s)\n", localMsg.constData(), file, context.line, function);
//            break;
//    }

    {
        QMutexLocker locker(&m_mutex);
        QTextStream m_textStream(&m_outFile);
        QString record = QDateTime::currentDateTime().toString("dd.MM.yyyy hh:mm:ss.zzz") + " " + localMsg;
        m_textStream << record << endl;
        m_logText += record + "\n";
        if (m_logText.length() > 10000)
            m_logText = m_logText.right(8000);
        //m_outFile.flush();
    }
    emit logTextChanged(m_logText);
}

//=====================================//
// QML SIGLETON TYPE PROVIDER FUNCTION //
//=====================================//

QObject *debugLogger_singletontype_provider(QQmlEngine *engine, QJSEngine *scriptEngine)
{
    Q_UNUSED(engine)
    Q_UNUSED(scriptEngine)

    return DebugLogger::getInstance();
}
