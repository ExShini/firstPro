#ifndef CONNECTOR_H
#define CONNECTOR_H
#include "gamecore.h"
#include "uidatacontroller.h"


class Connector
{
public:
    static void Connect(GameCore* gameCore, UiDataController* uiController);
private:
    Connector();
};

#endif // CONNECTOR_H
