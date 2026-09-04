import QtQuick
import QtQuick.Controls
import QtQuick.Layouts

GlowPanel {
    id: root
    panelTitle: "Memory System"

    property int editingMemoryId: -1

    ColumnLayout {
        anchors.fill: parent
        anchors.margins: 12
        spacing: 12

        // Create memory section
        Rectangle {
            Layout.fillWidth: true
            height: 80
            radius: 4
            color: "#0c1420"

            ColumnLayout {
                anchors.fill: parent
                anchors.margins: 8
                spacing: 6

                Text {
                    text: "CREATE NEW MEMORY"
                    font.family: "Consolas"
                    font.pixelSize: 10
                    color: "#3a5a6a"
                }

                TextField {
                    id: nameField
                    Layout.fillWidth: true
                    height: 28
                    placeholderText: "Memory name..."
                    font.family: "Consolas"
                    font.pixelSize: 12
                    color: "#8abacc"
                    background: Rectangle { color: "#0a1018"; radius: 4; border.color: "#1a2a3a" }
                }

                RowLayout {
                    Layout.fillWidth: true
                    spacing: 8

                    TextField {
                        id: descField
                        Layout.fillWidth: true
                        height: 28
                        placeholderText: "Description..."
                        font.family: "Consolas"
                        font.pixelSize: 12
                        color: "#8abacc"
                        background: Rectangle { color: "#0a1018"; radius: 4; border.color: "#1a2a3a" }
                    }

                    NeonButton {
                        text: "CREATE"
                        width: 80
                        height: 28
                        baseColor: "#0a2a1a"
                        textColor: "#00ff88"
                        onClicked: {
                            if (nameField.text.length > 0) {
                                app.createMemory(nameField.text, descField.text)
                                nameField.text = ""
                                descField.text = ""
                            }
                        }
                    }
                }
            }
        }

        // Memory list
        ScrollView {
            Layout.fillWidth: true
            Layout.fillHeight: true
            clip: true

            ListView {
                id: memoryList
                model: app.memories
                spacing: 6

                delegate: Rectangle {
                    width: memoryList.width
                    height: 60
                    radius: 4
                    color: mouseArea.containsMouse ? "#0c1a28" : "#0c1420"
                    border.color: "#1a2a3a"
                    border.width: 1

                    RowLayout {
                        anchors.fill: parent
                        anchors.margins: 8
                        spacing: 12

                        Rectangle {
                            width: 4
                            height: 40
                            radius: 2
                            color: "#00d4ff"
                        }

                        ColumnLayout {
                            Layout.fillWidth: true
                            spacing: 4

                            Text {
                                text: modelData.name
                                font.family: "Consolas"
                                font.pixelSize: 12
                                font.bold: true
                                color: "#c0e0f0"
                                elide: Text.ElideRight
                                Layout.fillWidth: true
                            }

                            Text {
                                text: modelData.description
                                font.family: "Consolas"
                                font.pixelSize: 10
                                color: "#4a6a7a"
                                elide: Text.ElideRight
                                Layout.fillWidth: true
                                visible: modelData.description.length > 0
                            }

                            Row {
                                spacing: 12
                                Text {
                                    text: "INTENSITY: " + modelData.intensity.toFixed(0) + "%"
                                    font.family: "Consolas"
                                    font.pixelSize: 9
                                    color: "#5a8a9a"
                                }
                                Text {
                                    text: "STRENGTH: " + modelData.strength.toFixed(2)
                                    font.family: "Consolas"
                                    font.pixelSize: 9
                                    color: "#5a8a9a"
                                }
                                Text {
                                    text: "NEURONS: " + modelData.neuronCount
                                    font.family: "Consolas"
                                    font.pixelSize: 9
                                    color: "#5a8a9a"
                                }
                            }
                        }

                        NeonButton {
                            text: "ACTIVATE"
                            width: 72
                            height: 24
                            fontSize: 10
                            baseColor: "#0a1a2a"
                            textColor: "#00d4ff"
                            onClicked: app.activateMemory(modelData.id)
                        }

                        NeonButton {
                            text: "X"
                            width: 24
                            height: 24
                            fontSize: 10
                            baseColor: "#2a0a0a"
                            textColor: "#ff6666"
                            onClicked: app.deleteMemory(modelData.id)
                        }
                    }

                    MouseArea {
                        id: mouseArea
                        anchors.fill: parent
                        hoverEnabled: true
                        acceptedButtons: Qt.NoButton
                    }
                }

                Text {
                    anchors.centerIn: parent
                    visible: app.memories.length === 0
                    text: "No memories yet.\nCreate one above."
                    font.family: "Consolas"
                    font.pixelSize: 12
                    color: "#3a4a5a"
                    horizontalAlignment: Text.AlignHCenter
                }
            }
        }
    }
}
