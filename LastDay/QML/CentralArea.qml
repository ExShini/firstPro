import QtQuick 2.2
import QtQuick.Controls 1.1

Rectangle {
    border.width: 1
    border.color: "blue"


    Image {
        id: centralImage
        anchors.fill: parent
        z: 0
        source: "Res/mainScene1.png"
    }

    Text
    {
        anchors.centerIn: parent
        z: 1
        color: "red"
        text: "Central area"
    }
}
