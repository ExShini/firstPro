#include "uidatacontroller.h"
#include <QtQml>



UiDataController::UiDataController(QObject *parent):
    QObject(parent)
{
}

void UiDataController::init(QQmlApplicationEngine *engine)
{
     m_uiGameController = new UIGameController(this);
     m_settlersData = new SettlersMainData(this);


     engine->rootContext()->setContextProperty("uiDataController", this);

     qmlRegisterType<UIGameController>("lastDayEng", 1, 0, "UIGameController");
     qmlRegisterType<SettlersMainData>("lastDayEng", 1, 0, "SettlersMainData");
}

