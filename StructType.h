#ifndef STRUCTTYPE_H
#define STRUCTTYPE_H
#include "HCNetSDK.h"

typedef struct initializerCameraParamter{
    DWORD reconnectionWaitTime; //重连等待时间
    DWORD reconnectionNumber; //重连次数
    DWORD reconnectionTimeInterval; //重连时间间隔
    DWORD whetherToReconnection; //是否重连
}InitializeCameraParamter;

typedef struct startPlayParamter{
    int channelNumber; // 通道号
    LONG loginId; // 登录id
    DWORD streamNumber; // 解码流
    DWORD connectionWay; // 连接方式
    HWND HandleNumber; // 窗口句柄
}StartPlayParamter;

typedef struct cameraLoginParamter{
    char *ipAddress; //ip地址
    WORD port; //端口号
    char *userName; //账户名
    char *password; //密码
}LoginParamter;

typedef struct savePlayParamter{
    LONG equidmentId; //设备播放号
    char* fileName; //保存文件名
}SavePlayParamter;

#endif // STRUCTTYPE_H
