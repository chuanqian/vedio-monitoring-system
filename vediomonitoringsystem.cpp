#include "vediomonitoringsystem.h"
#include "qwidget.h"
#include "qpushbutton.h"
#include "QHBoxLayout"
#include "QDebug"
#include "tvreal.h"
#include "qcombobox.h"
#include "logindialog.h"
#include "qdialog.h"
#include "qmessagebox.h"

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
    mainbutton = new QPushButton(this);
    mainbutton->setGeometry(10,globalHeightSize-10-50,80,50);
    mainbutton->setText("菜单");
    mainbutton->setStyleSheet("QPushButton{"
                                  "background-color:rgba(80, 100, 255,100%);"
                                  "color: white;border-radius: 10px;"
                                  "border: 0px groove gray;"
                                  "border-style: outset;"
                              "}" // 按键本色
                              "QPushButton:pressed{"
                                  "background-color:rgba(0, 255, 0, 50%);"
                                  " border-style: inset; "
                              "}" // 鼠标按下的色彩
                              );
    //创建一级菜单
    createOneMeun();
    //添加车厢按钮
    createCompartmentButtom();
    /**
     * @brief connect 菜单点击链接
     */
    connect(mainbutton,&QPushButton::clicked,this,&VedioMonitoringSystem::showHideOneMenu);

//    /**
//     * @brief loadCameraUtils 摄像头工具类
//     */
//    loadCameraUtils();
//    /**
//     * @brief loadVeido 加载视频
//     */
//    loadVeido();

}

VedioMonitoringSystem::~VedioMonitoringSystem()
{
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

void VedioMonitoringSystem::createCompartmentButtom(){
    carBtnWidget = new QWidget(this);
    carBtnWidget->setAttribute(Qt::WA_TranslucentBackground,true);
    carHeadBtn = new QPushButton(carBtnWidget);
    carHeadBtn->setText("车头");
    carHeadBtn->setGeometry(0,0,126,50);
    carHeadBtn->setStyleSheet("QPushButton{"
                                  "background-color:rgba(80, 100, 255,100%);"
                                  "color: white;border-radius: 10px;"
                                  "border: 0px groove gray;"
                                  "border-style: outset;"
                              "}" // 按键本色
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
    // 设置透明度
    oneMenuWidget->setAttribute(Qt::WA_TranslucentBackground, true);

    loginBtn = new QPushButton(oneMenuWidget);
    loginBtn->setText(tr("登录"));
    loginBtn->setGeometry(0,0,80,50);
    loginBtn->setStyleSheet("QPushButton{"
                                  "background-color:rgba(80, 100, 255,100%);"
                                  "color: white;border-radius: 10px;"
                                  "border: 0px groove gray;"
                                  "border-style: outset;"
                              "}" // 按键本色
                              "QPushButton:pressed{"
                                  "background-color:rgba(0, 255, 0, 50%);"
                                  " border-style: inset; "
                              "}" // 鼠标按下的色彩
                              );

    connect(loginBtn,&QPushButton::clicked,this,&VedioMonitoringSystem::showHideCar);

    logoutBtn = new QPushButton(oneMenuWidget);
    logoutBtn->setText(tr("注销"));
    logoutBtn->setGeometry(0,60,80,50);
    logoutBtn->setStyleSheet("QPushButton{"
                                  "background-color:rgba(80, 100, 255,100%);"
                                  "color: white;border-radius: 10px;"
                                  "border: 0px groove gray;"
                                  "border-style: outset;"
                              "}" // 按键本色
                              "QPushButton:pressed{"
                                  "background-color:rgba(0, 255, 0, 50%);"
                                  " border-style: inset; "
                              "}" // 鼠标按下的色彩
                              );
    connect(logoutBtn,&QPushButton::clicked,this,&VedioMonitoringSystem::showHideCar);

    roundRobinBtn = new QPushButton(oneMenuWidget);
    roundRobinBtn->setText(tr("轮巡"));
    roundRobinBtn->setGeometry(0,120,80,50);
    roundRobinBtn->setStyleSheet("QPushButton{"
                                  "background-color:rgba(80, 100, 255,100%);"
                                  "color: white;border-radius: 10px;"
                                  "border: 0px groove gray;"
                                  "border-style: outset;"
                              "}" // 按键本色
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
                              "QPushButton:pressed{"
                                  "background-color:rgba(0, 255, 0, 50%);"
                                  " border-style: inset; "
                              "}" // 鼠标按下的色彩
                              );

    setBtn = new QPushButton(oneMenuWidget);
    setBtn->setText(tr("设置"));
    setBtn->setChecked(true);
    setBtn->toggle();
    setBtn->setGeometry(0,360,80,50);
    setBtn->setStyleSheet("QPushButton{"
                              "background-color:rgba(80, 100, 255,100%);"
                              "color: white;border-radius: 10px;"
                              "border: 0px groove gray;"
                              "border-style: outset;"
                          "}" // 按键本色
                          "QPushButton:pressed{"
                              "background-color:rgba(0, 255, 0, 50%);"
                              " border-style: inset; "
                          "}" // 鼠标按下的色彩
                          );

    oneMenuWidget->setGeometry(10,globalHeightSize-10-50-430,80,420);
    oneMenuWidget->setVisible(false);
}

void VedioMonitoringSystem::showHideCar(){
    QPushButton* oneEventBtn = qobject_cast<QPushButton*>(sender());
    QString oneEventBtnText = oneEventBtn->text();
    if(oneEventBtnText=="车厢"){
        if(!carFlag){
            carFlag = 1;
            oneEventBtn->setStyleSheet("QPushButton{"
                                    "background-color:rgba(80, 100, 255,100%);"
                                    "color: white;border-radius: 10px;"
                                    "border: 0px groove gray;"
                                    "border-style: outset;"
                                "}" // 按键本色
                                "QPushButton:pressed{"
                                    "background-color:rgba(0, 255, 0, 50%);"
                                    " border-style: inset; "
                                "}" // 鼠标按下的色彩
                                );
        }else{
            carFlag = 0;
            oneEventBtn->setStyleSheet("QPushButton{"
                                    "background-color:rgba(255, 191, 0,100%);"
                                    "color: white;border-radius: 10px;"
                                    "border: 0px groove gray;"
                                    "border-style: outset;"
                                "}" // 按键本色
                                "QPushButton:pressed{"
                                    "background-color:rgba(0, 255, 0, 50%);"
                                    " border-style: inset; "
                                "}" // 鼠标按下的色彩
                                );
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
    }else if(oneEventBtnText == "注销"){
        if(loginBtn->text()=="登录"){
            QMessageBox::information(this,"登录提示","未登录");
        }else{
            oneEventBtn->setEnabled(false);
            loginBtn->setText("登录");
            loginBtn->setEnabled(true);
        }
    }

}


void VedioMonitoringSystem::showHideOneMenu(){
    oneMenuWidget->setVisible(!oneMenuWidget->isVisible());
}

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
    inputBox->setGeometry(140,65,330,40);
    inputBox->setFont(enterPwdLabelFont);
    QFont keyBoardFont("SimHei",26);
    keyBoardFont.setPixelSize(26);
    oneBtn = new QPushButton("1",loginDialog);
    oneBtn->setFont(keyBoardFont);
    oneBtn->setGeometry(10,125,152,50);
    oneBtn->setStyleSheet("QPushButton{"
                          "background-color:rgba(255,255,255,100%);"
                          "color: black;border-radius: 10px;"
                          "border: 1px groove black;"
                          "border-style: outset;"
                      "}" // 按键本色
                      "QPushButton:pressed{"
                          "background-color:rgba(0, 64, 255, 100%);"
                          " border-style: inset; "
                      "}" // 鼠标按下的色彩
                      );
    connect(oneBtn,&QPushButton::clicked,this,&VedioMonitoringSystem::getInputPwd);

    twoBtn = new QPushButton("2",loginDialog);
    twoBtn->setFont(keyBoardFont);
    twoBtn->setGeometry(164,125,152,50);
    twoBtn->setStyleSheet("QPushButton{"
                          "background-color:rgba(255,255,255,100%);"
                          "color: black;border-radius: 10px;"
                          "border: 1px groove black;"
                          "border-style: outset;"
                      "}" // 按键本色
                      "QPushButton:pressed{"
                          "background-color:rgba(0, 64, 255, 100%);"
                          " border-style: inset; "
                      "}" // 鼠标按下的色彩
                      );
    connect(twoBtn,&QPushButton::clicked,this,&VedioMonitoringSystem::getInputPwd);

    threeBtn = new QPushButton("3",loginDialog);
    threeBtn->setFont(keyBoardFont);
    threeBtn->setGeometry(318,125,152,50);
    threeBtn->setStyleSheet("QPushButton{"
                          "background-color:rgba(255,255,255,100%);"
                          "color: black;border-radius: 10px;"
                          "border: 1px groove black;"
                          "border-style: outset;"
                      "}" // 按键本色
                      "QPushButton:pressed{"
                          "background-color:rgba(0, 64, 255, 100%);"
                          " border-style: inset; "
                      "}" // 鼠标按下的色彩
                      );
    connect(threeBtn,&QPushButton::clicked,this,&VedioMonitoringSystem::getInputPwd);

    fourBtn = new QPushButton("4",loginDialog);
    fourBtn->setFont(keyBoardFont);
    fourBtn->setGeometry(10,177,152,50);
    fourBtn->setStyleSheet("QPushButton{"
                          "background-color:rgba(255,255,255,100%);"
                          "color: black;border-radius: 10px;"
                          "border: 1px groove black;"
                          "border-style: outset;"
                      "}" // 按键本色
                      "QPushButton:pressed{"
                          "background-color:rgba(0, 64, 255, 100%);"
                          " border-style: inset; "
                      "}" // 鼠标按下的色彩
                      );
    connect(fourBtn,&QPushButton::clicked,this,&VedioMonitoringSystem::getInputPwd);

    fiveBtn = new QPushButton("5",loginDialog);
    fiveBtn->setFont(keyBoardFont);
    fiveBtn->setGeometry(164,177,152,50);
    fiveBtn->setStyleSheet("QPushButton{"
                          "background-color:rgba(255,255,255,100%);"
                          "color: black;border-radius: 10px;"
                          "border: 1px groove black;"
                          "border-style: outset;"
                      "}" // 按键本色
                      "QPushButton:pressed{"
                          "background-color:rgba(0, 64, 255, 100%);"
                          " border-style: inset; "
                      "}" // 鼠标按下的色彩
                      );
    connect(fiveBtn,&QPushButton::clicked,this,&VedioMonitoringSystem::getInputPwd);

    sixBtn = new QPushButton("6",loginDialog);
    sixBtn->setFont(keyBoardFont);
    sixBtn->setGeometry(318,177,152,50);
    sixBtn->setStyleSheet("QPushButton{"
                          "background-color:rgba(255,255,255,100%);"
                          "color: black;border-radius: 10px;"
                          "border: 1px groove black;"
                          "border-style: outset;"
                      "}" // 按键本色
                      "QPushButton:pressed{"
                          "background-color:rgba(0, 64, 255, 100%);"
                          " border-style: inset; "
                      "}" // 鼠标按下的色彩
                      );
    connect(sixBtn,&QPushButton::clicked,this,&VedioMonitoringSystem::getInputPwd);

    servenBtn = new QPushButton("7",loginDialog);
    servenBtn->setFont(keyBoardFont);
    servenBtn->setGeometry(10,229,152,50);
    servenBtn->setStyleSheet("QPushButton{"
                          "background-color:rgba(255,255,255,100%);"
                          "color: black;border-radius: 10px;"
                          "border: 1px groove black;"
                          "border-style: outset;"
                      "}" // 按键本色
                      "QPushButton:pressed{"
                          "background-color:rgba(0, 64, 255, 100%);"
                          " border-style: inset; "
                      "}" // 鼠标按下的色彩
                      );
    connect(servenBtn,&QPushButton::clicked,this,&VedioMonitoringSystem::getInputPwd);

    eightBtn = new QPushButton("8",loginDialog);
    eightBtn->setFont(keyBoardFont);
    eightBtn->setGeometry(164,229,152,50);
    eightBtn->setStyleSheet("QPushButton{"
                          "background-color:rgba(255,255,255,100%);"
                          "color: black;border-radius: 10px;"
                          "border: 1px groove black;"
                          "border-style: outset;"
                      "}" // 按键本色
                      "QPushButton:pressed{"
                          "background-color:rgba(0, 64, 255, 100%);"
                          " border-style: inset; "
                      "}" // 鼠标按下的色彩
                      );
    connect(eightBtn,&QPushButton::clicked,this,&VedioMonitoringSystem::getInputPwd);

    nineBtn = new QPushButton("9",loginDialog);
    nineBtn->setFont(keyBoardFont);
    nineBtn->setGeometry(318,229,152,50);
    nineBtn->setStyleSheet("QPushButton{"
                          "background-color:rgba(255,255,255,100%);"
                          "color: black;border-radius: 10px;"
                          "border: 1px groove black;"
                          "border-style: outset;"
                      "}" // 按键本色
                      "QPushButton:pressed{"
                          "background-color:rgba(0, 64, 255, 100%);"
                          " border-style: inset; "
                      "}" // 鼠标按下的色彩
                      );
    connect(nineBtn,&QPushButton::clicked,this,&VedioMonitoringSystem::getInputPwd);

    spaceBtn = new QPushButton("",loginDialog);
    spaceBtn->setFont(keyBoardFont);
    spaceBtn->setEnabled(false);
    spaceBtn->setGeometry(10,281,152,50);
    spaceBtn->setStyleSheet("QPushButton{"
                          "background-color:rgba(255,255,255,100%);"
                          "color: black;border-radius: 10px;"
                          "border: 1px groove black;"
                          "border-style: outset;"
                      "}" // 按键本色
                      "QPushButton:pressed{"
                          "background-color:rgba(0, 64, 255, 100%);"
                          " border-style: inset; "
                      "}" // 鼠标按下的色彩
                      );
    zeroBtn = new QPushButton("0",loginDialog);
    zeroBtn->setFont(keyBoardFont);
    zeroBtn->setGeometry(164,281,152,50);
    zeroBtn->setStyleSheet("QPushButton{"
                          "background-color:rgba(255,255,255,100%);"
                          "color: black;border-radius: 10px;"
                          "border: 1px groove black;"
                          "border-style: outset;"
                      "}" // 按键本色
                      "QPushButton:pressed{"
                          "background-color:rgba(0, 64, 255, 100%);"
                          " border-style: inset; "
                      "}" // 鼠标按下的色彩
                      );
    connect(zeroBtn,&QPushButton::clicked,this,&VedioMonitoringSystem::getInputPwd);

    errorBtn = new QPushButton("<",loginDialog);
    errorBtn->setFont(keyBoardFont);
    errorBtn->setGeometry(318,281,152,50);
    errorBtn->setStyleSheet("QPushButton{"
                          "background-color:rgba(255,255,255,100%);"
                          "color: black;border-radius: 10px;"
                          "border: 1px groove black;"
                          "border-style: outset;"
                      "}" // 按键本色
                      "QPushButton:pressed{"
                          "background-color:rgba(0, 64, 255, 100%);"
                          " border-style: inset; "
                      "}" // 鼠标按下的色彩
                      );
    connect(errorBtn,&QPushButton::clicked,this,&VedioMonitoringSystem::getInputPwd);

    determineBtn = new QPushButton("确定",loginDialog);
    determineBtn->setFont(enterPwdLabelFont);
    determineBtn->setGeometry(30,345,160,50);
    determineBtn->setStyleSheet("QPushButton{"
                          "background-color:rgba(255,255,255,100%);"
                          "color: black;border-radius: 10px;"
                          "border: 1px groove black;"
                          "border-style: outset;"
                      "}" // 按键本色
                      "QPushButton:pressed{"
                          "background-color:rgba(0, 64, 255, 100%);"
                          " border-style: inset; "
                      "}" // 鼠标按下的色彩
                      );
    connect(determineBtn,&QPushButton::clicked,this,&VedioMonitoringSystem::determineLoginEvent);

    cancelBtn = new QPushButton("取消",loginDialog);
    cancelBtn->setFont(enterPwdLabelFont);
    cancelBtn->setGeometry(290,345,160,50);
    cancelBtn->setStyleSheet("QPushButton{"
                          "background-color:rgba(255,255,255,100%);"
                          "color: black;border-radius: 10px;"
                          "border: 1px groove black;"
                          "border-style: outset;"
                      "}" // 按键本色
                      "QPushButton:pressed{"
                          "background-color:rgba(0, 64, 255, 100%);"
                          " border-style: inset; "
                      "}" // 鼠标按下的色彩
                      );
    connect(cancelBtn,&QPushButton::clicked,this,&VedioMonitoringSystem::cancalLoginEvent);

}

void VedioMonitoringSystem::getInputPwd(){
    QPushButton* loginDialogBtn = qobject_cast<QPushButton*>(sender());
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
        loginBtn->setEnabled(false);
        logoutBtn->setEnabled(true);
        QMessageBox::information(this,"登录成功","登录成功");
    }else{
        QMessageBox::critical(this,"密码错误！","登录失败");
    }
    delete(loginDialog);
}

void VedioMonitoringSystem::loadVeido(){
    LoginParamter ltloginParamter = {};
    ltloginParamter.ipAddress = const_cast<char*>("192.168.112.202");
    ltloginParamter.port = 8000;
    ltloginParamter.userName = const_cast<char*>("admin");
    ltloginParamter.password = const_cast<char*>("Aa108852");
    long ltLoginId = ctvReal->LoginFoarmt(ltloginParamter);
    StartPlayParamter ltStartPlayParamter = {};
    ltStartPlayParamter.loginId = ltLoginId;
    ltStartPlayParamter.channelNumber = 1;
    ltStartPlayParamter.streamNumber = 1;
    ltStartPlayParamter.connectionWay = 5;
    ltStartPlayParamter.HandleNumber = (HWND) ltLabel->winId();
    DWORD ltReturnId = ctvReal->StartPlay(ltStartPlayParamter);
    qDebug() << "打印:"<< ltReturnId;

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
    qDebug() << "打印:"<< rtReturnId;

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
    qDebug() << "打印:"<< lbReturnId;



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

