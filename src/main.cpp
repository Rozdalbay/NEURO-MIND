#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>
#include <QQuickStyle>
#include <cstdio>

#include "app/ApplicationController.h"

int main(int argc, char *argv[])
{
    fprintf(stderr, "NEURO//MIND starting...\n");
    fflush(stderr);

    QQuickStyle::setStyle("Material");
    QGuiApplication app(argc, argv);
    app.setApplicationName("NEURO//MIND");
    app.setOrganizationName("Neuromind");

    fprintf(stderr, "Creating QML engine...\n");
    fflush(stderr);

    QQmlApplicationEngine engine;
    ApplicationController controller(&engine);
    engine.rootContext()->setContextProperty("app", &controller);

    QObject::connect(
        &engine,
        &QQmlApplicationEngine::objectCreationFailed,
        &app,
        []() {
            fprintf(stderr, "QML object creation FAILED\n");
            fflush(stderr);
            QCoreApplication::exit(-1);
        },
        Qt::QueuedConnection
    );

    QObject::connect(
        &engine,
        &QQmlApplicationEngine::objectCreated,
        &app,
        [](QObject *obj, const QUrl &) {
            fprintf(stderr, "QML object created: %p\n", obj);
            fflush(stderr);
        },
        Qt::QueuedConnection
    );

    fprintf(stderr, "Loading QML module...\n");
    fflush(stderr);

    engine.loadFromModule("NeuroMind", "Main");

    fprintf(stderr, "Entering event loop...\n");
    fflush(stderr);

    return app.exec();
}
