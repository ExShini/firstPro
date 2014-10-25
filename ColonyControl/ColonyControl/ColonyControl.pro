#-------------------------------------------------
#
# Project created by QtCreator 2014-03-10T16:59:25
#
#-------------------------------------------------
QT       += core

QT       -= gui

TARGET = ColonyControll
CONFIG   += console

TEMPLATE = app


SOURCES += main.cpp \
    render/render.cpp \
    render/textureprovider.cpp \
    objectController/gobject.cpp \
    objectController/objectcontroller.cpp \
    gameapp.cpp \
    eventController/eventcontroller.cpp \
    eventController/keyboardeventproc.cpp \
    objectController/movableobj.cpp \
    objectController/objects/testobjects.cpp \
    randomgen.cpp \
    render/framecontroller.cpp \
    eventController/mouseeventproc.cpp \
    objectController/objects/sector.cpp \
    objectController/objects/humanBuildings/settlement.cpp \
    objectController/mapGenarator/planetmap.cpp \
    objectController/mapGenarator/mapgenerator.cpp \
    TimeManager/timeguard.cpp \
    TimeManager/timeevent.cpp \
    gameProcessor/gameprocessor.cpp \
    objectController/objects/lavamount.cpp \
    objectController/objects/lava.cpp \
    gameProcessor/unitcontroller.cpp \
    gameProcessor/unit.cpp \
    gameProcessor/Units/humancolonists.cpp \
    objectController/objects/humanBuildings/colonycenter.cpp \
    Subsystems/sectorradar.cpp \
    gameProcessor/playercontroller.cpp \
    gameProcessor/Playrs/player.cpp \
    gameProcessor/Playrs/humanplayer.cpp \
    gameProcessor/Units/UnitProcessors/unitprocessor.cpp \
    gameProcessor/Units/UnitProcessors/humshutlereturntobaseproc.cpp \
    gameProcessor/Units/UnitProcessors/humshutleemigrationproc.cpp \
    gameProcessor/Units/UnitProcessors/humshutleimmigrateproc.cpp


LIBS += -lSDL2
LIBS += -lSDL2_image

HEADERS += \
    render/render.h \
    enums/enums.h \
    enums/gui_enums.h \
    enums/random_enums.h \
    enums/textures_paths.h \
    render/textureprovider.h \
    enums/objects.h \
    objectController/gobject.h \
    objectController/objectcontroller.h \
    gameapp.h \
    eventController/eventcontroller.h \
    eventController/keyboardeventproc.h \
    objectController/movableobj.h \
    objectController/objects/testobjects.h \
    randomgen.h \
    objectController/objectList.h \
    render/framecontroller.h \
    eventController/mouseeventproc.h \
    enums/event_handling_enum.h \
    objectController/objects/sector.h \
    objectController/objects/humanBuildings/settlement.h \
    objectController/mapGenarator/planetmap.h \
    objectController/mapGenarator/mapgenerator.h \
    enums/mapGeneratorSattings.h \
    TimeManager/timeguard.h \
    TimeManager/timeevent.h \
    gameProcessor/gameprocessor.h \
    enums/gameProcessingSettings.h \
    objectController/objects/lavamount.h \
    objectController/objects/lava.h \
    gameProcessor/unitcontroller.h \
    gameProcessor/unit.h \
    gameProcessor/Units/humancolonists.h \
    enums/Units/humanUnits.h \
    gameProcessor/allUnits.h \
    objectController/objects/humanBuildings/colonycenter.h \
    Subsystems/sectorradar.h \
    Subsystems/coordinate.h \
    gameProcessor/playercontroller.h \
    gameProcessor/Playrs/player.h \
    objectController/objects/building.h \
    gameProcessor/Playrs/humanplayer.h \
    gameProcessor/Units/UnitProcessors/unitprocessor.h \
    gameProcessor/Units/UnitProcessors/humshutlereturntobaseproc.h \
    gameProcessor/Units/UnitProcessors/humshutleemigrationproc.h \
    gameProcessor/Units/UnitProcessors/humshutleimmigrateproc.h
