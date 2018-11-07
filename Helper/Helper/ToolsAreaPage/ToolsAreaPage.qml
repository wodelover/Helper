/*************************************************************************/
/*                          Copyright Notice                             */
/* The code can not be copied or provided to other people without the    */
/* permission of Zhang Hao,otherwise intellectual property infringement  */
/* will be prosecuted.If you have any questions,please send me an email. */
/* My email is kingderzhang@foxmail.com. The final interpretation rights */
/* are interpreted by ZhangHao.                                          */
/*                  Copyright (C) ZhangHao All rights reserved           */
/*************************************************************************/

import QtQuick 2.7
import QtQuick.Controls 2.2
import QtQuick.Controls.Material 2.2
/**
 * @ClassName: ToolsAreaPage
 * @Description: 工具栏页面设置
 * @Autor: zhanghao kinderzhang@foxmail.com
 * @date: 2018-11-06 14:21:21
 * @Version: 1.0.0
 * @update_autor
 * @update_time
**/
Item {
    Item {
        id: rightToolArea
        width: 40
        height: parent.height
        Pane{
            width: parent.width
            height: parent.height
            padding: 0
            Material.elevation: 10
            Rectangle {
                color: "dimgray"
                opacity: 1
                anchors.fill: parent
                ScrollListView{
                    anchors.fill: parent
                    scrollDelegate: delegate
                    scrollModel: model
                }
            }
        }
    }
    ListModel{
        id: model
        ListElement{
            subText: "\uf2bc"
            toolTipText: qsTr("我的隐私")
        }
        ListElement{
            subText: "\uf11c"
            toolTipText: qsTr("修改密码")
        }
        ListElement{
            subText: "\uf084"
            toolTipText: qsTr("更新秘钥")
        }
        ListElement{
            subText: "\uf017"
            toolTipText: qsTr("时间管理")
        }
    }

    Component{
        id: delegate
        Item {
            id: delegateView
            width: rightToolArea.width
            height: rightToolArea.width
            Button{
                y: -5
                width: parent.width
                height: parent.width + 10
                text: subText
                flat: true
                font.family: "FontAwesome"
                font.pointSize: 16
                highlighted: true
                hoverEnabled: true
                ToolTip{
                    x: parent.width + 5
                    y: 10
                    visible: parent.hovered
                    text: toolTipText
                    font.family: defaultFontFamily
                }
            }
        }
    }

    Item {
        id: leftToolArea
        x: rightToolArea.width
        width: parent.width - rightToolArea.width
        height: parent.height
    }

}
