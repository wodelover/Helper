import QtQuick 2.10
import QtQuick.Controls 2.3
import "./ImageAreaPage"
import "./MessageAreaPage"
import "./ToolsAreaPage"

ApplicationWindow {
    id: mainWindow
    visible: true
    width: 640
    height: 480
    title: qsTr("Helper")
    flags:  Qt.FramelessWindowHint | Qt.Window

    // 定义本模式下默认字体
    property string defaultFontFamily: "STXIHEI"


    property int mainWindowX : 0 //用来存储主窗口x坐标
    property int mainWindowY : 0 //存储窗口y坐标
    property int xMouse : 0 //存储鼠标x坐标
    property int yMouse : 0 //存储鼠标y坐标

    MouseArea { //为窗口移动添加鼠标事件
        anchors.fill: head
        acceptedButtons: Qt.LeftButton //只处理鼠标左键
        property point clickPos: "0,0"
        onPressed: { //接收鼠标按下事件
            clickPos  = Qt.point(mouse.x,mouse.y)
        }
        onPositionChanged: { //鼠标按下后改变位置
            //鼠标偏移量
            var delta = Qt.point(mouse.x-clickPos.x, mouse.y-clickPos.y)
            //如果mainwindow继承自QWidget,用setPos
            mainWindow.setX(mainWindow.x+delta.x)
            mainWindow.setY(mainWindow.y+delta.y)
        }
    }


    SwipeView {
        id: swipeView
        y: head.height
        width: parent.width
        height: parent.height - head.height
        currentIndex: tabBar.currentIndex
        MessageAreaPage{
            itemWidth: mainWindow.width
            itemHeight: 40
        }
        ImageAreaPage{}
        ToolsAreaPage{}
    }

    Rectangle {//重写标题栏
        id: head
        color: "dimgray"
        width: parent.width
        height: 30
        Text {
            id: proIcon
            x: 2
            font.family: "FontAwesome"
            font.pointSize: 20
            color: "deepskyblue"
            text: "\uf015"
            verticalAlignment: Text.AlignHCenter
        }
        Text {
            x: proIcon.width + 4
            text: qsTr("Helper")
            color: "white"
            font.pointSize: 20
            verticalAlignment: Text.AlignHCenter
        }
        Button{
            y:parent.y - 10
            x:parent.width-width * 2 - 18
            width: 25
            height: 35
            font.family: "FontAwesome"
            text: "\uf068"
            onClicked: mainWindow.showMinimized()
        }
        Button{
            y:parent.y - 10
            x:parent.width-width - 2
            width: 40
            height: 35
            font.family: "FontAwesome"
            text: "\uf00d"
            onClicked: Qt.quit()
        }
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
