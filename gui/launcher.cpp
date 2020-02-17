#include "launcher.h"
#include <QGuiApplication>
#include <QQmlApplicationEngine>

Core::Launcher::Launcher(int argc, char *argv[]): _argc(argc)
  , _argv(argv)
{

}

std::unique_ptr<Core::Launcher> Core::Launcher::Create(int argc, char *argv[])
{
    return std::make_unique<Launcher>(argc, argv);
}

int Core::Launcher::exec()
{
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);

    QGuiApplication app(_argc, _argv);

    QQmlApplicationEngine engine;
    const QUrl url(QStringLiteral("qrc:/main.qml"));
    QObject::connect(&engine, &QQmlApplicationEngine::objectCreated,
                     &app, [url](QObject *obj, const QUrl &objUrl) {
        if (!obj && url == objUrl)
            QCoreApplication::exit(-1);
    }, Qt::QueuedConnection);
    engine.load(url);

    return app.exec();
}
