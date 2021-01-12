#include "vediomonitoringsystem.h"
#include "qwidget.h"
#include "qpushbutton.h"
#include "QHBoxLayout"
#include "QDebug"
#include "tvreal.h"
#include "qcombobox.h"

VedioMonitoringSystem::VedioMonitoringSystem(QWidget *parent)
    : QWidget(parent)
{

    resize(globalWidthSize,globalHeightSize);
    setWindowTitle("视频监控系统");
    layout = new QGridLayout;
    createFourView();
    //添加四个显示视频窗体
    layout->addWidget(leftTopWidget,0,0);
    layout->addWidget(leftButtomWidget,1,0);
    layout->addWidget(rightTopWidget,0,1);
    layout->addWidget(rightButtomWidget,1,1);
    layout->setMargin(0);
    this->setLayout(layout);
    //初始化主菜单按钮
    mainbutton = new QPushButton(this);
    mainbutton->setGeometry(10,globalHeightSize-10-50,80,50);
    mainbutton->setText("菜单");
    mainbutton->setStyleSheet("QPushButton{"
                                  "background-color:rgba(80, 100, 255,100%);"
                                  "color: white;border-radius: 10px;"
                                  "border: 0px groove gray;"
                                  "border-style: outset;"
                              "}" // 按键本色
                              "QPushButton:hover{"
                                  "background-color:white;"
                                  " color: black;"
                              "}"  // 鼠标停放时的色彩
                              "QPushButton:pressed{"
                                  "background-color:rgba(0, 255, 0, 50%);"
                                  " border-style: inset; "
                              "}" // 鼠标按下的色彩
                              );
    //添加车厢按钮
    createCompartmentButtom();
    //创建一级菜单
    createOneMeun();
    connect(mainbutton,&QPushButton::clicked,this,&VedioMonitoringSystem::showHideOneMenu);

    loadCameraUtils();
    loadVeido();

}

VedioMonitoringSystem::~VedioMonitoringSystem()
{
}

void VedioMonitoringSystem::createFourView(){

    leftTopWidget = new QWidget;
    leftTopWidget->resize(quarterScreenWidth,quarterScreenHeight);

    ltltLabel = new QLabel;
    ltltLabel->resize(quarterScreenWidth/2,quarterScreenHeight/2);
    ltltLabel->setStyleSheet("border: 1px groove green;");

    ltlbLabel = new QLabel;
    ltlbLabel->resize(quarterScreenWidth/2,quarterScreenHeight/2);
    ltlbLabel->setStyleSheet("border: 1px groove green;");

    ltrtLabel = new QLabel;
    ltrtLabel->resize(quarterScreenWidth/2,quarterScreenHeight/2);
    ltrtLabel->setStyleSheet("border: 1px groove green;");

    ltrbLabel = new QLabel;
    ltrbLabel->resize(quarterScreenWidth/2,quarterScreenHeight/2);
    ltrbLabel->setStyleSheet("border: 1px groove green;");

    ltLayout = new QGridLayout;
    ltLayout->addWidget(ltltLabel,0,0);
    ltLayout->addWidget(ltlbLabel,0,1);
    ltLayout->addWidget(ltrtLabel,1,0);
    ltLayout->addWidget(ltrbLabel,1,1);
    ltLayout->setMargin(0);
    leftTopWidget->setLayout(ltLayout);




    leftButtomWidget = new QWidget;
    leftButtomWidget->resize(quarterScreenWidth,quarterScreenHeight);

    lbltLabel = new QLabel;
    lbltLabel->resize(quarterScreenWidth/2,quarterScreenHeight/2);
    lbltLabel->setStyleSheet("border: 1px groove green;");

    lblbLabel = new QLabel;
    lblbLabel->resize(quarterScreenWidth/2,quarterScreenHeight/2);
    lblbLabel->setStyleSheet("border: 1px groove green;");

    lbrtLabel = new QLabel;
    lbrtLabel->resize(quarterScreenWidth/2,quarterScreenHeight/2);
    lbrtLabel->setStyleSheet("border: 1px groove green;");

    lbrbLabel = new QLabel;
    lbrbLabel->resize(quarterScreenWidth/2,quarterScreenHeight/2);
    lbrbLabel->setStyleSheet("border: 1px groove green;");

    lbLayout = new QGridLayout;
    lbLayout->addWidget(lbltLabel,0,0);
    lbLayout->addWidget(lblbLabel,0,1);
    lbLayout->addWidget(lbrtLabel,1,0);
    lbLayout->addWidget(lbrbLabel,1,1);
    lbLayout->setMargin(0);
    leftButtomWidget->setLayout(lbLayout);




    rightTopWidget = new QWidget;
    rightTopWidget->resize(quarterScreenWidth,quarterScreenHeight);

    rtltLabel = new QLabel;
    rtltLabel->resize(quarterScreenWidth/2,quarterScreenHeight/2);
    rtltLabel->setStyleSheet("border: 1px groove green;");

    rtlbLabel = new QLabel;
    rtlbLabel->resize(quarterScreenWidth/2,quarterScreenHeight/2);
    rtlbLabel->setStyleSheet("border: 1px groove green;");

    rtrtLabel = new QLabel;
    rtrtLabel->resize(quarterScreenWidth/2,quarterScreenHeight/2);
    rtrtLabel->setStyleSheet("border: 1px groove green;");

    rtrbLabel = new QLabel;
    rtrbLabel->resize(quarterScreenWidth/2,quarterScreenHeight/2);
    rtrbLabel->setStyleSheet("border: 1px groove green;");

    rtLayout = new QGridLayout;
    rtLayout->addWidget(rtltLabel,0,0);
    rtLayout->addWidget(rtlbLabel,0,1);
    rtLayout->addWidget(rtrtLabel,1,0);
    rtLayout->addWidget(rtrbLabel,1,1);
    rtLayout->setMargin(0);
    rightTopWidget->setLayout(rtLayout);





    rightButtomWidget = new QWidget;
    rightButtomWidget->resize(quarterScreenWidth,quarterScreenHeight);
    rbLabel = new QLabel(rightButtomWidget);
    rbLabel->setGeometry(0,0,quarterScreenWidth-10,quarterScreenHeight-10);
    rbLabel->setStyleSheet("border: 1px groove blue;");

}

void VedioMonitoringSystem::createCompartmentButtom(){
    carBtnWidget = new QWidget(this);    
    carHeadBtn = new QPushButton(carBtnWidget);
    carHeadBtn->setText("车头");
    carHeadBtn->setGeometry(0,0,126,50);
    carHeadBtn->setStyleSheet("QPushButton{"
                                  "background-color:rgba(80, 100, 255,100%);"
                                  "color: white;border-radius: 10px;"
                                  "border: 0px groove gray;"
                                  "border-style: outset;"
                              "}" // 按键本色
                              "QPushButton:hover{"
                                  "background-color:white;"
                                  " color: black;"
                              "}"  // 鼠标停放时的色彩
                              "QPushButton:pressed{"
                                  "background-color:rgba(0, 255, 0, 50%);"
                                  " border-style: inset; "
                              "}" // 鼠标按下的色彩
                              );

    //车头点击事件
//    connect(carHeadBtn,&QPushButton::clicked,this,)



    oneCarBtn = new QPushButton(carBtnWidget);
    oneCarBtn->setText("一车厢");
    oneCarBtn->setGeometry(128,0,126,50);
    oneCarBtn->setStyleSheet("QPushButton{"
                             "background-color:rgba(80, 100, 255,100%);"
                             "color: white;border-radius: 10px;"
                             "border: 0px groove gray;"
                             "border-style: outset;"
                         "}" // 按键本色
                         "QPushButton:hover{"
                             "background-color:white;"
                             " color: black;"
                         "}"  // 鼠标停放时的色彩
                         "QPushButton:pressed{"
                             "background-color:rgba(0, 255, 0, 50%);"
                             " border-style: inset; "
                         "}" // 鼠标按下的色彩
                         );
    twoCarBtn = new QPushButton(carBtnWidget);
    twoCarBtn->setText("二车厢");
    twoCarBtn->setGeometry(256,0,126,50);
    twoCarBtn->setStyleSheet("QPushButton{"
                             "background-color:rgba(80, 100, 255,100%);"
                             "color: white;border-radius: 10px;"
                             "border: 0px groove gray;"
                             "border-style: outset;"
                         "}" // 按键本色
                         "QPushButton:hover{"
                             "background-color:white;"
                             " color: black;"
                         "}"  // 鼠标停放时的色彩
                         "QPushButton:pressed{"
                             "background-color:rgba(0, 255, 0, 50%);"
                             " border-style: inset; "
                         "}" // 鼠标按下的色彩
                         );
    threeCarBtn = new QPushButton(carBtnWidget);
    threeCarBtn->setText("三车厢");
    threeCarBtn->setGeometry(384,0,126,50);
    threeCarBtn->setStyleSheet("QPushButton{"
                               "background-color:rgba(80, 100, 255,100%);"
                               "color: white;border-radius: 10px;"
                               "border: 0px groove gray;"
                               "border-style: outset;"
                           "}" // 按键本色
                           "QPushButton:hover{"
                               "background-color:white;"
                               " color: black;"
                           "}"  // 鼠标停放时的色彩
                           "QPushButton:pressed{"
                               "background-color:rgba(0, 255, 0, 50%);"
                               " border-style: inset; "
                           "}" // 鼠标按下的色彩
                           );

    rear = new QPushButton(carBtnWidget);
    rear->setText("车尾");
    rear->setGeometry(512,0,126,50);
    rear->setStyleSheet("QPushButton{"
                            "background-color:rgba(80, 100, 255,100%);"
                            "color: white;border-radius: 10px;"
                            "border: 0px groove gray;"
                            "border-style: outset;"
                        "}" // 按键本色
                        "QPushButton:hover{"
                            "background-color:white;"
                            " color: black;"
                        "}"  // 鼠标停放时的色彩
                        "QPushButton:pressed{"
                            "background-color:rgba(0, 255, 0, 50%);"
                            " border-style: inset; "
                        "}" // 鼠标按下的色彩
                        );

    carBtnWidget->setGeometry(192,globalHeightSize-10-50,640,50);
    carBtnWidget->setVisible(false);
}

void VedioMonitoringSystem::createOneMeun(){
    oneMenuWidget = new QWidget(this);

    loginBtn = new QPushButton(oneMenuWidget);
    loginBtn->setText(tr("登录"));
    loginBtn->setGeometry(0,0,80,50);
    loginBtn->setStyleSheet("QPushButton{"
                                  "background-color:rgba(80, 100, 255,100%);"
                                  "color: white;border-radius: 10px;"
                                  "border: 0px groove gray;"
                                  "border-style: outset;"
                              "}" // 按键本色
                              "QPushButton:hover{"
                                  "background-color:white;"
                                  " color: black;"
                              "}"  // 鼠标停放时的色彩
                              "QPushButton:pressed{"
                                  "background-color:rgba(0, 255, 0, 50%);"
                                  " border-style: inset; "
                              "}" // 鼠标按下的色彩
                              );

    logoutBtn = new QPushButton(oneMenuWidget);
    logoutBtn->setText(tr("注销"));
    logoutBtn->setGeometry(0,60,80,50);
    logoutBtn->setStyleSheet("QPushButton{"
                                  "background-color:rgba(80, 100, 255,100%);"
                                  "color: white;border-radius: 10px;"
                                  "border: 0px groove gray;"
                                  "border-style: outset;"
                              "}" // 按键本色
                              "QPushButton:hover{"
                                  "background-color:white;"
                                  " color: black;"
                              "}"  // 鼠标停放时的色彩
                              "QPushButton:pressed{"
                                  "background-color:rgba(0, 255, 0, 50%);"
                                  " border-style: inset; "
                              "}" // 鼠标按下的色彩
                              );

    roundRobinBtn = new QPushButton(oneMenuWidget);
    roundRobinBtn->setText(tr("轮巡"));
    roundRobinBtn->setGeometry(0,120,80,50);
    roundRobinBtn->setStyleSheet("QPushButton{"
                                  "background-color:rgba(80, 100, 255,100%);"
                                  "color: white;border-radius: 10px;"
                                  "border: 0px groove gray;"
                                  "border-style: outset;"
                              "}" // 按键本色
                              "QPushButton:hover{"
                                  "background-color:white;"
                                  " color: black;"
                              "}"  // 鼠标停放时的色彩
                              "QPushButton:pressed{"
                                  "background-color:rgba(0, 255, 0, 50%);"
                                  " border-style: inset; "
                              "}" // 鼠标按下的色彩
                              );

    faultFuidanceBtn = new QPushButton(oneMenuWidget);
    faultFuidanceBtn->setText(tr("故障指导"));
    faultFuidanceBtn->setGeometry(0,180,80,50);
    faultFuidanceBtn->setStyleSheet("QPushButton{"
                                  "background-color:rgba(80, 100, 255,100%);"
                                  "color: white;border-radius: 10px;"
                                  "border: 0px groove gray;"
                                  "border-style: outset;"
                              "}" // 按键本色
                              "QPushButton:hover{"
                                  "background-color:white;"
                                  " color: black;"
                              "}"  // 鼠标停放时的色彩
                              "QPushButton:pressed{"
                                  "background-color:rgba(0, 255, 0, 50%);"
                                  " border-style: inset; "
                              "}" // 鼠标按下的色彩
                              );

    carBtn = new QPushButton(oneMenuWidget);
    carBtn->setText(tr("车厢"));
    carBtn->setGeometry(0,240,80,50);
    carBtn->setStyleSheet("QPushButton{"
                                  "background-color:rgba(80, 100, 255,100%);"
                                  "color: white;border-radius: 10px;"
                                  "border: 0px groove gray;"
                                  "border-style: outset;"
                              "}" // 按键本色
                              "QPushButton:hover{"
                                  "background-color:white;"
                                  " color: black;"
                              "}"  // 鼠标停放时的色彩
                              "QPushButton:pressed{"
                                  "background-color:rgba(0, 255, 0, 50%);"
                                  " border-style: inset; "
                              "}" // 鼠标按下的色彩
                              );
    //车厢显示隐藏事件
    //void(VedioMonitoringSystem::*oneMenuCarChange)(QPushButton) = &VedioMonitoringSystem::showHideCar;
    connect(carBtn,&QPushButton::clicked,this,&VedioMonitoringSystem::showHideCar);

    replayBtn = new QPushButton(oneMenuWidget);
    replayBtn->setText(tr("回放"));
    replayBtn->setGeometry(0,300,80,50);
    replayBtn->setStyleSheet("QPushButton{"
                                  "background-color:rgba(80, 100, 255,100%);"
                                  "color: white;border-radius: 10px;"
                                  "border: 0px groove gray;"
                                  "border-style: outset;"
                              "}" // 按键本色
                              "QPushButton:hover{"
                                  "background-color:white;"
                                  " color: black;"
                              "}"  // 鼠标停放时的色彩
                              "QPushButton:pressed{"
                                  "background-color:rgba(0, 255, 0, 50%);"
                                  " border-style: inset; "
                              "}" // 鼠标按下的色彩
                              );

    setBtn = new QPushButton(oneMenuWidget);
    setBtn->setText(tr("设置"));
    setBtn->setGeometry(0,360,80,50);
    setBtn->setStyleSheet("QPushButton{"
                              "background-color:rgba(80, 100, 255,100%);"
                              "color: white;border-radius: 10px;"
                              "border: 0px groove gray;"
                              "border-style: outset;"
                          "}" // 按键本色
                          "QPushButton:hover{"
                              "background-color:white;"
                              " color: black;"
                          "}"  // 鼠标停放时的色彩
                          "QPushButton:pressed{"
                              "background-color:rgba(0, 255, 0, 50%);"
                              " border-style: inset; "
                          "}" // 鼠标按下的色彩
                          );

    oneMenuWidget->setGeometry(10,globalHeightSize-10-50-430,80,420);
    oneMenuWidget->setVisible(false);
}

void VedioMonitoringSystem::showHideCar(){
    if(!carFlag){
        carFlag = 1;
        carBtn->setStyleSheet("QPushButton{"
                                "background-color:rgba(80, 100, 255,100%);"
                                "color: white;border-radius: 10px;"
                                "border: 0px groove gray;"
                                "border-style: outset;"
                            "}" // 按键本色
                            "QPushButton:hover{"
                                "background-color:white;"
                                " color: black;"
                            "}"  // 鼠标停放时的色彩
                            "QPushButton:pressed{"
                                "background-color:rgba(0, 255, 0, 50%);"
                                " border-style: inset; "
                            "}" // 鼠标按下的色彩
                            );
    }else{
        carFlag = 0;
        carBtn->setStyleSheet("QPushButton{"
                                "background-color:rgba(255, 191, 0,100%);"
                                "color: white;border-radius: 10px;"
                                "border: 0px groove gray;"
                                "border-style: outset;"
                            "}" // 按键本色
                            "QPushButton:hover{"
                                "background-color:white;"
                                " color: black;"
                            "}"  // 鼠标停放时的色彩
                            "QPushButton:pressed{"
                                "background-color:rgba(0, 255, 0, 50%);"
                                " border-style: inset; "
                            "}" // 鼠标按下的色彩
                            );
    }
    carBtnWidget->setVisible(!carBtnWidget->isVisible());
}


void VedioMonitoringSystem::showHideOneMenu(){
    oneMenuWidget->setVisible(!oneMenuWidget->isVisible());



}

void VedioMonitoringSystem::loadVeido(){
    LoginParamter ltltloginParamter = {};
    ltltloginParamter.ipAddress = const_cast<char*>("192.168.112.203");
    ltltloginParamter.port = 8000;
    ltltloginParamter.userName = const_cast<char*>("admin");
    ltltloginParamter.password = const_cast<char*>("Aa108852");
    long ltLoginId = ctvReal->LoginFoarmt(ltltloginParamter);
    StartPlayParamter ltltStartPlayParamter = {};
    ltltStartPlayParamter.loginId = ltLoginId;
    ltltStartPlayParamter.channelNumber = 1;
    ltltStartPlayParamter.streamNumber = 0;
    ltltStartPlayParamter.connectionWay = 5;
    ltltStartPlayParamter.HandleNumber = (HWND) ltltLabel->winId();
    DWORD ltReturnId = ctvReal->StartPlay(ltltStartPlayParamter);
    qDebug() << "打印:"<< ltReturnId;

    LoginParamter rtltloginParamter = {};
    rtltloginParamter.ipAddress = const_cast<char*>("192.168.112.204");
    rtltloginParamter.port = 8000;
    rtltloginParamter.userName = const_cast<char*>("admin");
    rtltloginParamter.password = const_cast<char*>("Aa108852");
    long rtUserId = ctvReal->LoginFoarmt(rtltloginParamter);
    StartPlayParamter rtltStartPlayParamter = {};
    rtltStartPlayParamter.loginId = rtUserId;
    rtltStartPlayParamter.channelNumber = 1;
    rtltStartPlayParamter.streamNumber = 0;
    rtltStartPlayParamter.connectionWay = 5;
    rtltStartPlayParamter.HandleNumber = (HWND) rtltLabel->winId();
    DWORD rtReturnId = ctvReal->StartPlay(rtltStartPlayParamter);
    qDebug() << "打印:"<< rtReturnId;

    LoginParamter rbloginParamter = {};
    rbloginParamter.ipAddress = const_cast<char*>("192.168.112.202");
    rbloginParamter.port = 8000;
    rbloginParamter.userName = const_cast<char*>("admin");
    rbloginParamter.password = const_cast<char*>("Aa108852");
    long rbUserId = ctvReal->LoginFoarmt(rbloginParamter);
    StartPlayParamter rbStartPlayParamter = {};
    rbStartPlayParamter.loginId = rbUserId;
    rbStartPlayParamter.channelNumber = 1;
    rbStartPlayParamter.streamNumber = 1;
    rbStartPlayParamter.connectionWay = 5;
    rbStartPlayParamter.HandleNumber = (HWND) rbLabel->winId();
    DWORD rbReturnId = ctvReal->StartPlay(rbStartPlayParamter);
    qDebug() << "打印:"<< rbReturnId;
}

void VedioMonitoringSystem::loadCameraUtils(){
    ctvReal = new CTVReal();
    InitializeCameraParamter initializeCameraParamter = {};
    initializeCameraParamter.reconnectionWaitTime = 300000;
    initializeCameraParamter.reconnectionNumber = 2;
    initializeCameraParamter.whetherToReconnection = false;
    initializeCameraParamter.reconnectionTimeInterval = 20000;
    ctvReal->initialize(initializeCameraParamter);
}

