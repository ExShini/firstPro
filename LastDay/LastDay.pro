TEMPLATE = app

QT += qml quick widgets

SOURCES += main.cpp \
    uidatacontroller.cpp \
    uiDataModels/settlersmaindata.cpp \
    uiDataModels/uigamecontroller.cpp \
    gamecore.cpp \
    connector.cpp \
    CoreProcessing/popgroup.cpp

RESOURCES += qml.qrc

# Additional import path used to resolve QML modules in Qt Creator's code model
QML_IMPORT_PATH =

# Default rules for deployment.
include(deployment.pri)

HEADERS += \
    uidatacontroller.h \
    uiDataModels/settlersmaindata.h \
    uiDataModels/uigamecontroller.h \
    gamecore.h \
    connector.h \
    CoreProcessing/popgroup.h

OTHER_FILES +=
