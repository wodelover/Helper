/*************************************************************************/
/*                          Copyright Notice                             */
/* The code can not be copied or provided to other people without the    */
/* permission of Zhang Hao,otherwise intellectual property infringement  */
/* will be prosecuted.If you have any questions,please send me an email. */
/* My email is kingderzhang@foxmail.com. The final interpretation rights */
/* are interpreted by ZhangHao.                                          */
/*                  Copyright (C) ZhangHao All rights reserved           */
/*************************************************************************/

import QtQuick 2.10
import QtQuick.Controls 2.3
import QtQuick.Controls.Material 2.2
/**
 * @ClassName: MessageBox
 * @Description: 消息提示框
 * @Autor: zhanghao kinderzhang@foxmail.com
 * @date: 2018-11-14 14:11:19
 * @Version: 1.0.0
 * @update_autor
 * @update_time
**/

Item {

    function openBox(){
        popup.open()
    }

    function closeBox(){
        popup.close()
    }

    Popup { //消息弹窗
        id: popup
        x: parent.width * 0.2
        y: parent.height * 0.2
        width: parent.width * 0.6
        height: parent.height * 0.6
        modal: true
        focus: true
        closePolicy: Popup.CloseOnEscape | Popup.CloseOnPressOutside
    }
}



