/***************************************************************************************************************/
/*                                             Copyright Notice                                               */
/* The code can not be copied or provided to other people without the      */
/* permission of Zhang Hao,otherwise intellectual property infringement  */
/* will be prosecuted.If you have any questions,please send me an email.   */
/* My email is kingderzhang@foxmail.com. The final interpretation rights */
/* are interpreted by ZhangHao.                                                                     */
/*                  Copyright (C) ZhangHao All rights reserved                              */
/***************************************************************************************************************/

#ifndef HTTPCOM_H
#define HTTPCOM_H

#include "httpcom_global.h"
#include <QObject>
#include <QNetworkAccessManager>
#include <QNetworkRequest>
#include <QUrl>

class QByteArray;

/**
 * @Title: HttpCom
 * @FileName: HttpCom
 * @Description: 用于Http通信
 * @author ZhangHao kinderzhang@foxmail.com
 * @date 2018-10-22 21:39:33
 * @update_author
 * @update_time
 * @version V1.0
*/
class HTTPCOMSHARED_EXPORT HttpCom : public QObject
{
    Q_OBJECT
public:
    static HttpCom* getInstance();


    Q_INVOKABLE static QByteArray requestDataFromServer(QString url);

private:
    HttpCom();
    static HttpCom * instance;
    QNetworkAccessManager *m_manager;
    QNetworkRequest *m_request;

};

#endif // HTTPCOM_H
