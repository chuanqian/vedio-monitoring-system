#include "buttoninfo.h"

ButtonInfo::ButtonInfo(QWidget *parent) : QPushButton(parent){
    setStyleSheet("QPushButton{"
                  "background-color: #909399;"
                  "color: #FFF;"
                  "border-color: #909399"
                  "border-radius: 5px;"
                  "}"
                  "QPushButton:pressed{"
                  "background: #a6a9ad;"
                  "border-color: #6a9ad;"
                  "color: #FFF;"
                  "}"
                );
}
