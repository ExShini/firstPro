#-------------------------------------------------
#
# Project created by QtCreator 2014-03-10T16:59:25
#
#-------------------------------------------------
QT       += core

QT       -= gui

TARGET = StarRunners
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
    objectController/mapGenarator/room.cpp \
    objectController/mapGenarator/modulegenerator.cpp \
    objectController/objects/testobjects.cpp \
    objectController/objects/wall.cpp \
    randomgen.cpp \
    objectController/mapGenarator/rooms/testroom.cpp


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
    objectController/mapGenarator/room.h \
    objectController/mapGenarator/modulegenerator.h \
    objectController/objects/testobjects.h \
    objectController/objects/wall.h \
    enums/moduleGeneratorSattings.h \
    randomgen.h \
    objectController/mapGenarator/rooms/testroom.h
