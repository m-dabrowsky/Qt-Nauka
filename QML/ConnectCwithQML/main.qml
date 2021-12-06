import QtQuick 2.15
import QtQuick.Window 2.15
import QtQuick.Controls 2.15
import Mike 1.0

Window {
    width: 640
    height: 480
    visible: true
    title: "Hello World"

    SomeClass{
        id: myClass
    }

    Connections{
        target: myClass
        onSomeVarChanged: myLabel.text = myClass.getsomeVar();
    }


    Button {
        id: myButton
        anchors.centerIn: parent
        text: "Click me"
        onClicked: {
            // myClass.callMe()
            //myClass.anotherFunction()
            myClass.setSomeVar("ABC")
        }

    }

    Text {
        id: myLabel
        anchors {
            top: parent.top
            horizontalCenter: parent.horizontalCenter
            topMargin: 20
        }
        font.pixelSize: 24
        text: myClass.getsomeVar() // wymaga uzycia Connection
               //myClass.someVar
    }


}
