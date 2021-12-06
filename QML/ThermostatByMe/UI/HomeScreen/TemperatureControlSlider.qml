import QtQuick 2.0
import QtQuick.Controls 2.12
import Mike 1.0
Slider {
    id: temperatureControlSlider
    from: 55                     // od jakiej wartości zacząć
    to: 85                      // do jakiej maksymalnie mozna zwiekszyc
    stepSize: 1                 // co ile zwiekszac
    orientation: Qt.Vertical    // orientacja suwaka
    onValueChanged: systemController.setTargetTemp( value ) // na zmianę wartosci ustawia temp w systemcontroler

    // linia po ktorej porusza się¸ suwak
    background: Rectangle {
        height: parent.height
        width: 3
        anchors.centerIn: parent
    }

    // handle - przechowuje zawartość dla suwaka slidera (środek suwaka)
    handle: Rectangle {
        y: temperatureControlSlider.visualPosition * ( temperatureControlSlider.availableHeight - height )
        width: 76
        height: 76
        radius: width / 2
        color: "black"
        border.color: "white"
        border.width: 3
        anchors.horizontalCenter: parent.horizontalCenter

        Text {
            anchors.centerIn: parent
            color: "white"
            font.pixelSize: 30
            text: temperatureControlSlider.value
        }
    }
}
