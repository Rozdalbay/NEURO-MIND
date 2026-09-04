import QtQuick
import QtQuick.Controls
import QtQuick.Layouts

import NeuroMind

Item {
    id: root

    Component.onCompleted: {
        app.initialize()
    }

    // Top bar
    Rectangle {
        id: topBar
        anchors.top: parent.top
        anchors.left: parent.left
        anchors.right: parent.right
        height: 48
        color: "#0c1220"

        Rectangle {
            anchors.bottom: parent.bottom
            anchors.left: parent.left
            anchors.right: parent.right
            height: 1
            color: "#1a2a3a"
        }

        RowLayout {
            anchors.fill: parent
            anchors.leftMargin: 16
            anchors.rightMargin: 16
            spacing: 24

            Text {
                text: "NEURO//MIND"
                font.family: "Consolas"
                font.pixelSize: 16
                font.bold: true
                color: "#00d4ff"
            }

            Rectangle {
                width: 1
                height: 24
                color: "#1a2a3a"
            }

            Row {
                spacing: 8
                StatusIndicator {
                    active: app.isOnline
                    label: app.isOnline ? "ONLINE" : "OFFLINE"
                    activeColor: "#00ff88"
                    inactiveColor: "#ff4444"
                }
            }

            Rectangle {
                width: 1
                height: 24
                color: "#1a2a3a"
            }

            Row {
                spacing: 8
                Text {
                    text: "SIMULATION"
                    font.family: "Consolas"
                    font.pixelSize: 11
                    color: "#4a6a7a"
                    anchors.verticalCenter: parent.verticalCenter
                }
                Text {
                    text: app.clock.elapsed.toFixed(1) + "s"
                    font.family: "Consolas"
                    font.pixelSize: 12
                    color: "#00d4ff"
                    anchors.verticalCenter: parent.verticalCenter
                }
            }

            Item { Layout.fillWidth: true }

            // Dream mode toggle
            NeonButton {
                text: app.isDreamMode ? "EXIT DREAM" : "DREAM MODE"
                width: 120
                height: 30
                baseColor: app.isDreamMode ? "#9b59b6" : "#1a2a3a"
                onClicked: {
                    if (app.isDreamMode)
                        app.exitDreamMode()
                    else
                        app.enterDreamMode()
                }
            }

            // Speed control
            Row {
                spacing: 8
                Text {
                    text: "SPEED"
                    font.family: "Consolas"
                    font.pixelSize: 11
                    color: "#4a6a7a"
                    anchors.verticalCenter: parent.verticalCenter
                }
                Slider {
                    id: speedSlider
                    width: 100
                    height: 30
                    from: 0.1
                    to: 5.0
                    value: app.simulationSpeed
                    stepSize: 0.1
                    onMoved: app.simulationSpeed = value
                    background: Rectangle {
                        x: parent.leftPadding
                        y: parent.topPadding + parent.availableHeight / 2 - height / 2
                        width: parent.availableWidth
                        height: 4
                        radius: 2
                        color: "#1a2a3a"
                        Rectangle {
                            width: parent.width * parent.parent.value / parent.parent.to
                            height: parent.height
                            radius: 2
                            color: "#00d4ff"
                        }
                    }
                    handle: Rectangle {
                        x: parent.leftPadding + parent.visualPosition * (parent.availableWidth - width)
                        y: parent.topPadding + parent.availableHeight / 2 - height / 2
                        width: 12
                        height: 12
                        radius: 6
                        color: "#00d4ff"
                        border.color: "#006688"
                        border.width: 1
                    }
                }
                Text {
                    text: app.simulationSpeed.toFixed(1) + "x"
                    font.family: "Consolas"
                    font.pixelSize: 12
                    color: "#00d4ff"
                    anchors.verticalCenter: parent.verticalCenter
                }
            }

            Rectangle {
                width: 1
                height: 24
                color: "#1a2a3a"
            }

            NeonButton {
                text: "RESET"
                width: 70
                height: 30
                baseColor: "#3a1a1a"
                textColor: "#ff6666"
                onClicked: app.resetSimulation()
            }
        }
    }

    // Main content
    RowLayout {
        anchors.top: topBar.bottom
        anchors.left: parent.left
        anchors.right: parent.right
        anchors.bottom: parent.bottom
        anchors.margins: 0
        spacing: 0

        // Left sidebar
        Rectangle {
            Layout.preferredWidth: 200
            Layout.fillHeight: true
            color: "#0c1220"

            Rectangle {
                anchors.right: parent.right
                anchors.top: parent.top
                anchors.bottom: parent.bottom
                width: 1
                color: "#1a2a3a"
            }

            ColumnLayout {
                anchors.fill: parent
                anchors.margins: 8
                spacing: 4

                Repeater {
                    model: ListModel {
                        ListElement { name: "DASHBOARD"; icon: "◈" }
                        ListElement { name: "BRAIN"; icon: "◉" }
                        ListElement { name: "MEMORY"; icon: "◆" }
                        ListElement { name: "EMOTION"; icon: "♡" }
                        ListElement { name: "DREAM"; icon: "☽" }
                        ListElement { name: "LOG"; icon: "▤" }
                    }

                    delegate: NeonButton {
                        Layout.fillWidth: true
                        height: 36
                        text: icon + "  " + name
                        baseColor: sidebarStack.depth > 0 && sidebarStack.currentItem.objectName === name.toLowerCase()
                               ? "#0a1a2a" : "transparent"
                        textColor: sidebarStack.depth > 0 && sidebarStack.currentItem.objectName === name.toLowerCase()
                                   ? "#00d4ff" : "#5a7a8a"
                        hoveredColor: "#0a1520"
                        onClicked: {
                            switch (name) {
                            case "DASHBOARD": sidebarStack.push(dashboardComponent); break;
                            case "BRAIN": sidebarStack.push(brainComponent); break;
                            case "MEMORY": sidebarStack.push(memoryComponent); break;
                            case "EMOTION": sidebarStack.push(emotionComponent); break;
                            case "DREAM": sidebarStack.push(dreamComponent); break;
                            case "LOG": sidebarStack.push(logComponent); break;
                            }
                        }
                    }
                }

                Item { Layout.fillHeight: true }

                // Quick stats
                ColumnLayout {
                    Layout.fillWidth: true
                    spacing: 4

                    Rectangle {
                        Layout.fillWidth: true
                        height: 1
                        color: "#1a2a3a"
                    }

                    Text {
                        text: "NETWORK STATS"
                        font.family: "Consolas"
                        font.pixelSize: 10
                        color: "#3a5a6a"
                    }

                    RowLayout {
                        Text {
                            text: "Neurons"
                            font.family: "Consolas"
                            font.pixelSize: 11
                            color: "#5a7a8a"
                            Layout.fillWidth: true
                        }
                        Text {
                            text: app.neuronCount.toString()
                            font.family: "Consolas"
                            font.pixelSize: 11
                            color: "#00d4ff"
                        }
                    }

                    RowLayout {
                        Text {
                            text: "Synapses"
                            font.family: "Consolas"
                            font.pixelSize: 11
                            color: "#5a7a8a"
                            Layout.fillWidth: true
                        }
                        Text {
                            text: app.synapseCount.toString()
                            font.family: "Consolas"
                            font.pixelSize: 11
                            color: "#00d4ff"
                        }
                    }

                    RowLayout {
                        Text {
                            text: "Active"
                            font.family: "Consolas"
                            font.pixelSize: 11
                            color: "#5a7a8a"
                            Layout.fillWidth: true
                        }
                        Text {
                            text: app.activeNeuronCount.toString()
                            font.family: "Consolas"
                            font.pixelSize: 11
                            color: "#00ff88"
                        }
                    }

                    RowLayout {
                        Text {
                            text: "Activity"
                            font.family: "Consolas"
                            font.pixelSize: 11
                            color: "#5a7a8a"
                            Layout.fillWidth: true
                        }
                        Text {
                            text: app.networkActivity.toFixed(1) + "%"
                            font.family: "Consolas"
                            font.pixelSize: 11
                            color: "#00d4ff"
                        }
                    }

                    RowLayout {
                        Text {
                            text: "Memories"
                            font.family: "Consolas"
                            font.pixelSize: 11
                            color: "#5a7a8a"
                            Layout.fillWidth: true
                        }
                        Text {
                            text: app.memoryCount.toString()
                            font.family: "Consolas"
                            font.pixelSize: 11
                            color: "#00d4ff"
                        }
                    }
                }
            }
        }

        // Content area
        StackView {
            id: sidebarStack
            Layout.fillWidth: true
            Layout.fillHeight: true
            initialItem: dashboardComponent
            clip: true

            Component { id: dashboardComponent; DashboardPanel { objectName: "dashboard" } }
            Component { id: brainComponent; BrainVisualization { objectName: "brain" } }
            Component { id: memoryComponent; MemoryPanel { objectName: "memory" } }
            Component { id: emotionComponent; EmotionPanel { objectName: "emotion" } }
            Component { id: dreamComponent; DreamPanel { objectName: "dream" } }
            Component { id: logComponent; LogPanel { objectName: "log" } }
        }
    }

    // Log panel at bottom
    Rectangle {
        id: bottomBar
        anchors.left: parent.left
        anchors.right: parent.right
        anchors.bottom: parent.bottom
        height: 24
        color: "#080c14"

        Rectangle {
            anchors.top: parent.top
            anchors.left: parent.left
            anchors.right: parent.right
            height: 1
            color: "#1a2a3a"
        }

        RowLayout {
            anchors.fill: parent
            anchors.leftMargin: 12
            anchors.rightMargin: 12
            spacing: 16

            Text {
                text: "TICK: " + app.clock.tickCount
                font.family: "Consolas"
                font.pixelSize: 11
                color: "#3a5a6a"
            }

            Text {
                text: "FPS: 60"
                font.family: "Consolas"
                font.pixelSize: 11
                color: "#3a5a6a"
            }

            Item { Layout.fillWidth: true }

            Text {
                text: "v0.1.0-alpha"
                font.family: "Consolas"
                font.pixelSize: 11
                color: "#2a3a4a"
            }
        }
    }

    Component {
        id: dashboardComponent
        DashboardPanel {}
    }

    Component {
        id: brainComponent
        BrainVisualization {}
    }

    Component {
        id: memoryComponent
        MemoryPanel {}
    }

    Component {
        id: emotionComponent
        EmotionPanel {}
    }

    Component {
        id: dreamComponent
        DreamPanel {}
    }

    Component {
        id: logComponent
        LogPanel {}
    }
}
