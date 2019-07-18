import QtQuick 2.12
import QtQuick.Controls 2.5



ApplicationWindow {
    visible: true
    width: 640
    height: 480
    title: qsTr("Tabs of Robin")

    SwipeView {
        id: swipeView
        anchors.fill: parent
        currentIndex: tabBar.currentIndex

        Page1Form {
        }

        Page2Form {
               }
        }

    footer: TabBar {
        id: tabBar
        currentIndex: swipeView.currentIndex

        TabButton {
            text: qsTr("Page 1 for Button")
        }
        TabButton {
            text: qsTr("Page 2 for Log")
        }
    }
}
