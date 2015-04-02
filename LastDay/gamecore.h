#ifndef GAMECORE_H
#define GAMECORE_H
#include <QObject>
#include <QThread>
#include <QTimer>


class GameCore: public QObject
{
    Q_OBJECT
public:
    GameCore(QObject* parent = 0);


signals:
    void nextLoop();

public slots:
    void StartNewGame();

protected slots:
    void GameLoop();
    void IncrementTicks();

protected:
    QThread* m_thread;
    QTimer* m_timer;

    int m_ticks;
};

#endif // GAMECORE_H
