import QtQuick 2.6
import QtQuick.Controls 2.0
import io.qt.examples.backend 1.0
ApplicationWindow {
    id: window
    width: 300
    height: 480
    visible: true

    BackEnd {
        id: backend
    }

    TextField {
        text: backend.userName
        placeholderText: qsTr("User name")
        anchors.centerIn: parent

        onTextChanged: backend.userName = text
    }


    Drawer{
        id:drawer
        width:window.width/2
        height:window.height
        Label{
            text: "Conents"
            anchors.centerIn: parent
        }
            }

    }

//    Label{
//        id:content
//        text:"HEllo"
//        font.pixelSize: 96
//        anchors.fill: parent
//        verticalAlignment: Label.AlignVCenter
//        horizontalAlignment: Label.AlignHCenter
//        transform: Translate{
//        x:drawer.position*content.width*0.33
//    }
//    }

//    NavigationDrawer {
//        id: drawer
//        anchors.top: navigationBar.bottom
//        anchors.bottom: parent.bottom

//        position: Qt.LeftEdge
//        visualParent: stackView
//}


