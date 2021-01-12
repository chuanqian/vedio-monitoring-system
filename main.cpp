#include "vediomonitoringsystem.h"

#include <QApplication>
#include "logindialog.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QFont font("SimHei",16);
    a.setFont(font);
    VedioMonitoringSystem w;
//    LoginDialog login;
//    login.show();
    w.show();
    return a.exec();
}
