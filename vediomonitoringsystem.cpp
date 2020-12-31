#include "vediomonitoringsystem.h"
#include "qwidget.h"
#include "qpushbutton.h"
#include "QHBoxLayout"
#include "QDebug"

VedioMonitoringSystem::VedioMonitoringSystem(QWidget *parent)
    : QWidget(parent)
{
    QFont font("ZYSong18030",12);
    font.setPixelSize(18);
    font.setBold(true);
    font.setFamily("Microsoft YaHei");
    this->setFont(font);
    resize(globalWidthSize,globalHeightSize);
    setWindowTitle("视频监控系统");
    layout = new QGridLayout;
    createFourView();
    //添加四个显示视频窗体
    layout->addWidget(leftTopWidget,0,0);
    layout->addWidget(leftButtomWidget,0,1);
    layout->addWidget(rightTopWidget,1,0);
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

}

VedioMonitoringSystem::~VedioMonitoringSystem()
{
}

void VedioMonitoringSystem::createFourView(){

    leftTopWidget = new QWidget;
    leftTopWidget->resize(quarterScreenWidth,quarterScreenHeight);
    ltlTopWidget = new QWidget;
    ltlTopWidget->resize(quarterScreenWidth/2,quarterScreenHeight/2);
    QPushButton *qPushButton1 = new QPushButton(ltlTopWidget);
    qPushButton1->setText("视频1");
    qPushButton1->resize(quarterScreenWidth/2,quarterScreenHeight/2);
    ltlButtomWidget = new QWidget;
    ltlButtomWidget->resize(quarterScreenWidth/2,quarterScreenHeight/2);
    QPushButton *qPushButton2 = new QPushButton(ltlButtomWidget);
    qPushButton2->setText("视频2");
    qPushButton2->resize(quarterScreenWidth/2,quarterScreenHeight/2);
    ltrTopWidget = new QWidget;
    ltrTopWidget->resize(quarterScreenWidth/2,quarterScreenHeight/2);
    QPushButton *qPushButton3 = new QPushButton(ltrTopWidget);
    qPushButton3->setText("视频3");
    qPushButton3->resize(quarterScreenWidth/2,quarterScreenHeight/2);
    ltrButtomWidget = new QWidget;
    ltrButtomWidget->resize(quarterScreenWidth/2,quarterScreenHeight/2);
    QPushButton *qPushButton4 = new QPushButton(ltrButtomWidget);
    qPushButton4->setText("视频4");
    qPushButton4->resize(quarterScreenWidth/2,quarterScreenHeight/2);
    ltLayout = new QGridLayout;
    ltLayout->addWidget(ltlTopWidget,0,0);
    ltLayout->addWidget(ltlButtomWidget,0,1);
    ltLayout->addWidget(ltrTopWidget,1,0);
    ltLayout->addWidget(ltrButtomWidget,1,1);
    ltLayout->setMargin(0);
    leftTopWidget->setLayout(ltLayout);

    leftButtomWidget = new QWidget;
    leftButtomWidget->resize(quarterScreenWidth,quarterScreenHeight);
    lblTopWidget = new QWidget(leftButtomWidget);
    lblTopWidget->resize(quarterScreenWidth/2,quarterScreenHeight/2);
    lblButtomWidget = new QWidget(leftButtomWidget);
    lblButtomWidget->resize(quarterScreenWidth/2,quarterScreenHeight/2);
    lbrTopWidget = new QWidget(leftButtomWidget);
    lbrTopWidget->resize(quarterScreenWidth/2,quarterScreenHeight/2);
    lbrButtomWidget = new QWidget(leftButtomWidget);
    lbrButtomWidget->resize(quarterScreenWidth/2,quarterScreenHeight/2);

    rightTopWidget = new QWidget;
    rightTopWidget->resize(quarterScreenWidth,quarterScreenHeight);
    rtlTopWidget = new QWidget(rightTopWidget);
    rtlTopWidget->resize(quarterScreenWidth/2,quarterScreenHeight/2);
    rtlButtomWidget = new QWidget(rightTopWidget);
    rtlButtomWidget->resize(quarterScreenWidth/2,quarterScreenHeight/2);
    rtrTopWidget = new QWidget(rightTopWidget);
    rtrTopWidget->resize(quarterScreenWidth/2,quarterScreenHeight/2);
    rtrButtomWidget = new QWidget(rightTopWidget);
    rtrButtomWidget->resize(quarterScreenWidth/2,quarterScreenHeight/2);

    rightButtomWidget = new QWidget;
    rightButtomWidget->resize(quarterScreenWidth,quarterScreenHeight);

}

void VedioMonitoringSystem::createCompartmentButtom(){
    carBtnWidget = new QWidget(this);    
    carHeadBtn = new QPushButton(carBtnWidget);
    carHeadBtn->setText("车头");
    carHeadBtn->setGeometry(0,0,128,50);
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

    oneCarBtn = new QPushButton(carBtnWidget);
    oneCarBtn->setText("一车厢");
    oneCarBtn->setGeometry(138,0,128,50);
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
    twoCarBtn->setGeometry(276,0,128,50);
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
    threeCarBtn->setGeometry(414,0,128,50);
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
    rear->setGeometry(552,0,128,50);
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

    carBtnWidget->setGeometry(globalWidthSize/4,globalHeightSize-10-50,680,50);
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

