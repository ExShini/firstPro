#include "connector.h"
#include <QObject>

void Connector::Connect(GameCore *gameCore, UiDataController *uiController)
{
    UIGameController* uiStatusContr = uiController->getStatusController();
    QObject::connect(uiStatusContr, SIGNAL(lounchGame()), gameCore, SLOT(StartNewGame()), Qt::QueuedConnection);
}
