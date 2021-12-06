import QtQuick 2.0

Rectangle {

    property string dayOfWeek: " "
    property string tempMin: "--.- ℃"
    property string tempMax: "--.- ℃"
    property bool lineVisible: true
    property real scaleFactor: 1.0

    color: "transparent"

    function setIcon(value){
        imgWeather.source = "qrc:/images/" + value + ".png"
    }



    Text {
        id: txtDayOfWeek
        anchors.horizontalCenter: parent.horizontalCenter
        anchors.bottom: imgWeather.top
        anchors.bottomMargin: 10
        color: "#FA9727"
        font.bold: true
        font.pointSize: 15
        //font.family: fontOpenSans.name
        text: dayOfWeek

    }
    Image {
        id: imgWeather
        anchors.centerIn: parent
        source: "qrc:/Img/01-s.png"
        scale: scaleFactor

    }


    Rectangle {
        id: recTemperatures
        width: parent.width
        height: 25
        anchors.horizontalCenter: parent.horizontalCenter
        anchors.top:imgWeather.bottom
        anchors.topMargin: 10 * scaleFactor
        color: "transparent"

        Text {
            id: txtTempMin
            anchors.verticalCenter: parent.verticalCenter
            anchors.right: parent.horizontalCenter
            anchors.rightMargin: 25
            color: "#3ecdfd"
            font.bold: true
            font.pointSize: 13
            //font.family: fontOpenSans.name
            text: tempMin
        }
        Text {
            id: txtTempMax
            anchors.verticalCenter: parent.verticalCenter
            anchors.left: parent.horizontalCenter
            anchors.leftMargin: 15
            color: "#fb5255"
            font.bold: true
            font.pointSize: 13
            //font.family: fontOpenSans.name
            text: tempMax
        }
    }
    Rectangle {
        id: verticalLine
        width: 1
        height: parent.height - 30
        anchors.verticalCenter: parent.verticalCenter
        anchors.right: parent.right
        border.width: 1
        border.color: "white"
        visible: lineVisible
    }


}
