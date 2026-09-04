import QtQuick
import QtQuick.Controls
import QtQuick.Layouts
import QtQuick.Effects

Item {
    id: root
    signal startupComplete()

    property real progress: 0
    property int phase: 0

    Timer {
        id: startupTimer
        interval: 30
        repeat: true
        running: true
        onTriggered: {
            progress += 0.02
            if (progress >= 1.0) {
                progress = 1.0
                phase++
                if (phase === 1) {
                    phaseLabel.text = "INITIALIZING MEMORY..."
                } else if (phase === 2) {
                    phaseLabel.text = "STARTING CONSCIOUSNESS..."
                } else if (phase === 3) {
                    running = false
                    statusLabel.opacity = 1.0
                    onlineTimer.start()
                }
            }
        }
    }

    Timer {
        id: onlineTimer
        interval: 800
        repeat: false
        running: false
        onTriggered: root.startupComplete()
    }

    Rectangle {
        anchors.fill: parent
        color: "#060a12"

        gradient: Gradient {
            orientation: Gradient.Vertical
            GradientStop { position: 0.0; color: "#060a12" }
            GradientStop { position: 1.0; color: "#0c1220" }
        }
    }

    ColumnLayout {
        anchors.centerIn: parent
        spacing: 30

        Text {
            Layout.alignment: Qt.AlignHCenter
            text: "NEURO//MIND"
            font.family: "Consolas"
            font.pixelSize: 48
            font.bold: true
            color: "#00d4ff"
            style: Text.Raised
            styleColor: "#003844"
        }

        Text {
            id: phaseLabel
            Layout.alignment: Qt.AlignHCenter
            text: "LOADING SYNAPTIC MATRIX..."
            font.family: "Consolas"
            font.pixelSize: 14
            color: "#5a7a8a"
            opacity: 0.8
        }

        ColumnLayout {
            Layout.alignment: Qt.AlignHCenter
            Layout.preferredWidth: 400
            spacing: 8

            Rectangle {
                Layout.fillWidth: true
                height: 4
                radius: 2
                color: "#0c1a2a"

                Rectangle {
                    height: parent.height
                    radius: 2
                    width: parent.width * root.progress
                    color: "#00d4ff"

                    Behavior on width {
                        NumberAnimation { duration: 50; easing.type: Easing.Linear }
                    }
                }
            }

            Text {
                Layout.alignment: Qt.AlignRight
                text: Math.floor(root.progress * 100) + "%"
                font.family: "Consolas"
                font.pixelSize: 12
                color: "#3a6a7a"
            }
        }

        Text {
            id: statusLabel
            Layout.alignment: Qt.AlignHCenter
            text: "ONLINE"
            font.family: "Consolas"
            font.pixelSize: 18
            font.bold: true
            color: "#00ff88"
            opacity: 0

            Behavior on opacity {
                NumberAnimation { duration: 300 }
            }
        }
    }

    Rectangle {
        anchors.bottom: parent.bottom
        anchors.left: parent.left
        anchors.right: parent.right
        height: 1
        color: "#0a1520"
    }

    Row {
        anchors.bottom: parent.bottom
        anchors.right: parent.right
        anchors.margins: 20
        spacing: 20

        Repeater {
            model: 3

            Rectangle {
                width: 6
                height: 6
                radius: 3
                color: root.progress > (index + 1) * 0.33 ? "#00d4ff" : "#1a2a3a"

                Behavior on color {
                    ColorAnimation { duration: 200 }
                }
            }
        }
    }
}
