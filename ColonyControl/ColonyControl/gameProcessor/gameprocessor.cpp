#include "gameprocessor.h"


#ifdef WIN32
#include "../objectController/objectcontroller.h"
#include "../randomgen.h"
#else
#include "objectController/objectcontroller.h"
#include "randomgen.h"
#endif

GameProcessor* GameProcessor::m_instance = new GameProcessor();

/*************************************
FUNC: GameProcessor()
DESC: constructor
*************************************/
GameProcessor::GameProcessor():
    m_objController(0),
    m_eventID(0)
{
}

/*************************************
FUNC: init()
DESC: initialize GameProcessor
*************************************/
void GameProcessor::init()
{
    m_objController = ObjectController::getInstance();
    m_timeGuard = TimeGuard::getInstance();
    m_eventID = m_timeGuard->addEvent(500);
}

/*************************************
FUNC: getInstance()
DESC: return GameProcessor instance
*************************************/
GameProcessor* GameProcessor::getInstance()
{
    return m_instance;
}

/*************************************
FUNC: addSettlementToProcess(Settlement* sett)
DESC: add new settlement to process map
*************************************/
bool GameProcessor::addSettlementToProcess(Settlement* sett)
{
    int key = getFieldKey(sett->getX(), sett->getY());

    if(m_processMap.find(key) != m_processMap.end())
        return false;

    m_processMap[key] = sett;
    return true;
}

/*************************************
FUNC: removeSettlementFromProcess(int key)
DESC: remove settlement from process map
*************************************/
void GameProcessor::removeSettlementFromProcess(int key)
{
    m_processMap.erase(key);
}

/*************************************
FUNC: process()
DESC: main game processing func
*************************************/
void GameProcessor::process()
{
    //check GameProcessor time event
    if (!m_timeGuard->checkEvent(m_eventID, true))
        return;

    map<int, Settlement*>::iterator iterator = m_processMap.begin();
    map<int, Settlement*>::iterator end = m_processMap.end();

    for(; iterator != end; iterator++)
    {
        Settlement* settlement = (*iterator).second;
        settlement->process();

        if (settlement->readyToMove)
        {
            //find coordinates for colonist
            int x = 0, y = 0;
            provideMovingCoordinat(&x, &y, settlement);

            int newSettlementKey = getFieldKey(x, y);
            if(m_processMap.find(newSettlementKey) != m_processMap.end())
            {
                Settlement* targetSettlement = m_processMap[newSettlementKey];
                int colonists = settlement->sendColonists();
                targetSettlement->inviteColonists(colonists);
            }
            else
            {
                m_objController->addNewSettlement(x, y, settlement->sendColonists());
            }
        }
    }
}

/*************************************
FUNC: provideMovingCoordinat(int *x, int *y, Settlement* set)
DESC: find point for colonists moving
*************************************/
void GameProcessor::provideMovingCoordinat(int *x, int *y, Settlement* set)
{
    bool applicable = false;
    while (!applicable)
    {
        int direction = RandomGen::getRand() % NUMBER_OF_DIRECTIONS;

        switch(direction)
        {
        case UP:
            if (set->getY() > 0)
            {
                *x = set->getX();
                *y = set->getY() - 1;
                applicable = m_objController->checkAreaApplicable(*x, *y);
            }
            break;
        case LEFT:
            if (set->getX() > 0)
            {
                *x = set->getX() - 1;
                *y = set->getY();
                applicable = m_objController->checkAreaApplicable(*x, *y);
            }
            break;
        case DOWN:
            if (set->getY() < MAP_HEIGHT)
            {
                *x = set->getX();
                *y = set->getY() + 1;
                applicable = m_objController->checkAreaApplicable(*x, *y);
            }
            break;
        case RIGHT:
            if (set->getX() < MAP_WIDTH)
            {
                *x = set->getX() + 1;
                *y = set->getY();
                applicable = m_objController->checkAreaApplicable(*x, *y);
            }
            break;
        }
    }
}

/*************************************
FUNC: getFieldKey(genMapField *field)
DESC: calculate and return key for genMapField by coordinate
*************************************/
int GameProcessor::getFieldKey(int x, int y)
{
    return y * MAP_WIDTH + x;
}
