#include <QGuiApplication>
#include <QQmlApplicationEngine>

#include "Sources/Shark/DebugLogger.h" //Robin according to yamassa
#include "Sources/Common.h" //Robin according to yamassa

int main(int argc, char *argv[])
{
    qInstallMessageHandler(logHandler); //Robin according to yamassa


    qInfo() << ""; //Robin according to yamassa
    qInfo() << "START"; //own Robin

    qInfo() << (QString("Shark App v") + QString::number(VER_MAJOR) + "." + QString::number(VER_MINOR) + "." + QString::number(VER_MICRO)).toStdString().c_str();

    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);

    QGuiApplication app(argc, argv);

    QQmlApplicationEngine engine;
    const QUrl url(QStringLiteral("qrc:/main.qml"));
    QObject::connect(&engine, &QQmlApplicationEngine::objectCreated,
                     &app, [url](QObject *obj, const QUrl &objUrl) {
        if (!obj && url == objUrl)
            QCoreApplication::exit(-1);
    }, Qt::QueuedConnection);
    engine.load(url);

    int result = app.exec(); //Robin podle yamassa

    return result;
}
