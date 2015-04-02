import QtQuick 2.2
import QtQuick.Controls 1.1

import lastDayEng 1.0

ApplicationWindow {
    visible: true
    width: 1024
    height: 680
    title: qsTr("Last Day!")

    menuBar: MenuBar {
        Menu {
            title: qsTr("Game menu")
            MenuItem {
                text: qsTr("Start new game!")
                onTriggered:  uiDataController.getStatusController().startGame();
            }
            MenuItem {
                text: qsTr("Exit")
                onTriggered: Qt.quit();
            }
        }
    }

    HeaderBar
    {
        id: header
        width: parent.width
        height: (parent.height *10) / 100       // 10 perc
        anchors.top: parent.top
    }

    Rectangle
    {
        id: centralAreaRect
        width: parent.width
        height: (parent.height * 65) / 100      // 65 perc
        anchors.top: header.bottom

        Resourses
        {
            id: populationBar
            width: (parent.width * 20) / 100    // 20 perc
            height: parent.height
            anchors.top: parent.top
            anchors.left: parent.left
        }

        EventBar
        {
            id: commandBar
            width: (parent.width * 20) / 100    // 20 perc
            height: parent.height
            anchors.top: parent.top
            anchors.right: parent.right
        }

        CentralArea
        {
            id: centralArea
            height: parent.height
            anchors.top: parent.top
            anchors.right: commandBar.left
            anchors.left: populationBar.right
        }
    }



    MainSettlersBar
    {
        id: mainBar
        width: parent.width
        height: (parent.height * 25) / 100
        anchors.bottom: parent.bottom
    }

}
