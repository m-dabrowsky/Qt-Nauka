import QtQuick 2.0
import QtQuick.Controls 2.12
BaseSheet {
    id: root


    Column {
        anchors.horizontalCenter: parent.horizontalCenter
        anchors.top: mySwitchButton.bottom
        anchors.topMargin: 30
        spacing: 30


        RadioButton {
            id: myRadioButton
            text: "Radio Button" 
        }

        Switch {
            id: mySwitchButton
            text: "Switch Button"
            onCheckedChanged: {
                if(checked){
                    console.log("switch button on");
                } else {
                    console.log("switch box unchecked");
                }
            }
        }

        Button {
            id: myButton
            text: "Click Me!"
        }

        ToolButton{
            width: 180
            //icon.source: Style.image("onoff")
            text: "tool button"
        }

        Slider {

        }

        Label {
           text: "I am a label"
        }

        BusyIndicator {

        }

        Dial {

        }

    }

}
