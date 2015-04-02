#ifndef UIGAMECONTROLLER_H
#define UIGAMECONTROLLER_H
#include "QObject"


class UIGameController: public QObject
{
    Q_OBJECT
public:
    UIGameController(QObject* parent = 0);

    Q_INVOKABLE void startGame();

signals:
    void lounchGame();
};

#endif // UIGAMECONTROLLER_H
