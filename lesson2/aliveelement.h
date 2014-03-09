#ifndef ALIVEELEMENT_H
#define ALIVEELEMENT_H
#include "structs.h"
#include "enum.h"

class AliveElement
{
public:
    AliveElement(short x, short y);
    ~AliveElement();
    bool Die();

    short getX() { return m_x; }
    short getY() { return m_y; }

    AliveElement * getNextEl() { return m_next; }
    AliveElement * getPreviousEl() { return m_previous; }

    void setNextEl(AliveElement * el) { m_next = el; }
    void setPreviousEl(AliveElement * el) { m_previous = el; }

    point * getPEmpty() { return m_empty; }
    point * getPAlive() { return m_liveAround; }

    short getNumEmpty() { return m_countEmpty; }
    short getNumAlive() { return m_countLive; }

    void setNumEmpty(short num) { m_countEmpty = num; }
    void setNumAlive(short num) { m_countLive = num; }

private:
    short m_ears;

    short m_x;
    short m_y;

    AliveElement * m_previous;
    AliveElement * m_next;

    // each element may have only 4 empty field or over alive around
    point m_empty[4];
    point m_liveAround[4];
    short m_countEmpty;
    short m_countLive;

};

typedef struct
{
    AliveElement * m_head;
    AliveElement * m_tail;
} AEQueue;

#endif // ALIVEELEMENT_H
