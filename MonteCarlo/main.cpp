#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQuickView>
#include "cryptocoin.h"

int main(int argc, char *argv[])
{
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);

    QGuiApplication app(argc, argv); // Obiectul de tip aplicatie Qt cu interfata grafica

    // Inregistram tipul CryptoCoin su interfata QML pentru a putea instantia obiecte de acest tip
    // si pentru a lega atributele obiectului de elemente din interfata grafica precum casute text pentru editarea valorilor
    qmlRegisterType<CryptoCoin>("cryptocoin.monte.carlo", 1, 0, "CryptoCoin");

    // Adaugam interfata QML aplicatiei Qt
    QQmlApplicationEngine engine;
    const QUrl url(QStringLiteral("qrc:/main.qml"));
    QObject::connect(&engine, &QQmlApplicationEngine::objectCreated,
                     &app, [url](QObject *obj, const QUrl &objUrl) {
        if (!obj && url == objUrl)
            QCoreApplication::exit(-1);
    }, Qt::QueuedConnection);
    engine.load(url);

    // Rulam aplicatia si afisam interfata utilizatorului
    return app.exec();
}
