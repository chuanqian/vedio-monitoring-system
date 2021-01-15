#include "vediomonitoringsystem.h"

#include "signal.h"
#include <QApplication>



int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QFont font("Microsoft YaHei",14);
    a.setFont(font);
    VedioMonitoringSystem w;
    w.show();

    return a.exec();
}
