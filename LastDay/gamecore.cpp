#include "gamecore.h"
#include "QDebug"

#define TIME_RATE 10
#define ONE_SECOND 1000

/**************************
Constructor
**************************/
GameCore::GameCore(QObject* parent):
    QObject(parent),
    m_ticks(0)
{
    m_thread = new QThread();
    this->moveToThread(m_thread);

    m_timer = new QTimer();

    QObject::connect(this, SIGNAL(nextLoop()),this, SLOT(GameLoop()), Qt::QueuedConnection);
    QObject::connect(m_timer, SIGNAL(timeout()),this, SLOT(IncrementTicks()), Qt::QueuedConnection);

    m_thread->start();
}

/**************************
Main game loop
**************************/
void GameCore::GameLoop()
{

}

/**************************
Start new game and initialize all start settings
**************************/
void GameCore::StartNewGame()
{
    qDebug() << "GameCore::StartNewGame()";
    m_timer->start(ONE_SECOND / TIME_RATE);
}

/**************************
Increment main game timer
**************************/
void GameCore::IncrementTicks()
{
    m_ticks++;
    if(m_ticks >= TIME_RATE)
    {
        m_ticks = 0;
    }

    emit nextLoop();
}
