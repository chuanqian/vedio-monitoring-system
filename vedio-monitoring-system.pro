QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

LIBS += $$PWD/lib/HCCore.lib
LIBS += $$PWD/lib/HCNetSDK.lib
LIBS += $$PWD/lib/PlayCtrl.lib
LIBS += $$PWD/lib/GdiPlus.lib

#LIBS += $$PWD/lib/GdiPlus.lib
#LIBS += $$PWD/lib/GdiPlus.lib
#LIBS += $$PWD/lib/GdiPlus.lib

INCLUDEPATH += $$PWD\include



CONFIG += c++11

# The following define makes your compiler emit warnings if you use
# any Qt feature that has been marked deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    buttondanger.cpp \
    buttoninfo.cpp \
    buttonwarning.cpp \
    loginbutton.cpp \
    main.cpp \
    systempushbutton.cpp \
    tvreal.cpp \
    vediomonitoringsystem.cpp

HEADERS += \
    StructType.h \
    buttondanger.h \
    buttoninfo.h \
    buttonwarning.h \
    loginbutton.h \
    systempushbutton.h \
    tvreal.h \
    vediomonitoringsystem.h

TRANSLATIONS += \
    vedio-monitoring-system_zh_CN.ts

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    resources.qrc
