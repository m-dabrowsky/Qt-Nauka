import QtQuick 2.0
import QtQuick.Templates 2.4 as t
import utils 1.0

t.Slider {
    id: root
    implicitHeight: 20
    implicitWidth: 170

    background: Rectangle {

        width: parent.width
        height: parent.height / 4
        anchors.verticalCenter: parent.verticalCenter
        radius: 20
        color: Style.inactiveColor
        Rectangle {
                width: (root.value * parent.width)
                height: parent.height
                color: Style.mainColor
                radius: 20
    }

   handle: Rectangle {
        property int calcDim: (root.height < 10) ? root.heigth : (root.height / 2)
        width: calcDim
        height: calcDim
        anchors.verticalCenter: parent.verticalCenter
        x: (root.value * (root.width - calcDim))
        radius: width /2
        color: Style.mainColor


   }


}
}
