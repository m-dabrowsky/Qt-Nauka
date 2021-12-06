import QtQuick 2.11
import QtQuick.Templates 2.4 as t
import utils 1.0

t.BusyIndicator {
    id: root
    implicitWidth: 64
    implicitHeight: 64

    contentItem: Item {
        id: contentItem
        anchors.fill: parent
        x: parent.width / 2 - 32
        y: parent.height / 2 - 32
        opacity: root.running ? 1 : 0

        Behavior on opacity {
            OpacityAnimator {
                duration: 250
            }
        }

        RotationAnimator {
            target: contentItem
            running: root.visible && root.running
            from: 0
            to: 360
            loops: Animation.Infinite
            duration: 1250
        }

        Repeater {
            id: repeater
            model: 6

            Rectangle {
                x: contentItem.width / 2 - width / 2
                y: contentItem.height / 2 - height / 2
                implicitWidth: 10
                implicitHeight: 10
                radius: 5
                color: Style.mainColor
                transform: [
                    Translate {
                        y: -Math.min(contentItem.width, contentItem.height) * 0.5 + 5
                    },
                    Rotation {
                        angle: index / repeater.count * 360
                        origin.x: 5
                        origin.y: 5
                    }
                ]
            }
        }
    }


}
