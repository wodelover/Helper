/***************************************************************************************************************/
/*                                             Copyright Notice                                               */
/* The code can not be copied or provided to other people without the      */
/* permission of Zhang Hao,otherwise intellectual property infringement  */
/* will be prosecuted.If you have any questions,please send me an email.   */
/* My email is kingderzhang@foxmail.com. The final interpretation rights */
/* are interpreted by ZhangHao.                                                                     */
/*                  Copyright (C) ZhangHao All rights reserved                              */
/***************************************************************************************************************/

import QtQuick 2.0
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
            settingText: qsTr("设备连接")
            childText: qsTr("蓝牙、WiFi、DLAN")
            readStatus: true
        }
        ListElement{
            settingText: qsTr("模式切换")
            childText: qsTr("经典、动感、传统")
            readStatus: true
        }
        ListElement{
            settingText: qsTr("显示调节")
            childText: qsTr("亮度、色调、环境")
            readStatus: false
        }
        ListElement{
            settingText: qsTr("语言切换")
            childText: qsTr("简体中文、English")
            readStatus: false
        }
        ListElement{
            settingText: qsTr("行车设置")
            childText: qsTr("超速提示、车门控制、时间")
            readStatus: false
        }
        ListElement{
            settingText: qsTr("系统信息")
            childText: qsTr("系统更新、系统版本")
            readStatus: false
        }
        ListElement{
            settingText: qsTr("设备连接")
            childText: qsTr("蓝牙、WiFi、DLAN")
            readStatus: false
        }
        ListElement{
            settingText: qsTr("模式切换")
            childText: qsTr("经典、动感、传统")
            readStatus: false
        }
        ListElement{
            settingText: qsTr("显示调节")
            childText: qsTr("亮度、色调、环境")
            readStatus: false
        }
        ListElement{
            settingText: qsTr("语言切换")
            childText: qsTr("简体中文、English")
            readStatus: false
        }
        ListElement{
            settingText: qsTr("行车设置")
            childText: qsTr("超速提示、车门控制、时间")
            readStatus: false
        }
        ListElement{
            settingText: qsTr("系统信息")
            childText: qsTr("系统更新、系统版本")
            readStatus: false
        }
    }
    Component{//单个子项组件
        id: settingDelegate
        Item{
            width: itemWidth
            height: itemHeight
            Text {//主设置项
                x: itemHeight * 0.1
                y: itemHeight * 0.01
                text: settingText
                color: "white"
                font.bold: true
                font.pointSize: itemHeight * 0.45
                font.family: defaultFontFamily
                verticalAlignment: Text.AlignVCenter
                horizontalAlignment: Text.AlignHCenter
            }
            Text {//子项显示信息
                x: itemHeight * 0.1
                y: itemHeight * 0.65
                text: childText
                color: "white"
                opacity: 0.7
                font.pointSize: itemHeight * 0.2
                font.family: defaultFontFamily
                verticalAlignment: Text.AlignVCenter
                horizontalAlignment: Text.AlignHCenter
            }
            Text {
                x: parent.width - width - 15
                y: (itemHeight - height) / 2
                width: itemHeight * 0.3
                height: itemHeight * 0.3
                font.pointSize: itemHeight * 0.3
                color: "red"
                text: "\uf0eb"
                visible: readStatus
                font.family: "FontAwesome"
                verticalAlignment: Text.AlignVCenter
                horizontalAlignment: Text.AlignHCenter
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
            opacity: 0.3
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
            focus: true
            highlightRangeMode: ListView.ApplyRange
        }
    }
}
