#include <QApplication>
#include <QQmlApplicationEngine>
#include "uidatacontroller.h"
#include "gamecore.h"
#include "connector.h"


int main(int argc, char *argv[])
{
    QApplication app(argc, argv);


    //UI part
    QQmlApplicationEngine engine;
    UiDataController * controller = new UiDataController();
    controller->init(&engine);

    //Game core
    GameCore* core = new GameCore();

    //connect core with GUI
    Connector::Connect(core, controller);

    engine.load(QUrl(QStringLiteral("qrc:/QML/main.qml")));

    return app.exec();
}
