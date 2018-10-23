/*************************************************************************/
/*                          Copyright Notice                             */
/* The code can not be copied or provided to other people without the    */
/* permission of Zhang Hao,otherwise intellectual property infringement  */
/* will be prosecuted.If you have any questions,please send me an email. */
/* My email is kingderzhang@foxmail.com. The final interpretation rights */
/* are interpreted by ZhangHao.                                          */
/*                  Copyright (C) ZhangHao All rights reserved           */
/*************************************************************************/

#include "httpcom.h"
HttpCom *HttpCom::instance = nullptr;

HttpCom *HttpCom::getInstance()
{
    if(instance == nullptr){
        instance = new HttpCom;
    }
    return instance;
}

void HttpCom::requestFinished()
{
    emit hasDataComeFromServer(m_reply->readAll());
}

void HttpCom::slotError(QNetworkReply::NetworkError errCode)
{
    emit requestError(static_cast<int>(errCode));
}

void HttpCom::sendDataToServerByPost(QUrl url, QByteArray data)
{
    m_request.setUrl(url);
    m_reply = m_manager.post(m_request,data);
    connect(m_reply, SIGNAL(readyRead()), this, SLOT(requestFinished()));
    connect(m_reply, SIGNAL(error(QNetworkReply::NetworkError)),
            this, SLOT(slotError(QNetworkReply::NetworkError)));
}

void HttpCom::sendDataToServerByPost(QString url, QByteArray data)
{
    QUrl address(url);
    sendDataToServerByPost(address,data);
}

void HttpCom::getDataFromServerByGet(QUrl url)
{
    m_request.setUrl(url);
    m_reply = m_manager.get(m_request);
    connect(m_reply, SIGNAL(readyRead()), this, SLOT(requestFinished()));
    connect(m_reply, SIGNAL(error(QNetworkReply::NetworkError)),
            this, SLOT(slotError(QNetworkReply::NetworkError)));
    connect(m_reply, SIGNAL(sslErrors(QList<QSslError>)),
             this, SLOT(slotSslErrors(QList<QSslError>)));
}

void HttpCom::getDataFromServerByGet(QString url)
{
    QUrl address(url);
    getDataFromServerByGet(address);
}

void HttpCom::setrequestRawHeader(QByteArray key,QByteArray value)
{
    m_request.setRawHeader(key,value);
}

HttpCom::HttpCom()
{

}
