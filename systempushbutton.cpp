#include "systempushbutton.h"

SystemPushButton::SystemPushButton(QWidget *parent) : QPushButton(parent){
    setStyleSheet("QPushButton{"
                  "background-color: #409EFF;"
                  "color: #000;"
                  "border-radius: 5px;"
                  "border-color: #409EFF;"
                  "}"
                  "QPushButton:pressed{"
                  "background: #3a8ee6;"
                  "border-color: #3a8ee6;"
                  "color: #000;"
                  "}"
                  );
}
