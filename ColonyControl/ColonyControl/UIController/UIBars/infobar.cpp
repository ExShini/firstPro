#include "iostream"
#include "infobar.h"

#ifdef WIN32
#include "../../enums/gui_enums.h"
#include "../../render/textureprovider.h"
#include "../../objectController/objectcontroller.h"
#else
#include "enums/gui_enums.h"
#include "render/textureprovider.h"
#include "objectController/objectcontroller.h"
#endif

#include "UIElements/singletextcontroll.h"
#include "UIElements/doubletextcontroll.h"

using namespace std;

InfoBar::InfoBar()
    :UIBar()
{
    m_type = t_HumanInfoBar;
    m_fcontroller = new FrameController(
                TextureProvider::getInstance()->getTexture(m_type), true);


    SDL_QueryTexture(m_fcontroller->getTexture(), NULL, NULL, &m_width, &m_height);

    m_x = (WIDTH_MAIN_WINDOW - m_width) / 2;
    m_y = HEIGHT_MAIN_WINDOW - m_height;

    m_objController = ObjectController::getInstance();
    m_target = m_objController->getTarget();


    SingleTextControll * textFirtility = new SingleTextControll();
    textFirtility->setData(0);
    textFirtility->setX(25);
    textFirtility->setY(20);
    m_elements[e_fertitilyUIC] = textFirtility;

    SingleTextControll * textMineralW = new SingleTextControll();
    textMineralW->setData(0);
    textMineralW->setX(25);
    textMineralW->setY(40);
    m_elements[e_mineralWealthUIC] = textMineralW;


    DoubleTextControll * population = new DoubleTextControll();
    population->setFirstData(0);
    population->setSecondData(0);
    string sep = "/";
    population->setSeparator(sep);
    population->setX(125);
    population->setY(20);
    population->ApplyChange();
    m_elements[e_populationUIC] = population;

    DoubleTextControll * food = new DoubleTextControll();
    food->setFirstData(0);
    food->setSecondData(0);
    food->setSeparator(sep);
    food->setX(125);
    food->setY(40);
    food->ApplyChange();
    m_elements[e_foodStorageUIC] = food;

    DoubleTextControll * mineralsS = new DoubleTextControll();
    mineralsS->setFirstData(0);
    mineralsS->setSecondData(0);
    mineralsS->setSeparator(sep);
    mineralsS->setX(125);
    mineralsS->setY(60);
    mineralsS->ApplyChange();
    m_elements[e_mineralStoargeUIC] = mineralsS;


    DoubleTextControll * level = new DoubleTextControll();
    string levelT = "Level";
    level->setFirstData(levelT);
    level->setSecondData(0);
    string levelSep = ": ";
    level->setSeparator(levelSep);
    level->setX(225);
    level->setY(20);
    level->ApplyChange();
    m_elements[e_settlementLevelUIC] = level;


    DoubleTextControll * Infr = new DoubleTextControll();
    Infr->setFirstData(0);
    Infr->setSecondData(0);
    Infr->setSeparator(sep);
    Infr->setX(225);
    Infr->setY(40);
    Infr->ApplyChange();
    m_elements[e_infrostructureUIC] = Infr;
}


void InfoBar::UpdateInfo()
{
    if(m_target->isValidLink())
    {
        int x = m_target->getX();
        int y = m_target->getY();

        PlanetMap* pMap = m_objController->getPlanetMap();

        //Sector UICs
        Sector* sector = static_cast<Sector*>(pMap->objects[SECTOR_LEVEL]->lMap[x][y]);

        //set fertitily to UIC
        SingleTextControll * fer = static_cast<SingleTextControll*>(m_elements[e_fertitilyUIC]);
        fer->setData(sector->getFertility());

        //set mineral wealth to UIC
        SingleTextControll * minW = static_cast<SingleTextControll*>(m_elements[e_mineralWealthUIC]);
        minW->setData(sector->getMineralWealth());


        //Settlement UICs
        Settlement* settl = static_cast<Settlement*>(pMap->objects[SETTLEMENT_LEVEL]->lMap[x][y]);
        if(settl != NULL)
        {
            //set population to UIC
            DoubleTextControll * pop = static_cast<DoubleTextControll*>(m_elements[e_populationUIC]);
            pop->setFirstData(settl->getPopulation());
            pop->setSecondData(settl->getPopulationLimit());
            pop->ApplyChange();

            //set food storage to UIC
            DoubleTextControll * food = static_cast<DoubleTextControll*>(m_elements[e_foodStorageUIC]);
            food->setFirstData(settl->getFood());
            //food->setSecondData(settl->getPopulationLimit());
            food->ApplyChange();

            //set mineral storage to UIC
            DoubleTextControll * mineralS = static_cast<DoubleTextControll*>(m_elements[e_mineralStoargeUIC]);
            mineralS->setFirstData(settl->getMinerals());
            //food->setSecondData(settl->getPopulationLimit());
            mineralS->ApplyChange();

            //set settlement's level to UIC
            DoubleTextControll * lev = static_cast<DoubleTextControll*>(m_elements[e_settlementLevelUIC]);
            lev->setSecondData(settl->getSettlementLevel());
            lev->ApplyChange();

            //set settlement's infrostructure to UIC
            DoubleTextControll * infr = static_cast<DoubleTextControll*>(m_elements[e_infrostructureUIC]);
            infr->setFirstData(settl->getSettlementInfr());
            infr->setSecondData(settl->getSettlementNextInfrBrd());
            infr->ApplyChange();
        }
    }
}
