/***************************************************************************************************************/
/*                                             Copyright Notice                                               */
/* The code can not be copied or provided to other people without the      */
/* permission of Zhang Hao,otherwise intellectual property infringement  */
/* will be prosecuted.If you have any questions,please send me an email.   */
/* My email is kingderzhang@foxmail.com. The final interpretation rights */
/* are interpreted by ZhangHao.                                                                     */
/*                  Copyright (C) ZhangHao All rights reserved                              */
/***************************************************************************************************************/

import QtQuick 2.7
import QtQuick.Controls 2.2

/**
 * @Title: MessageAreaPage
 * @FileName: MessageAreaPage
 * @Description: 消息提示区域
 * @author ZhangHao kinderzhang@foxmail.com
 * @date 2018-10-28 21:02:39
 * @update_author
 * @update_time
 * @version V1.0
*/
Item {
    property int itemX: 0 //X位置
    property int itemY: 0 //Y位置
    property int itemWidth: 0 // 单独子项的宽度
    property int itemHeight: 0 // 单独子项的高度
    property int currentValue: 0 //当前选中项索引

    function nextItem(){ //下一项
        settingListView.decrementCurrentIndex()
    }

    function previousItem(){ //上一项
        settingListView.incrementCurrentIndex()
    }

    ListModel{//模型数据
        id: settingModel
        ListElement{
            settingText: qsTr("设备连接11111111111111111111111111111111122222222222222222222222223333333333R")
            childText: qsTr("蓝牙、WiFi、DLAN0000000000000000000000000000000000000000000000000000000000")
            timeText: "下午5:10"
        }
        ListElement{
            settingText: qsTr("模式切换")
            childText: qsTr("经典、动感、传统")
            timeText: "下午5:19"
        }
        ListElement{
            settingText: qsTr("显示调节")
            childText: qsTr("亮度、色调、环境")
            timeText: "中午12:01"
        }
        ListElement{
            settingText: qsTr("语言切换")
            childText: qsTr("简体中文、English")
            timeText: "早上8:18"
        }
        ListElement{
            settingText: qsTr("行车设置")
            childText: qsTr("超速提示、车门控制、时间")
            timeText: "下午6:19"
        }
        ListElement{
            settingText: qsTr("系统信息")
            childText: qsTr("系统更新、系统版本")
            timeText: "下午4:19"
        }
        ListElement{
            settingText: qsTr("设备连接")
            childText: qsTr("蓝牙、WiFi、DLAN")
            timeText: "下午2:19"
        }
        ListElement{
            settingText: qsTr("模式切换")
            childText: qsTr("经典、动感、传统")
            timeText: "昨天15:10"
        }
        ListElement{
            settingText: qsTr("显示调节")
            childText: qsTr("亮度、色调、环境")
            timeText: "昨天13:19"
        }
        ListElement{
            settingText: qsTr("语言切换")
            childText: qsTr("简体中文、English")
            timeText: "昨天5:19"
        }
        ListElement{
            settingText: qsTr("行车设置")
            childText: qsTr("超速提示、车门控制、时间")
            timeText: "星期五"
        }
        ListElement{
            settingText: qsTr("系统信息")
            childText: qsTr("系统更新、系统版本")
            timeText: "星期四"
        }
    }
    Component{//单个子项组件
        id: settingDelegate
        Item{
            id: delegateItem
            width: itemWidth
            height: itemHeight
            property bool isReaded: false // 数据绑定到每一项是否被点击阅读
            Text {//消息标题
                id: mainText
                x: itemHeight * 0.1
                y: itemHeight * 0.2
                width: itemWidth * 0.7
                height: itemHeight * 0.38
                text: settingText
                elide: Text.ElideRight
                smooth: true
                color: delegateItem.ListView.isCurrentItem ? "lightpink" : "white"
                font.bold: true
                font.pointSize: itemHeight * 0.38
                font.family: defaultFontFamily
                verticalAlignment: Text.AlignVCenter
                horizontalAlignment: Text.AlignLeft
            }
            Text {//消息预览内容
                x: itemHeight * 0.1
                y: itemHeight * 0.67
                width: itemWidth * 0.7
                text: childText
                color: delegateItem.ListView.isCurrentItem ? "lightpink" : "snow"
                smooth: true
                elide: Text.ElideRight
                font.pointSize: itemHeight * 0.2
                font.family: defaultFontFamily
                verticalAlignment: Text.AlignVCenter
                horizontalAlignment: Text.AlignLeft
            }
            Text {//消息时间显示
                x: itemWidth * 0.75
                y: itemHeight / 2
                width: itemWidth * 0.7
                text: timeText
                color: delegateItem.ListView.isCurrentItem ? "lightpink" : "snow"
                smooth: true
                font.pointSize: itemHeight * 0.25
                font.family: defaultFontFamily
                verticalAlignment: Text.AlignVCenter
                horizontalAlignment: Text.AlignLeft
            }
            MouseArea{ //单独一项鼠标处理事件
                anchors.fill: parent
                onDoubleClicked: {
                    console.log(index)
                }
                onClicked: {
                    delegateItem.ListView.view.currentIndex = index
                }
            }
            Button {//新信息提示指示区域
                x: parent.width - width - 15
                y: (itemHeight - height) / 2
                width: 25//itemHeight * 0.4
                height: 40//itemHeight * 0.4
                font.pointSize: itemHeight * 0.3
                smooth: true
                flat: true
                highlighted: true
                text: "\uf0eb"
                visible: !isReaded
                font.family: "FontAwesome"
                onClicked: {
                    isReaded = true
                    delegateItem.ListView.view.currentIndex = index
                }
            }

        }
    }

    Component{//高亮背景组件
        id: settingHightLight
        Rectangle {
            id: idBackGrdImg
            width: itemWidth
            height: itemHeight
            radius: 10
            color: "white"
            opacity: 0.1
        }
    }

    ScrollView {
        id: settingScrollView
        anchors.fill: parent
        //verticalScrollBarPolicy: Qt.ScrollBarAlwaysOff //禁止垂直滚动条

        ListView {
            id: settingListView
            anchors.fill: parent
            model: settingModel
            delegate: settingDelegate
            highlight: settingHightLight
            highlightFollowsCurrentItem: true
            highlightMoveDuration: 80 // 设置移动选中项的过渡时间
            highlightRangeMode: ListView.NoHighlightRange//设置内容自动滚动的方式
        }
    }

}
