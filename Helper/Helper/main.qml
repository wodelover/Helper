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
    property int buttonWidth: 45 //定义标题栏菜单按钮宽度
    property int tittleMenuHeight: 30//定义菜单栏高度
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
        currentIndex: 1//tabBar.currentIndex
        MessageAreaPage{
            itemWidth: mainWindow.width
            itemHeight: 45
        }
        ImageAreaPage{}
        ToolsAreaPage{}
    }

    Rectangle {//重写标题栏
        id: head
        color: "dimgray"
        width: parent.width
        height: tittleMenuHeight
        Text { //系统图标
            id: proIcon
            x: 2
            y: 2
            font.family: "FontAwesome"
            font.pointSize: 20
            color: "deepskyblue"
            text: "\uf015"
            verticalAlignment: Text.AlignHCenter
        }

        Item{ //顶部菜单
            x: proIcon.width + 4
            width: parent.width - proIcon.width - miniButton.width - closeButton.width - 10
            height: tittleMenuHeight

            Row{
                y: -5
                spacing: 2
                Button{ //消息
                    flat: true // 隐藏外边框
                    text: qsTr("消息")
                    width: buttonWidth
                    height: tittleMenuHeight + 10
                    font.family: defaultFontFamily
                    font.pointSize: 10
                }
                Button{ //图像
                    flat: true // 隐藏外边框
                    text: qsTr("图像")
                    width: buttonWidth
                    height: tittleMenuHeight + 10
                    font.family: defaultFontFamily
                    font.pointSize: 10
                }
                Button{ //设置
                    flat: true // 隐藏外边框
                    text: qsTr("设置")
                    width: buttonWidth
                    height: tittleMenuHeight + 10
                    font.family: defaultFontFamily
                    font.pointSize: 10
                }
                Button{ //帮助
                    flat: true // 隐藏外边框
                    text: qsTr("帮助")
                    width: buttonWidth
                    height: tittleMenuHeight + 10
                    font.family: defaultFontFamily
                    font.pointSize: 10
                }
            }
        }

        Button{ // 最小化
            id: miniButton
            y:parent.y - 10
            x:parent.width-width * 2 - 18
            width: 25
            height: 35
            font.family: "FontAwesome"
            text: "\uf068"
            onClicked: mainWindow.showMinimized()
        }
        Button{// 关闭
            id: closeButton
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