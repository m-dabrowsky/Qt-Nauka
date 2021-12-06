import QtQuick 2.11

Item {
    id: root
    width: 170
    height: 30

    property alias text: textLabel.text
    property bool checked: false

    state: "off"

    Rectangle {
        id: background
        width: root.width / 3
        height: parent.height
        color: "transparent"
        border.color: "#A8A8A8"
        radius: width / 3
        Rectangle {
            id: indicator
            width: parent.width / 2
            height: parent.height
            color: "#00D1A9"
            radius: width / 2
            x: 0
            y: 0
        }
        MouseArea {
            anchors.fill: parent
            onClicked: {
                if (root.state === "on") {
                    root.state = "off";
                } else {
                    root.state = "on";
                }
            }
        }
    }

    Text {
        id: textLabel
        anchors.left: background.right
        anchors.leftMargin: 10
        anchors.verticalCenter: parent.verticalCenter
        font.pixelSize: 14
        color: "#A8A8A8"
    }

    states: [
        State {
            name: "on"
            PropertyChanges { target: indicator; x: (background.width - indicator.width) }
            PropertyChanges { target: root; checked: true }
        },
        State {
            name: "off"
            PropertyChanges { target: indicator; x: 0 }
            PropertyChanges { target: root; checked: false }
        }
    ]

    transitions: Transition {
        NumberAnimation { properties: "x"; easing.type: Easing.InOutQuad; duration: 200 }
    }
}
