import QtQuick
import QtQuick.Controls
import QtQuick.Layouts
import QtQuick.Shapes

GlowPanel {
    id: root
    panelTitle: "Brain Visualization"

    property real zoom: 1.0
    property real offsetX: 0
    property real offsetY: 0
    property int hoveredNeuronId: -1

    Item {
        anchors.fill: parent
        clip: true

        Canvas {
            id: brainCanvas
            anchors.fill: parent

            property real lastMouseX: 0
            property real lastMouseY: 0
            property bool dragging: false

            onPaint: {
                var ctx = getContext("2d")
                ctx.clearRect(0, 0, width, height)

                // Background grid
                drawGrid(ctx)

                // Synapses
                drawSynapses(ctx)

                // Neurons
                drawNeurons(ctx)
            }

            function drawGrid(ctx) {
                ctx.strokeStyle = "#0a1520"
                ctx.lineWidth = 1

                var gridSize = 50 * root.zoom
                var startX = root.offsetX % gridSize
                var startY = root.offsetY % gridSize

                ctx.beginPath()
                for (var x = startX; x < width; x += gridSize) {
                    ctx.moveTo(x, 0)
                    ctx.lineTo(x, height)
                }
                for (var y = startY; y < height; y += gridSize) {
                    ctx.moveTo(0, y)
                    ctx.lineTo(width, y)
                }
                ctx.stroke()
            }

            function drawSynapses(ctx) {
                var synapses = app.synapses
                var neurons = app.neurons
                var neuronMap = {}

                for (var ni = 0; ni < neurons.length; ni++) {
                    neuronMap[neurons[ni].id] = neurons[ni]
                }

                for (var i = 0; i < synapses.length; i++) {
                    var s = synapses[i]
                    var src = neuronMap[s.sourceId]
                    var tgt = neuronMap[s.targetId]

                    if (!src || !tgt) continue

                    var sx = src.x * root.zoom + root.offsetX
                    var sy = src.y * root.zoom + root.offsetY
                    var tx = tgt.x * root.zoom + root.offsetX
                    var ty = tgt.y * root.zoom + root.offsetY

                    var isSelected = (src.id === root.hoveredNeuronId || tgt.id === root.hoveredNeuronId)

                    if (isSelected) {
                        ctx.strokeStyle = "rgba(0, 212, 255, 0.6)"
                        ctx.lineWidth = 2.0 * s.weight
                    } else {
                        var alpha = 0.1 + s.weight * 0.2 + s.activity * 0.3
                        var activityColor = s.activity > 0.1
                            ? "rgba(0, 212, 255, " + alpha + ")"
                            : "rgba(30, 60, 80, " + alpha + ")"
                        ctx.strokeStyle = activityColor
                        ctx.lineWidth = 0.5 + s.weight * 1.5
                    }

                    ctx.beginPath()
                    ctx.moveTo(sx, sy)
                    ctx.lineTo(tx, ty)
                    ctx.stroke()

                    if (s.activity > 0.2) {
                        drawPulse(ctx, sx, sy, tx, ty, s.activity)
                    }
                }
            }

            function drawPulse(ctx, sx, sy, tx, ty, activity) {
                var progress = (Date.now() % 1000) / 1000.0
                var px = sx + (tx - sx) * progress
                var py = sy + (ty - sy) * progress
                var radius = 2 + activity * 3

                ctx.fillStyle = "rgba(0, 212, 255, " + (activity * 0.8) + ")"
                ctx.beginPath()
                ctx.arc(px, py, radius, 0, Math.PI * 2)
                ctx.fill()

                // Glow
                var gradient = ctx.createRadialGradient(px, py, 0, px, py, radius * 3)
                gradient.addColorStop(0, "rgba(0, 212, 255, " + (activity * 0.3) + ")")
                gradient.addColorStop(1, "rgba(0, 212, 255, 0)")
                ctx.fillStyle = gradient
                ctx.beginPath()
                ctx.arc(px, py, radius * 3, 0, Math.PI * 2)
                ctx.fill()
            }

            function drawNeurons(ctx) {
                var neurons = app.neurons
                var selectedId = app.selectedNeuronId

                for (var i = 0; i < neurons.length; i++) {
                    var n = neurons[i]
                    var nx = n.x * root.zoom + root.offsetX
                    var ny = n.y * root.zoom + root.offsetY

                    var baseRadius = 4 + n.type * 2
                    var activationRadius = baseRadius * (1.0 + n.activation * 1.5)
                    var isSelected = (n.id === selectedId || n.id === root.hoveredNeuronId)

                    // Glow for active neurons
                    if (n.activation > 0.1 || isSelected) {
                        var glowRadius = activationRadius * 3
                        var gradient = ctx.createRadialGradient(nx, ny, 0, nx, ny, glowRadius)
                        var glowAlpha = Math.min(1.0, n.activation * 0.5 + (isSelected ? 0.3 : 0))
                        gradient.addColorStop(0, "rgba(0, 212, 255, " + glowAlpha + ")")
                        gradient.addColorStop(1, "rgba(0, 212, 255, 0)")
                        ctx.fillStyle = gradient
                        ctx.beginPath()
                        ctx.arc(nx, ny, glowRadius, 0, Math.PI * 2)
                        ctx.fill()
                    }

                    // Neuron body
                    var bodyColor
                    if (isSelected) {
                        bodyColor = "#00d4ff"
                    } else if (n.active) {
                        var brightness = Math.floor(150 + n.activation * 105)
                        bodyColor = "rgb(0, " + brightness + ", " + (brightness - 20) + ")"
                    } else {
                        bodyColor = "#1a3a4a"
                    }

                    ctx.fillStyle = bodyColor
                    ctx.beginPath()
                    ctx.arc(nx, ny, activationRadius, 0, Math.PI * 2)
                    ctx.fill()

                    // Border
                    ctx.strokeStyle = isSelected ? "#00d4ff" : "#2a4a5a"
                    ctx.lineWidth = isSelected ? 2 : 1
                    ctx.stroke()

                    // Center dot
                    ctx.fillStyle = n.active ? "#00ffaa" : "#2a3a4a"
                    ctx.beginPath()
                    ctx.arc(nx, ny, 2, 0, Math.PI * 2)
                    ctx.fill()
                }
            }

            MouseArea {
                anchors.fill: parent
                hoverEnabled: true
                acceptedButtons: Qt.LeftButton | Qt.RightButton

                onPressed: function(mouse) {
                    if (mouse.button === Qt.LeftButton) {
                        brainCanvas.lastMouseX = mouse.x
                        brainCanvas.lastMouseY = mouse.y
                        brainCanvas.dragging = true
                    }
                }

                onReleased: function(mouse) {
                    if (mouse.button === Qt.LeftButton) {
                        brainCanvas.dragging = false
                    }
                }

                onPositionChanged: function(mouse) {
                    if (brainCanvas.dragging) {
                        root.offsetX += mouse.x - brainCanvas.lastMouseX
                        root.offsetY += mouse.y - brainCanvas.lastMouseY
                        brainCanvas.lastMouseX = mouse.x
                        brainCanvas.lastMouseY = mouse.y
                        brainCanvas.requestPaint()
                    } else {
                        var foundId = findNeuronAt(mouse.x, mouse.y)
                        if (foundId !== root.hoveredNeuronId) {
                            root.hoveredNeuronId = foundId
                            brainCanvas.requestPaint()
                        }
                    }
                }

                onClicked: function(mouse) {
                    if (mouse.button === Qt.LeftButton) {
                        var neuronId = findNeuronAt(mouse.x, mouse.y)
                        if (neuronId >= 0) {
                            app.selectNeuron(neuronId)
                        } else {
                            app.deselectNeuron()
                        }
                        brainCanvas.requestPaint()
                    }
                }

                onWheel: function(wheel) {
                    var zoomFactor = wheel.angleDelta.y > 0 ? 1.1 : 0.9
                    root.zoom = Math.max(0.2, Math.min(5.0, root.zoom * zoomFactor))
                    brainCanvas.requestPaint()
                }
            }

            function findNeuronAt(mx, my) {
                var neurons = app.neurons
                for (var i = neurons.length - 1; i >= 0; i--) {
                    var n = neurons[i]
                    var nx = n.x * root.zoom + root.offsetX
                    var ny = n.y * root.zoom + root.offsetY
                    var dx = mx - nx
                    var dy = my - ny
                    var radius = (4 + n.type * 2) * (1.0 + n.activation * 1.5)
                    if (dx * dx + dy * dy < radius * radius * 2) {
                        return n.id
                    }
                }
                return -1
            }
        }

        // Animation timer for continuous repaint
        Timer {
            interval: 33
            repeat: true
            running: true
            onTriggered: brainCanvas.requestPaint()
        }

        // Zoom indicator
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
                onClicked: {
                    root.zoom = Math.max(0.2, root.zoom * 0.8)
                    brainCanvas.requestPaint()
                }
            }

            Text {
                text: (root.zoom * 100).toFixed(0) + "%"
                font.family: "Consolas"
                font.pixelSize: 11
                color: "#4a6a7a"
                anchors.verticalCenter: parent.verticalCenter
            }

            NeonButton {
                text: "+"
                width: 28
                height: 28
                fontSize: 14
                onClicked: {
                    root.zoom = Math.min(5.0, root.zoom * 1.25)
                    brainCanvas.requestPaint()
                }
            }

            NeonButton {
                text: "RESET"
                width: 56
                height: 28
                fontSize: 10
                onClicked: {
                    root.zoom = 1.0
                    root.offsetX = 0
                    root.offsetY = 0
                    brainCanvas.requestPaint()
                }
            }
        }

        // Stimulate button
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
