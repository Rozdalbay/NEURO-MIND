import QtQuick
import QtQuick.Controls
import QtQuick.Layouts

Rectangle {
    id: root

    property string panelTitle: ""
    default property alias content: contentArea.data

    color: "#0a1018"
    radius: 6

    border.color: "#1a2a3a"
    border.width: 1

    ColumnLayout {
        anchors.fill: parent
        anchors.margins: 12
        spacing: 8

        RowLayout {
            Layout.fillWidth: true

            Rectangle {
                width: 3
                height: 14
                radius: 1
                color: "#00d4ff"
            }

            Text {
                text: root.panelTitle.toUpperCase()
                font.family: "Consolas"
                font.pixelSize: 12
                font.bold: true
                color: "#5a8a9a"
            }

            Item { Layout.fillWidth: true }
        }

        Rectangle {
            Layout.fillWidth: true
            height: 1
            color: "#142030"
        }

        Item {
            id: contentArea
            Layout.fillWidth: true
            Layout.fillHeight: true
        }
    }
}
