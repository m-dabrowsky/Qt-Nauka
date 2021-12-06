import QtQuick 2.15
import QtQuick.Window 2.15
import QtQuick.Controls 2.15
import Mike 1.0

Window {
    width: 800
    height: 480
    visible: true
    title: qsTr("Hello World")

    ApiRest{
        id: appBridge
    }

    Timer {
        interval: 100 // 1 sekunda
        running: true
        repeat: true
        onTriggered: {
            time.text = Qt.formatDateTime(new Date(), "hh:mm:ss")
            date.text = Qt.formatDateTime(new Date(), "dddd dd MMMM")
        }
    }




    Rectangle{
        id: recDataTime
        width: parent.width
        height: parent.height
        anchors.horizontalCenter: parent.horizontalCenter
        anchors.top:parent.top
        color: "#233343"

        //Time
        Rectangle {
            id: rectTime
            width: parent.width
            height: 100
            anchors.horizontalCenter: parent.horizontalCenter
            anchors.top:parent.top
            anchors.topMargin: 25
            color: "transparent"

            Text {
                id: time
                text: "10:25"
                anchors.centerIn: parent
                color: "white"
                font.pointSize: 80
            }
        }
        Rectangle {
            id:rectDate
            anchors.horizontalCenter: parent.horizontalCenter
            anchors.top: rectTime.bottom
            width: parent.width
            height: 60
            color: "transparent"

            Text {
                id: date
                text: "Marzec 25 2021"
                anchors.verticalCenterOffset: 0
                anchors.horizontalCenterOffset: 1
                anchors.centerIn: parent
                color: "white"
                font.pointSize: 25

            }
        }
    // Today Weather
        ItemWeather {
            id: weather0
            y: 185
            height: 130
            width: 150
            anchors.horizontalCenterOffset: 0
            anchors.horizontalCenter: parent.horizontalCenter
            scaleFactor: 1.0
            lineVisible: false
        }
    // Weather from tomorrow
        Rectangle {
            id: rectangle

            anchors.horizontalCenter: parent.horizontalCenter
            anchors.bottom: parent.bottom
            width: parent.width + 0.9
            height: 150
            color: "transparent"
            Rectangle {
                id: horizontalLine
                anchors.horizontalCenter: parent.horizontalCenter
                anchors.top: parent.top
                width: parent.width
                height: 1
                border.width: 1
                border.color: "white"
            }

            ItemWeather {
                id: weather1
                y: 8
                height: 130
                anchors.verticalCenter: parent.verticalCenter
                anchors.left: parent.left
                anchors.verticalCenterOffset: 0
                anchors.leftMargin: 13
                width: 150

                dayOfWeek: "Monday"
                lineVisible: false
            }
            ItemWeather {
                id: weather2
                height: 130
                width: 150
                anchors.left: weather1.right
                anchors.verticalCenterOffset: 0
                anchors.leftMargin: 59
                anchors.verticalCenter: parent.verticalCenter
                dayOfWeek: "Tuesday"
                lineVisible: false
            }
            ItemWeather {
                id: weather3
                height: 130
                width: 150
                anchors.left: weather2.right
                anchors.verticalCenterOffset: 0
                anchors.leftMargin: 59
                anchors.verticalCenter: parent.verticalCenter
                dayOfWeek: "Wednesday"
                lineVisible: false
            }
            ItemWeather {
                id: weather4
                height: 130
                anchors.left: weather3.right
                anchors.right: parent.right
                anchors.rightMargin: 13
                anchors.verticalCenterOffset: 0
                anchors.leftMargin: 59
                anchors.verticalCenter: parent.verticalCenter
                dayOfWeek: "Thursday"
                lineVisible: false
            }
        }

    }

    // Create invisible Button to try http request
    Rectangle {
        id: btnRequest

        anchors.top: parent.top
        anchors.right: parent.right
        width: 120
        height: 50
        color: "transparent"

        MouseArea{
            anchors.fill: parent
            onClicked: {

            appBridge.restApiRequest();
            }

            Label {
                id: label
                x: 25
                y: 19
                width: 87
                height: 23
                color: "#e5e8ea"
                text: qsTr("CLICK ME")
                styleColor: "#f7f6f6"
            }
        }
    }

    Connections {
       target: appBridge
       function onDataChanged() {
           weather0.setIcon(appBr.JsonData.DailyForecasts[0].Day.Icon)
           weather0.tempMin = appBridge.JsonData.DailyForecasts[0].Temperature.Minimum.Value + " ℃"
           weather0.tempMax = appBridge.JsonData.DailyForecasts[0].Temperature.Maximum.Value + " ℃"

           // 1
           var date = new Date(appBridge.JsonData.DailyForecasts[1].EpochDate + 1000);
           weather1.dayOfWeek = Qt.formatDateTime(date, "dddd")
           weather1.setIcon(appBridge.JsonData.DailyForecasts[1].Day.Icon)
           weather1.tempMin = appBridge.JsonData.DailyForecasts[1].Temperature.Minimum.Value + " ℃"
           weather1.tempMax = appBridge.JsonData.DailyForecasts[1].Temperature.Maximum.Value + " ℃"

           // 2
           var date1 = new Date(appBridge.JsonData.DailyForecasts[2].EpochDate + 1000);
           weather2.dayOfWeek = Qt.formatDateTime(date1, "dddd")
           weather2.setIcon(appBridge.JsonData.DailyForecasts[2].Day.Icon)
           weather2.tempMin = appBridge.JsonData.DailyForecasts[2].Temperature.Minimum.Value + " ℃"
           weather2.tempMax = appBridge.JsonData.DailyForecasts[2].Temperature.Maximum.Value + " ℃"

           // 3
           var date2 = new Date(appBridge.JsonData.DailyForecasts[3].EpochDate + 1000);
           weather3.dayOfWeek = Qt.formatDateTime(date2, "dddd")
           weather3.setIcon(appBridge.JsonData.DailyForecasts[3].Day.Icon)
           weather3.tempMin = appBridge.JsonData.DailyForecasts[3].Temperature.Minimum.Value + " ℃"
           weather3.tempMax = appBridge.JsonData.DailyForecasts[3].Temperature.Maximum.Value + " ℃"

           // 4
           var date3 = new Date(appBridge.JsonData.DailyForecasts[4].EpochDate + 1000);
           weather4.dayOfWeek = Qt.formatDateTime(date3, "dddd")
           weather4.setIcon(appBridge.JsonData.DailyForecasts[4].Day.Icon)
           weather4.tempMin = appBridge.JsonData.DailyForecasts[4].Temperature.Minimum.Value + " ℃"
           weather4.tempMax = appBridge.JsonData.DailyForecasts[4].Temperature.Maximum.Value + " ℃"

       }
    }
}
