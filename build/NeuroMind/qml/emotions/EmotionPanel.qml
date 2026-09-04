import QtQuick
import QtQuick.Controls
import QtQuick.Layouts

import NeuroMind

GlowPanel {
    id: root
    panelTitle: "Emotion System"

    ScrollView {
        anchors.fill: parent
        clip: true

        ColumnLayout {
            width: parent.width
            spacing: 16

            Repeater {
                model: app.emotions

                delegate: GlowPanel {
                    Layout.fillWidth: true
                    Layout.preferredHeight: 100
                    panelTitle: modelData.name

                    ColumnLayout {
                        anchors.fill: parent
                        anchors.margins: 12
                        spacing: 8

                        RowLayout {
                            Text {
                                text: "LEVEL"
                                font.family: "Consolas"
                                font.pixelSize: 10
                                color: "#4a6a7a"
                            }
                            Item { Layout.fillWidth: true }
                            Text {
                                text: modelData.value.toFixed(1)
                                font.family: "Consolas"
                                font.pixelSize: 16
                                font.bold: true
                                color: modelData.color
                            }
                        }

                        Rectangle {
                            Layout.fillWidth: true
                            height: 6
                            radius: 3
                            color: "#0c1a2a"

                            Rectangle {
                                height: parent.height
                                radius: 3
                                width: parent.width * modelData.value / 100
                                color: modelData.color

                                Behavior on width {
                                    NumberAnimation { duration: 300 }
                                }
                            }
                        }

                        Row {
                            spacing: 4
                            Text {
                                text: getEmotionDescription(modelData.name)
                                font.family: "Consolas"
                                font.pixelSize: 9
                                color: "#3a5a6a"
                                wrapMode: Text.Wrap
                            }
                        }
                    }

                    function getEmotionDescription(name) {
                        switch(name) {
                        case "Happiness": return "Boosts network stability and memory formation"
                        case "Sadness": return "Increases introspection, slows activity"
                        case "Fear": return "Heightens sensitivity to stimuli"
                        case "Anger": return "Amplifies signal strength"
                        case "Curiosity": return "Promotes exploration and neurogenesis"
                        case "Calm": return "Enhances focused processing"
                        default: return ""
                        }
                    }
                }
            }
        }
    }
}
