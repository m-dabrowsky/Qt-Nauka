import QtQuick 2.0

BaseSheet {
    id: root
    clip: true

    PathView{
        anchors.fill: parent
        model: 100
        currentIndex: 0

        path: Path{
            startX: 0; startY: 250
            PathAttribute {name: "iconScale"; value: 0.5}
            PathAttribute {name: "iconz"; value: 0}
            PathAttribute {name: "iconx"; value: 0}
            PathAttribute {name: "icony"; value: 1}
            PathAttribute {name: "angleMove"; value: 40}
            PathQuad {x: parent.width / 2; y: 250; controlX: 162.5; controlY: 225}
            PathAttribute {name: "iconScale"; value: 1.5}
            PathAttribute {name: "iconz"; value: 20}
            PathAttribute {name: "iconx"; value: 0.5}
            PathAttribute {name: "icony"; value: 0.5}
            PathAttribute {name: "angleMove"; value: 0}
            PathQuad {x: parent.width; y: 250; controlX: 225; controlY: 225}
            PathAttribute {name: "iconScale"; value: 0.5}
            PathAttribute {name: "iconz"; value: 0}
            PathAttribute {name: "iconx"; value: 0}
            PathAttribute {name: "icony"; value: 1}
            PathAttribute {name: "angleMove"; value: -40}
        }

        delegate: Rectangle {
            width: 100
            height: 100
            z: PathView.iconz
            scale: PathView.iconScale
            color: Qt.rgba(Math.random(), Math.random(), Math.random(), 1)
            border.color: "black"
            property double iconx: PathView.iconx
            property double icony: PathView.icony
            property double angleMove: PathView.angleMove
            transform:
                Rotation {axis {x: iconx; y: icony; z: 0} angle: angleMove}
            Rectangle {
                id: dimming
                width: parent.width
                height: 40
                anchors.bottom: parent.bottom
                opacity: 0.2
            }
            Text {
                anchors.centerIn: dimming
                text: index
            }
        }
    }
}

