#include "buttonwarning.h"

ButtonWarning::ButtonWarning(QWidget *parent) : QPushButton(parent){
    setStyleSheet("QPushButton{"
                  "background-color: #E6A23C;"
                  "color: #FFF;"
                  "border-color: #E6A23C;"
                  "border-radius: 5px;"
                  "}"
                  "QPushButton:pressed{"
                  "background: #cf9236;"
                  "border-color: #cf9236;"
                  "color: #FFF;"
                  "}"
                );
}
