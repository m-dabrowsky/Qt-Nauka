
import QtQuick 2.11
import QtQuick.Window 2.11
import QtQuick.Controls 2.1
import QtQuick.Particles 2.12

import Controls 1.0
import utils 1.0
import "Imports/Controls"
import "Imports/qdashboardStyles"


/*
    Okno z możliwością łatwego dodania toolBar, statusBar itd.
*/
ApplicationWindow {
    width: 595
    height: 842
    visible: false

    // Lista Elementów które znajduja się na pasku po lewej stronie
    ListModel {
        id: listModel
        ListElement {url: "sheets/WidgetsSheet.qml"; text: "Basic Widgets"}
        ListElement {url: "sheets/ListViewSheet.qml"; text: "ListView"}
        ListElement {url: "sheets/GridViewSheet.qml"; text: "GridView"}
        ListElement {url: "sheets/PathViewSheet.qml"; text: "PathView"}
        ListElement {url: "sheets/WindmillSheet.qml"; text: "Windmill Animation"}
        ListElement {url: "sheets/ParticlesSheet.qml"; text: "Particles Animation"}
    }
    // Okno na samej górzej z tytułem
    header: Item{
        width: parent.width         // rozciągające się na całe okno
        height: 30                  // o wysokości = 30

        // Prostokąt w którym znajdzie się tytuł
        Rectangle {
            width: menuArea.width
            height: parent.height
            color: Style.mainColor
        }

        /*Rectangle {
            id: fillColorRect
            width: (parent.width - menuArea.width)
            height: parent.height
            anchors.right: parent.right
            color: "red"
        }*/

        Text {
            anchors.centerIn: parent
            text: listModel.get(listView.currentIndex).text // wyświetlenie tekstu odpowiednio dla każdego indeksku z ListModel
        }

    }
    // Konfiguracja menu po lewej stronie
    contentData: Item {
        id: menuArea
        anchors.fill: parent

        // pasek z opcjami po lewej stronie
        Rectangle {
            width: 185
            height: parent.height
            color: Style.mainColor

            // Określenie widoku listy (modelu)
            ListView {
                id: listView
                anchors.fill: parent
                anchors.topMargin: 30
                model: listModel            // model z danymi
                interactive: false          // ??????
                spacing: 10                 // odstęp między wierszami
                highlight: Item {           // podświeltenie
                    width: parent.width
                    height: 47

                    // prostokąt z tekstem
                    Rectangle {
                        anchors.fill: parent
                        color: Style.bgColor
                        opacity: 0.6
                    }
                    // biały pasek
                    Rectangle {
                        width: 5
                        height: parent.height
                        color: "#fff"
                    }
                }
                // ??????????????????????
                delegate: Item {
                    width: parent.width
                    height: 47
                    // tekst na liście
                    Text {
                        anchors.centerIn: parent
                        color: "#fff"
                        text: model.text
                    }
                    MouseArea {
                        anchors.fill: parent
                        onClicked: {
                            listView.currentIndex = index;
                            stackView.push(Qt.resolvedUrl(model.url));
                        }
                    }
                }
            }
        }

        // przechodzenie i powrót do sheetsów
        StackView {
            id: stackView
            width: parent.width - listView.width
            height: parent.height
            anchors.right: parent.right
            initialItem: Qt.resolvedUrl("sheets/WidgetsSheet.qml")
            popEnter: Transition {              //???????
                PropertyAnimation {
                    property: "opacity"
                    from: 0
                    to: 1
                    duration: 200
                }
            }
            popExit: Transition {
                PropertyAnimation {
                    property: "opacity"
                    from: 1
                    to: 0
                    duration: 200
                }
            }

            pushEnter: Transition {
                PropertyAnimation {
                    property: "opacity"
                    from: 0
                    to: 1
                    duration: 200
                }
            }

            pushExit: Transition {
                PropertyAnimation {
                    property: "opacity"
                    from: 1
                    to: 0
                    duration: 200
                }
            }

        }
    }
}



