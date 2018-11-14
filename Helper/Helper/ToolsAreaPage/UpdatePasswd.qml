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
 * @ClassName: UpdatePasswd
 * @Description: 更新用户密码
 * @Autor: zhanghao kinderzhang@foxmail.com
 * @date: 2018-11-07 13:52:00
 * @Version: 1.0.0
 * @update_autor
 * @update_time
**/
Item {

    Column{
        anchors.centerIn: parent
        spacing: 10
        Row{//old password
            spacing: 10
            padding: 10
            Button{
                flat: true
                width: 30
                height: 40
                font.family: defaultIconFamily
                text: "\uf13e"
                highlighted: true
                font.pointSize: defaultFontSize
                hoverEnabled: true
                ToolTip{
                    y: parent.height
                    visible: parent.hovered
                    text: qsTr("原密码")
                    font.family: defaultFontFamily
                    font.pointSize: defaultFontSize
                }
            }
            TextField{
                id: oldPassword
                placeholderText: qsTr("输入原密码")
                echoMode: TextInput.Password
                font.family: defaultFontFamily
                font.pointSize: defaultFontSize
            }
            Button{
                flat: true
                width: 30
                height: 40
                font.family: defaultIconFamily
                text: "\uf070"
                font.pointSize: defaultFontSize
                property bool selected: true
                onClicked: {
                    if(selected){
                        text = "\uf06e"
                        highlighted = true
                        oldPassword.echoMode = TextInput.Normal
                    }else{
                        text = "\uf070"
                        highlighted = false
                        oldPassword.echoMode = TextInput.Password
                    }
                    selected = !selected
                }
            }
        }
        Row{//new password
            spacing: 10
            padding: 10
            Button{
                flat: true
                width: 30
                height: 40
                font.family: defaultIconFamily
                text: "\uf084"
                highlighted: true
                font.pointSize: defaultFontSize
                hoverEnabled: true
                ToolTip{
                    y: parent.height
                    visible: parent.hovered
                    text: qsTr("新密码")
                    font.family: defaultFontFamily
                    font.pointSize: defaultFontSize
                }
            }
            TextField{
                id: newPassword
                placeholderText: qsTr("新密码")
                echoMode: TextInput.Password
                font.family: defaultFontFamily
                font.pointSize: defaultFontSize
            }
            Button{
                flat: true
                width: 30
                height: 40
                font.family: defaultIconFamily
                text: "\uf070"
                font.pointSize: defaultFontSize
                property bool newselected: true
                onClicked: {
                    if(newselected){
                        text = "\uf06e"
                        highlighted = true
                        newPassword.echoMode = TextInput.Normal
                    }else{
                        text = "\uf070"
                        highlighted = false
                        newPassword.echoMode = TextInput.Password
                    }
                    newselected = !newselected
                }
            }
        }
        Row{//confirm password
            spacing: 10
            padding: 10
            Button{
                flat: true
                width: 30
                height: 40
                font.family: defaultIconFamily
                text: "\uf084"
                highlighted: true
                font.pointSize: defaultFontSize
                hoverEnabled: true
                ToolTip{
                    y: parent.height
                    visible: parent.hovered
                    text: qsTr("确认密码")
                    font.family: defaultFontFamily
                    font.pointSize: defaultFontSize
                }
            }
            TextField{
                placeholderText: qsTr("验证密码")
                echoMode: TextInput.Password
                font.family: defaultFontFamily
                font.pointSize: defaultFontSize
                onTextChanged: {
                    if(text === newPassword.text){
                        updateButton.visible = true
                    }else{
                        updateButton.visible = false
                    }
                }
            }
            Button{
                id: updateButton
                flat: true
                width: 30
                height: 40
                visible: false
                hoverEnabled: true
                Text {
                    anchors.centerIn: parent
                    visible: parent.visible
                    font.family: defaultIconFamily
                    font.pointSize: defaultFontSize
                    text: "\uf00c"
                    color: "springgreen"
                }
                ToolTip{
                    y: parent.height
                    visible: parent.hovered
                    text: qsTr("更新")
                    font.family: defaultFontFamily
                    font.pointSize: defaultFontSize
                }

                onClicked: {
                    // update password
                }
            }
        }
    }
}
