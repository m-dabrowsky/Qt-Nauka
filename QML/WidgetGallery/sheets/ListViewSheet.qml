import QtQuick 2.0

BaseSheet {
    id: root
    clip: true

    ListView {

        width: 150
        height: 400
        anchors.centerIn: parent
        model: 100      // liczba prostokatów
        delegate: Item {    // właściwośc dla jednego prostokąta
            id: colorIcon
            width: parent.width
            height: 40
            // prostokat w jednym kolorze
            Rectangle {
                width: parent.width
                height: 40
                anchors.left: parent.left
                anchors.leftMargin: 10
                anchors.verticalCenter: parent.verticalCenter
                color: Qt.rgba(Math.random(), Math.random(), Math.random(), 1)
            }
            // Tekst obok prostokata
            Text {
                anchors.left: colorIcon.right
                anchors.leftMargin: 20
                anchors.verticalCenter: parent.verticalCenter
                text: "Item " + index
            }
            // Linia oddzielająca
            Rectangle {
                width: parent.width
                height: 1
                color: "black"
                anchors.bottom: parent.bottom
            }
        }



    }


}
