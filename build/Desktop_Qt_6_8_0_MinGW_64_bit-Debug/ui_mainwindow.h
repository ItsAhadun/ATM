/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLCDNumber>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QVBoxLayout *verticalLayout;
    QStackedWidget *stackedWidget;
    QWidget *login_Page;
    QFrame *frame;
    QLabel *username_Label;
    QLineEdit *username_Line;
    QFrame *frame_2;
    QLineEdit *password_Line;
    QLabel *password_Label;
    QPushButton *createAccount_Button;
    QPushButton *login_Button;
    QLabel *mainlogin_Label;
    QWidget *accounts_Page;
    QPushButton *default_acc_Button;
    QPushButton *current_acc_Button;
    QPushButton *savings_acc_Button;
    QWidget *dashboard_Page;
    QPushButton *amount1000_Button;
    QPushButton *amount5000_Button;
    QPushButton *amount20000_Button;
    QPushButton *amount10000_Button;
    QPushButton *deposit_Button;
    QPushButton *checkBalance_Button;
    QPushButton *otherAmount_Button;
    QPushButton *amount25000_Button;
    QWidget *createUser_Page;
    QFrame *frame_3;
    QLineEdit *newUser_Line;
    QLabel *newUser_Label;
    QFrame *frame_4;
    QLineEdit *newPassword_Line;
    QLabel *newPassword_Label;
    QFrame *frame_5;
    QLineEdit *confirmPassword_Line;
    QLabel *confirmPassword_Label;
    QPushButton *submitApplication_Button;
    QWidget *numpad_Page;
    QLCDNumber *lcdNumber;
    QWidget *gridLayoutWidget;
    QGridLayout *numpad_Grid;
    QPushButton *zero_Button;
    QPushButton *blank_Button_2;
    QPushButton *eight_Button;
    QPushButton *two_Button;
    QPushButton *nine_Button;
    QPushButton *six_Button;
    QPushButton *three_Button;
    QPushButton *seven_Button;
    QPushButton *one_Button;
    QPushButton *blank_Button;
    QPushButton *five_Button;
    QPushButton *clear_Button;
    QPushButton *cancel_Button;
    QPushButton *enter_Button;
    QPushButton *blank_Button_3;
    QPushButton *four_Button;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(939, 683);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        verticalLayout = new QVBoxLayout(centralwidget);
        verticalLayout->setObjectName("verticalLayout");
        stackedWidget = new QStackedWidget(centralwidget);
        stackedWidget->setObjectName("stackedWidget");
        login_Page = new QWidget();
        login_Page->setObjectName("login_Page");
        frame = new QFrame(login_Page);
        frame->setObjectName("frame");
        frame->setGeometry(QRect(290, 110, 300, 100));
        frame->setMinimumSize(QSize(170, 100));
        frame->setMaximumSize(QSize(300, 100));
        frame->setFrameShape(QFrame::Shape::StyledPanel);
        frame->setFrameShadow(QFrame::Shadow::Raised);
        username_Label = new QLabel(frame);
        username_Label->setObjectName("username_Label");
        username_Label->setGeometry(QRect(0, 0, 171, 31));
        username_Label->setMaximumSize(QSize(200, 50));
        username_Label->setStyleSheet(QString::fromUtf8("Qlabel{\n"
"font-size:15px;\n"
"}"));
        username_Label->setAlignment(Qt::AlignmentFlag::AlignLeading|Qt::AlignmentFlag::AlignLeft|Qt::AlignmentFlag::AlignVCenter);
        username_Line = new QLineEdit(frame);
        username_Line->setObjectName("username_Line");
        username_Line->setGeometry(QRect(0, 40, 171, 28));
        username_Line->setStyleSheet(QString::fromUtf8("QLineEdit{\n"
"font-size:15;\n"
"padding:5px;\n"
"}"));
        frame_2 = new QFrame(login_Page);
        frame_2->setObjectName("frame_2");
        frame_2->setGeometry(QRect(290, 230, 300, 100));
        frame_2->setMinimumSize(QSize(170, 100));
        frame_2->setMaximumSize(QSize(300, 100));
        frame_2->setFrameShape(QFrame::Shape::StyledPanel);
        frame_2->setFrameShadow(QFrame::Shadow::Raised);
        password_Line = new QLineEdit(frame_2);
        password_Line->setObjectName("password_Line");
        password_Line->setGeometry(QRect(0, 40, 171, 28));
        password_Line->setStyleSheet(QString::fromUtf8("QLineEdit{\n"
"font-size:15;\n"
"padding:5px;\n"
"}"));
        password_Line->setEchoMode(QLineEdit::EchoMode::Password);
        password_Label = new QLabel(frame_2);
        password_Label->setObjectName("password_Label");
        password_Label->setGeometry(QRect(0, 10, 171, 31));
        password_Label->setMaximumSize(QSize(200, 50));
        password_Label->setStyleSheet(QString::fromUtf8("Qlabel{\n"
"font-size:15px;\n"
"}"));
        password_Label->setAlignment(Qt::AlignmentFlag::AlignLeading|Qt::AlignmentFlag::AlignLeft|Qt::AlignmentFlag::AlignVCenter);
        createAccount_Button = new QPushButton(login_Page);
        createAccount_Button->setObjectName("createAccount_Button");
        createAccount_Button->setGeometry(QRect(350, 390, 200, 29));
        createAccount_Button->setMaximumSize(QSize(200, 30));
        createAccount_Button->setStyleSheet(QString::fromUtf8("QPushButton{\n"
"font-size:15;\n"
"background-color: qradialgradient(spread:reflect, cx:0.5, cy:0.5, radius:1.026, fx:0.331, fy:0.245, stop:0 rgba(4, 7, 255, 255), stop:1 rgba(255, 255, 255, 255));\n"
"}"));
        login_Button = new QPushButton(login_Page);
        login_Button->setObjectName("login_Button");
        login_Button->setGeometry(QRect(350, 354, 200, 29));
        login_Button->setMaximumSize(QSize(200, 30));
        login_Button->setStyleSheet(QString::fromUtf8("QPushButton{\n"
"font-size:15;\n"
"background-color: qradialgradient(spread:reflect, cx:0.5, cy:0.5, radius:1.026, fx:0.331, fy:0.245, stop:0 rgba(4, 7, 255, 255), stop:1 rgba(255, 255, 255, 255));\n"
"}\n"
""));
        mainlogin_Label = new QLabel(login_Page);
        mainlogin_Label->setObjectName("mainlogin_Label");
        mainlogin_Label->setGeometry(QRect(-20, 60, 917, 20));
        mainlogin_Label->setMinimumSize(QSize(0, 20));
        mainlogin_Label->setMaximumSize(QSize(16777215, 100));
        mainlogin_Label->setStyleSheet(QString::fromUtf8("Qlabel{\n"
"font-size:75px;\n"
"}"));
        mainlogin_Label->setAlignment(Qt::AlignmentFlag::AlignCenter);
        stackedWidget->addWidget(login_Page);
        accounts_Page = new QWidget();
        accounts_Page->setObjectName("accounts_Page");
        default_acc_Button = new QPushButton(accounts_Page);
        default_acc_Button->setObjectName("default_acc_Button");
        default_acc_Button->setGeometry(QRect(350, 400, 171, 81));
        current_acc_Button = new QPushButton(accounts_Page);
        current_acc_Button->setObjectName("current_acc_Button");
        current_acc_Button->setGeometry(QRect(350, 140, 171, 81));
        savings_acc_Button = new QPushButton(accounts_Page);
        savings_acc_Button->setObjectName("savings_acc_Button");
        savings_acc_Button->setGeometry(QRect(350, 270, 171, 81));
        stackedWidget->addWidget(accounts_Page);
        dashboard_Page = new QWidget();
        dashboard_Page->setObjectName("dashboard_Page");
        amount1000_Button = new QPushButton(dashboard_Page);
        amount1000_Button->setObjectName("amount1000_Button");
        amount1000_Button->setGeometry(QRect(40, 80, 141, 81));
        amount5000_Button = new QPushButton(dashboard_Page);
        amount5000_Button->setObjectName("amount5000_Button");
        amount5000_Button->setGeometry(QRect(40, 210, 141, 81));
        amount20000_Button = new QPushButton(dashboard_Page);
        amount20000_Button->setObjectName("amount20000_Button");
        amount20000_Button->setGeometry(QRect(40, 470, 141, 81));
        amount10000_Button = new QPushButton(dashboard_Page);
        amount10000_Button->setObjectName("amount10000_Button");
        amount10000_Button->setGeometry(QRect(40, 340, 141, 81));
        deposit_Button = new QPushButton(dashboard_Page);
        deposit_Button->setObjectName("deposit_Button");
        deposit_Button->setGeometry(QRect(740, 340, 141, 81));
        checkBalance_Button = new QPushButton(dashboard_Page);
        checkBalance_Button->setObjectName("checkBalance_Button");
        checkBalance_Button->setGeometry(QRect(740, 470, 141, 81));
        otherAmount_Button = new QPushButton(dashboard_Page);
        otherAmount_Button->setObjectName("otherAmount_Button");
        otherAmount_Button->setGeometry(QRect(740, 210, 141, 81));
        amount25000_Button = new QPushButton(dashboard_Page);
        amount25000_Button->setObjectName("amount25000_Button");
        amount25000_Button->setGeometry(QRect(740, 80, 141, 81));
        stackedWidget->addWidget(dashboard_Page);
        createUser_Page = new QWidget();
        createUser_Page->setObjectName("createUser_Page");
        frame_3 = new QFrame(createUser_Page);
        frame_3->setObjectName("frame_3");
        frame_3->setGeometry(QRect(340, 30, 181, 141));
        frame_3->setFrameShape(QFrame::Shape::StyledPanel);
        frame_3->setFrameShadow(QFrame::Shadow::Raised);
        newUser_Line = new QLineEdit(frame_3);
        newUser_Line->setObjectName("newUser_Line");
        newUser_Line->setGeometry(QRect(0, 70, 181, 31));
        newUser_Label = new QLabel(frame_3);
        newUser_Label->setObjectName("newUser_Label");
        newUser_Label->setGeometry(QRect(0, 40, 181, 20));
        frame_4 = new QFrame(createUser_Page);
        frame_4->setObjectName("frame_4");
        frame_4->setGeometry(QRect(340, 180, 181, 141));
        frame_4->setFrameShape(QFrame::Shape::StyledPanel);
        frame_4->setFrameShadow(QFrame::Shadow::Raised);
        newPassword_Line = new QLineEdit(frame_4);
        newPassword_Line->setObjectName("newPassword_Line");
        newPassword_Line->setGeometry(QRect(0, 70, 181, 31));
        newPassword_Label = new QLabel(frame_4);
        newPassword_Label->setObjectName("newPassword_Label");
        newPassword_Label->setGeometry(QRect(0, 40, 181, 20));
        frame_5 = new QFrame(createUser_Page);
        frame_5->setObjectName("frame_5");
        frame_5->setGeometry(QRect(340, 340, 181, 141));
        frame_5->setFrameShape(QFrame::Shape::StyledPanel);
        frame_5->setFrameShadow(QFrame::Shadow::Raised);
        confirmPassword_Line = new QLineEdit(frame_5);
        confirmPassword_Line->setObjectName("confirmPassword_Line");
        confirmPassword_Line->setGeometry(QRect(0, 70, 181, 31));
        confirmPassword_Label = new QLabel(frame_5);
        confirmPassword_Label->setObjectName("confirmPassword_Label");
        confirmPassword_Label->setGeometry(QRect(0, 40, 181, 20));
        submitApplication_Button = new QPushButton(createUser_Page);
        submitApplication_Button->setObjectName("submitApplication_Button");
        submitApplication_Button->setGeometry(QRect(340, 510, 181, 29));
        submitApplication_Button->setStyleSheet(QString::fromUtf8("background-color: qradialgradient(spread:reflect, cx:0.5, cy:0.5, radius:1.026, fx:0.331, fy:0.245, stop:0 rgba(4, 7, 255, 255), stop:1 rgba(255, 255, 255, 255));"));
        stackedWidget->addWidget(createUser_Page);
        numpad_Page = new QWidget();
        numpad_Page->setObjectName("numpad_Page");
        lcdNumber = new QLCDNumber(numpad_Page);
        lcdNumber->setObjectName("lcdNumber");
        lcdNumber->setGeometry(QRect(310, 130, 371, 71));
        gridLayoutWidget = new QWidget(numpad_Page);
        gridLayoutWidget->setObjectName("gridLayoutWidget");
        gridLayoutWidget->setGeometry(QRect(310, 210, 371, 331));
        numpad_Grid = new QGridLayout(gridLayoutWidget);
        numpad_Grid->setObjectName("numpad_Grid");
        numpad_Grid->setContentsMargins(5, 5, 5, 5);
        zero_Button = new QPushButton(gridLayoutWidget);
        zero_Button->setObjectName("zero_Button");
        zero_Button->setMinimumSize(QSize(75, 75));

        numpad_Grid->addWidget(zero_Button, 3, 1, 1, 1);

        blank_Button_2 = new QPushButton(gridLayoutWidget);
        blank_Button_2->setObjectName("blank_Button_2");
        blank_Button_2->setMinimumSize(QSize(75, 75));

        numpad_Grid->addWidget(blank_Button_2, 3, 0, 1, 1);

        eight_Button = new QPushButton(gridLayoutWidget);
        eight_Button->setObjectName("eight_Button");
        eight_Button->setMinimumSize(QSize(75, 75));

        numpad_Grid->addWidget(eight_Button, 2, 1, 1, 1);

        two_Button = new QPushButton(gridLayoutWidget);
        two_Button->setObjectName("two_Button");
        two_Button->setMinimumSize(QSize(75, 75));

        numpad_Grid->addWidget(two_Button, 0, 1, 1, 1);

        nine_Button = new QPushButton(gridLayoutWidget);
        nine_Button->setObjectName("nine_Button");
        nine_Button->setMinimumSize(QSize(75, 75));

        numpad_Grid->addWidget(nine_Button, 2, 2, 1, 1);

        six_Button = new QPushButton(gridLayoutWidget);
        six_Button->setObjectName("six_Button");
        six_Button->setMinimumSize(QSize(75, 75));

        numpad_Grid->addWidget(six_Button, 1, 2, 1, 1);

        three_Button = new QPushButton(gridLayoutWidget);
        three_Button->setObjectName("three_Button");
        three_Button->setMinimumSize(QSize(75, 75));

        numpad_Grid->addWidget(three_Button, 0, 2, 1, 1);

        seven_Button = new QPushButton(gridLayoutWidget);
        seven_Button->setObjectName("seven_Button");
        seven_Button->setMinimumSize(QSize(75, 75));

        numpad_Grid->addWidget(seven_Button, 2, 0, 1, 1);

        one_Button = new QPushButton(gridLayoutWidget);
        one_Button->setObjectName("one_Button");
        one_Button->setMinimumSize(QSize(75, 75));

        numpad_Grid->addWidget(one_Button, 0, 0, 1, 1);

        blank_Button = new QPushButton(gridLayoutWidget);
        blank_Button->setObjectName("blank_Button");
        blank_Button->setMinimumSize(QSize(75, 75));

        numpad_Grid->addWidget(blank_Button, 3, 2, 1, 1);

        five_Button = new QPushButton(gridLayoutWidget);
        five_Button->setObjectName("five_Button");
        five_Button->setMinimumSize(QSize(75, 75));

        numpad_Grid->addWidget(five_Button, 1, 1, 1, 1);

        clear_Button = new QPushButton(gridLayoutWidget);
        clear_Button->setObjectName("clear_Button");
        clear_Button->setMinimumSize(QSize(75, 75));

        numpad_Grid->addWidget(clear_Button, 0, 3, 1, 1);

        cancel_Button = new QPushButton(gridLayoutWidget);
        cancel_Button->setObjectName("cancel_Button");
        cancel_Button->setMinimumSize(QSize(75, 75));

        numpad_Grid->addWidget(cancel_Button, 1, 3, 1, 1);

        enter_Button = new QPushButton(gridLayoutWidget);
        enter_Button->setObjectName("enter_Button");
        enter_Button->setMinimumSize(QSize(75, 75));

        numpad_Grid->addWidget(enter_Button, 2, 3, 1, 1);

        blank_Button_3 = new QPushButton(gridLayoutWidget);
        blank_Button_3->setObjectName("blank_Button_3");
        blank_Button_3->setMinimumSize(QSize(75, 75));

        numpad_Grid->addWidget(blank_Button_3, 3, 3, 1, 1);

        four_Button = new QPushButton(gridLayoutWidget);
        four_Button->setObjectName("four_Button");
        four_Button->setMinimumSize(QSize(75, 75));

        numpad_Grid->addWidget(four_Button, 1, 0, 1, 1);

        stackedWidget->addWidget(numpad_Page);

        verticalLayout->addWidget(stackedWidget);

        MainWindow->setCentralWidget(centralwidget);

        retranslateUi(MainWindow);

        stackedWidget->setCurrentIndex(4);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        username_Label->setText(QCoreApplication::translate("MainWindow", "UserName:", nullptr));
        password_Label->setText(QCoreApplication::translate("MainWindow", "Password:", nullptr));
        createAccount_Button->setText(QCoreApplication::translate("MainWindow", "Create New account", nullptr));
        login_Button->setText(QCoreApplication::translate("MainWindow", "Login", nullptr));
        mainlogin_Label->setText(QCoreApplication::translate("MainWindow", "Bank al LUMS", nullptr));
        default_acc_Button->setText(QCoreApplication::translate("MainWindow", "Default Account", nullptr));
        current_acc_Button->setText(QCoreApplication::translate("MainWindow", "Current Account", nullptr));
        savings_acc_Button->setText(QCoreApplication::translate("MainWindow", "Savings Account", nullptr));
        amount1000_Button->setText(QCoreApplication::translate("MainWindow", "1000", nullptr));
        amount5000_Button->setText(QCoreApplication::translate("MainWindow", "5000", nullptr));
        amount20000_Button->setText(QCoreApplication::translate("MainWindow", "20,000", nullptr));
        amount10000_Button->setText(QCoreApplication::translate("MainWindow", "10000", nullptr));
        deposit_Button->setText(QCoreApplication::translate("MainWindow", "Deposit", nullptr));
        checkBalance_Button->setText(QCoreApplication::translate("MainWindow", "Check Balance", nullptr));
        otherAmount_Button->setText(QCoreApplication::translate("MainWindow", "Other Amount", nullptr));
        amount25000_Button->setText(QCoreApplication::translate("MainWindow", "25,000", nullptr));
        newUser_Label->setText(QCoreApplication::translate("MainWindow", "Enter UserName", nullptr));
        newPassword_Label->setText(QCoreApplication::translate("MainWindow", "Enter Password", nullptr));
        confirmPassword_Label->setText(QCoreApplication::translate("MainWindow", "Confirm Password", nullptr));
        submitApplication_Button->setText(QCoreApplication::translate("MainWindow", "Create account", nullptr));
        zero_Button->setText(QCoreApplication::translate("MainWindow", "0", nullptr));
        blank_Button_2->setText(QString());
        eight_Button->setText(QCoreApplication::translate("MainWindow", "8", nullptr));
        two_Button->setText(QCoreApplication::translate("MainWindow", "2", nullptr));
        nine_Button->setText(QCoreApplication::translate("MainWindow", "9", nullptr));
        six_Button->setText(QCoreApplication::translate("MainWindow", "6", nullptr));
        three_Button->setText(QCoreApplication::translate("MainWindow", "3", nullptr));
        seven_Button->setText(QCoreApplication::translate("MainWindow", "7", nullptr));
        one_Button->setText(QCoreApplication::translate("MainWindow", "1", nullptr));
        blank_Button->setText(QString());
        five_Button->setText(QCoreApplication::translate("MainWindow", "5", nullptr));
        clear_Button->setText(QCoreApplication::translate("MainWindow", "Clear", nullptr));
        cancel_Button->setText(QCoreApplication::translate("MainWindow", "Cancel", nullptr));
        enter_Button->setText(QCoreApplication::translate("MainWindow", "Enter", nullptr));
        blank_Button_3->setText(QString());
        four_Button->setText(QCoreApplication::translate("MainWindow", "4", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
