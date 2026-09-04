import QtQuick
import QtQuick.Controls
import QtQuick.Layouts

import NeuroMind

GlowPanel {
    id: root
    panelTitle: "Dream Mode"

    ColumnLayout {
        anchors.fill: parent
        anchors.margins: 12
        spacing: 12

        // Status
        Rectangle {
            Layout.fillWidth: true
            height: 50
            radius: 4
            color: app.isDreamMode ? "#1a0a2a" : "#0c1420"

            RowLayout {
                anchors.fill: parent
                anchors.margins: 12

                Rectangle {
                    width: 12
                    height: 12
                    radius: 6
                    color: app.isDreamMode ? "#9b59b6" : "#2a3a4a"

                    SequentialAnimation on opacity {
                        loops: Animation.Infinite
                        running: app.isDreamMode
                        NumberAnimation { to: 0.4; duration: 1500 }
                        NumberAnimation { to: 1.0; duration: 1500 }
                    }
                }

                Text {
                    text: app.isDreamMode ? "DREAM MODE ACTIVE" : "DREAM MODE INACTIVE"
                    font.family: "Consolas"
                    font.pixelSize: 12
                    font.bold: true
                    color: app.isDreamMode ? "#9b59b6" : "#4a6a7a"
                }

                Item { Layout.fillWidth: true }

                NeonButton {
                    text: app.isDreamMode ? "WAKE" : "ENTER DREAM"
                    width: 120
                    height: 30
                    baseColor: app.isDreamMode ? "#2a1a0a" : "#1a0a2a"
                    textColor: app.isDreamMode ? "#ffaa44" : "#9b59b6"
                    onClicked: {
                        if (app.isDreamMode)
                            app.exitDreamMode()
                        else
                            app.enterDreamMode()
                    }
                }
            }
        }

        // Info
        GlowPanel {
            Layout.fillWidth: true
            Layout.preferredHeight: 170
            panelTitle: "About Dream Mode"

            ColumnLayout {
                anchors.fill: parent
                anchors.margins: 12
                spacing: 6

                Text {
                    text: "During dream mode:"
                    font.family: "Consolas"
                    font.pixelSize: 11
                    color: "#5a8a9a"
                }

                Text {
                    text: "  - External stimuli are dampened\n  - Memories activate associatively\n  - Random activity increases\n  - Weak connections have a chance to fire\n  - Neurogenesis probability increases"
                    font.family: "Consolas"
                    font.pixelSize: 10
                    color: "#4a6a7a"
                    lineHeight: 1.6
                }
            }
        }

        // Active dream memories
        GlowPanel {
            Layout.fillWidth: true
            Layout.fillHeight: true
            panelTitle: "Dream Activity"

            ScrollView {
                anchors.fill: parent
                clip: true

                ListView {
                    id: dreamLog
                    model: []

                    delegate: Rectangle {
                        width: dreamLog.width
                        height: 32
                        radius: 4
                        color: "#0c1420"

                        RowLayout {
                            anchors.fill: parent
                            anchors.leftMargin: 8
                            anchors.rightMargin: 8

                            Rectangle {
                                width: 6
                                height: 6
                                radius: 3
                                color: "#9b59b6"
                            }

                            Text {
                                text: modelData
                                font.family: "Consolas"
                                font.pixelSize: 10
                                color: "#7a5a8a"
                            }
                        }
                    }
                }

                Text {
                    anchors.centerIn: parent
                    visible: !app.isDreamMode
                    text: "Enter dream mode to observe"
                    font.family: "Consolas"
                    font.pixelSize: 11
                    color: "#3a4a5a"
                }
            }
        }

        Connections {
            target: app
            function onDreamMemoryActivated(id, name) {
                var model = dreamLog.model
                var newModel = [name + " (activated)"].concat(model.slice(0, 19))
                dreamLog.model = newModel
            }
        }
    }
}
