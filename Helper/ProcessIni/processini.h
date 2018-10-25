/**************************************************************************************************************/
/*                                             Copyright Notice                                               */
/* The code can not be copied or provided to other people without the      */
/* permission of Zhang Hao,otherwise intellectual property infringement  */
/* will be prosecuted.If you have any questions,please send me an email.   */
/* My email is kingderzhang@foxmail.com. The final interpretation rights */
/* are interpreted by ZhangHao.                                                                     */
/*                  Copyright (C) ZhangHao All rights reserved                              */
/***************************************************************************************************************/

#ifndef PROCESSINI_H
#define PROCESSINI_H

#include "processini_global.h"
#include <QSettings>
#include <QVariant>
#include <QByteArray>
#include <QCryptographicHash>

/**
 * @ClassName: ProcessIni
 * @Description: 系统配置信息保存
 * @Autor: zhanghao kinderzhang@foxmail.com
 * @date: 2018-09-25 16:48:00
 * @Version: 1.0.0
 * @update_autor
 * @update_time
**/
class PROCESSINISHARED_EXPORT ProcessIni
{
public:
    enum EncryptionType{
        Md4,
        Md5,
        Sha1,
        Sha256,
        Sha512,
        Sha3_256,
        Sha3_512,
        Keccak_256,
        Keccak_512,
    };
    ProcessIni();
    ~ProcessIni();
    /**
     * @MethodName: writeIni
     * @ClassName: ProcessIni
     * @Description: 写入配置信息
     * @Autor: ZhangHao kinderzhang@foxmail.com
     * @date: 2018-09-25 17:03:17
     * @Version: 1.0.0
     * @update_autor
     * @update_time
     * @Parma: [QString] content 结构树名称
     * @Parma: [QString] key 键名
     * @Parma: [QVariant] data 键值
     * @Return: [bool] 写入状态
    **/
    Q_INVOKABLE bool writeIni(QString content,QString key,QVariant data);

    /**
     * @MethodName: readIni
     * @ClassName: ProcessIni
     * @Description: 读取配置项信息
     * @Autor: ZhangHao kinderzhang@foxmail.com
     * @date: 2018-09-25 17:03:26
     * @Version: 1.0.0
     * @update_autor
     * @update_time
     * @Parma: [QString] content 结构树名称
     * @Parma: [QString] key 键名
     * @Return: [QVariant] 键值
    **/
    Q_INVOKABLE QVariant readIni(QString content,QString key);

    /**
     * @MethodName: getIniFilePath
     * @ClassName: ProcessIni
     * @Description: 返回配置文件路径
     * @Autor: ZhangHao kinderzhang@foxmail.com
     * @date: 2018-09-25 17:03:36
     * @Version: 1.0.0
     * @update_autor
     * @update_time
     * @Return: [QString] 配置文件路径
    **/
    Q_INVOKABLE QString getIniFilePath();

    /**
     * @MethodName: setIniFilePath
     * @ClassName: ProcessIni
     * @Description: 设置配置文件的路径
     * @Autor: ZhangHao kinderzhang@foxmail.com
     * @date: 2018-10-25 13:23:58
     * @Version: 1.0.0
     * @update_autor
     * @update_time
     * @Parma: [QString] path 配置文件路径
     * @Return: [void]
    **/
    Q_INVOKABLE void setIniFilePath(QString path);

    /**
     * @Title: encryptionData
     * @Class: ProcessIni
     * @Description: 对输入的数据进行加密
     * @author ZhangHao kinderzhang@foxmail.com
     * @date 2018-10-22 21:06:39
     * @update_author
     * @update_time
     * @version V1.0
     * @param [QByteArray] data 需要加密的数据
     * @param [EncryptionType] type 加密方式
     * @return [QString] 加密后的文本
    */
    Q_INVOKABLE QString encryptionData(const QByteArray &data,EncryptionType type);

    /**
     * @Title: encryptionData
     * @Class: ProcessIni
     * @Description: 对输入的数据进行加密
     * @author ZhangHao kinderzhang@foxmail.com
     * @date 2018-10-22 21:06:39
     * @update_author
     * @update_time
     * @version V1.0
     * @param [QString] data 需要加密的数据
     * @param [EncryptionType] type 加密方式
     * @return [QString] 加密后的文本
    */
    Q_INVOKABLE QString encryptionData(const QString &data,EncryptionType type);
private:
    QString m_IniFilePath = "./config.ini";

};

#endif // PROCESSINI_H
