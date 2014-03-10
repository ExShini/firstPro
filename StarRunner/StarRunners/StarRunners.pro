#-------------------------------------------------
#
# Project created by QtCreator 2014-03-10T16:59:25
#
#-------------------------------------------------
QT       += core

QT       -= gui

TARGET = StarRunners
CONFIG   += console
CONFIG   -= app_bundle

TEMPLATE = app


SOURCES += main.cpp \
    render/render.cpp \
    gobject.cpp \
    render/textureprovider.cpp \
    objectController/gobject.cpp \
    objectController/testobjects.cpp


unix:!macx:!symbian: LIBS += -lSDL2

HEADERS += \
    render/render.h \
    gobject.h \
    enums/enums.h \
    enums/gui_enums.h \
    enums/random_enums.h \
    enums/textures_paths.h \
    render/textureprovider.h \
    enums/objects.h \
    objectController/gobject.h \
    objectController/testobjects.h
