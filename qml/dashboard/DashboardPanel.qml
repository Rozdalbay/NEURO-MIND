import QtQuick
import QtQuick.Controls
import QtQuick.Layouts

import NeuroMind

GlowPanel {
    id: root
    panelTitle: "Dashboard"

    ScrollView {
        anchors.fill: parent
        clip: true

        ColumnLayout {
            width: parent.width
            spacing: 16

            // Activity overview
            GlowPanel {
                Layout.fillWidth: true
                Layout.preferredHeight: 160
                panelTitle: "Network Activity"

                ColumnLayout {
                    anchors.fill: parent
                    anchors.margins: 12
                    spacing: 8

                    RowLayout {
                        Text {
                            text: "CURRENT ACTIVITY"
                            font.family: "Consolas"
                            font.pixelSize: 11
                            color: "#4a6a7a"
                        }
                        Item { Layout.fillWidth: true }
                        Text {
                            text: app.networkActivity.toFixed(1) + "%"
                            font.family: "Consolas"
                            font.pixelSize: 20
                            font.bold: true
                            color: "#00d4ff"
                        }
                    }

                    Rectangle {
                        Layout.fillWidth: true
                        height: 8
                        radius: 4
                        color: "#0c1a2a"

                        Rectangle {
                            height: parent.height
                            radius: 4
                            width: parent.width * app.networkActivity / 100
                            color: "#00d4ff"

                            Behavior on width {
                                NumberAnimation { duration: 200 }
                            }
                        }
                    }

                    RowLayout {
                        Text {
                            text: "ACTIVE NEURONS"
                            font.family: "Consolas"
                            font.pixelSize: 11
                            color: "#4a6a7a"
                        }
                        Item { Layout.fillWidth: true }
                        Text {
                            text: app.activeNeuronCount + " / " + app.neuronCount
                            font.family: "Consolas"
                            font.pixelSize: 12
                            color: "#00ff88"
                        }
                    }

                    RowLayout {
                        Text {
                            text: "SYNAPSES"
                            font.family: "Consolas"
                            font.pixelSize: 11
                            color: "#4a6a7a"
                        }
                        Item { Layout.fillWidth: true }
                        Text {
                            text: app.synapseCount.toString()
                            font.family: "Consolas"
                            font.pixelSize: 12
                            color: "#00d4ff"
                        }
                    }
                }
            }

            // Emotions overview
            GlowPanel {
                Layout.fillWidth: true
                Layout.preferredHeight: 220
                panelTitle: "Emotional State"

                GridLayout {
                    anchors.fill: parent
                    anchors.margins: 12
                    columns: 2
                    columnSpacing: 16
                    rowSpacing: 12

                    Repeater {
                        model: app.emotions

                        delegate: ColumnLayout {
                            Layout.fillWidth: true
                            spacing: 4

                            RowLayout {
                                Rectangle {
                                    width: 8
                                    height: 8
                                    radius: 4
                                    color: modelData.color
                                }
                                Text {
                                    text: modelData.name.toUpperCase()
                                    font.family: "Consolas"
                                    font.pixelSize: 10
                                    color: "#5a8a9a"
                                }
                                Item { Layout.fillWidth: true }
                                Text {
                                    text: modelData.value.toFixed(0)
                                    font.family: "Consolas"
                                    font.pixelSize: 10
                                    color: "#8abacc"
                                }
                            }

                            Rectangle {
                                Layout.fillWidth: true
                                height: 4
                                radius: 2
                                color: "#0c1a2a"

                                Rectangle {
                                    height: parent.height
                                    radius: 2
                                    width: parent.width * modelData.value / 100
                                    color: modelData.color

                                    Behavior on width {
                                        NumberAnimation { duration: 300 }
                                    }
                                }
                            }
                        }
                    }
                }
            }

            // Memories overview
            GlowPanel {
                Layout.fillWidth: true
                Layout.preferredHeight: 180
                panelTitle: "Memories"

                ColumnLayout {
                    anchors.fill: parent
                    anchors.margins: 12
                    spacing: 6

                    Repeater {
                        model: Math.min(app.memories.length, 5)

                        delegate: Rectangle {
                            Layout.fillWidth: true
                            height: 30
                            radius: 4
                            color: "#0c1420"

                            RowLayout {
                                anchors.fill: parent
                                anchors.leftMargin: 8
                                anchors.rightMargin: 8

                                Rectangle {
                                    width: 3
                                    height: 18
                                    radius: 1
                                    color: "#00d4ff"
                                }

                                Text {
                                    text: app.memories[index].name
                                    font.family: "Consolas"
                                    font.pixelSize: 11
                                    color: "#8abacc"
                                    Layout.fillWidth: true
                                    elide: Text.ElideRight
                                }

                                Text {
                                    text: app.memories[index].intensity.toFixed(0) + "%"
                                    font.family: "Consolas"
                                    font.pixelSize: 10
                                    color: "#4a6a7a"
                                }
                            }
                        }
                    }

                    Text {
                        visible: app.memories.length === 0
                        text: "No memories yet"
                        font.family: "Consolas"
                        font.pixelSize: 11
                        color: "#3a4a5a"
                        Layout.fillWidth: true
                        horizontalAlignment: Text.AlignHCenter
                    }
                }
            }
        }
    }
}
