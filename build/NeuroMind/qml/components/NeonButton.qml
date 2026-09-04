import QtQuick
import QtQuick.Controls

Rectangle {
    id: root

    property string label: ""
    property string text: ""
    property color baseColor: "#1a2a3a"
    property color textColor: "#8aaabc"
    property color hoveredColor: "#1a3040"
    property color pressedColor: "#0a1520"
    property real fontSize: 12

    signal clicked()

    radius: 4
    color: mouseArea.pressed ? pressedColor : (mouseArea.containsMouse ? hoveredColor : root.baseColor)

    Behavior on color {
        ColorAnimation { duration: 150 }
    }

    Text {
        anchors.centerIn: parent
        text: root.text
        font.family: "Consolas"
        font.pixelSize: root.fontSize
        color: root.textColor
    }

    MouseArea {
        id: mouseArea
        anchors.fill: parent
        hoverEnabled: true
        onClicked: root.clicked()
    }
}
