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
    objectController/mapGenarator/module.cpp \
    render/framecontroller.cpp \
    eventController/mouseeventproc.cpp \
    objectController/objects/sector.cpp \
    objectController/objects/settlement.cpp \
    objectController/mapGenarator/planetmap.cpp \
    objectController/mapGenarator/mapgenerator.cpp


unix:!macx:!symbian: LIBS += -lSDL2

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
    objectController/mapGenarator/module.h \
    render/framecontroller.h \
    eventController/mouseeventproc.h \
    enums/event_handling_enum.h \
    objectController/objects/sector.h \
    objectController/objects/settlement.h \
    objectController/mapGenarator/planetmap.h \
    objectController/mapGenarator/mapgenerator.h \
    enums/mapGeneratorSattings.h
