TEMPLATE = app
CONFIG += console
CONFIG -= qt

SOURCES += main.cpp \
    gameapp.cpp \
    render.cpp \
    randomgen.cpp \
    aliveelement.cpp


unix:!macx:!symbian: LIBS += -lSDL2

HEADERS += \
    gameapp.h \
    enum.h \
    render.h \
    randomgen.h \
    aliveelement.h \
    structs.h
