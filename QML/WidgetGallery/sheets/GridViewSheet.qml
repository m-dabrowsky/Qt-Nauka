import QtQuick 2.0

BaseSheet {
    id: root
    clip: true

    GridView {
        id: gridView
        width: 360
        height: parent.height
        anchors.horizontalCenter: parent.horizontalCenter
        cellHeight: 120                                     // wysokosc
        cellWidth: 120                                      // szerokosc
        model: 100                                          // liczba elementow
        delegate: Rectangle {                               // właściowości delegata
            width: gridView.cellWidth
            height: gridView.cellHeight
            color: Qt.rgba(Math.random(), Math.random(), Math.random(), 1)  // losowy wybór kolorów
            border.color: "black"
            // prostokąt z numerem
            Rectangle {
                id: dimming
                width: parent.width
                height: 40
                anchors.bottom: parent.bottom
                opacity: 0.2    // przezroczystosc
            }
            Text {
                anchors.centerIn: dimming
                text: index
            }
        }
    }

}
