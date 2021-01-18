#include "tvreal.h"
#include "QDebug"

CTVReal::CTVReal(){
}

CTVReal::~CTVReal(){
}

void CTVReal::initialize(InitializeCameraParamter initializeCameraParamter){
    bool m_status = NET_DVR_Init();
    if (!m_status)
    {
        printf("Login failed, error code: %d\n", (int)NET_DVR_GetLastError());
        NET_DVR_Cleanup();
        return;
    }
    NET_DVR_SetConnectTime(initializeCameraParamter.reconnectionWaitTime, initializeCameraParamter.reconnectionNumber);
    NET_DVR_SetReconnect(initializeCameraParamter.reconnectionTimeInterval, initializeCameraParamter.whetherToReconnection);
    NET_DVR_SetExceptionCallBack_V30(0, NULL,NULL, NULL);
}



void CTVReal::Layout(LONG lUserID){
    NET_DVR_Logout(lUserID);
    NET_DVR_Cleanup();
}

LONG CTVReal::LoginFoarmt(LoginParamter loginParamter){
    LONG lUserID;
    NET_DVR_USER_LOGIN_INFO struLoginInfo = {};
    struLoginInfo.bUseAsynLogin = 0; //同步登录方式
    strcpy(struLoginInfo.sDeviceAddress, loginParamter.ipAddress); //设备IP地址
    struLoginInfo.wPort = loginParamter.port; //设备服务端口
    strcpy(struLoginInfo.sUserName, loginParamter.userName); //设备登录用户名
    strcpy(struLoginInfo.sPassword, loginParamter.password); //设备登录密码

    //设备信息, 输出参数
    NET_DVR_DEVICEINFO_V40 struDeviceInfoV40 = {};

    lUserID = NET_DVR_Login_V40(&struLoginInfo, &struDeviceInfoV40);
    if (lUserID < 0)
    {
        printf("Login failed, error code: %d\n", (int)NET_DVR_GetLastError());
        NET_DVR_Cleanup();
        return -1;
    }
    return lUserID;
}


DWORD CTVReal::StartPlay(StartPlayParamter startPlayParamter){
    NET_DVR_PREVIEWINFO struPlayInfo = { };
    struPlayInfo.hPlayWnd = startPlayParamter.HandleNumber;         //需要SDK解码时句柄设为有效值，仅取流不解码时可设为空
    struPlayInfo.lChannel = startPlayParamter.channelNumber;       //预览通道号
    struPlayInfo.dwStreamType = startPlayParamter.streamNumber;       //0-主码流，1-子码流，2-码流3，3-码流4，以此类推
    struPlayInfo.dwLinkMode = startPlayParamter.connectionWay;       //0- TCP方式，1- UDP方式，2- 多播方式，3- RTP方式，4-RTP/RTSP，5-RSTP/HTTP
    struPlayInfo.bBlocked = 0;       //0- 非阻塞取流，1- 阻塞取流

    long lRealPlayHandle = NET_DVR_RealPlay_V40(startPlayParamter.loginId, &struPlayInfo, nullptr, nullptr);
    if (lRealPlayHandle < 0)
    {
        DWORD err = NET_DVR_GetLastError();
        qDebug() << "err: " << err;
        return lRealPlayHandle;
    }
    equipmentList.push_back(lRealPlayHandle);
    return lRealPlayHandle;
}


DWORD CTVReal::StopPlay(LONG lRealPlayHandle){
    BOOL status = NET_DVR_StopRealPlay(lRealPlayHandle);
    if (!status)
    {
        DWORD err = NET_DVR_GetLastError();
        return err;
    }
    return 0;
}

DWORD CTVReal::SavePlay(SavePlayParamter savePlayParamter){
    bool status = NET_DVR_SaveRealData(savePlayParamter.equidmentId, savePlayParamter.fileName);
    if (!status)
    {
        DWORD err = NET_DVR_GetLastError();
        return err;
    }
    return 0;
}
