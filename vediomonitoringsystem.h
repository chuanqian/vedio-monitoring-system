#ifndef VEDIOMONITORINGSYSTEM_H
#define VEDIOMONITORINGSYSTEM_H

#include <QWidget>
#include <QGridLayout>
#include <QHBoxLayout>
#include <HCNetSDK.h>
#include <plaympeg4.h>
#include "tvreal.h"
#include "qlabel.h"
#include "qopenglwidget.h"
#include "qcombobox.h"
#include "systempushbutton.h"
#include "loginbutton.h"

class VedioMonitoringSystem : public QWidget
{
    Q_OBJECT

public:
    VedioMonitoringSystem(QWidget *parent = nullptr);
    ~VedioMonitoringSystem();
    /**
     * @brief createFourView 创建四个大窗口显示视频和16个小视频窗口
     */
    void createFourView();

    /**
     * @brief createCompartmentButtom 创建车厢按钮函数
     */
    void createCompartmentButtom();
    /**
     * @brief createOneMeun 创建一级菜单
     */
    void createOneMeun();
    /**
     * @brief createUi 创建登录非模态框
     */
    void createUi();

    /**
     * @brief loadVeido 加载视频
     */
    void loadVeido();

    /**
     * @brief loadCameraUtils 摄像头获取工具类
     */
    void loadCameraUtils();

    /**
     * @brief setInputPwd 设置密码
     * @param strPwd 输入字符
     */
    void setInputPwd(QString strPwd);

    /**
     * @brief createTwoMenu 创建二级菜单
     */
    void createTwoMenu();

public slots:
    /**
     * @brief showHideCar 车厢显示和隐藏槽
     */
    void showHideCar();
    /**
     * @brief showHideOneMenu 一级菜单显示隐藏槽
     */
    void showHideOneMenu();
    /**
     * @brief getInputPwd 获取数字键盘的密码
     */
    void getInputPwd();

    /**
     * @brief cancalLoginEvent 登录点击取消事件
     */
    void cancalLoginEvent();

    /**
     * @brief determineLoginEvent 登录点击确认事件
     */
    void determineLoginEvent();


private:
    /**
     * @brief loginBtnFlag 登录按钮标志
     * @brief loginFlag 登录标志
     */
    bool loginBtnFlag = false;
    bool loginFlag = false;
    /**
     * @brief ctvReal 摄像头工具类对象
     */
    CTVReal *ctvReal;
    /**
     * @brief carFlag   车厢按钮的点击控制参数
     * @brief carBtnFlag    一级菜单中车厢按钮点击控制参数
     */
    bool carFlag = 1;
    bool carBtnFlag = 1;
    /**
     * @brief globalWidthSize 全局宽度
     * @brief globalHeightSize 全局高度
     * @brief quarterScreenWidth 四分屏宽度
     * @brief quarterScreenHeight 四分屏高度
     */
    int globalWidthSize = 1024;
    int globalHeightSize = 768;
    int quarterScreenWidth = 512;
    int quarterScreenHeight = 384;

    QGridLayout *layout;

    /**
     * @brief ltLabel 左上角视频
     * @brief rtLabel 右上角视频
     * @brief lbLabel 左下角视频
     * @brief rbLabel 右下角视频
     */
    QLabel *ltLabel;
    QLabel *rtLabel;
    QLabel *lbLabel;
    QLabel *rbLabel;


    /**
     * @brief mainbutton 主菜单按钮
     */
    SystemPushButton *mainbutton;

    /**
     * @brief carBtnWidget 显示车厢按钮的窗口
     * @brief carHeadBtn 车头按钮
     * @brief oneCarBtn 一车厢按钮
     * @brief twoCarBtn 二车厢按钮
     * @brief threeCarBtn 三车厢按钮
     * @brief Rear 车尾按钮
     */
    QWidget *carBtnWidget;
    SystemPushButton *carHeadBtn;
    SystemPushButton *oneCarBtn;
    SystemPushButton *twoCarBtn;
    SystemPushButton *threeCarBtn;
    SystemPushButton *rear;
    QHBoxLayout *carBtnLayout;

    /**
     * @brief oneMenuWidget 显示一级菜单的窗口
     * @brief loginBtn 登录
     * @brief carBtn 车厢
     * @brief roundRobinBtn 轮巡
     * @brief replayBtn 回放
     * @brief faultFuidanceBtn 故障指导
     */
    QWidget *oneMenuWidget;
    SystemPushButton *loginBtn;
    SystemPushButton *carBtn;
    SystemPushButton *roundRobinBtn;
    SystemPushButton *replayBtn;

    /**
     * @brief twoMenuWidget 显示二级菜单的窗口
     * @brief timing 校时
     * @brief systemStatus 系统状态
     * @brief carHeadOrReal 车头/车尾
     * @brief hardDriveCapacity 硬盘容量
     * @brief quit 退出
     * @brief logoutBtn 注销
     * @brief setBtn 设置
     * @brief faultFuidanceBtn 故障指导
     */
    QWidget *twoMenuWidget;
    SystemPushButton *timing;
    SystemPushButton *systemStatus;
    SystemPushButton *carHeadOrReal;
    SystemPushButton *hardDriveCapacity;
    SystemPushButton *quit;
    SystemPushButton *logoutBtn;
    SystemPushButton *setBtn;
    SystemPushButton *faultFuidanceBtn;

    /**
     * @brief loginDialog 登录框对象
     */
    QDialog *loginDialog;
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
    LoginButton *zeroBtn;
    LoginButton *oneBtn;
    LoginButton *twoBtn;
    LoginButton *threeBtn;
    LoginButton *fourBtn;
    LoginButton *fiveBtn;
    LoginButton *sixBtn;
    LoginButton *servenBtn;
    LoginButton *eightBtn;
    LoginButton *nineBtn;
    LoginButton *errorBtn;
    LoginButton *spaceBtn;
    SystemPushButton *determineBtn;
    SystemPushButton *cancelBtn;

};
#endif // VEDIOMONITORINGSYSTEM_H
