/********************************************************************************
** Form generated from reading UI file 'login_page.ui'
**
** Created by: Qt User Interface Compiler version 6.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LOGIN_PAGE_H
#define UI_LOGIN_PAGE_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFrame>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_login_page
{
public:
    QVBoxLayout *mainLayout;
    QFrame *loginFrame;
    QVBoxLayout *frameLayout;
    QLabel *titleLabel;
    QLineEdit *username_Line;
    QLineEdit *password_Line;
    QPushButton *login_Button;
    QPushButton *createAccount_Button;

    void setupUi(QWidget *LoginPage)
    {
        if (LoginPage->objectName().isEmpty())
            LoginPage->setObjectName("LoginPage");
        LoginPage->resize(800, 600);
        mainLayout = new QVBoxLayout(LoginPage);
        mainLayout->setSpacing(20);
        mainLayout->setContentsMargins(30, 30, 30, 30);
        mainLayout->setObjectName("mainLayout");
        loginFrame = new QFrame(LoginPage);
        loginFrame->setObjectName("loginFrame");
        frameLayout = new QVBoxLayout(loginFrame);
        frameLayout->setSpacing(15);
        frameLayout->setContentsMargins(20, 20, 20, 20);
        frameLayout->setObjectName("frameLayout");
        titleLabel = new QLabel(loginFrame);
        titleLabel->setObjectName("titleLabel");
        titleLabel->setAlignment(Qt::AlignmentFlag::AlignCenter);

        frameLayout->addWidget(titleLabel);

        username_Line = new QLineEdit(loginFrame);
        username_Line->setObjectName("username_Line");

        frameLayout->addWidget(username_Line);

        password_Line = new QLineEdit(loginFrame);
        password_Line->setObjectName("password_Line");
        password_Line->setEchoMode(QLineEdit::EchoMode::Password);

        frameLayout->addWidget(password_Line);

        login_Button = new QPushButton(loginFrame);
        login_Button->setObjectName("login_Button");

        frameLayout->addWidget(login_Button);

        createAccount_Button = new QPushButton(loginFrame);
        createAccount_Button->setObjectName("createAccount_Button");

        frameLayout->addWidget(createAccount_Button);


        mainLayout->addWidget(loginFrame);


        retranslateUi(LoginPage);

        QMetaObject::connectSlotsByName(LoginPage);
    } // setupUi

    void retranslateUi(QWidget *LoginPage)
    {
        LoginPage->setWindowTitle(QCoreApplication::translate("login_page", "Login", nullptr));
        loginFrame->setStyleSheet(QCoreApplication::translate("login_page", "\n"
"        QFrame {\n"
"            border-radius: 15px;\n"
"            background-color: #f5f5f5;\n"
"            box-shadow: 0px 4px 15px rgba(0, 0, 0, 0.2);\n"
"            margin: auto;\n"
"        }\n"
"        QLabel {\n"
"            font-size: 18px;\n"
"            color: #333333;\n"
"        }\n"
"        QLineEdit {\n"
"            font-size: 16px;\n"
"            padding: 10px;\n"
"            border: 2px solid #d3d3d3;\n"
"            border-radius: 10px;\n"
"            background-color: white;\n"
"        }\n"
"        QPushButton {\n"
"            font-size: 16px;\n"
"            padding: 10px;\n"
"            border-radius: 10px;\n"
"            background-color: #4CAF50;\n"
"            color: white;\n"
"        }\n"
"        QPushButton:hover {\n"
"            background-color: #45a049;\n"
"        }\n"
"        QPushButton:pressed {\n"
"            background-color: #397d39;\n"
"        }\n"
"      ", nullptr));
        titleLabel->setText(QCoreApplication::translate("login_page", "Welcome to Bank al LUMS", nullptr));
        username_Line->setPlaceholderText(QCoreApplication::translate("login_page", "Enter your username", nullptr));
        password_Line->setPlaceholderText(QCoreApplication::translate("login_page", "Enter your password", nullptr));
        login_Button->setText(QCoreApplication::translate("login_page", "Login", nullptr));
        createAccount_Button->setStyleSheet(QCoreApplication::translate("login_page", "\n"
"           QPushButton {\n"
"               font-size: 14px;\n"
"               background-color: transparent;\n"
"               color: #007BFF;\n"
"               border: none;\n"
"               text-decoration: underline;\n"
"           }\n"
"           QPushButton:hover {\n"
"               color: #0056b3;\n"
"           }\n"
"           QPushButton:pressed {\n"
"               color: #003d80;\n"
"           }\n"
"         ", nullptr));
        createAccount_Button->setText(QCoreApplication::translate("login_page", "Create New Account", nullptr));
    } // retranslateUi

};

namespace Ui {
    class login_page: public Ui_login_page {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LOGIN_PAGE_H
