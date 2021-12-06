import QtQuick 2.0
import QtQuick.Templates 2.4 as t
import utils 1.0

t.RadioButton {
    id: root
    implicitHeight: 50
    implicitWidth: 120

    background: Rectangle {
        id: fillRect
        width: parent.height
        height: width
        radius: width / 2
        color: "transparent"
        border.color: Style.inactiveColor
    }

    indicator: Rectangle {
        width: (parent.height - 10)
        height: (parent.height - 10)
        anchors.centerIn: fillRect
        radius: width / 2
        visible: root.checked
        color: Style.mainColor
    }

    contentItem: Item {
        width: (parent.width - fillRect.width- 10)
        height: parent.height
        anchors.left: fillRect.right
        anchors.leftMargin: 10
        Label {
            id: textLabel
            anchors.verticalCenter: parent.verticalCenter
            text: root.text
        }
    }

}
