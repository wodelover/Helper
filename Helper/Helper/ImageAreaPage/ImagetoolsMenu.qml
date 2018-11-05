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
    property int buttonWidth: 0//40 按钮的宽度
    property int buttonHeight: 0//40 按钮的高度
    property int fontSize: 10 //40按钮字体大小
    Row{
        id: toolRow
        x: -parent.width - buttonWidth * 4
        layoutDirection: Qt.RightToLeft
        Button{//暂停按钮
            width: buttonWidth
            height: buttonHeight
            flat: true // 隐藏外边框
            text: "\uf04b"
            font.family: "FontAwesome"
            highlighted: true
            font.pointSize: fontSize
            opacity: 0.5
            property bool selected: true
            onClicked: {
                console.log("Play/Pause")
                if(selected){
                    opacity = 1
                    selected =!selected
                }else{
                    opacity = 0.5
                    selected =!selected
                }
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

        Item{//美颜区域
            width: buttonWidth
            height: buttonHeight
            MouseArea{
                id: mainMouseArea
                width: buttonWidth
                height: buttonHeight
                hoverEnabled: true
                property bool enter: false
                onEntered: {
                    enter = true
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
                width: beautySlider.width
                height: beautySlider.height
                hoverEnabled: true
                onExited: {
                    beautySlider.visible = false
                    mainMouseArea.enter = false
                }
                onEntered: {
                    if(mainMouseArea.enter){
                        beautySlider.visible = true
                    }
                }
                Slider{
                    id: beautySlider
                    anchors.fill: parent
                    from: 0
                    to: 100
                    visible: false
                    onValueChanged: console.log("beauty:"+value)
                }
            }
        }

        Button{//亮度按钮
            width: buttonWidth
            height: buttonHeight
            flat: true // 隐藏外边框
            text: "\uf185"
            font.family: "FontAwesome"
            highlighted: true
            opacity: 0.5
            font.pointSize: fontSize
            property bool selected: true
            onClicked: {
                if(selected){
                    opacity = 1
                    selected =!selected
                }else{
                    opacity = 0.5
                    selected =!selected
                }
            }
        }
    }

}
