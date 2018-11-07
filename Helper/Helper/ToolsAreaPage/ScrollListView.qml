/*************************************************************************/
/*                          Copyright Notice                             */
/* The code can not be copied or provided to other people without the    */
/* permission of Zhang Hao,otherwise intellectual property infringement  */
/* will be prosecuted.If you have any questions,please send me an email. */
/* My email is kingderzhang@foxmail.com. The final interpretation rights */
/* are interpreted by ZhangHao.                                          */
/*                  Copyright (C) ZhangHao All rights reserved           */
/*************************************************************************/

import QtQuick 2.0
import QtQuick.Controls 1.4

/**
 * @ClassName: ScrollListView
 * @Description: 滚动列表
 * @Autor: zhanghao kinderzhang@foxmail.com
 * @date: 2018-11-07 11:00:01
 * @Version: 1.0.0
 * @update_autor
 * @update_time
**/
Item {
    property var scrollDelegate: [] //单个模型控件
    property var scrollModel: [] //模型数据

    ScrollView{
        anchors.fill: parent
        verticalScrollBarPolicy: Qt.ScrollBarAlwaysOff //禁止垂直滚动条
        ListView{
            anchors.fill: parent
            delegate: scrollDelegate
            model: scrollModel
        }
    }
}
