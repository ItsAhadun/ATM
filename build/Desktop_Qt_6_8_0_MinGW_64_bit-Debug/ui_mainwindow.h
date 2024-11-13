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
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QStatusBar>
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
    QLabel *label_2;
    QLineEdit *lineEdit;
    QFrame *frame_2;
    QLineEdit *lineEdit_2;
    QLabel *label_3;
    QPushButton *createaccount_button;
    QPushButton *login_button;
    QLabel *label;
    QWidget *accounts_Page;
    QPushButton *default_acc_button;
    QPushButton *current_acc_button;
    QPushButton *savings_acc_button;
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
    QLabel *label_4;
    QFrame *frame_4;
    QLineEdit *newPassword_Line;
    QLabel *label_6;
    QFrame *frame_5;
    QLineEdit *confirmPassword_Line;
    QLabel *label_8;
    QPushButton *createAccount_Button;
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
    QMenuBar *menubar;
    QStatusBar *statusbar;

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
        label_2 = new QLabel(frame);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(0, 0, 171, 31));
        label_2->setMaximumSize(QSize(200, 50));
        label_2->setStyleSheet(QString::fromUtf8("Qlabel{\n"
"font-size:15px;\n"
"}"));
        label_2->setAlignment(Qt::AlignmentFlag::AlignLeading|Qt::AlignmentFlag::AlignLeft|Qt::AlignmentFlag::AlignVCenter);
        lineEdit = new QLineEdit(frame);
        lineEdit->setObjectName("lineEdit");
        lineEdit->setGeometry(QRect(0, 40, 171, 28));
        lineEdit->setStyleSheet(QString::fromUtf8("QLineEdit{\n"
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
        lineEdit_2 = new QLineEdit(frame_2);
        lineEdit_2->setObjectName("lineEdit_2");
        lineEdit_2->setGeometry(QRect(0, 40, 171, 28));
        lineEdit_2->setStyleSheet(QString::fromUtf8("QLineEdit{\n"
"font-size:15;\n"
"padding:5px;\n"
"}"));
        lineEdit_2->setEchoMode(QLineEdit::EchoMode::Password);
        label_3 = new QLabel(frame_2);
        label_3->setObjectName("label_3");
        label_3->setGeometry(QRect(0, 10, 171, 31));
        label_3->setMaximumSize(QSize(200, 50));
        label_3->setStyleSheet(QString::fromUtf8("Qlabel{\n"
"font-size:15px;\n"
"}"));
        label_3->setAlignment(Qt::AlignmentFlag::AlignLeading|Qt::AlignmentFlag::AlignLeft|Qt::AlignmentFlag::AlignVCenter);
        createaccount_button = new QPushButton(login_Page);
        createaccount_button->setObjectName("createaccount_button");
        createaccount_button->setGeometry(QRect(350, 390, 200, 29));
        createaccount_button->setMaximumSize(QSize(200, 30));
        createaccount_button->setStyleSheet(QString::fromUtf8("QPushButton{\n"
"font-size:15;\n"
"}"));
        login_button = new QPushButton(login_Page);
        login_button->setObjectName("login_button");
        login_button->setGeometry(QRect(350, 354, 200, 29));
        login_button->setMaximumSize(QSize(200, 30));
        login_button->setStyleSheet(QString::fromUtf8("QPushButton{\n"
"font-size:15;\n"
"}"));
        label = new QLabel(login_Page);
        label->setObjectName("label");
        label->setGeometry(QRect(-20, 60, 917, 20));
        label->setMinimumSize(QSize(0, 20));
        label->setMaximumSize(QSize(16777215, 100));
        label->setStyleSheet(QString::fromUtf8("Qlabel{\n"
"font-size:75px;\n"
"}"));
        label->setAlignment(Qt::AlignmentFlag::AlignCenter);
        stackedWidget->addWidget(login_Page);
        accounts_Page = new QWidget();
        accounts_Page->setObjectName("accounts_Page");
        default_acc_button = new QPushButton(accounts_Page);
        default_acc_button->setObjectName("default_acc_button");
        default_acc_button->setGeometry(QRect(350, 400, 171, 81));
        current_acc_button = new QPushButton(accounts_Page);
        current_acc_button->setObjectName("current_acc_button");
        current_acc_button->setGeometry(QRect(350, 140, 171, 81));
        savings_acc_button = new QPushButton(accounts_Page);
        savings_acc_button->setObjectName("savings_acc_button");
        savings_acc_button->setGeometry(QRect(350, 270, 171, 81));
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
        label_4 = new QLabel(frame_3);
        label_4->setObjectName("label_4");
        label_4->setGeometry(QRect(0, 40, 181, 20));
        frame_4 = new QFrame(createUser_Page);
        frame_4->setObjectName("frame_4");
        frame_4->setGeometry(QRect(340, 180, 181, 141));
        frame_4->setFrameShape(QFrame::Shape::StyledPanel);
        frame_4->setFrameShadow(QFrame::Shadow::Raised);
        newPassword_Line = new QLineEdit(frame_4);
        newPassword_Line->setObjectName("newPassword_Line");
        newPassword_Line->setGeometry(QRect(0, 70, 181, 31));
        label_6 = new QLabel(frame_4);
        label_6->setObjectName("label_6");
        label_6->setGeometry(QRect(0, 40, 181, 20));
        frame_5 = new QFrame(createUser_Page);
        frame_5->setObjectName("frame_5");
        frame_5->setGeometry(QRect(340, 340, 181, 141));
        frame_5->setFrameShape(QFrame::Shape::StyledPanel);
        frame_5->setFrameShadow(QFrame::Shadow::Raised);
        confirmPassword_Line = new QLineEdit(frame_5);
        confirmPassword_Line->setObjectName("confirmPassword_Line");
        confirmPassword_Line->setGeometry(QRect(0, 70, 181, 31));
        label_8 = new QLabel(frame_5);
        label_8->setObjectName("label_8");
        label_8->setGeometry(QRect(0, 40, 181, 20));
        createAccount_Button = new QPushButton(createUser_Page);
        createAccount_Button->setObjectName("createAccount_Button");
        createAccount_Button->setGeometry(QRect(340, 510, 181, 29));
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
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 939, 25));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName("statusbar");
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        stackedWidget->setCurrentIndex(3);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        label_2->setText(QCoreApplication::translate("MainWindow", "UserName:", nullptr));
        label_3->setText(QCoreApplication::translate("MainWindow", "Password:", nullptr));
        createaccount_button->setText(QCoreApplication::translate("MainWindow", "Create New account", nullptr));
        login_button->setText(QCoreApplication::translate("MainWindow", "Login", nullptr));
        label->setText(QCoreApplication::translate("MainWindow", "Bank al LUMS", nullptr));
        default_acc_button->setText(QCoreApplication::translate("MainWindow", "Default Account", nullptr));
        current_acc_button->setText(QCoreApplication::translate("MainWindow", "Current Account", nullptr));
        savings_acc_button->setText(QCoreApplication::translate("MainWindow", "Savings Account", nullptr));
        amount1000_Button->setText(QCoreApplication::translate("MainWindow", "1000", nullptr));
        amount5000_Button->setText(QCoreApplication::translate("MainWindow", "5000", nullptr));
        amount20000_Button->setText(QCoreApplication::translate("MainWindow", "20,000", nullptr));
        amount10000_Button->setText(QCoreApplication::translate("MainWindow", "10000", nullptr));
        deposit_Button->setText(QCoreApplication::translate("MainWindow", "Deposit", nullptr));
        checkBalance_Button->setText(QCoreApplication::translate("MainWindow", "Check Balance", nullptr));
        otherAmount_Button->setText(QCoreApplication::translate("MainWindow", "Other Amount", nullptr));
        amount25000_Button->setText(QCoreApplication::translate("MainWindow", "25,000", nullptr));
        label_4->setText(QCoreApplication::translate("MainWindow", "Enter UserName", nullptr));
        label_6->setText(QCoreApplication::translate("MainWindow", "Enter Password", nullptr));
        label_8->setText(QCoreApplication::translate("MainWindow", "Confirm Password", nullptr));
        createAccount_Button->setText(QCoreApplication::translate("MainWindow", "Create account", nullptr));
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
