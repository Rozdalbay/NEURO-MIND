import QtQuick

Text {
    id: root

    property real targetValue: 0
    property string suffix: ""
    property string format: "f1"

    text: targetValue.toFixed(1) + suffix

    Behavior on targetValue {
        NumberAnimation { duration: 300; easing.type: Easing.InOutQuad }
    }
}
