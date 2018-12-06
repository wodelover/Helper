#include "face.h"
#include "FormatConversion.h"

Face::Face()
{

}

Face::~Face()
{

}

void Face::setFaceAppID(QString appID)
{
    if(appID!=m_APPID){
        m_APPID = appID;
        emit faceAppIDChanged(m_APPID);
    }
}

void Face::setFaceKey(QString key)
{
    if(key!=m_Key){
        m_Key = key;
        emit faceKeyChanged(m_Key);
    }
}

QString Face::faceAppID()
{
    return m_APPID;
}

QString Face::faceKey()
{
    return m_Key;
}

bool Face::VerifyAirFaceOperaterKey()
{
    return m_airsoftFace.VerifyAirFaceOperaterKey(m_APPID.toLatin1().data(),m_Key.toLatin1().data());
}

bool Face::InitFaceEngine(AirFaceOperater::DetectedMode mode, AirFaceOperater::OrientPriority priority)
{
    return m_airsoftFace.InitFaceEngine(mode,priority);
}

vector<AirFaceOperater::FaceRect> Face::FaceDetection(QString path)
{
    return m_airsoftFace.FaceDetection(path.toLatin1().data());
}

vector<AirFaceOperater::FaceRect> Face::FaceDetection(Mat &img)
{
    return m_airsoftFace.FaceDetection(img);
}

vector<AirFaceOperater::FaceRect> Face::FaceDetection(QImage &img)
{
    Mat mat;
    FormatConversion format;
    mat = format.QImage2Mat(img);
    return m_airsoftFace.FaceDetection(mat);
}

float Face::FaceComparison(QString srcPath, QString dstPath, bool mutilpCompare)
{
    return m_airsoftFace.FaceComparison(srcPath.toLatin1().data(),dstPath.toLatin1().data(),mutilpCompare);
}

float Face::FaceComparison(Mat &srcImg, Mat &dstImg, bool mutilpCompare)
{
    return m_airsoftFace.FaceComparison(&srcImg,&dstImg,mutilpCompare);
}

float Face::FaceComparison(QImage &srcImg, QImage &dstImg, bool mutilpCompare)
{
    Mat srcMat,dstMat;
    FormatConversion format;
    srcMat = format.QImage2Mat(srcImg);
    dstMat = format.QImage2Mat(dstImg);
    return m_airsoftFace.FaceComparison(&srcMat,&dstMat,mutilpCompare);
}

vector<int> Face::GetAges(QString imgPath)
{
    return m_airsoftFace.GetAges(imgPath.toLatin1().data());
}

vector<int> Face::GetAges(Mat &img)
{
    return m_airsoftFace.GetAges(&img);
}

vector<int> Face::GetAges(QImage &img)
{
    Mat mat;
    FormatConversion format;
    mat = format.QImage2Mat(img);
    return m_airsoftFace.GetAges(&mat);
}

vector<int> Face::GetGender(QString imgPath)
{
    return m_airsoftFace.GetGender(imgPath.toLatin1().data());
}

vector<int> Face::GetGender(Mat &img)
{
    return m_airsoftFace.GetGender(&img);
}

vector<int> Face::GetGender(QImage &img)
{
    Mat mat;
    FormatConversion format;
    mat = format.QImage2Mat(img);
    return m_airsoftFace.GetGender(&mat);
}

vector<AirFaceOperater::FaceAngle> Face::Get3DAngle(QString imgPath)
{
    return m_airsoftFace.Get3DAngle(imgPath.toLatin1().data());
}

vector<AirFaceOperater::FaceAngle> Face::Get3DAngle(Mat &img)
{
    return m_airsoftFace.Get3DAngle(img);
}

vector<AirFaceOperater::FaceAngle> Face::Get3DAngle(QImage &img)
{
    Mat mat;
    FormatConversion format;
    mat = format.QImage2Mat(img);
    return m_airsoftFace.Get3DAngle(mat);
}

QMap<QString, QString> Face::GetFaceVersionInfo()
{
    QMap<char *,char *> map(m_airsoftFace.GetFaceVersionInfo());
    QMap<QString, QString> info;
    QMap<char *,char *>::iterator itr = map.begin();

    for(;itr!=map.end();itr++){
        QString key = itr.key();
        QString value = itr.value();
        info.insert(key,value);
    }
    return info;
}
