import QtQuick 2.15
import QtQuick.Window 2.15
import Mike 1.0


Window {
    width: 640
    height: 480
    visible: true
    title: qsTr("Thermostat")

    SystemController{
        id: systemController
    }

    // Załadowanie pliku z głównym ekranem
    Loader {
        id: mainLoader
        anchors.fill: parent
        source: "./UI/HomeScreen/HomeScreen.qml"
    }



}
