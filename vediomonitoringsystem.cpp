#include "vediomonitoringsystem.h"
#include "qwidget.h"
#include "qpushbutton.h"
#include "QHBoxLayout"
#include "QDebug"
#include "tvreal.h"
#include "qcombobox.h"
#include "qdialog.h"
#include "qmessagebox.h"
#include "qapplication.h"
#include "qlineedit.h"

VedioMonitoringSystem::VedioMonitoringSystem(QWidget *parent)
    : QWidget(parent)
{

    resize(globalWidthSize,globalHeightSize);
    setWindowTitle("视频监控系统");
    layout = new QGridLayout;
    createFourView();
    //添加四个显示视频窗体
    layout->addWidget(ltLabel,0,0);
    layout->addWidget(rtLabel,1,0);
    layout->addWidget(lbLabel,0,1);
    layout->addWidget(rbLabel,1,1);
    layout->setMargin(0);
    this->setLayout(layout);
    //初始化主菜单按钮
    mainbutton = new SystemPushButton(this);
    mainbutton->setGeometry(10,globalHeightSize-10-50,80,50);
    mainbutton->setText("菜单");
    //创建一级菜单
    createOneMeun();
    //添加车厢按钮
    createCompartmentButtom();
    /**
     * @brief connect 菜单点击链接
     */
    connect(mainbutton,&QPushButton::clicked,this,&VedioMonitoringSystem::showHideOneMenu);

    /**
     * @brief loadCameraUtils 摄像头工具类
     */
    loadCameraUtils();
    /**
     * @brief loadVeido 加载视频
     */
    loadVeido();

}

VedioMonitoringSystem::~VedioMonitoringSystem(){
}

void VedioMonitoringSystem::showHideCar(){
    SystemPushButton* oneEventBtn = qobject_cast<SystemPushButton*>(sender());
    QString oneEventBtnText = oneEventBtn->text();
    if(oneEventBtnText=="车厢"){
        if(!carFlag){
            carFlag = 1;
        }else{
            carFlag = 0;
        }
        carBtnWidget->setVisible(!carBtnWidget->isVisible());
    }else if(oneEventBtnText=="登录"){
        if(!loginBtnFlag){
            loginDialog = new QDialog(this);
            loginDialog->setWindowTitle("登录");
            loginDialog->resize(480,410);
            createUi();
            loginDialog->setAttribute(Qt::WA_DeleteOnClose);
            loginDialog->exec();
        }
    }else if(oneEventBtnText=="已登录"){
        QMessageBox::information(this,"登录提示","已登录!");
    }else if(oneEventBtnText == "注销"){
        if(loginBtn->text()=="登录"){
            QMessageBox::information(this,"登录提示","未登录");
        }else{
             if(QMessageBox::Ok == QMessageBox::question(this,"是否注销","是否确认注销",QMessageBox::Ok | QMessageBox::No,QMessageBox::Ok)){
                 loginBtnFlag = false;
                 delete(twoMenuWidget);
                 loginBtn->setText("登录");
             }
        }
    }else if(oneEventBtnText=="退出"){
        if(QMessageBox::Ok == QMessageBox::question(this,"是否退出","确认退出系统？",QMessageBox::Ok | QMessageBox::No,QMessageBox::Ok)){

        }
    }

}

void VedioMonitoringSystem::getInputPwd(){
    LoginButton* loginDialogBtn = qobject_cast<LoginButton*>(sender());
    QString strPwd = loginDialogBtn->text();
    if(strPwd != " "){
        setInputPwd(strPwd);
    }
}

void VedioMonitoringSystem::setInputPwd(QString strPwd){
    try {
        QString inputText = inputBox->text();
        if(inputText != nullptr){
            if(strPwd!="<"){
                inputBox->setText(inputText+strPwd);
            }else if(strPwd == "<"){
                inputBox->setText(inputText.mid(0,inputText.length()-1));
            }
        }else{
            inputBox->setText(inputText+strPwd);
        }
    } catch (EXCEPTION_RECORD *ec) {
        qDebug() << "出现异常";
    }
}

void VedioMonitoringSystem::cancalLoginEvent(){
    delete(loginDialog);
}

void VedioMonitoringSystem::determineLoginEvent(){
    if(inputBox->text() == "123456"){
        loginBtn->setText("已登录");
        loginBtnFlag = true;
        createTwoMenu();
        twoMenuWidget->setVisible(!twoMenuWidget->isVisible());
        QMessageBox::information(this,"登录成功","登录成功");
        delete(loginDialog);
    }else{
        QMessageBox::critical(this,"密码错误！","登录失败");
    }
}

void VedioMonitoringSystem::showHideOneMenu(){
    if(loginBtnFlag){
        twoMenuWidget->setVisible(!twoMenuWidget->isVisible());
    }
    oneMenuWidget->setVisible(!oneMenuWidget->isVisible());
}

void VedioMonitoringSystem::loadVeido(){
    LoginParamter ltloginParamter = {};
    ltloginParamter.ipAddress = const_cast<char*>("192.168.112.202");
    ltloginParamter.port = 8000;
    ltloginParamter.userName = const_cast<char*>("admin");
    ltloginParamter.password = const_cast<char*>("Aa108852");
    long ltLoginId = ctvReal->LoginFoarmt(ltloginParamter);
    if(ltLoginId < 0){
        ltLabel->setText("播放失败");
        ltLabel->setStyleSheet("QLabel{background-color: rgb(200,101,102)}");
        rtLabel->setText("播放失败");
        rtLabel->setStyleSheet("QLabel{background-color: rgb(200,101,102)}");
        lbLabel->setText("播放失败");
        lbLabel->setStyleSheet("QLabel{background-color: rgb(200,101,102)}");
        rbLabel->setText("播放失败");
        rbLabel->setStyleSheet("QLabel{background-color: rgb(200,101,102)}");
    }else{
        StartPlayParamter ltStartPlayParamter = {};
        ltStartPlayParamter.loginId = ltLoginId;
        ltStartPlayParamter.channelNumber = 1;
        ltStartPlayParamter.streamNumber = 1;
        ltStartPlayParamter.connectionWay = 5;
        ltStartPlayParamter.HandleNumber = (HWND) ltLabel->winId();
        DWORD ltReturnId = ctvReal->StartPlay(ltStartPlayParamter);
        if(ltReturnId < 0){
            ltLabel->setText("播放失败");
            ltLabel->setStyleSheet("QLabel{background-color: rgb(200,101,102)}");
        }

        LoginParamter rtloginParamter = {};
        rtloginParamter.ipAddress = const_cast<char*>("192.168.112.203");
        rtloginParamter.port = 8000;
        rtloginParamter.userName = const_cast<char*>("admin");
        rtloginParamter.password = const_cast<char*>("Aa108852");
        long rtUserId = ctvReal->LoginFoarmt(rtloginParamter);
        StartPlayParamter rtStartPlayParamter = {};
        rtStartPlayParamter.loginId = rtUserId;
        rtStartPlayParamter.channelNumber = 1;
        rtStartPlayParamter.streamNumber = 0;
        rtStartPlayParamter.connectionWay = 5;
        rtStartPlayParamter.HandleNumber = (HWND) rtLabel->winId();
        DWORD rtReturnId = ctvReal->StartPlay(rtStartPlayParamter);
        if(rtReturnId < 0){
            rtLabel->setText("播放失败");
            rtLabel->setStyleSheet("QLabel{background-color: rgb(200,101,102)}");
        }

        LoginParamter lbloginParamter = {};
        lbloginParamter.ipAddress = const_cast<char*>("192.168.112.204");
        lbloginParamter.port = 8000;
        lbloginParamter.userName = const_cast<char*>("admin");
        lbloginParamter.password = const_cast<char*>("Aa108852");
        long lbLoginId = ctvReal->LoginFoarmt(lbloginParamter);
        StartPlayParamter lbStartPlayParamter = {};
        lbStartPlayParamter.loginId = lbLoginId;
        lbStartPlayParamter.channelNumber = 1;
        lbStartPlayParamter.streamNumber = 0;
        lbStartPlayParamter.connectionWay = 5;
        lbStartPlayParamter.HandleNumber = (HWND) lbLabel->winId();
        DWORD lbReturnId = ctvReal->StartPlay(lbStartPlayParamter);
        if(lbReturnId < 0){
            lbLabel->setText("播放失败");
            lbLabel->setStyleSheet("QLabel{background-color: rgb(200,101,102)}");
        }



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
        if(rbReturnId < 0){
            rbLabel->setText("播放失败");
            rbLabel->setStyleSheet("QLabel{background-color: rgb(200,101,102)}");
        }
    }
}

void VedioMonitoringSystem::loadCameraUtils(){
    ctvReal = new CTVReal();
    InitializeCameraParamter initializeCameraParamter = {};
    initializeCameraParamter.reconnectionWaitTime = 2000;
    initializeCameraParamter.reconnectionNumber = 1;
    initializeCameraParamter.whetherToReconnection = true;
    initializeCameraParamter.reconnectionTimeInterval = 10000;
    ctvReal->initialize(initializeCameraParamter);
}

void VedioMonitoringSystem::createFourView(){


    ltLabel = new QLabel;
    ltLabel->resize(quarterScreenWidth,quarterScreenHeight);
    ltLabel->setStyleSheet("border: 1px groove green;");
    rtLabel = new QLabel;
    rtLabel->resize(quarterScreenWidth,quarterScreenHeight);
    rtLabel->setStyleSheet("border: 1px groove green;");
    lbLabel = new QLabel;
    lbLabel->resize(quarterScreenWidth,quarterScreenHeight);
    lbLabel->setStyleSheet("border: 1px groove green;");
    rbLabel = new QLabel;
    lbLabel->resize(quarterScreenWidth,quarterScreenHeight);
    rbLabel->setStyleSheet("border: 1px groove blue;");
}

/**
 * @brief VedioMonitoringSystem::createCompartmentButtom 创建车厢按钮视图
 */
void VedioMonitoringSystem::createCompartmentButtom(){
    carBtnWidget = new QWidget(this);
    carBtnWidget->setAttribute(Qt::WA_TranslucentBackground,true);
    carHeadBtn = new SystemPushButton(carBtnWidget);
    carHeadBtn->setText("车头");
    carHeadBtn->setGeometry(0,0,126,50);


    oneCarBtn = new SystemPushButton(carBtnWidget);
    oneCarBtn->setText("一车厢");
    oneCarBtn->setGeometry(128,0,126,50);


    twoCarBtn = new SystemPushButton(carBtnWidget);
    twoCarBtn->setText("二车厢");
    twoCarBtn->setGeometry(256,0,126,50);


    threeCarBtn = new SystemPushButton(carBtnWidget);
    threeCarBtn->setText("三车厢");
    threeCarBtn->setGeometry(384,0,126,50);


    rear = new SystemPushButton(carBtnWidget);
    rear->setText("车尾");
    rear->setGeometry(512,0,126,50);


    carBtnWidget->setGeometry(192,globalHeightSize-10-50,640,50);
    carBtnWidget->setVisible(false);
}
/**
 * @brief VedioMonitoringSystem::createOneMeun 创建一级菜单
 */
void VedioMonitoringSystem::createOneMeun(){
    oneMenuWidget = new QWidget(this);
    // 设置透明度
    oneMenuWidget->setAttribute(Qt::WA_TranslucentBackground, true);

    loginBtn = new SystemPushButton(oneMenuWidget);
    loginBtn->setText(tr("登录"));
    loginBtn->setGeometry(0,0,80,50);
    connect(loginBtn,&QPushButton::clicked,this,&VedioMonitoringSystem::showHideCar);

    roundRobinBtn = new SystemPushButton(oneMenuWidget);
    roundRobinBtn->setText(tr("轮询"));
    roundRobinBtn->setGeometry(0,60,80,50);

    carBtn = new SystemPushButton(oneMenuWidget);
    carBtn->setText(tr("车厢"));
    carBtn->setGeometry(0,120,80,50);
    connect(carBtn,&QPushButton::clicked,this,&VedioMonitoringSystem::showHideCar);

    replayBtn = new SystemPushButton(oneMenuWidget);
    replayBtn->setText(tr("回放"));
    replayBtn->setGeometry(0,180,80,50);

    oneMenuWidget->setGeometry(10,globalHeightSize-10-50-240,80,240);
    oneMenuWidget->setVisible(false);
}

/**
 * @brief VedioMonitoringSystem::createTwoMenu 创建二级菜单
 */
void VedioMonitoringSystem::createTwoMenu(){
    twoMenuWidget = new QWidget(this);
    // 设置透明度
    twoMenuWidget->setAttribute(Qt::WA_TranslucentBackground, true);
    systemStatus = new SystemPushButton(twoMenuWidget);
    systemStatus->setText("系统状态");
    systemStatus->setGeometry(0,0,80,50);

    hardDriveCapacity = new SystemPushButton(twoMenuWidget);
    hardDriveCapacity->setText("硬盘容量");
    hardDriveCapacity->setGeometry(0,60,80,50);

    carHeadOrReal = new SystemPushButton(twoMenuWidget);
    carHeadOrReal->setText("车头/车尾");
    carHeadOrReal->setGeometry(0,120,80,50);

    faultFuidanceBtn = new SystemPushButton(twoMenuWidget);
    faultFuidanceBtn->setText(tr("故障指导"));
    faultFuidanceBtn->setGeometry(0,180,80,50);

    setBtn = new SystemPushButton(twoMenuWidget);
    setBtn->setText(tr("设置"));
    setBtn->setGeometry(0,240,80,50);

    quit = new SystemPushButton(twoMenuWidget);
    quit->setText("退出");
    quit->setGeometry(0,300,80,50);
    connect(quit,&QPushButton::clicked,this,&VedioMonitoringSystem::close);

    logoutBtn = new SystemPushButton(twoMenuWidget);
    logoutBtn->setText(tr("注销"));
    logoutBtn->setGeometry(0,360,80,50);
    connect(logoutBtn,&QPushButton::clicked,this,&VedioMonitoringSystem::showHideCar);

    twoMenuWidget->setGeometry(10,globalHeightSize-10-50-240-420, 80, 420);
    twoMenuWidget->setVisible(false);
}

/**
 * @brief VedioMonitoringSystem::createUi 创建登录框
 */
void VedioMonitoringSystem::createUi(){
    QFont loginLabelFont("SimHei",32);
    loginLabelFont.setPixelSize(32);
    loginLabelFont.setBold(true);
    loginLabelFont.setFamily("SimHei");
    loginLabel = new QLabel("登录",loginDialog);
    loginLabel->setFont(loginLabelFont);
    loginLabel->setGeometry(0,5,480,60);
    loginLabel->setAlignment(Qt::AlignCenter);
    loginLabel->setStyleSheet("border: 0px groove red;");
    enterPwdLabel = new QLabel("请输入密码：",loginDialog);
    QFont enterPwdLabelFont("SimHei",20);
    enterPwdLabelFont.setPixelSize(20);
    enterPwdLabel->setFont(enterPwdLabelFont);
    enterPwdLabel->setStyleSheet("border: 0px groove green");
    enterPwdLabel->setAlignment(Qt::AlignCenter);
    enterPwdLabel->setGeometry(0,65,140,40);
    inputBox = new QLineEdit(loginDialog);
    inputBox->setEchoMode(QLineEdit::Password);
    inputBox->setMaxLength(6);
    inputBox->setGeometry(140,65,330,40);
    inputBox->setFont(enterPwdLabelFont);
    QFont keyBoardFont("SimHei",26);
    keyBoardFont.setPixelSize(26);


    oneBtn = new LoginButton;
    oneBtn->setText("1");
    oneBtn->setParent(loginDialog);
    oneBtn->setFont(keyBoardFont);
    oneBtn->setGeometry(10,125,152,50);
    connect(oneBtn,&QPushButton::clicked,this,&VedioMonitoringSystem::getInputPwd);

    twoBtn = new LoginButton;
    twoBtn->setText("2");
    twoBtn->setParent(loginDialog);
    twoBtn->setFont(keyBoardFont);
    twoBtn->setGeometry(164,125,152,50);
    connect(twoBtn,&QPushButton::clicked,this,&VedioMonitoringSystem::getInputPwd);

    threeBtn = new LoginButton;
    threeBtn->setText("3");
    threeBtn->setParent(loginDialog);
    threeBtn->setFont(keyBoardFont);
    threeBtn->setGeometry(318,125,152,50);
    connect(threeBtn,&QPushButton::clicked,this,&VedioMonitoringSystem::getInputPwd);

    fourBtn = new LoginButton;
    fourBtn->setText("4");
    fourBtn->setParent(loginDialog);
    fourBtn->setFont(keyBoardFont);
    fourBtn->setGeometry(10,177,152,50);
    connect(fourBtn,&QPushButton::clicked,this,&VedioMonitoringSystem::getInputPwd);

    fiveBtn = new LoginButton;
    fiveBtn->setText("5");
    fiveBtn->setParent(loginDialog);
    fiveBtn->setFont(keyBoardFont);
    fiveBtn->setGeometry(164,177,152,50);
    connect(fiveBtn,&QPushButton::clicked,this,&VedioMonitoringSystem::getInputPwd);

    sixBtn = new LoginButton;
    sixBtn->setText("6");
    sixBtn->setParent(loginDialog);
    sixBtn->setFont(keyBoardFont);
    sixBtn->setGeometry(318,177,152,50);
    connect(sixBtn,&QPushButton::clicked,this,&VedioMonitoringSystem::getInputPwd);

    servenBtn = new LoginButton;
    servenBtn->setText("7");
    servenBtn->setParent(loginDialog);
    servenBtn->setFont(keyBoardFont);
    servenBtn->setGeometry(10,229,152,50);
    connect(servenBtn,&QPushButton::clicked,this,&VedioMonitoringSystem::getInputPwd);

    eightBtn = new LoginButton;
    eightBtn->setText("8");
    eightBtn->setParent(loginDialog);
    eightBtn->setFont(keyBoardFont);
    eightBtn->setGeometry(164,229,152,50);
    connect(eightBtn,&QPushButton::clicked,this,&VedioMonitoringSystem::getInputPwd);

    nineBtn = new LoginButton;
    nineBtn->setText("9");
    nineBtn->setParent(loginDialog);
    nineBtn->setFont(keyBoardFont);
    nineBtn->setGeometry(318,229,152,50);
    connect(nineBtn,&QPushButton::clicked,this,&VedioMonitoringSystem::getInputPwd);

    spaceBtn = new LoginButton;
    spaceBtn->setText(" ");
    spaceBtn->setParent(loginDialog);
    spaceBtn->setFont(keyBoardFont);
    spaceBtn->setEnabled(false);
    spaceBtn->setGeometry(10,281,152,50);

    zeroBtn = new LoginButton;
    zeroBtn->setText("0");
    zeroBtn->setParent(loginDialog);
    zeroBtn->setFont(keyBoardFont);
    zeroBtn->setGeometry(164,281,152,50);
    connect(zeroBtn,&QPushButton::clicked,this,&VedioMonitoringSystem::getInputPwd);

    errorBtn = new LoginButton;
    errorBtn->setText("<");
    errorBtn->setParent(loginDialog);
    errorBtn->setFont(keyBoardFont);
    errorBtn->setGeometry(318,281,152,50);
    connect(errorBtn,&QPushButton::clicked,this,&VedioMonitoringSystem::getInputPwd);

    determineBtn = new SystemPushButton;
    determineBtn->setText("确定");
    determineBtn->setParent(loginDialog);
    determineBtn->setFont(enterPwdLabelFont);
    determineBtn->setGeometry(30,345,160,50);
    connect(determineBtn,&QPushButton::clicked,this,&VedioMonitoringSystem::determineLoginEvent);

    cancelBtn = new SystemPushButton;
    cancelBtn->setText("取消");
    cancelBtn->setParent(loginDialog);
    cancelBtn->setFont(enterPwdLabelFont);
    cancelBtn->setGeometry(290,345,160,50);
    connect(cancelBtn,&QPushButton::clicked,this,&VedioMonitoringSystem::cancalLoginEvent);

}

