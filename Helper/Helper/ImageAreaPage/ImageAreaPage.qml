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
import QtQuick.Controls 2.2

/**
 * @ClassName: ImageAreaPage
 * @Description: 图像显示区域
 * @Autor: zhanghao kinderzhang@foxmail.com
 * @date: 2018-10-30 18:48:56
 * @Version: 1.0.0
 * @update_autor
 * @update_time
**/
Item {

    // 图像辅助工具栏,最上层显示
    Button{
        property bool opened: false // 用于标记是否已经打开工具栏
        property var submenu: [] //存储工具栏
        id: tools
        x: parent.width - width - 10
        width: 50
        height: 60
        flat: true // 隐藏外边框
        opacity: 0.7
        highlighted: true
        text: "\uf055"
        font.family: defaultIconFamily
        font.pointSize: 40
        onClicked: {
            if(opened){
                //close submenu
                if(submenu.length)
                {
                    submenu.pop().destroy()
                    tools.opacity = 0.7
                    tools.text = "\uf055"
                    opened = !opened
                }
            }else{
                //open submenu
                var component = Qt.createComponent("./ImagetoolsMenu.qml")

                if(component.status === Component.Ready && !submenu.length){
                    var imageToolBar = component.createObject(tools)
                    imageToolBar.buttonWidth = tools.width
                    imageToolBar.buttonHeight = tools.height
                    imageToolBar.fontSize = tools.font.pointSize / 2
                    submenu.push(imageToolBar)
                    tools.text = "\uf056"
                    tools.opacity = 1
                    opened = !opened
                }
            }
        }
    }
}
