import QtQuick 2.0
import QtQuick.Templates 2.12 as t
import utils 1.0


t.Button {
    id: root
    implicitWidth: 120
    implicitHeight: 40


    background: Item{
        anchors.fill: parent
        Rectangle {
            id: backgroundFill
            anchors.fill: parent
            radius: 30
            color: root.pressed ? Style.inactiveColor : Style.mainColor
        }
    }

    contentItem: Item {
        anchors.fill: parent
        Label {
            anchors.centerIn: parent
            color: Style.fontConstrastColor
            text: root.text
        }
    }
}
