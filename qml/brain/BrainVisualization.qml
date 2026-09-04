import QtQuick
import QtQuick.Controls
import QtQuick.Layouts

import NeuroMind

GlowPanel {
    id: root
    panelTitle: "Brain Visualization / GPU Scene Graph"

    property real zoom: 1.0
    property real offsetX: 0
    property real offsetY: 0
    property int hoveredNeuronId: -1
    property var neuronSnapshot: []
    property var synapseSnapshot: []

    function refreshSnapshot() {
        neuronSnapshot = app.neurons
        synapseSnapshot = app.synapses
    }

    Component.onCompleted: refreshSnapshot()

    Item {
        anchors.fill: parent
        clip: true

        Rectangle {
            anchors.fill: parent
            color: "#070d15"

            gradient: Gradient {
                orientation: Gradient.Vertical
                GradientStop { position: 0.0; color: "#091421" }
                GradientStop { position: 1.0; color: "#050a11" }
            }
        }

        NeuralNetworkItem {
            id: networkRenderer
            anchors.fill: parent
            neurons: root.neuronSnapshot
            synapses: root.synapseSnapshot
            zoom: root.zoom
            offsetX: root.offsetX
            offsetY: root.offsetY
            selectedNeuronId: app.selectedNeuronId
            hoveredNeuronId: root.hoveredNeuronId
        }

        MouseArea {
            id: interactionArea
            anchors.fill: parent
            hoverEnabled: true
            acceptedButtons: Qt.LeftButton | Qt.RightButton

            property real lastMouseX: 0
            property real lastMouseY: 0
            property bool dragging: false

            onPressed: function(mouse) {
                if (mouse.button === Qt.LeftButton) {
                    lastMouseX = mouse.x
                    lastMouseY = mouse.y
                    dragging = true
                }
            }

            onReleased: function(mouse) {
                if (mouse.button === Qt.LeftButton)
                    dragging = false
            }

            onPositionChanged: function(mouse) {
                if (dragging) {
                    root.offsetX += mouse.x - lastMouseX
                    root.offsetY += mouse.y - lastMouseY
                    lastMouseX = mouse.x
                    lastMouseY = mouse.y
                } else {
                    root.hoveredNeuronId = networkRenderer.neuronAt(mouse.x, mouse.y)
                }
            }

            onExited: root.hoveredNeuronId = -1

            onClicked: function(mouse) {
                if (mouse.button !== Qt.LeftButton)
                    return
                var neuronId = networkRenderer.neuronAt(mouse.x, mouse.y)
                if (neuronId >= 0)
                    app.selectNeuron(neuronId)
                else
                    app.deselectNeuron()
            }

            onWheel: function(wheel) {
                var oldZoom = root.zoom
                var newZoom = Math.max(0.2, Math.min(5.0,
                                   oldZoom * (wheel.angleDelta.y > 0 ? 1.12 : 0.89)))
                root.offsetX = wheel.x - (wheel.x - root.offsetX) * newZoom / oldZoom
                root.offsetY = wheel.y - (wheel.y - root.offsetY) * newZoom / oldZoom
                root.zoom = newZoom
            }
        }

        Timer {
            interval: 50
            repeat: true
            running: root.visible
            onTriggered: root.refreshSnapshot()
        }

        Rectangle {
            anchors.top: parent.top
            anchors.left: parent.left
            anchors.margins: 12
            width: rendererLabel.width + 20
            height: 26
            radius: 4
            color: "#b30a1724"
            border.color: "#24435a"

            Text {
                id: rendererLabel
                anchors.centerIn: parent
                text: "GPU RENDERER  /  " + app.neuronCount + " NODES"
                font.family: "Consolas"
                font.pixelSize: 9
                font.letterSpacing: 1
                color: "#58b9d8"
            }
        }

        Row {
            anchors.bottom: parent.bottom
            anchors.right: parent.right
            anchors.margins: 12
            spacing: 8

            NeonButton {
                text: "-"
                width: 28
                height: 28
                fontSize: 14
                onClicked: root.zoom = Math.max(0.2, root.zoom * 0.8)
            }

            Text {
                text: (root.zoom * 100).toFixed(0) + "%"
                font.family: "Consolas"
                font.pixelSize: 11
                color: "#6f91a6"
                anchors.verticalCenter: parent.verticalCenter
            }

            NeonButton {
                text: "+"
                width: 28
                height: 28
                fontSize: 14
                onClicked: root.zoom = Math.min(5.0, root.zoom * 1.25)
            }

            NeonButton {
                text: "CENTER"
                width: 64
                height: 28
                fontSize: 9
                onClicked: {
                    root.zoom = 1.0
                    root.offsetX = 0
                    root.offsetY = 0
                }
            }
        }

        NeonButton {
            anchors.bottom: parent.bottom
            anchors.left: parent.left
            anchors.margins: 12
            text: "STIMULATE RANDOM"
            width: 140
            height: 32
            baseColor: "#0a2a1a"
            textColor: "#00ff88"
            onClicked: app.stimulateRandom(0.8)
        }
    }
}
