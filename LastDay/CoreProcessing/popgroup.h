#ifndef POPGROUP_H
#define POPGROUP_H
#include <QObject>

enum GROUP
{
    HOME,
    MISS,
    HOSP
};

class PopGroup: public QObject
{
    Q_OBJECT
public:
    PopGroup();

    int all()       { return m_free + m_active + m_notActive; }   //calc and return number of whole population
    int free()      { return m_free; }
    int active()    { return m_active; }
    int notActive() { return m_notActive; }
    int max()       { return m_max; }

    void takeDamage(int kill, int damaged, GROUP group);
    void sendToWork(int workers);
    void cured(int pop);
    void freed(int freedWorkers);

    void sendUpdate();

signals:
    void popChanged(int free, int active, int notActive, int max);

protected:



    int m_free;
    int m_active;
    int m_notActive;
    int m_max;
};

#endif // POPGROUP_H
