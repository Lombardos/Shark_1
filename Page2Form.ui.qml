import QtQuick 2.12
import QtQuick.Controls 2.5

import CA.singleton.DebugLogger 1.0

Page {
    width: 600
    height: 400

    header: Label {
        text: qsTr("Page 2")
        font.pixelSize: Qt.application.font.pixelSize * 2
        padding: 10
    }

    ScrollView {
        id: logScrollView
        implicitWidth: Common.winWidth/(1405/1355) //1355
        implicitHeight: Common.winHeight/(1020/920) //920
        TextArea {
            text: DebugLogger.logText
            font.pixelSize: Common.winHeight/(1020/16) //16
            background: Rectangle {
                implicitWidth: Common.winWidth/(1405/1305) //1305
                implicitHeight: Common.winHeight/(1020/880) //880
                radius: 2
                color: "white"
            }
        }
    }

   /* Label {
        text: qsTr("You are on Page 2.")
        anchors.centerIn: parent
    }*/
}
