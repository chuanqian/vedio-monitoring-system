#include "loginbutton.h"

LoginButton::LoginButton(QWidget *parent) : QPushButton(parent){
    setStyleSheet("QPushButton{"
                  "background-color: #FFF;"
                  "color: #606366;"
                  "border-radius: 5px;"
                  "}"
                  "QPushButton:pressed{"
                  "background: #3a8ee6;"
                  "border-color: #3a8ee6;"
                  "color: #000;"
                  "outline: 0;"
                  "}"
                );
}
