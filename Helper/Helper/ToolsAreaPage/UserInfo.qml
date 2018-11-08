/*************************************************************************/
/*                          Copyright Notice                             */
/* The code can not be copied or provided to other people without the    */
/* permission of Zhang Hao,otherwise intellectual property infringement  */
/* will be prosecuted.If you have any questions,please send me an email. */
/* My email is kingderzhang@foxmail.com. The final interpretation rights */
/* are interpreted by ZhangHao.                                          */
/*                  Copyright (C) ZhangHao All rights reserved           */
/*************************************************************************/

/**************************************************/
/*             | 姓名：张三       | 性别：小哥哥  */
/*    头像     | 工号：123        | 状态：活力少年*/
/*             | 职位：XXX        |               */
/*             |                  |               */
/*-------------|------------------|---------------*/
/*             |                  |               */
/*  今日打卡   |   工作时长       |  月统计打卡   */
/*             |                  |               */
/*             |                  |               */
/**************************************************/

import QtQuick 2.9
import QtQuick.Controls 2.4
import QtQuick.Dialogs 1.2
import QtQuick.Controls.Material 2.2
/**
 * @ClassName: UserInfo
 * @Description: 用户个人信息页面
 * @Autor: zhanghao kinderzhang@foxmail.com
 * @date: 2018-11-07 13:51:03
 * @Version: 1.0.0
 * @update_autor
 * @update_time
**/
Item {

    //base infomation
    property string userName: "zhangsan"//user name
    property string userNum: "CBAZ1234" //user number
    property string userJob: "软件工程师" //user job
    property var userSex: ["小哥哥","小姐姐"] //user sex
    property var userBoyStatus: ["志学之年","弱冠之年","而立之年","不惑之年","知非之年","杖乡之年","从心之年","耄耋之年"] //user status
    property var userGirlStatus: ["豆蔻年华","及笄之年","碧玉年华","花信年华","年逾半百","年过花甲","从心之年","耄耋之年"] //user status

    //sign infomation


    Column{//列布局
        spacing: 5
        anchors.fill: parent
        Row{
            padding: 5
            width: parent.width
            height: parent.height / 2
            Item {//头像区域
                width: parent.width * 0.2
                height: parent.height
                Image {
                    id: photo
                    width: parent.width
                    height: parent.height
                    source: ""
                    MouseArea{
                        anchors.fill: photo
                        hoverEnabled: true
                        onEntered: {
                            photoButton.visible = true
                        }

                        onExited: {
                            photoButton.visible = false
                        }

                        Button{
                            id: photoButton
                            anchors.fill: parent
                            text: qsTr("上传美照")
                            icon.color: "transparent"//设置头像原图显示
                            icon.width: parent.width
                            icon.height: parent.height
                            font.family: defaultFontFamily
                            font.pointSize: defaultFontSize
                            onClicked: {
                                photoDialog.open()
                            }
                        }

                        FileDialog{
                            id: photoDialog
                            title: qsTr("选择你的美照");
                            nameFilters:"Image Files (*.jpg *.png *.bmp *.ico)"
                            onAccepted: {
                                photo.source = fileUrl
                            }
                            onRejected: {
                                photoButton.text = qsTr("上传美照")
                            }
                        }
                    }
                }
            }
            Item {//基本信息1
                width: parent.width * 0.4
                height: parent.height
                Column{
                    anchors.fill: parent
                    Row{// 名字区域
                        spacing: 10
                        padding: 10
                        Button{
                            flat: true
                            width: 30
                            height: 40
                            font.family: defaultIconFamily
                            text: "\uf007"
                            highlighted: true
                            font.pointSize: defaultFontSize
                            hoverEnabled: true
                            ToolTip{
                                y: parent.height
                                visible: parent.hovered
                                text: qsTr("我的名字")
                                font.family: defaultFontFamily
                                font.pointSize: defaultFontSize
                            }
                        }
                        TextField{
                            id: name
                            placeholderText: userName
                            font.bold: true
                            font.family: defaultFontFamily
                            font.pointSize: defaultFontSize
                            onTextChanged: {
                                updateNameButton.visible = true
                            }
                        }
                        Button{
                            id: updateNameButton
                            flat: true
                            width: 30
                            height: 40
                            font.family: defaultIconFamily
                            text: "\uf021"
                            highlighted: true
                            font.pointSize: defaultFontSize
                            hoverEnabled: true
                            visible: false
                            ToolTip{
                                y: parent.height
                                visible: parent.hovered
                                text: qsTr("确认更改")
                                font.family: defaultFontFamily
                                font.pointSize: defaultFontSize
                            }
                            onClicked: {
                                console.log(name.text)
                                // to do update user name to server
                                visible = false
                            }
                        }
                    }

                    Row{// 工号区域
                        spacing: 10
                        padding: 10
                        Button{
                            flat: true
                            width: 30
                            height: 40
                            font.family: defaultIconFamily
                            text: "\uf2c1"
                            highlighted: true
                            font.pointSize: defaultFontSize
                            hoverEnabled: true
                            ToolTip{
                                y: parent.height
                                visible: parent.hovered
                                text: qsTr("我的工号")
                                font.family: defaultFontFamily
                                font.pointSize: defaultFontSize
                            }
                        }
                        TextField{
                            text: userNum
                            readOnly: true
                            font.bold: true
                            hoverEnabled: true
                            font.family: defaultFontFamily
                            font.pointSize: defaultFontSize
                            ToolTip{
                                y: parent.height
                                visible: parent.hovered
                                text: qsTr("不可以修改")
                                font.family: defaultFontFamily
                                font.pointSize: defaultFontSize
                            }
                        }
                    }

                    Row{// 职位区域
                        spacing: 10
                        padding: 10
                        Button{
                            flat: true
                            width: 30
                            height: 40
                            font.family: defaultIconFamily
                            text: "\uf2ba"
                            highlighted: true
                            font.pointSize: defaultFontSize
                            hoverEnabled: true
                            ToolTip{
                                y: parent.height
                                visible: parent.hovered
                                text: qsTr("我的职位")
                                font.family: defaultFontFamily
                                font.pointSize: defaultFontSize
                            }
                        }
                        TextField{
                            text: userJob
                            readOnly: true
                            font.bold: true
                            hoverEnabled: true
                            font.family: defaultFontFamily
                            font.pointSize: defaultFontSize
                            ToolTip{
                                y: parent.height
                                visible: parent.hovered
                                text: qsTr("不可以修改")
                                font.family: defaultFontFamily
                                font.pointSize: defaultFontSize
                            }
                        }
                    }
                }
            }
            Item {//基本信息2
                width: parent.width * 0.4
                height: parent.height
                Column{
                    anchors.fill: parent
                    Row{// 性别区域
                        spacing: 10
                        padding: 10
                        Button{
                            id: sex
                            flat: true
                            width: 30
                            height: 40
                            font.family: defaultIconFamily
                            text: "\uf222"
                            highlighted: true
                            font.pointSize: defaultFontSize
                            hoverEnabled: true
                            ToolTip{
                                y: parent.height
                                visible: parent.hovered
                                text: qsTr("我的性别")
                                font.family: defaultFontFamily
                                font.pointSize: defaultFontSize
                            }
                        }
                        ComboBox{//性别选择
                            id: sexComboBox
                            model: userSex
                            flat: true
                            y: -5
                            font.family: defaultFontFamily
                            font.pointSize: defaultFontSize
                            onCurrentIndexChanged: {
                                if(!currentIndex){
                                    sex.text = "\uf222"
                                    ageComboBox.model = userBoyStatus
                                }else{
                                    sex.text = "\uf221"
                                    ageComboBox.model = userGirlStatus
                                }
                                console.log(sexComboBox.textAt(currentIndex))
                            }
                        }
                    }

                    Row{// 状态区域
                        spacing: 10
                        padding: 10
                        Button{// 年龄状态区域
                            flat: true
                            width: 30
                            height: 40
                            font.family: defaultIconFamily
                            text: "\uf263"
                            highlighted: true
                            font.pointSize: defaultFontSize
                            hoverEnabled: true
                            ToolTip{
                                y: parent.height
                                visible: parent.hovered
                                text: qsTr("我的年龄")
                                font.family: defaultFontFamily
                                font.pointSize: defaultFontSize
                            }
                        }
                        ComboBox{//年龄状态选择
                            id: ageComboBox
                            y: -5
                            width: 140
                            model: userBoyStatus
                            flat: true
                            font.family: defaultFontFamily
                            font.pointSize: defaultFontSize
                            onCurrentIndexChanged: {
                                if(!currentIndex){
                                    sex.text = "\uf222"
                                }else{
                                    sex.text = "\uf221"
                                }
                                console.log(ageComboBox.textAt(currentIndex))
                            }
                        }
                    }

                }
            }
        }
        Row{
            spacing: 5
            width: parent.width
            height: parent.height / 2
            Item {//当日打卡信息
                width: parent.width * 0.33
                height: parent.height
                Rectangle{
                    anchors.fill: parent
                    color: "white"
                }
            }
            Item {//本周打卡信息
                width: parent.width * 0.33
                height: parent.height
                Rectangle{
                    anchors.fill: parent
                    color: "red"
                }
            }
            Item {//当月打卡信息
                width: parent.width * 0.33
                height: parent.height
                Rectangle{
                    anchors.fill: parent
                    color: "green"
                }
            }
        }
    }
}
