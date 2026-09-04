import QtQuick
import QtQuick.Controls

Rectangle {
    id: root

    property string label: ""
    property color activeColor: "#00ff88"
    property color inactiveColor: "#ff4444"
    property bool active: false

    width: indicator.width + label.width + 8
    height: 20

    Rectangle {
        id: indicator
        width: 8
        height: 8
        radius: 4
        anchors.verticalCenter: parent.verticalCenter
        color: root.active ? root.activeColor : root.inactiveColor

        SequentialAnimation on opacity {
            loops: Animation.Infinite
            running: root.active
            NumberAnimation { to: 0.3; duration: 1000 }
            NumberAnimation { to: 1.0; duration: 1000 }
        }
    }

    Text {
        id: label
        text: root.label
        font.family: "Consolas"
        font.pixelSize: 11
        color: root.active ? root.activeColor : root.inactiveColor
        anchors.verticalCenter: parent.verticalCenter
        anchors.left: indicator.right
        anchors.leftMargin: 4
    }
}
