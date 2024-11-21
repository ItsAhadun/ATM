QT       += core gui sql

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    accounts_page.cpp \
    create_user_page.cpp \
    dashboard_page.cpp \
    login_page.cpp \
    main.cpp \
    mainwindow.cpp \
    numpad_page.cpp

HEADERS += \
    accounts_page.h \
    dashboard_page.h \
    mainwindow.h \
    numpad_page.h

FORMS += \
    accounts_page.ui \
    create_user_page.ui \
    dashboard_page.ui \
    login_page.ui \
    mainwindow.ui \
    numpad_page.ui

TRANSLATIONS += \
    LoginScreen_en_US.ts
CONFIG += lrelease
CONFIG += embed_translations

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
