import QtQuick 2.10
import QtQuick.Controls 2.3
import "./ImageAreaPage"
import "./MessageAreaPage"
import "./ToolsAreaPage"

ApplicationWindow {
    visible: true
    width: 640
    height: 480
    title: qsTr("Helper")

    SwipeView {
        id: swipeView
        anchors.fill: parent
        currentIndex: tabBar.currentIndex

        MessageAreaPage{}
        ImageAreaPage{}
        ToolsAreaPage{}
    }

    footer: TabBar {
        id: tabBar
        currentIndex: swipeView.currentIndex

        TabButton {
            font.family:  "FontAwesome"
            text: "\uf0e5"
            font.pointSize: 26
        }
        TabButton {
            font.family:  "FontAwesome"
            font.pointSize: 26
            text: "\uf083"
        }
        TabButton {
            font.family:  "FontAwesome"
            font.pointSize: 26
            text: "\uf0b1"
        }
    }
}
