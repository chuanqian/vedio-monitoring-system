#include "buttondanger.h"

ButtonDanger::ButtonDanger(QWidget *parent) : QPushButton(parent){
    setStyleSheet("QPushButton{"
                  "background-color: #F56C6C;"
                  "color: #FFF;"
                  "border-color: #F56C6C"
                  "border-radius: 5px;"
                  "}"
                  "QPushButton:pressed{"
                  "background: #dd6161;"
                  "border-color: #dd6161;"
                  "color: #FFF;"
                  "}"
                );
}
