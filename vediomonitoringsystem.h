#ifndef VEDIOMONITORINGSYSTEM_H
#define VEDIOMONITORINGSYSTEM_H

#include <QWidget>
#include <QGridLayout>
#include "qpushbutton.h"
#include <QHBoxLayout>
#include <windows.h>
#include <HCNetSDK.h>
#include <plaympeg4.h>
#include "tvreal.h"
#include "qlabel.h"
#include "qopenglwidget.h"
#include "qcombobox.h"

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
     * @brief loadVeido 加载视频
     */
    void loadVeido();

    void loadCameraUtils();
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
     * @brief ltLayout 左上角视频布局
     * @brief lbLayout 左下角视频布局
     * @brief rtLayout 右上角视频布局
     */
    QGridLayout *ltLayout;
    QGridLayout *lbLayout;
    QGridLayout *rtLayout;

    /**
     * @brief ltltLabel 视频1左上角label
     * @brief lbltLabel 视频1左下角label
     * @brief rtltLabel 视频1右上角label
     * @brief rbltLabel 视频1右下角label
     */
    QLabel *ltltLabel;
    QLabel *ltlbLabel;
    QLabel *ltrtLabel;
    QLabel *ltrbLabel;

    /**
     * @brief rtltLabel 视频2左上角label
     * @brief rtlbLabel 视频2左下角label
     * @brief rtrtLabel 视频2右上角label
     * @brief rtrbLabel 视频2右下角label
     */
    QLabel *rtltLabel;
    QLabel *rtlbLabel;
    QLabel *rtrtLabel;
    QLabel *rtrbLabel;

    /**
     * @brief lbltLabel 视频3左上角label
     * @brief lblbLabel 视频3左下角label
     * @brief lbrtLabel 视频3右上角label
     * @brief lbrbLabel 视频3右下角label
     */
    QLabel *lbltLabel;
    QLabel *lblbLabel;
    QLabel *lbrtLabel;
    QLabel *lbrbLabel;

    /**
     * @brief rbLabel 右下角视频
     */
    QLabel *rbLabel;

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
//    BOOL m_IsPaint;

};
#endif // VEDIOMONITORINGSYSTEM_H
