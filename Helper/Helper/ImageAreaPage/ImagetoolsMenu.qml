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
    //property string defaultFontFamily: "田相岳圆楷体"
    property int buttonWidth: 0//40 按钮的宽度
    property int buttonHeight: 0//40 按钮的高度
    property int fontSize: 10 //40按钮字体大小
    Row{
        id: toolRow
        x: -parent.width - buttonWidth * 4
        layoutDirection: Qt.RightToLeft

        Item{//美颜区域
            width: buttonWidth
            height: buttonHeight
            MouseArea{
                id: mainMouseArea
                width: buttonWidth
                height: buttonHeight
                hoverEnabled: true
                property bool beautyEnter: false
                onEntered: {
                    beautyEnter = true
                    if(beautyButton.selected){
                        beautySlider.visible = true
                    }
                }
                onExited: {
                    beautySlider.visible = false
                }

                Button{//美颜按钮
                    id: beautyButton
                    width: buttonWidth
                    height: buttonHeight
                    flat: true // 隐藏外边框
                    text: "\uf2be"
                    font.family: "FontAwesome"
                    highlighted: true
                    opacity: 0.5
                    font.pointSize: fontSize
                    ToolTip{
                        visible: parent.hovered
                        text: qsTr("美美哒")
                        font.family: defaultFontFamily
                    }
                    property bool selected: false
                    onClicked: {
                        selected =!selected
                        if(selected){
                            opacity = 1
                            beautySlider.visible = true
                        }else{
                            opacity = 0.5
                            beautySlider.visible = false
                        }
                    }
                }
            }
            MouseArea{
                x: (-width + beautyButton.width)/2
                y: beautyButton.height
                width: 160
                height: 40
                hoverEnabled: true
                onExited: {
                    beautySlider.visible = false
                    mainMouseArea.beautyEnter = false
                }
                onEntered: {
                    if(mainMouseArea.beautyEnter&&beautyButton.selected){
                        beautySlider.visible = true
                    }
                }
                Slider{
                    id: beautySlider
                    anchors.fill: parent
                    from: 0
                    to: 100
                    visible: false
                    ToolTip {
                        id: beautyTooltip
                        parent: beautySlider.handle
                        visible: beautySlider.pressed
                        font.family: defaultFontFamily
                    }
                    onValueChanged:
                    {
                        if(value>99.5){
                            beautyTooltip.text = qsTr("已经最美了")
                        }
                        else{
                            beautyTooltip.text = value.toFixed(0)
                        }
                        console.log("beauty:"+value)
                    }
                }
            }
        }

        Button{//暂停按钮
            width: buttonWidth
            height: buttonHeight
            flat: true // 隐藏外边框
            text: "\uf04b"
            font.family: "FontAwesome"
            highlighted: true
            font.pointSize: fontSize
            opacity: 0.5
            ToolTip{
                id: tooltip
                visible: parent.hovered
                text:  qsTr("休息一会儿")
                font.family: defaultFontFamily
            }
            property bool selected: true
            onClicked: {
                console.log("Play/Pause")
                if(selected){
                    opacity = 1
                    tooltip.text = qsTr("休息一会")
                }else{
                    opacity = 0.5
                    tooltip.text = qsTr("继续工作")
                }
                selected =!selected
            }
        }

        Button{//截图按钮
            width: buttonWidth
            height: buttonHeight
            flat: true // 隐藏外边框
            text: "\uf03e"
            font.family: "FontAwesome"
            highlighted: true
            opacity: 0.5
            font.pointSize: fontSize
            ToolTip{
                visible: parent.hovered
                text: qsTr("纪念此刻")
                font.family: defaultFontFamily
            }
            property bool selected: true
            onClicked: {
                console.log("GrabImage")
                if(selected){
                    opacity = 1
                    selected =!selected
                }else{
                    opacity = 0.5
                    selected =!selected
                }
            }
        }

        Item{//亮度区域
            width: buttonWidth
            height: buttonHeight
            MouseArea{
                id: brightlessArea
                width: buttonWidth
                height: buttonHeight
                hoverEnabled: true
                property bool brightlessEnter: false
                onEntered: {
                    brightlessEnter = true
                    if(brightlessButton.selected){
                        brightlessSlider.visible = true
                    }
                }
                onExited: {
                    brightlessSlider.visible = false
                }

                Button{//美颜按钮
                    id: brightlessButton
                    width: buttonWidth
                    height: buttonHeight
                    flat: true // 隐藏外边框
                    text: "\uf185"
                    font.family: "FontAwesome"
                    highlighted: true
                    opacity: 0.5
                    font.pointSize: fontSize
                    ToolTip{
                        visible: parent.hovered
                        text: qsTr("美白")
                        font.family: defaultFontFamily
                    }
                    property bool selected: false
                    onClicked: {
                        selected =!selected
                        if(selected){
                            opacity = 1
                            brightlessSlider.visible = true
                        }else{
                            opacity = 0.5
                            brightlessSlider.visible = false
                        }
                    }
                }
            }
            MouseArea{
                x: (-width + brightlessButton.width)/2
                y: brightlessButton.height
                width: 160
                height: 40
                hoverEnabled: true
                onExited: {
                    brightlessSlider.visible = false
                    brightlessArea.brightlessEnter = false
                }
                onEntered: {
                    if(brightlessArea.brightlessEnter&&brightlessButton.selected){
                        brightlessSlider.visible = true
                    }
                }
                Slider{
                    id: brightlessSlider
                    anchors.fill: parent
                    from: 0
                    to: 100
                    visible: false
                    onValueChanged: {
                        if(value>99.5){
                            brightlessTooltip.text = qsTr("已经很白了")
                        }
                        else{
                            brightlessTooltip.text = value.toFixed(0)
                        }
                        console.log("brightless:"+value)
                    }

                    ToolTip {
                        id: brightlessTooltip
                        parent: brightlessSlider.handle
                        visible: brightlessSlider.pressed
                        font.family: defaultFontFamily
                    }
                }
            }
        }
    }
}
