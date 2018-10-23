#include "httpcom.h"

HttpCom *HttpCom::instance = nullptr;

HttpCom *HttpCom::getInstance()
{
    if(instance == nullptr){
        instance = new HttpCom;
    }
    return instance;
}

QByteArray HttpCom::requestDataFromServer(QString url)
{

}

HttpCom::HttpCom()
{
    m_manager = new QNetworkAccessManager;
    m_request = new QNetworkRequest;
}
