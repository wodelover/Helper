/*************************************************************************/
/*                          Copyright Notice                             */
/* The code can not be copied or provided to other people without the    */
/* permission of Zhang Hao,otherwise intellectual property infringement  */
/* will be prosecuted.If you have any questions,please send me an email. */
/* My email is kingderzhang@foxmail.com. The final interpretation rights */
/* are interpreted by ZhangHao.                                          */
/*                  Copyright (C) ZhangHao All rights reserved           */
/*************************************************************************/

import QtQuick 2.9
import QtQuick.Controls 2.4

/**
 * @ClassName: UpdateAuthenticationKey
 * @Description: 从服务器更新人脸识别Key
 * @Autor: zhanghao kinderzhang@foxmail.com
 * @date: 2018-11-07 13:53:54
 * @Version: 1.0.0
 * @update_autor
 * @update_time
**/
Item {
    property string authenticationKeyString: "K544A4ACD4D5C454A5D9812ASA"

    Row{
        anchors.verticalCenter: parent.verticalCenter
        anchors.horizontalCenter: parent.horizontalCenter
        spacing: 10
        Button{
            flat: true
            width: 30
            height: 40
            font.family: defaultIconFamily
            text: "\uf0ed"
            highlighted: true
            font.pointSize: defaultFontSize
            hoverEnabled: true
            ToolTip{
                y: parent.height
                visible: parent.hovered
                text: qsTr("认证秘钥")
                font.family: defaultFontFamily
                font.pointSize: defaultFontSize
            }
        }
        TextField{
            id: authenticationKey
            width: 300
            text: authenticationKeyString
            font.bold: true
            selectByMouse: true
            font.family: defaultFontFamily
            font.pointSize: defaultFontSize
            onTextChanged: {
                console.log("authenticationKey")
            }
        }
        Button{
            id: updateAuthenticationKeyButton
            flat: true
            width: 30
            height: 40
            Text {
                anchors.centerIn: parent
                font.family: defaultIconFamily
                text: "\uf021"
                font.pointSize: defaultFontSize
                color: "springgreen"
            }
            hoverEnabled: true
            ToolTip{
                y: parent.height
                visible: parent.hovered
                text: qsTr("检查更新")
                font.family: defaultFontFamily
                font.pointSize: defaultFontSize
            }
            onClicked: {
                console.log(authenticationKey.text)
                // to do update user key to server

            }
        }
    }
}
