import QtQuick
import QtQuick.Window
import QtQuick.Controls
import QtQuick.Controls.Material

import NeuroMind

ApplicationWindow {
    id: root

    visible: true
    width: 1400
    height: 900
    minimumWidth: 1000
    minimumHeight: 600
    title: "NEURO//MIND"
    color: "#0a0e17"

    Material.theme: Material.Dark
    Material.accent: "#00d4ff"
    Material.primary: "#00d4ff"
    Material.background: "#0a0e17"

    Component.onCompleted: {
        stackView.push(startupComponent)
    }

    Component {
        id: startupComponent
        StartupScreen {
            onStartupComplete: {
                stackView.pop()
                stackView.push(mainWindowComponent)
            }
        }
    }

    Component {
        id: mainWindowComponent
        MainWindow {
        }
    }

    StackView {
        id: stackView
        anchors.fill: parent
        initialItem: null

    }
}
