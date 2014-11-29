#include "iostream"

#include "gameprocessor.h"
#include "allUnits.h"

#ifdef WIN32
#include "../objectController/objectcontroller.h"
#include "../randomgen.h"
#else
#include "objectController/objectcontroller.h"
#include "randomgen.h"
#endif

using namespace std;

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
    m_unitController = UnitController::getInstance();
    m_plController = PlayerController::getInstance();
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
FUNC: addBuildingToProcess(Settlement* sett)
DESC: add new settlement to process map
*************************************/
bool GameProcessor::addBuildingToProcess(Buildings* sett)
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

    map<int, Buildings*>::iterator iterator = m_processMap.begin();
    map<int, Buildings*>::iterator end = m_processMap.end();

    for(; iterator != end; iterator++)
    {
        Buildings* settlement = static_cast<Buildings*>((*iterator).second);
        settlement->process();
    }
}

/*************************************
FUNC: tryColonize(int x, int y, int colonists)
DESC: try colonize targer sector with current number of colonists
*************************************/
bool GameProcessor::tryColonize(int x, int y, int colonists, int playerID)
{
    int newSettlementKey = getFieldKey(x, y);
    if(m_processMap.find(newSettlementKey) != m_processMap.end())
    {
        Settlement* targetSettlement = (Settlement*)m_processMap[newSettlementKey];
        if(targetSettlement->getPlayerID() == playerID)
        {
            targetSettlement->inviteColonists(colonists);
            return true;
        }

        return false;
    }
    else
    {
        Buildings* sett = NULL;
        Sector* sec = (Sector*)m_objController->getPlanetMap()->objects[SECTOR_LEVEL]->lMap[x][y];

        switch (m_plController->getPlayer(playerID)->getRace()) {
        case Human:
            sett = new Settlement(sec, playerID);
            sett->setPopulation(colonists);
            break;
        default:
            cout << "EROR! GameProcessor::tryColonize uncknown race!" << endl;
            break;
        }

        return m_objController->addNewBuilding(sett);
    }
}

/*************************************
FUNC: tryGetColonists(int x, int y, int maxCol, int playerID)
DESC: Try get colonists from target sector for shutle boarding
*************************************/
int GameProcessor::tryGetColonists(int x, int y, int maxCol, int playerID)
{
    int emigrantsSettlementKey = getFieldKey(x, y);
    if(m_processMap.find(emigrantsSettlementKey) != m_processMap.end())
    {
        Settlement* emigrantsSettlement = (Settlement*)m_processMap[emigrantsSettlementKey];
        if(emigrantsSettlement->getPlayerID() == playerID)
        {
            return emigrantsSettlement->sendColonists(maxCol);
        }
    }
    return 0;
}

/*************************************
FUNC: checkEmptyAreas(int x, int y, int playerID)
DESC: Try add empty areas newar current sector to colonists targets
*************************************/
void GameProcessor::checkEmptyAreas(int x, int y, int playerID)
{
    Player* pl = m_plController->getPlayer(playerID);

    int startDir = RandomGen::getRand() % NUMBER_OF_DIRECTIONS;

    for(int i = 0; i < NUMBER_OF_DIRECTIONS; i++)
    {
        switch (startDir) {
        case UP:
            TryAddAreaForColonize(x, y - 1, pl);
            break;
        case DOWN:
            TryAddAreaForColonize(x, y + 1, pl);
            break;
        case LEFT:
            TryAddAreaForColonize(x - 1, y, pl);
            break;
        case RIGHT:
            TryAddAreaForColonize(x + 1, y, pl);
            break;
        default:
            break;
        }


        startDir++;
        if(startDir == NUMBER_OF_DIRECTIONS)
            startDir = UP;  // set startDir to 0;
    }
}

/*************************************
FUNC: TryAddAreaForColonize(int x, int y, Player *player)
DESC: Try add current area to colonist target
*************************************/
void GameProcessor::TryAddAreaForColonize(int x, int y, Player *player)
{
    PlanetMap* plmap = m_objController->getPlanetMap();
    if(m_objController->checkAreaApplicable(x, y))
    {
        GObject* settlement = plmap->objects[SETTLEMENT_LEVEL]->lMap[x][y];
        if (settlement == NULL)
        {
            player->addColonistTarget(plmap->objects[SECTOR_LEVEL]->lMap[x][y]);
        }
    }
}

/*************************************
FUNC: addNewPlayer(int x, int y, int playerID)
DESC: add new player to game
*************************************/
void GameProcessor::addNewPlayer(int x, int y, int race)
{

    int playerID = m_plController->addNewPlayer(race);

    if(playerID == -1)
        return;

    Sector* sec = (Sector*) m_objController->getPlanetMap()->objects[SECTOR_LEVEL]->lMap[x][y];

    switch (race) {
    case Human:
    {
        ColonyCenter* colC = new ColonyCenter(sec, playerID);
        colC->setPopulation(1500);
        m_objController->addNewBuilding(colC);
        break;
    }
    default:
        cout << "GameProcessor::addNewPlayer uncknown race!" <<endl;
        break;
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
