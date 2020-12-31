#ifndef LOGINDIALOG_H
#define LOGINDIALOG_H

#include <QWidget>
#include "qlabel.h"
#include "qpushbutton.h"
#include "qlineedit.h"
#include "QHBoxLayout"
#include "qgridlayout.h"

class LoginDialog : public QWidget
{
    Q_OBJECT
public:
    explicit LoginDialog(QWidget *parent = nullptr);
    void createUi();


private:
    /**
     * @brief loginLabel 登录标题
     * @brief enterPwdLabel 输入密码标签
     * @brief inputBox 输入框
     * @brief zeroBtn 0
     * @brief oneBtn 1
     * @brief twoBtn 2
     * @brief threeBtn 3
     * @brief fourBtn 4
     * @brief fiveBtn 5
     * @brief sixBtn 6
     * @brief servenBtn 7
     * @brief eightBtn 8
     * @brief nineBtn 9
     * @brief errorBtn 删除
     * @brief determineBtn 确定
     * @brief cancelBtn 取消
     */
    QLabel *loginLabel;
    QLabel *enterPwdLabel;
    QLineEdit *inputBox;
    QPushButton *zeroBtn;
    QPushButton *oneBtn;
    QPushButton *twoBtn;
    QPushButton *threeBtn;
    QPushButton *fourBtn;
    QPushButton *fiveBtn;
    QPushButton *sixBtn;
    QPushButton *servenBtn;
    QPushButton *eightBtn;
    QPushButton *nineBtn;
    QPushButton *errorBtn;
    QPushButton *determineBtn;
    QPushButton *cancelBtn;
    QPushButton *spaceBtn;

signals:

};

#endif // LOGINDIALOG_H
