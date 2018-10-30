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
 * @ClassName: ImagetoolsMenu
 * @Description: 图像工具栏折叠项目框
 * @Autor: zhanghao kinderzhang@foxmail.com
 * @date: 2018-10-30 19:02:26
 * @Version: 1.0.0
 * @update_autor
 * @update_time
**/
Item {
    // 下列属性需要外部设置
    property int buttonWidth: 0//50
    property int buttonHeight: 0//60
    property int buttonTextSize: 0//40

    x: -parent.width - 5

    Rectangle{
        width: buttonWidth
        height: buttonHeight
        color: "red"
    }

//    Pane{
//        Row{
//            spacing: 2
//            Button{//美颜

//            }
//        }
//    }

}
