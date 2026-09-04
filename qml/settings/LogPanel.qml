import QtQuick
import QtQuick.Controls
import QtQuick.Layouts

import NeuroMind

GlowPanel {
    id: root
    panelTitle: "System Log"

    ScrollView {
        anchors.fill: parent
        clip: true

        TextArea {
            readOnly: true
            text: app.logger.logText
            font.family: "Consolas"
            font.pixelSize: 11
            color: "#5a7a8a"
            wrapMode: TextArea.Wrap

            background: Rectangle {
                color: "transparent"
            }

            onTextChanged: {
                cursorPosition = length
            }
        }
    }

    NeonButton {
        anchors.bottom: parent.bottom
        anchors.right: parent.right
        anchors.margins: 8
        text: "CLEAR"
        width: 64
        height: 24
        fontSize: 10
        onClicked: app.logger.clear()
    }
}
