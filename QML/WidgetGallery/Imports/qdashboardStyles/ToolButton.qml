import QtQuick 2.0
import QtQuick.Templates 2.4 as t
import utils 1.0


t.ToolButton {
    id: root
    implicitWidth: 140
    implicitHeight: 40

    background: Item{
        id: background
        anchors.fill: parent
        Image {
            id: iconImg
            anchors.verticalCenter: parent.verticalCenter
            source: icon.source
        }
    }

    contentItem: Item {
        width: (parent.height - iconImg.width)
        height: parent.height
        anchors.ledt: parent.left
        anchors.leftMargin: (iconImg.width > 0) ? (iconImg.width + 10) : 0
        Label {
            anchors.fill: parent
            verticalAlignment: Text.AlignVCenter
            text: root.text
            color: root.pressed ? Style.mainColor : Style.inactiveColor

        }
    }

}
