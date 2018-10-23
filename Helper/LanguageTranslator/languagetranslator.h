/*************************************************************************/
/*                          Copyright Notice                             */
/* This code is only for use by Hangzhou Aoteng Electronics Co., Ltd.The */
/* code can not be copied or provided to other people without the        */
/* permission of Zhang Hao,otherwise intellectual property infringement  */
/* will be prosecuted.If you have any questions,please send me an email. */
/* My email is kingderzhang@foxmail.com. Note: the release of this code  */
/* version is also controlled by Hangzhou Aoteng Electronics Co., Ltd.   */
/* The final interpretation rights are interpreted by ZhangHao.          */
/*                  Copyright (C) ZhangHao All rights reserved           */
/*************************************************************************/
#ifndef LANGUAGETRANSLATOR_H
#define LANGUAGETRANSLATOR_H

#include "languagetranslator_global.h"
#include <QObject>
#include <QTranslator>
#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QDir>

const QString packet_path = "/LanguagePacket/";

const QString zh_CN_path = "zh_CN.qm";
const QString zh_HK_path = "zh_HK.qm";
const QString en_US_path = "en_US.qm";
const QString ar_AE_path = "ar_AE.qm";
const QString ar_EG_path = "ar_EG.qm";
const QString be_BY_path = "be_BY.qm";
const QString da_DK_path = "da_DK.qm";
const QString de_AT_path = "de_AT.qm";
const QString de_DE_path = "de_DE.qm";
const QString es_ES_path = "es_ES.qm";
const QString fr_FR_path = "fr_FR.qm";
const QString it_IT_path = "it_IT.qm";
const QString ja_JA_path = "ja_JA.qm";
const QString th_TH_path = "th_TH.qm";
const QString uk_UA_path = "uk_UA.qm";

/**
 * @ClassName: LanguageTranslator
 * @Description: Qt多语言翻译
 * @Autor: zhanghao kinderzhang@foxmail.com
 * @date: 2018-09-26 13:03:10
 * @Version: 1.0.0
 * @update_autor
 * @update_time
**/
class LANGUAGETRANSLATORSHARED_EXPORT LanguageTranslator: public QObject
{
    Q_OBJECT
public:
    Q_ENUMS(LanguageType)
    enum LanguageType{
        ZH_CN,//中文(中国)
        ZH_HK,//中文(台湾)
        EN_US,//英文(美国)
        AR_AE,//阿拉伯文(阿拉伯联合酋长国)
        AR_EG,//阿拉伯文(埃及)
        BE_BY,//白俄罗斯文(白俄罗斯)
        DA_DK,//丹麦文(丹麦)
        DE_AT,//德文(奥地利)
        DE_DE,//德文(德国)
        ES_ES,//西班牙文(西班牙)
        FR_FR,//法文(法国)
        IT_IT,//意大利文(意大利)
        JA_JA,//日文(日本)
        TH_TH,//泰文(泰国)
        UK_UA //乌克兰文(乌克兰)
    };
    LanguageTranslator(QGuiApplication& app, QQmlApplicationEngine &engine);
    /**
     * @MethodName: setLanguage
     * @ClassName: LanguageTranslator
     * @Description: 设置系统语言
     * @Autor: ZhangHao kinderzhang@foxmail.com
     * @date: 2018-09-26 14:05:39
     * @Version: 1.0.0
     * @update_autor
     * @update_time
     * @Parma: [LanguageType] languageType 系统支持的语言枚举类型
     * @Return: [void]
    **/
    Q_INVOKABLE void setLanguage(LanguageTranslator::LanguageType languageType);

    /**
     * @MethodName: getAppPath
     * @ClassName: LanguageTranslator
     * @Description: 获取系统程序的运行路径
     * @Autor: ZhangHao kinderzhang@foxmail.com
     * @date: 2018-09-28 16:09:06
     * @Version: 1.0.0
     * @update_autor
     * @update_time
     * @Return: [QString] 程序当前的运行路径
    **/
    Q_INVOKABLE QString getAppPath()const;
private:
    QGuiApplication *m_app;
    QQmlApplicationEngine *m_engine;
    QString m_appPath;
};

#endif // LANGUAGETRANSLATOR_H
