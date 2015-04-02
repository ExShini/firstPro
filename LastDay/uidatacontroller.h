#ifndef UIDATACONTROLLER_H
#define UIDATACONTROLLER_H
#include <QQmlApplicationEngine>
#include <QObject>

#include "uiDataModels/uigamecontroller.h"
#include "uiDataModels/settlersmaindata.h"

class UiDataController: public QObject
{
private:
    Q_OBJECT
public:
    UiDataController(QObject* parent = 0);

    void init(QQmlApplicationEngine* engine);

    Q_INVOKABLE UIGameController* getStatusController() { return m_uiGameController; }
    Q_INVOKABLE SettlersMainData* getSettlersData() { return m_settlersData; }

protected:
    UIGameController* m_uiGameController;
    SettlersMainData* m_settlersData;
};


#endif // UIDATACONTROLLER_H
