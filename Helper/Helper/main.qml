import QtQuick 2.10
import QtQuick.Controls 2.3
import "./ImageAreaPage"
import "./MessageAreaPage"
import "./ToolsAreaPage"
import QtQuick.Controls.Material 2.2

ApplicationWindow {
    id: mainWindow
    visible: true
    width: 640
    height: 480
    flags: Qt.FramelessWindowHint | Qt.Window

    // 定义本模式下默认字体
    property string defaultFontFamily: "华文行楷" //默认字体
    property string defaultIconFamily: "FontAwesome" //默认图标库
    property int defaultFontSize: 16 // 默认字体大小
    property int buttonWidth: 45 //定义标题栏菜单按钮宽度
    property int tittleMenuHeight: 30//定义菜单栏高度
    property int mainWindowX : 0 //用来存储主窗口x坐标
    property int mainWindowY : 0 //存储窗口y坐标
    property int xMouse : 0 //存储鼠标x坐标
    property int yMouse : 0 //存储鼠标y坐标

    Rectangle{
        y: head.height
        width: parent.width
        height: parent.height - head.height
        color: Qt.rgba(0.16,0.16,0.16,1)
        SwipeView {
            id: swipeView
            anchors.fill: parent
            currentIndex: 2//tabBar.currentIndex
            MessageAreaPage{
                itemWidth: mainWindow.width
                itemHeight: 50
            }
            ImageAreaPage{}
            ToolsAreaPage{}
        }
    }

    Pane{
        width: parent.width
        height: tittleMenuHeight
        padding: 0
        Material.elevation: 20
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

        Rectangle {//重写标题栏
            id: head
            color: "dimgray"
            width: parent.width
            height: tittleMenuHeight
            Image { //系统图标
                id: proIcon
                x: tittleMenuHeight * 0.1
                y: tittleMenuHeight * 0.1
                width: tittleMenuHeight * 0.8
                height: tittleMenuHeight * 0.8
                source: "/Image/logo.png"
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
                        width: buttonWidth + 10
                        height: tittleMenuHeight + 10
                        font.family: defaultFontFamily
                        font.pointSize: 14
                    }
                    Button{ //图像
                        flat: true // 隐藏外边框
                        text: qsTr("图像")
                        width: buttonWidth + 10
                        height: tittleMenuHeight + 10
                        font.family: defaultFontFamily
                        font.pointSize: 14
                    }
                    Button{ //设置
                        flat: true // 隐藏外边框
                        text: qsTr("设置")
                        width: buttonWidth + 10
                        height: tittleMenuHeight + 10
                        font.family: defaultFontFamily
                        font.pointSize: 14
                    }
                    Button{ //帮助
                        flat: true // 隐藏外边框
                        text: qsTr("帮助")
                        width: buttonWidth + 10
                        height: tittleMenuHeight + 10
                        font.family: defaultFontFamily
                        font.pointSize: 14
                    }
                }
            }

            Button{ // 最小化
                id: miniButton
                y:parent.y - 10
                x:parent.width-width * 2 - 18
                width: 25
                height: 35
                font.family: defaultIconFamily
                text: "\uf068"
                onClicked: mainWindow.showMinimized()
            }
            Button{// 关闭
                id: closeButton
                y:parent.y - 10
                x:parent.width-width - 2
                width: 40
                height: 35
                font.family: defaultIconFamily
                text: "\uf00d"
                onClicked: Qt.quit()
            }
        }

    }

    footer: TabBar {
        id: tabBar
        currentIndex: swipeView.currentIndex

        TabButton {
            font.family:  defaultIconFamily
            text: "\uf0e5"
            font.pointSize: 26
        }
        TabButton {
            font.family:  defaultIconFamily
            font.pointSize: 26
            text: "\uf083"
        }
        TabButton {
            font.family:  defaultIconFamily
            font.pointSize: 26
            text: "\uf0b1"
        }
    }
}
