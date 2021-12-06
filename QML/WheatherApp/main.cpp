#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <apirest.h>
#include <QQmlContext>

int main(int argc, char *argv[])
{
#if QT_VERSION < QT_VERSION_CHECK(6, 0, 0)
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);
#endif

    QGuiApplication app(argc, argv);

    qmlRegisterType<Apirest>("Mike", 1, 0, "ApiRest");
    //Apirest apirest;

    QQmlApplicationEngine engine;
//    QQmlContext * rootContext = engine.rootContext();
//    rootContext->setContextProperty("appBrid", &apirest);

    const QUrl url(QStringLiteral("qrc:/main.qml"));
    QObject::connect(&engine, &QQmlApplicationEngine::objectCreated,
                     &app, [url](QObject *obj, const QUrl &objUrl) {
        if (!obj && url == objUrl)
            QCoreApplication::exit(-1);
    }, Qt::QueuedConnection);
    engine.load(url);

    return app.exec();
}
