#include "vediomonitoringsystem.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QFont font("Microsoft YaHei",15);
    a.setFont(font);
    VedioMonitoringSystem w;
    w.show();
    return a.exec();
}
