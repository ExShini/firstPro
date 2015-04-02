import QtQuick 2.2
import QtQuick.Controls 1.1

import lastDayEng 1.0

Rectangle
{
    border.color: "black"
    border.width: 1

    height: parent.height / 10

    anchors.left: parent.left
    anchors.right: parent.right
    anchors.top: parent.top

    anchors.leftMargin: 10
    anchors.rightMargin: 10
    anchors.topMargin: 10

    Text
    {
        anchors.fill: parent
        anchors.centerIn: parent
        text: "Население: " + uiDataController.getSettlersData().Pop
    }

    Component.onCompleted: console.log("x: ", x, " y: ", y, " width: ", width, "  height: ", height );
}
