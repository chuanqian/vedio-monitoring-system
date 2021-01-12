#ifndef TVREAL_H
#define TVREAL_H


//class TVReal
//{
//public:
//    TVReal();
//};

//#endif // TVREAL_H


#pragma once

#include <stdio.h>
#include <iostream>
#include <time.h>
#include <vector>
#include "HCNetSDK.h"
#include <QString>
#include "StructType.h"

using namespace std;


class CTVReal
{
public:
    CTVReal();
    ~CTVReal();

public:
    void initialize(InitializeCameraParamter initializeCameraParamter);// 初始化
    void Layout(LONG lUserID); //注销
    LONG LoginFoarmt(LoginParamter loginParmater); // 登录设备注册

    DWORD StartPlay(StartPlayParamter startPlayParamter);// 启用预览设备
    DWORD StopPlay(LONG lRealPlayHandle);//停止预览

    DWORD SavePlay(SavePlayParamter savePlayParamter);//截图保存

    vector <LONG> equipmentList; //设备信息列表

};

#endif // TVREAL_H
