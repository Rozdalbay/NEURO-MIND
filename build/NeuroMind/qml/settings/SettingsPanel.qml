import QtQuick
import QtQuick.Controls
import QtQuick.Layouts

import NeuroMind

GlowPanel {
    id: root
    panelTitle: "Settings"

    ScrollView {
        anchors.fill: parent
        clip: true

        ColumnLayout {
            width: parent.width
            spacing: 12

            GlowPanel {
                Layout.fillWidth: true
                Layout.preferredHeight: 130
                panelTitle: "Simulation"

                ColumnLayout {
                    anchors.fill: parent
                    anchors.margins: 12
                    spacing: 8

                    RowLayout {
                        Text {
                            text: "Speed"
                            font.family: "Consolas"
                            font.pixelSize: 11
                            color: "#5a8a9a"
                            Layout.preferredWidth: 80
                        }
                        Slider {
                            Layout.fillWidth: true
                            from: 0.1
                            to: 5.0
                            value: app.simulationSpeed
                            stepSize: 0.1
                            onMoved: app.simulationSpeed = value
                        }
                        Text {
                            text: app.simulationSpeed.toFixed(1) + "x"
                            font.family: "Consolas"
                            font.pixelSize: 11
                            color: "#00d4ff"
                            Layout.preferredWidth: 40
                        }
                    }
                }
            }

            GlowPanel {
                Layout.fillWidth: true
                Layout.preferredHeight: 190
                panelTitle: "File"

                ColumnLayout {
                    anchors.fill: parent
                    anchors.margins: 12
                    spacing: 8

                    NeonButton {
                        Layout.fillWidth: true
                        height: 32
                        text: "SAVE BRAIN"
                        baseColor: "#0a2a1a"
                        textColor: "#00ff88"
                        onClicked: app.saveBrain("brain_save.json")
                    }

                    NeonButton {
                        Layout.fillWidth: true
                        height: 32
                        text: "LOAD BRAIN"
                        baseColor: "#0a1a2a"
                        textColor: "#00d4ff"
                        onClicked: app.loadBrain("brain_save.json")
                    }

                    NeonButton {
                        Layout.fillWidth: true
                        height: 32
                        text: "NEW BRAIN"
                        baseColor: "#2a1a0a"
                        textColor: "#ffaa44"
                        onClicked: {
                            app.resetSimulation()
                            app.initialize()
                        }
                    }
                }
            }
        }
    }
}
