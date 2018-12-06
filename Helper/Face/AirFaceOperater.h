/*************************************************************************/
/*                          Copyright Notice                             */
/* The code can not be copied or provided to other people without the    */
/* permission of Zhang Hao,otherwise intellectual property infringement  */
/* will be prosecuted.If you have any questions,please send me an email. */
/* My email is kingderzhang@foxmail.com. The final interpretation rights */
/* are interpreted by ZhangHao.                                          */
/*                  Copyright (C) ZhangHao All rights reserved           */
/*************************************************************************/

#ifndef AirFaceOperater_H
#define AirFaceOperater_H

#include "inc/airface/arcsoft_face_sdk.h"
#include "inc/airface/asvloffscreen.h"
#include "inc/airface/merror.h"
#include <direct.h>
#include <iostream>
#include <stdarg.h>
#include <string>
#include <map>
#include "opencv.hpp"
#include "opencv2/core.hpp"
using namespace std;
using namespace cv;

#define SafeFree(p) { if ((p)) free(p); (p) = NULL; }
#define SafeArrayDelete(p) { if ((p)) delete [] (p); (p) = NULL; }
#define SafeDelete(p) { if ((p)) delete (p); (p) = NULL; }

/**
 * @ClassName: AirFaceOperater
 * @Description: 对两张图片进行比较
 * @Autor: zhanghao kinderzhang@foxmail.com
 * @date: 2018-12-04 13:11:08
 * @Version: 1.0.0
 * @update_autor
 * @update_time
**/
class AirFaceOperater
{
public:
    AirFaceOperater();
    ~AirFaceOperater();
    enum DetectedMode{//设置检测模式
        Image,
        Video
    };

    enum OrientPriority{//检测角度优先级
        OP_0_ONLY = 0x1,        // 0, 0, ...
        OP_90_ONLY = 0x2,		// 90, 90, ...
        OP_270_ONLY = 0x3,		// 270, 270, ...
        OP_180_ONLY = 0x4,		// 180, 180, ...
        OP_0_HIGHER_EXT = 0x5,	// 0, 90, 270, 180, 0, 90, 270, 180, ...
    };

    struct FaceAngle//单个人脸角度检测信息
    {
        float roll; //横滚角（Z）
        float yaw; //偏航角（Y）
        float pitch; //俯仰角（X）
        bool status;	//0: 正常，其他数值：出错
    };

    struct FaceRect{//单个人脸框信息
        float top;    //顶部起点
        float bottom; //底部起点
        float left;   //左边起点
        float right;  //右边起点
        int   Orient; //输入图像的角度
    };

    AirFaceOperater(char* APPID,char *SDKKey);
    /**
     * @MethodName: VerifyAirFaceOperaterKey
     * @Description: 验证人脸比对秘钥
     * @Autor: ZhangHao kinderzhang@foxmail.com
     * @date: 2018-12-04 13:59:18
     * @Version: 1.0.0
     * @update_autor
     * @update_time
     * @Parma: [APPID] 认证ID
     * @Parma: [SDKKey] 人脸比对秘钥
     * @Return: [bool]
    **/
    bool VerifyAirFaceOperaterKey(char* APPID,char *SDKKey);

    /**
     * @MethodName: InitFaceEngine
     * @Description: 初始化人脸操作引擎
     * @Autor: ZhangHao kinderzhang@foxmail.com
     * @date: 2018-12-04 14:57:55
     * @Version: 1.0.0
     * @Parma: [DetectedMode] 设置检测模式,图片或者视频流
     * @Parma: [OrientPriority] 设置检测角度优先级
    **/
    bool InitFaceEngine(DetectedMode mode = DetectedMode::Image,OrientPriority priority = OrientPriority::OP_0_ONLY);

    /**
     * @MethodName: FaceDetection
     * @Description: 人脸检测,返回检测到的人脸信息
     * @Autor: ZhangHao kinderzhang@foxmail.com
     * @date: 2018-12-05 10:39:56
     * @Version: 1.0.0
     * @Parma: [img] OpenCv Mat
     * @Return [vector<FaceRect>] 返回人脸矩形框数组
    **/
    vector<FaceRect> FaceDetection(char *imgPath);
    /**
     * @MethodName: FaceDetection
     * @Description: 人脸检测,返回检测到的人脸信息
     * @Autor: ZhangHao kinderzhang@foxmail.com
     * @date: 2018-12-05 10:39:56
     * @Version: 1.0.0
     * @Parma: [img] OpenCv Mat
     * @Return [vector<FaceRect>] 返回人脸矩形框数组
    **/
    vector<FaceRect> FaceDetection(Mat &img);

    /**
     * @MethodName: FaceComparison
     * @Description: 进行人脸对比
     * @Autor: ZhangHao kinderzhang@foxmail.com
     * @date: 2018-12-04 15:41:40
     * @Version: 1.0.0
     * @Parma: [srcPath] 待对比图片路径
     * @Parma: [dstPath] 待检测图片路径
     * @Parma: [mutilpCompare] 是否开启识别图片中多个人脸
     * @Return: [float] 相似度
    **/
    float FaceComparison(char *srcPath,char *dstPath,bool mutilpCompare = false);
    /**
     * @MethodName: FaceComparison
     * @Description: 进行人脸对比
     * @Autor: ZhangHao kinderzhang@foxmail.com
     * @date: 2018-12-04 15:44:59
     * @Version: 1.0.0
     * @Parma: [srcImg] 待对比图片Mat,以获取到的第一个人脸为准
     * @Parma: [dstImg] 待检测图片Mat,
     * mutilpCompare将控制是否与本图片中其他人脸进行比较
     * @Parma: [mutilpCompare] 是否开启识别图片中多个人脸
     * @Return: [float] 相似度
    **/
    float FaceComparison(Mat *srcImg, Mat *dstImg, bool mutilpCompare = false);

    /**
     * @MethodName: GetAges
     * @Description: 获取图像中的人年龄
     * @Autor: ZhangHao kinderzhang@foxmail.com
     * @date: 2018-12-04 16:58:27
     * @Version: 1.0.0
     * @Parma: [imgPath] 图片路径
    **/
    vector<int> GetAges(char *imgPath);
    /**
     * @MethodName: GetAges
     * @Description: 获取图像中的人年龄
     * @Autor: ZhangHao kinderzhang@foxmail.com
     * @date: 2018-12-04 16:58:27
     * @Version: 1.0.0
     * @Parma: [img] 图片
    **/
    vector<int> GetAges(Mat &img);

    /**
     * @MethodName: GetGender
     * @Description: 获取图像中的人性别(0->男,1->女)
     * @Autor: ZhangHao kinderzhang@foxmail.com
     * @date: 2018-12-04 16:58:27
     * @Version: 1.0.0
     * @Parma: [imgPath] 图片路径
    **/
    vector<int> GetGender(char *imgPath);
    /**
     * @MethodName: GetGender
     * @Description: 获取图像中的人性别(0->男,1->女)
     * @Autor: ZhangHao kinderzhang@foxmail.com
     * @date: 2018-12-04 16:58:27
     * @Version: 1.0.0
     * @Parma: [img] 图片
    **/
    vector<int> GetGender(Mat &img);

    /**
     * @MethodName: Get3DAngle
     * @Description: 获取图像中的人脸的3D角度
     * @Autor: ZhangHao kinderzhang@foxmail.com
     * @date: 2018-12-04 16:58:27
     * @Version: 1.0.0
     * @Parma: [imgPath] 图片路径
    **/
    vector<FaceAngle> Get3DAngle(char *imgPath);
    /**
     * @MethodName: Get3DAngle
     * @Description: 获取图像中的人脸的3D角度
     * @Autor: ZhangHao kinderzhang@foxmail.com
     * @date: 2018-12-04 16:58:27
     * @Version: 1.0.0
     * @Parma: [img] 图片
    **/
    vector<FaceAngle> Get3DAngle(Mat &img);

    /**
     * @MethodName: GetFaceVersionInfo
     * @Description: 获取人脸识别库的信息
     * @Autor: ZhangHao kinderzhang@foxmail.com
     * @date: 2018-12-04 15:21:15
     * @Version: 1.0.0
     * @Return: [map<char *,char *>] 信息名，信息值
    **/
    map<char *,char *> GetFaceVersionInfo();

    /**
     * @MethodName: DestroyFaceEngine
     * @Description: 释放人脸引擎
     * @Autor: ZhangHao kinderzhang@foxmail.com
     * @date: 2018-12-05 14:11:39
     * @Version: 1.0.0
    **/
    bool DestroyFaceEngine();

private:
    /**
     * @MethodName: RectificationImage
     * @Description: 矫正检测图片
     * @Autor: ZhangHao kinderzhang@foxmail.com
     * @date: 2018-12-04 17:03:18
     * @Version: 1.0.0
     * @Parma: [img] 待矫正的图像
    **/
    bool RectificationImage(Mat *img);

    MRESULT res;
    MHandle handle = nullptr;
    MInt32 mask = ASF_FACE_DETECT | ASF_FACERECOGNITION | ASF_AGE | ASF_GENDER | ASF_FACE3DANGLE;
};

#endif // AirFaceOperater_H
