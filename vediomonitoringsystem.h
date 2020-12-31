#ifndef VEDIOMONITORINGSYSTEM_H
#define VEDIOMONITORINGSYSTEM_H

#include <QWidget>
#include <QGridLayout>
#include "qpushbutton.h"
#include <QHBoxLayout>

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
public slots:
    /**
     * @brief showHideCar 车厢显示和隐藏槽
     */
    void showHideCar();
    /**
     * @brief showHideOneMenu 一级菜单显示隐藏槽
     */
    void showHideOneMenu();
private:
    /**
     * @brief carFlag   车厢按钮的点击控制参数
     * @brief carBtnFlag    一级菜单中车厢按钮点击控制参数
     */
    bool carFlag = 0;
    bool carBtnFlag = 0;
    /**
     * @brief globalWidthSize 全局宽度
     * @brief globalHeightSize 全局高度
     * @brief quarterScreenWidth 四分屏宽度
     * @brief quarterScreenHeight 四分屏高度
     */
    int globalWidthSize = 1280;
    int globalHeightSize = 720;
    int quarterScreenWidth = 640;
    int quarterScreenHeight = 360;
    /**
     * @brief leftTopWidget 左上角
     * @brief leftButtomWidget 左下角
     * @brief rightTopWidget 右上角
     * @brief rightButtomWidget 右下角
     * @brief layout 主页面布局方式
     */
    QWidget *leftTopWidget;
    QWidget *leftButtomWidget;
    QWidget *rightTopWidget;
    QWidget *rightButtomWidget;
    QGridLayout *layout;
    /**
     * @brief ltlTopWidget 左上角屏幕的左上角
     * @brief ltlButtomWidget 左上角屏幕的左下角
     * @brief ltrTopWidget 左上角屏幕的右上角
     * @brief ltrButtomWidget 左上角屏幕的右下角
     */
    QWidget *ltlTopWidget;
    QWidget *ltlButtomWidget;
    QWidget *ltrTopWidget;
    QWidget *ltrButtomWidget;
    QGridLayout *ltLayout;

    /**
     * @brief lblTopWidget 左下角屏幕的左上角
     * @brief lblButtomWidget 左下角屏幕的左下角
     * @brief lbrTopWidget 左下角屏幕的右上角
     * @brief lbrButtomWidget 左下角屏幕的右下角
     */
    QWidget *lblTopWidget;
    QWidget *lblButtomWidget;
    QWidget *lbrTopWidget;
    QWidget *lbrButtomWidget;

    /**
     * @brief rtlTopWidget 右上角屏幕的左上角
     * @brief rtlButtomWidget 右上角屏幕的左下角
     * @brief rtrTopWidget 右上角屏幕的右上角
     * @brief rtrButtomWidget 右上角屏幕的右下角
     */
    QWidget *rtlTopWidget;
    QWidget *rtlButtomWidget;
    QWidget *rtrTopWidget;
    QWidget *rtrButtomWidget;

    /**
     * @brief mainbutton 主菜单按钮
     */
    QPushButton *mainbutton;

    /**
     * @brief carBtnWidget 显示车厢按钮的窗口
     * @brief carHeadBtn 车头按钮
     * @brief oneCarBtn 一车厢按钮
     * @brief twoCarBtn 二车厢按钮
     * @brief threeCarBtn 三车厢按钮
     * @brief Rear 车尾按钮
     */
    QWidget *carBtnWidget;
    QPushButton *carHeadBtn;
    QPushButton *oneCarBtn;
    QPushButton *twoCarBtn;
    QPushButton *threeCarBtn;
    QPushButton *rear;
    QHBoxLayout *carBtnLayout;

    /**
     * @brief oneMenuWidget 显示一级菜单的窗口
     * @brief loginBtn 登录
     * @brief logoutBtn 注销
     * @brief carBtn 车厢
     * @brief roundRobinBtn 轮巡
     * @brief replayBtn 回放
     * @brief setBtn 设置
     * @brief faultFuidanceBtn 故障指导
     */
    QWidget *oneMenuWidget;
    QPushButton *loginBtn;
    QPushButton *logoutBtn;
    QPushButton *carBtn;
    QPushButton *roundRobinBtn;
    QPushButton *replayBtn;
    QPushButton *setBtn;
    QPushButton *faultFuidanceBtn;

};
#endif // VEDIOMONITORINGSYSTEM_H
