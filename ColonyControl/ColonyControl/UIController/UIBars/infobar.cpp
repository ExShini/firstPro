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

#include "UIElements/uilabel.h"
#include "UIElements/uiicon.h"

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

    //set icons
    UIIcon * firtilityIcon = new UIIcon(t_FirtilityIcon);
    firtilityIcon->setX(5);
    firtilityIcon->setY(19);
    m_elements[e_firtitilyIcon] = firtilityIcon;

    UIIcon * mineralWealthIcon = new UIIcon(t_MineralWealthIcon);
    mineralWealthIcon->setX(5);
    mineralWealthIcon->setY(39);
    m_elements[e_mineralWealthIcon] = mineralWealthIcon;

    UIIcon * populationIcon = new UIIcon(t_HumanPopulationIcon);
    populationIcon->setX(105);
    populationIcon->setY(19);
    m_elements[e_populationIcon] = populationIcon;

    UIIcon * foodStorageIcon = new UIIcon(t_FoodStorageIcon);
    foodStorageIcon->setX(105);
    foodStorageIcon->setY(39);
    m_elements[e_foodStorageIcon] = foodStorageIcon;

    UIIcon * mineralStorageIcon = new UIIcon(t_MineralStorageIcon);
    mineralStorageIcon->setX(105);
    mineralStorageIcon->setY(59);
    m_elements[e_mineralStoargeIcon] = mineralStorageIcon;

    UIIcon * infrostructureIcon = new UIIcon(t_InfrostructureIcon);
    infrostructureIcon->setX(205);
    infrostructureIcon->setY(39);
    m_elements[e_infrostructureIcon] = infrostructureIcon;


    //set labels
    UILabel * textFirtility = new UILabel();
    textFirtility->addData(0);
    textFirtility->applyChanges();
    textFirtility->setX(25);
    textFirtility->setY(20);
    m_elements[e_firtitilyUIC] = textFirtility;

    UILabel * textMineralW = new UILabel();
    textMineralW->addData(0);
    textMineralW->applyChanges();
    textMineralW->setX(25);
    textMineralW->setY(40);
    m_elements[e_mineralWealthUIC] = textMineralW;


    UILabel * population = new UILabel();
    population->addData(0);
    string sep = "/";
    population->addData(sep);
    population->addData(0);
    population->applyChanges();
    population->setX(125);
    population->setY(20);
    m_elements[e_populationUIC] = population;

    UILabel * food = new UILabel();
    food->addData(0);
    food->addData(sep);
    food->addData(0);
    food->applyChanges();
    food->setX(125);
    food->setY(40);
    m_elements[e_foodStorageUIC] = food;

    UILabel * mineralsS = new UILabel();
    mineralsS->addData(0);
    mineralsS->addData(sep);
    mineralsS->addData(0);
    mineralsS->setX(125);
    mineralsS->setY(60);
    mineralsS->applyChanges();
    m_elements[e_mineralStoargeUIC] = mineralsS;


    UILabel * level = new UILabel();
    string levelT = "Level :";
    level->addData(levelT);
    level->addData(0);
    level->applyChanges();
    level->setX(225);
    level->setY(20);
    m_elements[e_settlementLevelUIC] = level;


    UILabel * Infr = new UILabel();
    Infr->addData(0);
    Infr->addData(sep);
    Infr->addData(0);
    Infr->setX(225);
    Infr->setY(40);
    Infr->applyChanges();
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
        UILabel * fer = static_cast<UILabel*>(m_elements[e_firtitilyUIC]);
        fer->setDataTo(0, sector->getFertility());
        fer->applyChanges();

        //set mineral wealth to UIC
        UILabel * minW = static_cast<UILabel*>(m_elements[e_mineralWealthUIC]);
        minW->setDataTo(0, sector->getMineralWealth());
        minW->applyChanges();

        //Settlement UICs
        Settlement* settl = static_cast<Settlement*>(pMap->objects[SETTLEMENT_LEVEL]->lMap[x][y]);
        if(settl != NULL)
        {
            //set population to UIC
            UILabel * pop = static_cast<UILabel*>(m_elements[e_populationUIC]);
            pop->setDataTo(0, settl->getPopulation());
            pop->setDataTo(2, settl->getPopulationLimit());
            pop->applyChanges();

            //set food storage to UIC
            UILabel * food = static_cast<UILabel*>(m_elements[e_foodStorageUIC]);
            food->setDataTo(0, settl->getFood());
            //food->setSecondData(settl->getPopulationLimit());
            food->applyChanges();

            //set mineral storage to UIC
            UILabel * mineralS = static_cast<UILabel*>(m_elements[e_mineralStoargeUIC]);
            mineralS->setDataTo(0, settl->getMinerals());
            //food->setSecondData(settl->getPopulationLimit());
            mineralS->applyChanges();

            //set settlement's level to UIC
            UILabel * lev = static_cast<UILabel*>(m_elements[e_settlementLevelUIC]);
            lev->setDataTo(1, settl->getSettlementLevel());
            lev->applyChanges();

            //set settlement's infrostructure to UIC
            UILabel * infr = static_cast<UILabel*>(m_elements[e_infrostructureUIC]);
            infr->setDataTo(0, settl->getSettlementInfr());
            infr->setDataTo(2, settl->getSettlementNextInfrBrd());
            infr->applyChanges();
        }
    }
}
