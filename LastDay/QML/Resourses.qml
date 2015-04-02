import QtQuick 2.2
import QtQuick.Controls 1.1

import lastDayEng 1.0

Rectangle {
    border.width: 1
    border.color: "blue"

    ResourseItem
    {
        MouseArea
        {
            anchors.fill: parent
            onClicked: console.log("MouseArea clicked")
        }
    }
}

