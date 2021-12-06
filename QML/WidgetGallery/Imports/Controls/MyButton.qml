import QtQuick 2.11

Item {
    id: root
    width: 100
    height: 40

    signal clicked()
    property alias text: textElement.text

    Rectangle {
        anchors.fill: parent
        radius: 30
        color: mouseArea.pressed ? "#A8A8A8" : "#00D1A9"
    }

    Text {
        id: textElement
        anchors.centerIn: parent
        color: "#ffffff"
    }

    MouseArea {
        id: mouseArea
        anchors.fill: parent
        onClicked: {
            root.clicked();
        }
    }
}
