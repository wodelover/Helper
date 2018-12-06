#include "AirFaceOperater.h"

AirFaceOperater::AirFaceOperater()
{

}

AirFaceOperater::AirFaceOperater(char* APPID,char *SDKKey)
{
    VerifyAirFaceOperaterKey(APPID,SDKKey);
}

bool AirFaceOperater::VerifyAirFaceOperaterKey(char *APPID, char *SDKKey)
{
    res = ASFActivation(APPID, SDKKey);
    if (MOK != res && res != MERR_ASF_ALREADY_ACTIVATED)
    {
        printf("Activation SDK fail: %d\n", res);
        printf("First time Verify need connected network...\n");
        return false;
    }
    return true;
}

bool AirFaceOperater::InitFaceEngine(DetectedMode mode, OrientPriority priority)
{
    if(mode==Image){
        res = ASFInitEngine(static_cast<long>(ASF_DETECT_MODE_IMAGE), priority, 16, 5, mask, &handle);
    }else if(mode == Video){
        res = ASFInitEngine(static_cast<long>(ASF_DETECT_MODE_VIDEO), priority, 16, 5, mask, &handle);
    }

    if (res != MOK){
        printf("Init Engine fail: %d\n", res);
        return false;
    }
    return true;
}

vector<AirFaceOperater::FaceRect> AirFaceOperater::FaceDetection(char *imgPath)
{
    Mat img = imread(imgPath);
    return FaceDetection(img);
}

vector<AirFaceOperater::FaceRect> AirFaceOperater::FaceDetection(Mat &img)
{
    vector<AirFaceOperater::FaceRect> rects;
    //检测矫正图像数据
    if(RectificationImage(&img)){
        ASF_MultiFaceInfo detectedFaces = { nullptr,nullptr,0};
        res = ASFDetectFaces(handle, img.cols, img.rows , ASVL_PAF_RGB24_B8G8R8, static_cast<MUInt8*>(img.data),&detectedFaces);
        if (MOK == res)
        {
            for(int i =0;i< detectedFaces.faceNum;i++){
                FaceRect rect;
                rect.top = detectedFaces.faceRect[i].top;
                rect.bottom = detectedFaces.faceRect[i].bottom;
                rect.left = detectedFaces.faceRect[i].left;
                rect.right = detectedFaces.faceRect[i].right;
                rect.Orient = detectedFaces.faceOrient[i];
                rects.push_back(rect);
            }
        }else{
            printf("Face Detect fail:\n",res);
            return rects;
        }
    }else{
        printf("Check Image Error,width or image path is not right...\n");
        return rects;
    }
}

float AirFaceOperater::FaceComparison(char *srcPath,char *dstPath,bool mutilpCompare)
{
    Mat img1 = imread(srcPath);
    Mat img2 = imread(dstPath);
    return FaceComparison(&img1,&img2,mutilpCompare);
}

float AirFaceOperater::FaceComparison(Mat *srcImg, Mat *dstImg,bool mutilpCompare)
{
    //检测待检测图像数据是否正确,并对数据进行自我纠正
    if(RectificationImage(srcImg)&&RectificationImage(dstImg)){
        ASF_MultiFaceInfo detectedFaces1 = { nullptr,nullptr,0 };
        ASF_SingleFaceInfo SingleDetectedFaces1 = { {0,0,0,0},0};
        ASF_FaceFeature feature1 = { nullptr,0 };
        ASF_FaceFeature copyfeature1 = { nullptr,0 };
        res = ASFDetectFaces(handle, srcImg->cols, srcImg->rows, ASVL_PAF_RGB24_B8G8R8, (MUInt8*)srcImg->data, &detectedFaces1);
        if (MOK == res)
        {
            SingleDetectedFaces1.faceRect.left = detectedFaces1.faceRect[0].left;
            SingleDetectedFaces1.faceRect.top = detectedFaces1.faceRect[0].top;
            SingleDetectedFaces1.faceRect.right = detectedFaces1.faceRect[0].right;
            SingleDetectedFaces1.faceRect.bottom = detectedFaces1.faceRect[0].bottom;
            SingleDetectedFaces1.faceOrient = detectedFaces1.faceOrient[0];

            res = ASFFaceFeatureExtract(handle, srcImg->cols, srcImg->rows, ASVL_PAF_RGB24_B8G8R8, (MUInt8*)srcImg->data, &SingleDetectedFaces1, &feature1);
            if (res == MOK)
            {
                //拷贝feature
                copyfeature1.featureSize = feature1.featureSize;
                copyfeature1.feature = (MByte *)malloc(feature1.featureSize);
                memset(copyfeature1.feature, 0, feature1.featureSize);
                memcpy(copyfeature1.feature, feature1.feature, feature1.featureSize);
            }
            else{
                printf("ASFFaceFeatureExtract 1 fail: %d\n", res);
                SafeFree(copyfeature1.feature);		//释放内存
                return 0.0;
            }
        }
        else{
            printf("ASFDetectFaces 1 fail: %d\n", res);
            SafeFree(copyfeature1.feature);		//释放内存
            return 0.0;
        }

        //第二张人脸提取特征
        ASF_MultiFaceInfo	detectedFaces2 = { nullptr,nullptr,0 };
        ASF_SingleFaceInfo SingleDetectedFaces2 = { {0,0,0,0},0 };
        ASF_FaceFeature feature2 = { nullptr,0 };
        res = ASFDetectFaces(handle, dstImg->cols, dstImg->rows, ASVL_PAF_RGB24_B8G8R8, (MUInt8*)dstImg->data, &detectedFaces2);



        if (MOK != res)
        {
            printf("ASFDetectFaces 2 fail: %d\n", res);
            SafeFree(copyfeature1.feature);		//释放内存
            return 0.0;
        }

        int compareCount = 1;
        if(mutilpCompare){
            compareCount = detectedFaces2.faceNum;
        }

        MFloat confidenceLevel = 0.0;

        for(int i=0;i<compareCount;i++){
            SingleDetectedFaces2.faceRect.left = detectedFaces2.faceRect[i].left;
            SingleDetectedFaces2.faceRect.top = detectedFaces2.faceRect[i].top;
            SingleDetectedFaces2.faceRect.right = detectedFaces2.faceRect[i].right;
            SingleDetectedFaces2.faceRect.bottom = detectedFaces2.faceRect[i].bottom;
            SingleDetectedFaces2.faceOrient = detectedFaces2.faceOrient[i];
            res = ASFFaceFeatureExtract(handle, dstImg->cols, dstImg->rows, ASVL_PAF_RGB24_B8G8R8, (MUInt8*)dstImg->data, &SingleDetectedFaces2, &feature2);
            if (MOK != res){
                printf("ASFFaceFeatureExtract 2 fail: %d\n", res);
                continue;
            }

            // 单人脸特征比对
            float value = 0.0;
            res = ASFFaceFeatureCompare(handle, &copyfeature1, &feature2, &value);
            if (res != MOK){
                printf("ASFFaceFeatureCompare fail: %d\n", res);
                continue;
            }
            else{
                if(value>confidenceLevel){
                    confidenceLevel = value;
                }
            }
            SafeFree(copyfeature1.feature);		//释放内存
        }
        return confidenceLevel;
    }
    return 0.0;
}

vector<int> AirFaceOperater::GetAges(char *imgPath)
{
    Mat img = imread(imgPath);
    return GetAges(img);
}

vector<int> AirFaceOperater::GetAges(Mat &img)
{
    vector<int> ages;
    if(RectificationImage(&img)){
        MInt32 processMask = ASF_AGE;
        ASF_MultiFaceInfo detectedFaces = { nullptr,nullptr,0};
        //1、首先检测人脸
        res = ASFDetectFaces(handle, img.cols, img.rows , ASVL_PAF_RGB24_B8G8R8, static_cast<MUInt8*>(img.data),&detectedFaces);
        if(res != MOK){
            printf("Detect Faces Fail:%d\n",res);
            return ages;
        }
        //2、初始化人脸信息
        res = ASFProcess(handle, img.cols, img.rows, ASVL_PAF_RGB24_B8G8R8, static_cast<MUInt8*>(img.data), &detectedFaces, processMask);
        if (res != MOK){//初始化人脸信息失败
            printf("Face Process fail: %d\n", res);
        }
        else{// 获取年龄
            ASF_AgeInfo ageInfo = { nullptr,0 };
            //3、获取所有检测到的人脸年龄
            res = ASFGetAge(handle, &ageInfo);
            if (res != MOK){
                printf("GetAge fail: %d\n", res);
            }
            else{//将检测到的人的年龄压入数组中
                for(int i=0;i<ageInfo.num;i++){
                    ages.push_back(ageInfo.ageArray[i]);
                }
            }
        }
    }
    return ages;
}

vector<int> AirFaceOperater::GetGender(char *imgPath)
{
    Mat img = imread(imgPath);
    return GetGender(img);
}

vector<int> AirFaceOperater::GetGender(Mat &img)
{
    vector<int> gender;
    if(RectificationImage(&img)){
        MInt32 processMask = ASF_GENDER;
        ASF_MultiFaceInfo detectedFaces = { nullptr,nullptr,0};
        //1、首先检测人脸
        res = ASFDetectFaces(handle, img.cols, img.rows , ASVL_PAF_RGB24_B8G8R8, static_cast<MUInt8*>(img.data),&detectedFaces);
        if(res != MOK){
            printf("Detect Faces Fail:%d\n",res);
            return gender;
        }
        //2、初始化人脸信息
        res = ASFProcess(handle, img.cols, img.rows, ASVL_PAF_RGB24_B8G8R8, static_cast<MUInt8*>(img.data), &detectedFaces, processMask);
        if (res != MOK){//初始化人脸信息失败
            printf("Face Process fail: %d\n", res);
        }
        else{// 获取性别
            ASF_GenderInfo genderInfo = { nullptr,0 };
            //3、获取所有检测到的人脸性别
            res = ASFGetGender(handle, &genderInfo);
            if (res != MOK){
                printf("GetGender fail: %d\n", res);
            }
            else{//将检测到的人的性别压入数组中
                for(int i=0;i<genderInfo.num;i++){
                    gender.push_back(genderInfo.genderArray[i]);
                }
            }
        }
    }
    return gender;
}

vector<AirFaceOperater::FaceAngle> AirFaceOperater::Get3DAngle(char *imgPath)
{
    Mat img = imread(imgPath);
    return Get3DAngle(img);
}

vector<AirFaceOperater::FaceAngle> AirFaceOperater::Get3DAngle(Mat &img)
{
    vector<FaceAngle> angles;
    if(RectificationImage(&img)){
        MInt32 processMask = ASF_FACE3DANGLE;
        ASF_MultiFaceInfo detectedFaces = { nullptr,nullptr,0};
        //1、首先检测人脸
        res = ASFDetectFaces(handle, img.cols, img.rows , ASVL_PAF_RGB24_B8G8R8, static_cast<MUInt8*>(img.data),&detectedFaces);
        if(res != MOK){
            printf("Detect Faces Fail:%d\n",res);
            return angles;
        }
        //2、初始化人脸信息
        res = ASFProcess(handle, img.cols, img.rows, ASVL_PAF_RGB24_B8G8R8, static_cast<MUInt8*>(img.data), &detectedFaces, processMask);
        if (res != MOK){//初始化人脸信息失败
            printf("Face Process fail: %d\n", res);
        }
        else{// 获取角度
            ASF_Face3DAngle angleInfo = { nullptr, nullptr, nullptr, nullptr,0 };
            //3、获取所有检测到的人脸角度
            res = ASFGetFace3DAngle(handle, &angleInfo);
            if (res != MOK){
                printf("GetAngle fail: %d\n", res);
            }
            else{//拷贝角度数据
                for(int i =0;i<angleInfo.num;i++){
                    FaceAngle temp;
                    temp.yaw = angleInfo.yaw[i];
                    temp.roll = angleInfo.roll[i];
                    temp.pitch = angleInfo.pitch[i];
                    temp.status = angleInfo.status[i];
                    angles.push_back(temp);
                }
            }
        }
    }
    return angles;
}

map<char *, char *> AirFaceOperater::GetFaceVersionInfo()
{
    map<char *, char *> info;
    const ASF_VERSION* pVersionInfo = ASFGetVersion(handle);
    info.insert(map<char *, char *>::value_type(const_cast<char *>("Version"),pVersionInfo->Version));
    info.insert(map<char *, char *>::value_type(const_cast<char *>("BuildDate"),pVersionInfo->BuildDate));
    info.insert(map<char *, char *>::value_type(const_cast<char *>("CopyRight"),pVersionInfo->CopyRight));
    return info;
}

bool AirFaceOperater::DestroyFaceEngine()
{
    res = ASFUninitEngine(handle);
    if (res != MOK){
        printf("UninitEngine fail: %d\n", res);
        printf("did other face mode is working...");
        return false;
    }
    else
        return true;
}

AirFaceOperater::~AirFaceOperater()
{
    DestroyFaceEngine();
}

bool AirFaceOperater::RectificationImage(Mat *img)
{
    if(img->empty()){
        printf("input image data is empty.");
        return false;
    }else{
        //图像宽度需要是4的整数倍
        if(img->cols%4){
            resize(*img,*img,Size(img->cols/4,img->rows));
        }
        return true;
    }
}
