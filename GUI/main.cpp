#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include "serialcom.h"
#include <QQmlContext>


int main(int argc, char *argv[])
{
    QGuiApplication app(argc, argv);

    QQmlApplicationEngine engine;
    SerialCom serialCom;
    engine.rootContext()->setContextProperty("serialCom", &serialCom);

    QObject::connect(
        &engine,
        &QQmlApplicationEngine::objectCreationFailed,
        &app,
        []() { QCoreApplication::exit(-1); },
        Qt::QueuedConnection);
    engine.loadFromModule("Temp", "Main");

    return app.exec();
}
