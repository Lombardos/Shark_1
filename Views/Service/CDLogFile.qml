import QtQuick 2.8
import QtQuick.Dialogs 1.0
import QtQuick.Controls 1.4
import QtQuick.Controls 2.1
import QtQuick.Controls.impl 2.1
import QtQuick.Layouts 1.0
import CA.singleton.CrackDet 1.0
import CA.singleton.DebugLogger 1.0
import CA.singleton.Common 1.0
import "../../Controls" as CA_Controls

Frame {
    anchors.centerIn: parent
    spacing: 0

    background: Rectangle {
        border.width: 0
        color: "seagreen"
    }

    ColumnLayout {
        spacing: Common.winHeight/(1020/25)

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

        RowLayout {
            spacing: Common.winWidth/(1405/500)

            RowLayout {
                spacing: Common.winWidth/(1405/50)

                CA_Controls.Button {
                    id: clearLogBtn
                    width: 100*Common.winWidth/922 /*180*/; height: 100*Common.winHeight/2125 //48
                    text: qsTr("Clear Log")
                    font.pixelSize: Common.winHeight/57 //18

                    background: Rectangle {
                        implicitWidth: 100*Common.winWidth/922 //180
                        implicitHeight: 100*Common.winHeight/2125 //48
                        visible: !clearLogBtn.flat || clearLogBtn.down || clearLogBtn.checked || clearLogBtn.highlighted
                        radius: 0
                        color: clearLogBtn.down ? "lightgray" : "gray"
                        border.color: Default.focusColor
                        border.width: clearLogBtn.visualFocus ? 2 : 0
                    }

                    onClicked: {
                        DebugLogger.clearLog();
                    }
                }

                CA_Controls.Button {
                    id: readStatBtn
                    width: 100*Common.winWidth/922 /*180*/; height: 100*Common.winHeight/2125 //48
                    text: qsTr("Read Stat")
                    font.pixelSize: Common.winHeight/57 //18

                    background: Rectangle {
                        implicitWidth: 100*Common.winWidth/922 //180
                        implicitHeight: 100*Common.winHeight/2125 //48
                        visible: !readStatBtn.flat || readStatBtn.down || readStatBtn.checked || readStatBtn.highlighted
                        radius: 0
                        color: readStatBtn.down ? "lightgray" : "gray"
                        border.color: Default.focusColor
                        border.width: readStatBtn.visualFocus ? 2 : 0
                    }

                    onClicked: {
                        CrackDet.readStat();
                    }
                }
            }

            RowLayout {
                spacing: Common.winWidth/(1405/20)

                CA_Controls.Label {
                    Layout.alignment: Qt.AlignHCenter
                    color: "yellow"
                    font.pixelSize: 100*Common.winHeight/3643 //28
                    text: qsTr("Application version:")
                }

                CA_Controls.Label {
                    id: appVersion
                    Layout.alignment: Qt.AlignHCenter
                    color: "blue"
                    font.pixelSize: 100*Common.winHeight/3643 //28
                    text: "v" + Common.appVersion
                }
            }
        }
    }
}
