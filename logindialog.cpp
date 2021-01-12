#include "logindialog.h"
#include "qpushbutton.h"

LoginDialog::LoginDialog(QWidget *parent) : QWidget(parent)
{
    this->setWindowTitle("登录弹框");
    this->resize(480,410);
    this->setStyleSheet("background-color: white");
    createUi();

}

void LoginDialog::createUi(){
    QFont loginLabelFont("SimHei",32);
    loginLabelFont.setPixelSize(32);
    loginLabelFont.setBold(true);
    loginLabelFont.setFamily("SimHei");
    loginLabel = new QLabel("登录",this);
    loginLabel->setFont(loginLabelFont);
    loginLabel->setGeometry(0,5,480,60);
    loginLabel->setAlignment(Qt::AlignCenter);
    loginLabel->setStyleSheet("border: 0px groove red;");
    enterPwdLabel = new QLabel("请输入密码：",this);
    QFont enterPwdLabelFont("SimHei",20);
    enterPwdLabelFont.setPixelSize(20);
    enterPwdLabel->setFont(enterPwdLabelFont);
    enterPwdLabel->setStyleSheet("border: 0px groove green");
    enterPwdLabel->setAlignment(Qt::AlignCenter);
    enterPwdLabel->setGeometry(0,65,140,40);
    inputBox = new QLineEdit(this);
    inputBox->setGeometry(140,65,330,40);
    inputBox->setFont(enterPwdLabelFont);
    QFont keyBoardFont("SimHei",26);
    keyBoardFont.setPixelSize(26);
    oneBtn = new QPushButton("1",this);
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
    twoBtn = new QPushButton("2",this);
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
    threeBtn = new QPushButton("3",this);
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
    fourBtn = new QPushButton("4",this);
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
    fiveBtn = new QPushButton("5",this);
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
    sixBtn = new QPushButton("6",this);
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
    servenBtn = new QPushButton("7",this);
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
    eightBtn = new QPushButton("8",this);
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
    nineBtn = new QPushButton("9",this);
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
    spaceBtn = new QPushButton("",this);
    spaceBtn->setFont(keyBoardFont);
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
    zeroBtn = new QPushButton("0",this);
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
    errorBtn = new QPushButton("<",this);
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
    determineBtn = new QPushButton("确定",this);
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
    cancelBtn = new QPushButton("取消",this);
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

}
