#include "vediomonitoringsystem.h"

#include <QApplication>
#include "logindialog.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    //VedioMonitoringSystem w;
    LoginDialog login;
    login.show();
    //w.show();
    return a.exec();
}
