#include "uigamecontroller.h"
#include <QDebug>


UIGameController::UIGameController(QObject *parent):
    QObject(parent)
{
}

void UIGameController::startGame()
{
    qDebug() << "startGame";
    emit lounchGame();
}
