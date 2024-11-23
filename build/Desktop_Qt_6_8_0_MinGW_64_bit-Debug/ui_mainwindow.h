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
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLCDNumber>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSlider>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QToolButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QHBoxLayout *horizontalLayout;
    QStackedWidget *stackedWidget;
    QWidget *login_Page;
    QHBoxLayout *horizontalLayout_3;
    QSpacerItem *horizontalSpacer_6;
    QVBoxLayout *verticalLayout;
    QSpacerItem *verticalSpacer_7;
    QLabel *BankalLums;
    QLabel *username_Label;
    QLineEdit *loginUser_Line;
    QSpacerItem *verticalSpacer_10;
    QLabel *password_Label;
    QLineEdit *loginPass_Line;
    QSpacerItem *verticalSpacer_11;
    QPushButton *login_button;
    QSpacerItem *horizontalSpacer_8;
    QPushButton *createAccount_Button;
    QSpacerItem *verticalSpacer_8;
    QSpacerItem *horizontalSpacer_7;
    QWidget *receipt_Page;
    QWidget *deleteAccount_Page;
    QWidget *horizontalLayoutWidget;
    QHBoxLayout *horizontalLayout_4;
    QVBoxLayout *verticalLayout_3;
    QLabel *enterPass_Label;
    QLineEdit *deletePass_Line;
    QLabel *enterPassConfirm_Label;
    QLineEdit *deletePassConfirm_Line;
    QSlider *horizontalSlider;
    QLabel *deletion_Label;
    QWidget *accounts_Page;
    QHBoxLayout *horizontalLayout_5;
    QSpacerItem *horizontalSpacer_4;
    QVBoxLayout *verticalLayout_8;
    QSpacerItem *verticalSpacer_3;
    QPushButton *current_acc_button;
    QSpacerItem *verticalSpacer;
    QPushButton *savings_acc_button;
    QSpacerItem *verticalSpacer_2;
    QPushButton *default_acc_button;
    QSpacerItem *verticalSpacer_4;
    QSpacerItem *horizontalSpacer_5;
    QWidget *dashboard_Page;
    QHBoxLayout *horizontalLayout_2;
    QVBoxLayout *verticalLayout_6;
    QPushButton *amount1000_Button;
    QPushButton *amount5000_Button;
    QPushButton *amount10000_Button;
    QPushButton *amount20000_Button;
    QLabel *label_2;
    QSpacerItem *horizontalSpacer_3;
    QVBoxLayout *verticalLayout_7;
    QPushButton *amount25000_Button;
    QPushButton *otherAmount_Button;
    QPushButton *deposit_Button;
    QPushButton *checkBalance_Button;
    QToolButton *settings_Button;
    QWidget *createUser_Page;
    QWidget *verticalLayoutWidget;
    QVBoxLayout *verticalLayout_2;
    QFrame *frame_3;
    QLineEdit *newUser_Line;
    QLabel *newUser_Line_2;
    QFrame *frame_5;
    QLineEdit *confirmPassword_Line;
    QLabel *confirmPassword_Label;
    QFrame *frame_4;
    QLineEdit *newPassword_Line;
    QLabel *newPassword_Label;
    QPushButton *submitApplication_Button;
    QPushButton *acc_Cancel_Button;
    QWidget *numpad_Page;
    QHBoxLayout *horizontalLayout_6;
    QSpacerItem *horizontalSpacer;
    QVBoxLayout *verticalLayout_10;
    QSpacerItem *verticalSpacer_5;
    QLCDNumber *lcdNumber;
    QGridLayout *numpad_Grid;
    QPushButton *depositEnter_Button;
    QPushButton *blank_Button_2;
    QPushButton *four_Button;
    QPushButton *blank_Button_3;
    QPushButton *eight_Button;
    QPushButton *cancel_Button;
    QPushButton *seven_Button;
    QPushButton *three_Button;
    QPushButton *five_Button;
    QPushButton *clear_Button;
    QPushButton *nine_Button;
    QPushButton *zero_Button;
    QPushButton *two_Button;
    QPushButton *blank_Button;
    QPushButton *six_Button;
    QPushButton *one_Button;
    QSpacerItem *verticalSpacer_6;
    QSpacerItem *horizontalSpacer_2;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(940, 700);
        QSizePolicy sizePolicy(QSizePolicy::Policy::MinimumExpanding, QSizePolicy::Policy::MinimumExpanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(MainWindow->sizePolicy().hasHeightForWidth());
        MainWindow->setSizePolicy(sizePolicy);
        MainWindow->setMinimumSize(QSize(940, 700));
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        horizontalLayout = new QHBoxLayout(centralwidget);
        horizontalLayout->setObjectName("horizontalLayout");
        stackedWidget = new QStackedWidget(centralwidget);
        stackedWidget->setObjectName("stackedWidget");
        login_Page = new QWidget();
        login_Page->setObjectName("login_Page");
        horizontalLayout_3 = new QHBoxLayout(login_Page);
        horizontalLayout_3->setObjectName("horizontalLayout_3");
        horizontalSpacer_6 = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_6);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName("verticalLayout");
        verticalSpacer_7 = new QSpacerItem(20, 40, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Expanding);

        verticalLayout->addItem(verticalSpacer_7);

        BankalLums = new QLabel(login_Page);
        BankalLums->setObjectName("BankalLums");
        BankalLums->setMinimumSize(QSize(0, 20));
        BankalLums->setMaximumSize(QSize(16777215, 100));
        QFont font;
        font.setPointSize(36);
        font.setBold(true);
        BankalLums->setFont(font);
        BankalLums->setStyleSheet(QString::fromUtf8("Qlabel{\n"
"font-size:75px;\n"
"}"));
        BankalLums->setAlignment(Qt::AlignmentFlag::AlignCenter);

        verticalLayout->addWidget(BankalLums);

        username_Label = new QLabel(login_Page);
        username_Label->setObjectName("username_Label");
        username_Label->setMaximumSize(QSize(200, 50));
        QFont font1;
        font1.setPointSize(13);
        username_Label->setFont(font1);
        username_Label->setStyleSheet(QString::fromUtf8("Qlabel{\n"
"font-size:15px;\n"
"}"));
        username_Label->setAlignment(Qt::AlignmentFlag::AlignLeading|Qt::AlignmentFlag::AlignLeft|Qt::AlignmentFlag::AlignVCenter);

        verticalLayout->addWidget(username_Label);

        loginUser_Line = new QLineEdit(login_Page);
        loginUser_Line->setObjectName("loginUser_Line");
        loginUser_Line->setMinimumSize(QSize(260, 0));
        loginUser_Line->setStyleSheet(QString::fromUtf8("QLineEdit{\n"
"font-size:15;\n"
"padding:5px;\n"
"}"));

        verticalLayout->addWidget(loginUser_Line);

        verticalSpacer_10 = new QSpacerItem(20, 40, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Expanding);

        verticalLayout->addItem(verticalSpacer_10);

        password_Label = new QLabel(login_Page);
        password_Label->setObjectName("password_Label");
        password_Label->setMaximumSize(QSize(200, 50));
        password_Label->setFont(font1);
        password_Label->setStyleSheet(QString::fromUtf8("Qlabel{\n"
"font-size:15px;\n"
"}"));
        password_Label->setAlignment(Qt::AlignmentFlag::AlignLeading|Qt::AlignmentFlag::AlignLeft|Qt::AlignmentFlag::AlignVCenter);

        verticalLayout->addWidget(password_Label);

        loginPass_Line = new QLineEdit(login_Page);
        loginPass_Line->setObjectName("loginPass_Line");
        loginPass_Line->setMinimumSize(QSize(260, 0));
        loginPass_Line->setStyleSheet(QString::fromUtf8("QLineEdit{\n"
"font-size:15;\n"
"padding:5px;\n"
"}"));
        loginPass_Line->setEchoMode(QLineEdit::EchoMode::Password);

        verticalLayout->addWidget(loginPass_Line);

        verticalSpacer_11 = new QSpacerItem(20, 30, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Expanding);

        verticalLayout->addItem(verticalSpacer_11);

        login_button = new QPushButton(login_Page);
        login_button->setObjectName("login_button");
        sizePolicy.setHeightForWidth(login_button->sizePolicy().hasHeightForWidth());
        login_button->setSizePolicy(sizePolicy);
        login_button->setMinimumSize(QSize(260, 0));
        login_button->setMaximumSize(QSize(10000, 30));
        login_button->setStyleSheet(QString::fromUtf8("QPushButton{\n"
"font-size:15;\n"
"background-color: qradialgradient(spread:reflect, cx:0.5, cy:0.5, radius:1.026, fx:0.331, fy:0.245, stop:0 rgba(4, 7, 255, 255), stop:1 rgba(255, 255, 255, 255));\n"
"}\n"
""));

        verticalLayout->addWidget(login_button);

        horizontalSpacer_8 = new QSpacerItem(40, 10, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        verticalLayout->addItem(horizontalSpacer_8);

        createAccount_Button = new QPushButton(login_Page);
        createAccount_Button->setObjectName("createAccount_Button");
        sizePolicy.setHeightForWidth(createAccount_Button->sizePolicy().hasHeightForWidth());
        createAccount_Button->setSizePolicy(sizePolicy);
        createAccount_Button->setMinimumSize(QSize(260, 0));
        createAccount_Button->setMaximumSize(QSize(10000, 30));
        createAccount_Button->setStyleSheet(QString::fromUtf8("QPushButton{\n"
"font-size:15;\n"
"background-color: qradialgradient(spread:reflect, cx:0.5, cy:0.5, radius:1.026, fx:0.331, fy:0.245, stop:0 rgba(4, 7, 255, 255), stop:1 rgba(255, 255, 255, 255));\n"
"}"));

        verticalLayout->addWidget(createAccount_Button);

        verticalSpacer_8 = new QSpacerItem(20, 40, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Expanding);

        verticalLayout->addItem(verticalSpacer_8);

        verticalLayout->setStretch(0, 2);
        verticalLayout->setStretch(1, 2);
        verticalLayout->setStretch(2, 2);
        verticalLayout->setStretch(3, 2);
        verticalLayout->setStretch(4, 1);
        verticalLayout->setStretch(6, 2);
        verticalLayout->setStretch(7, 1);
        verticalLayout->setStretch(8, 2);
        verticalLayout->setStretch(10, 2);
        verticalLayout->setStretch(11, 2);

        horizontalLayout_3->addLayout(verticalLayout);

        horizontalSpacer_7 = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_7);

        stackedWidget->addWidget(login_Page);
        receipt_Page = new QWidget();
        receipt_Page->setObjectName("receipt_Page");
        stackedWidget->addWidget(receipt_Page);
        deleteAccount_Page = new QWidget();
        deleteAccount_Page->setObjectName("deleteAccount_Page");
        horizontalLayoutWidget = new QWidget(deleteAccount_Page);
        horizontalLayoutWidget->setObjectName("horizontalLayoutWidget");
        horizontalLayoutWidget->setGeometry(QRect(200, 170, 511, 331));
        horizontalLayout_4 = new QHBoxLayout(horizontalLayoutWidget);
        horizontalLayout_4->setObjectName("horizontalLayout_4");
        horizontalLayout_4->setContentsMargins(0, 0, 0, 0);
        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setObjectName("verticalLayout_3");
        enterPass_Label = new QLabel(horizontalLayoutWidget);
        enterPass_Label->setObjectName("enterPass_Label");
        QFont font2;
        font2.setPointSize(12);
        font2.setBold(true);
        font2.setItalic(true);
        enterPass_Label->setFont(font2);

        verticalLayout_3->addWidget(enterPass_Label);

        deletePass_Line = new QLineEdit(horizontalLayoutWidget);
        deletePass_Line->setObjectName("deletePass_Line");

        verticalLayout_3->addWidget(deletePass_Line);

        enterPassConfirm_Label = new QLabel(horizontalLayoutWidget);
        enterPassConfirm_Label->setObjectName("enterPassConfirm_Label");
        enterPassConfirm_Label->setFont(font2);
        enterPassConfirm_Label->setLineWidth(1);
        enterPassConfirm_Label->setAlignment(Qt::AlignmentFlag::AlignCenter);

        verticalLayout_3->addWidget(enterPassConfirm_Label);

        deletePassConfirm_Line = new QLineEdit(horizontalLayoutWidget);
        deletePassConfirm_Line->setObjectName("deletePassConfirm_Line");

        verticalLayout_3->addWidget(deletePassConfirm_Line);

        horizontalSlider = new QSlider(horizontalLayoutWidget);
        horizontalSlider->setObjectName("horizontalSlider");
        QFont font3;
        font3.setBold(true);
        horizontalSlider->setFont(font3);
        horizontalSlider->setCursor(QCursor(Qt::CursorShape::SizeAllCursor));
        horizontalSlider->setMinimum(0);
        horizontalSlider->setMaximum(20);
        horizontalSlider->setValue(0);
        horizontalSlider->setSliderPosition(0);
        horizontalSlider->setTracking(true);
        horizontalSlider->setOrientation(Qt::Orientation::Horizontal);
        horizontalSlider->setInvertedAppearance(false);
        horizontalSlider->setTickPosition(QSlider::TickPosition::TicksBelow);
        horizontalSlider->setTickInterval(4);

        verticalLayout_3->addWidget(horizontalSlider);

        deletion_Label = new QLabel(horizontalLayoutWidget);
        deletion_Label->setObjectName("deletion_Label");
        deletion_Label->setFont(font2);
        deletion_Label->setLineWidth(1);
        deletion_Label->setAlignment(Qt::AlignmentFlag::AlignCenter);

        verticalLayout_3->addWidget(deletion_Label);


        horizontalLayout_4->addLayout(verticalLayout_3);

        stackedWidget->addWidget(deleteAccount_Page);
        accounts_Page = new QWidget();
        accounts_Page->setObjectName("accounts_Page");
        horizontalLayout_5 = new QHBoxLayout(accounts_Page);
        horizontalLayout_5->setObjectName("horizontalLayout_5");
        horizontalSpacer_4 = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout_5->addItem(horizontalSpacer_4);

        verticalLayout_8 = new QVBoxLayout();
        verticalLayout_8->setSpacing(0);
        verticalLayout_8->setObjectName("verticalLayout_8");
        verticalLayout_8->setContentsMargins(-1, 10, -1, 10);
        verticalSpacer_3 = new QSpacerItem(20, 40, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Expanding);

        verticalLayout_8->addItem(verticalSpacer_3);

        current_acc_button = new QPushButton(accounts_Page);
        current_acc_button->setObjectName("current_acc_button");
        sizePolicy.setHeightForWidth(current_acc_button->sizePolicy().hasHeightForWidth());
        current_acc_button->setSizePolicy(sizePolicy);
        QFont font4;
        font4.setPointSize(15);
        font4.setBold(true);
        current_acc_button->setFont(font4);

        verticalLayout_8->addWidget(current_acc_button);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Expanding);

        verticalLayout_8->addItem(verticalSpacer);

        savings_acc_button = new QPushButton(accounts_Page);
        savings_acc_button->setObjectName("savings_acc_button");
        sizePolicy.setHeightForWidth(savings_acc_button->sizePolicy().hasHeightForWidth());
        savings_acc_button->setSizePolicy(sizePolicy);
        savings_acc_button->setFont(font4);

        verticalLayout_8->addWidget(savings_acc_button);

        verticalSpacer_2 = new QSpacerItem(20, 40, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Expanding);

        verticalLayout_8->addItem(verticalSpacer_2);

        default_acc_button = new QPushButton(accounts_Page);
        default_acc_button->setObjectName("default_acc_button");
        sizePolicy.setHeightForWidth(default_acc_button->sizePolicy().hasHeightForWidth());
        default_acc_button->setSizePolicy(sizePolicy);
        default_acc_button->setFont(font4);

        verticalLayout_8->addWidget(default_acc_button);

        verticalSpacer_4 = new QSpacerItem(20, 40, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Expanding);

        verticalLayout_8->addItem(verticalSpacer_4);


        horizontalLayout_5->addLayout(verticalLayout_8);

        horizontalSpacer_5 = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout_5->addItem(horizontalSpacer_5);

        stackedWidget->addWidget(accounts_Page);
        dashboard_Page = new QWidget();
        dashboard_Page->setObjectName("dashboard_Page");
        horizontalLayout_2 = new QHBoxLayout(dashboard_Page);
        horizontalLayout_2->setObjectName("horizontalLayout_2");
        verticalLayout_6 = new QVBoxLayout();
        verticalLayout_6->setSpacing(0);
        verticalLayout_6->setObjectName("verticalLayout_6");
        amount1000_Button = new QPushButton(dashboard_Page);
        amount1000_Button->setObjectName("amount1000_Button");
        amount1000_Button->setMinimumSize(QSize(100, 100));
        QFont font5;
        font5.setPointSize(12);
        font5.setBold(true);
        amount1000_Button->setFont(font5);

        verticalLayout_6->addWidget(amount1000_Button);

        amount5000_Button = new QPushButton(dashboard_Page);
        amount5000_Button->setObjectName("amount5000_Button");
        amount5000_Button->setMinimumSize(QSize(100, 100));
        amount5000_Button->setFont(font5);

        verticalLayout_6->addWidget(amount5000_Button);

        amount10000_Button = new QPushButton(dashboard_Page);
        amount10000_Button->setObjectName("amount10000_Button");
        amount10000_Button->setMinimumSize(QSize(100, 100));
        amount10000_Button->setFont(font5);

        verticalLayout_6->addWidget(amount10000_Button);

        amount20000_Button = new QPushButton(dashboard_Page);
        amount20000_Button->setObjectName("amount20000_Button");
        amount20000_Button->setMinimumSize(QSize(100, 100));
        amount20000_Button->setFont(font5);

        verticalLayout_6->addWidget(amount20000_Button);

        label_2 = new QLabel(dashboard_Page);
        label_2->setObjectName("label_2");
        QSizePolicy sizePolicy1(QSizePolicy::Policy::Fixed, QSizePolicy::Policy::Maximum);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(label_2->sizePolicy().hasHeightForWidth());
        label_2->setSizePolicy(sizePolicy1);

        verticalLayout_6->addWidget(label_2);


        horizontalLayout_2->addLayout(verticalLayout_6);

        horizontalSpacer_3 = new QSpacerItem(695, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_3);

        verticalLayout_7 = new QVBoxLayout();
        verticalLayout_7->setSpacing(0);
        verticalLayout_7->setObjectName("verticalLayout_7");
        amount25000_Button = new QPushButton(dashboard_Page);
        amount25000_Button->setObjectName("amount25000_Button");
        amount25000_Button->setMinimumSize(QSize(100, 100));
        amount25000_Button->setFont(font5);

        verticalLayout_7->addWidget(amount25000_Button);

        otherAmount_Button = new QPushButton(dashboard_Page);
        otherAmount_Button->setObjectName("otherAmount_Button");
        otherAmount_Button->setMinimumSize(QSize(100, 100));
        otherAmount_Button->setFont(font5);

        verticalLayout_7->addWidget(otherAmount_Button);

        deposit_Button = new QPushButton(dashboard_Page);
        deposit_Button->setObjectName("deposit_Button");
        deposit_Button->setMinimumSize(QSize(100, 100));
        deposit_Button->setFont(font5);

        verticalLayout_7->addWidget(deposit_Button);

        checkBalance_Button = new QPushButton(dashboard_Page);
        checkBalance_Button->setObjectName("checkBalance_Button");
        checkBalance_Button->setMinimumSize(QSize(100, 100));
        checkBalance_Button->setFont(font5);

        verticalLayout_7->addWidget(checkBalance_Button);

        settings_Button = new QToolButton(dashboard_Page);
        settings_Button->setObjectName("settings_Button");
        settings_Button->setMinimumSize(QSize(0, 0));
        QFont font6;
        font6.setPointSize(10);
        settings_Button->setFont(font6);

        verticalLayout_7->addWidget(settings_Button);


        horizontalLayout_2->addLayout(verticalLayout_7);

        stackedWidget->addWidget(dashboard_Page);
        createUser_Page = new QWidget();
        createUser_Page->setObjectName("createUser_Page");
        verticalLayoutWidget = new QWidget(createUser_Page);
        verticalLayoutWidget->setObjectName("verticalLayoutWidget");
        verticalLayoutWidget->setGeometry(QRect(289, 60, 221, 461));
        verticalLayout_2 = new QVBoxLayout(verticalLayoutWidget);
        verticalLayout_2->setSpacing(1);
        verticalLayout_2->setObjectName("verticalLayout_2");
        verticalLayout_2->setContentsMargins(5, 5, 5, 5);
        frame_3 = new QFrame(verticalLayoutWidget);
        frame_3->setObjectName("frame_3");
        frame_3->setFrameShape(QFrame::Shape::StyledPanel);
        frame_3->setFrameShadow(QFrame::Shadow::Raised);
        newUser_Line = new QLineEdit(frame_3);
        newUser_Line->setObjectName("newUser_Line");
        newUser_Line->setGeometry(QRect(0, 70, 181, 31));
        newUser_Line_2 = new QLabel(frame_3);
        newUser_Line_2->setObjectName("newUser_Line_2");
        newUser_Line_2->setGeometry(QRect(0, 40, 181, 20));

        verticalLayout_2->addWidget(frame_3);

        frame_5 = new QFrame(verticalLayoutWidget);
        frame_5->setObjectName("frame_5");
        frame_5->setFrameShape(QFrame::Shape::StyledPanel);
        frame_5->setFrameShadow(QFrame::Shadow::Raised);
        confirmPassword_Line = new QLineEdit(frame_5);
        confirmPassword_Line->setObjectName("confirmPassword_Line");
        confirmPassword_Line->setGeometry(QRect(0, 70, 1000, 31));
        confirmPassword_Label = new QLabel(frame_5);
        confirmPassword_Label->setObjectName("confirmPassword_Label");
        confirmPassword_Label->setGeometry(QRect(0, 40, 181, 20));

        verticalLayout_2->addWidget(frame_5);

        frame_4 = new QFrame(verticalLayoutWidget);
        frame_4->setObjectName("frame_4");
        frame_4->setFrameShape(QFrame::Shape::StyledPanel);
        frame_4->setFrameShadow(QFrame::Shadow::Raised);
        newPassword_Line = new QLineEdit(frame_4);
        newPassword_Line->setObjectName("newPassword_Line");
        newPassword_Line->setGeometry(QRect(0, 70, 181, 31));
        newPassword_Label = new QLabel(frame_4);
        newPassword_Label->setObjectName("newPassword_Label");
        newPassword_Label->setGeometry(QRect(0, 40, 181, 20));

        verticalLayout_2->addWidget(frame_4);

        submitApplication_Button = new QPushButton(verticalLayoutWidget);
        submitApplication_Button->setObjectName("submitApplication_Button");
        submitApplication_Button->setStyleSheet(QString::fromUtf8("background-color: qradialgradient(spread:reflect, cx:0.5, cy:0.5, radius:1.026, fx:0.331, fy:0.245, stop:0 rgba(4, 7, 255, 255), stop:1 rgba(255, 255, 255, 255));"));

        verticalLayout_2->addWidget(submitApplication_Button);

        acc_Cancel_Button = new QPushButton(verticalLayoutWidget);
        acc_Cancel_Button->setObjectName("acc_Cancel_Button");
        acc_Cancel_Button->setStyleSheet(QString::fromUtf8("background-color: qradialgradient(spread:reflect, cx:0.5, cy:0.5, radius:1.026, fx:0.331, fy:0.245, stop:0 rgba(4, 7, 255, 255), stop:1 rgba(255, 255, 255, 255));"));

        verticalLayout_2->addWidget(acc_Cancel_Button);

        stackedWidget->addWidget(createUser_Page);
        numpad_Page = new QWidget();
        numpad_Page->setObjectName("numpad_Page");
        horizontalLayout_6 = new QHBoxLayout(numpad_Page);
        horizontalLayout_6->setObjectName("horizontalLayout_6");
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout_6->addItem(horizontalSpacer);

        verticalLayout_10 = new QVBoxLayout();
        verticalLayout_10->setSpacing(2);
        verticalLayout_10->setObjectName("verticalLayout_10");
        verticalSpacer_5 = new QSpacerItem(20, 40, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Expanding);

        verticalLayout_10->addItem(verticalSpacer_5);

        lcdNumber = new QLCDNumber(numpad_Page);
        lcdNumber->setObjectName("lcdNumber");
        QFont font7;
        font7.setBold(false);
        lcdNumber->setFont(font7);
        lcdNumber->setSmallDecimalPoint(false);
        lcdNumber->setDigitCount(9);

        verticalLayout_10->addWidget(lcdNumber);

        numpad_Grid = new QGridLayout();
        numpad_Grid->setObjectName("numpad_Grid");
        numpad_Grid->setContentsMargins(5, 5, 5, 5);
        depositEnter_Button = new QPushButton(numpad_Page);
        depositEnter_Button->setObjectName("depositEnter_Button");
        depositEnter_Button->setMinimumSize(QSize(75, 75));

        numpad_Grid->addWidget(depositEnter_Button, 2, 3, 1, 1);

        blank_Button_2 = new QPushButton(numpad_Page);
        blank_Button_2->setObjectName("blank_Button_2");
        blank_Button_2->setMinimumSize(QSize(75, 75));

        numpad_Grid->addWidget(blank_Button_2, 3, 0, 1, 1);

        four_Button = new QPushButton(numpad_Page);
        four_Button->setObjectName("four_Button");
        four_Button->setMinimumSize(QSize(75, 75));

        numpad_Grid->addWidget(four_Button, 1, 0, 1, 1);

        blank_Button_3 = new QPushButton(numpad_Page);
        blank_Button_3->setObjectName("blank_Button_3");
        blank_Button_3->setMinimumSize(QSize(75, 75));

        numpad_Grid->addWidget(blank_Button_3, 3, 3, 1, 1);

        eight_Button = new QPushButton(numpad_Page);
        eight_Button->setObjectName("eight_Button");
        eight_Button->setMinimumSize(QSize(75, 75));

        numpad_Grid->addWidget(eight_Button, 2, 1, 1, 1);

        cancel_Button = new QPushButton(numpad_Page);
        cancel_Button->setObjectName("cancel_Button");
        cancel_Button->setMinimumSize(QSize(75, 75));

        numpad_Grid->addWidget(cancel_Button, 1, 3, 1, 1);

        seven_Button = new QPushButton(numpad_Page);
        seven_Button->setObjectName("seven_Button");
        seven_Button->setMinimumSize(QSize(75, 75));

        numpad_Grid->addWidget(seven_Button, 2, 0, 1, 1);

        three_Button = new QPushButton(numpad_Page);
        three_Button->setObjectName("three_Button");
        three_Button->setMinimumSize(QSize(75, 75));

        numpad_Grid->addWidget(three_Button, 0, 2, 1, 1);

        five_Button = new QPushButton(numpad_Page);
        five_Button->setObjectName("five_Button");
        five_Button->setMinimumSize(QSize(75, 75));

        numpad_Grid->addWidget(five_Button, 1, 1, 1, 1);

        clear_Button = new QPushButton(numpad_Page);
        clear_Button->setObjectName("clear_Button");
        clear_Button->setMinimumSize(QSize(75, 75));

        numpad_Grid->addWidget(clear_Button, 0, 3, 1, 1);

        nine_Button = new QPushButton(numpad_Page);
        nine_Button->setObjectName("nine_Button");
        nine_Button->setMinimumSize(QSize(75, 75));

        numpad_Grid->addWidget(nine_Button, 2, 2, 1, 1);

        zero_Button = new QPushButton(numpad_Page);
        zero_Button->setObjectName("zero_Button");
        zero_Button->setMinimumSize(QSize(75, 75));

        numpad_Grid->addWidget(zero_Button, 3, 1, 1, 1);

        two_Button = new QPushButton(numpad_Page);
        two_Button->setObjectName("two_Button");
        two_Button->setMinimumSize(QSize(75, 75));

        numpad_Grid->addWidget(two_Button, 0, 1, 1, 1);

        blank_Button = new QPushButton(numpad_Page);
        blank_Button->setObjectName("blank_Button");
        blank_Button->setMinimumSize(QSize(75, 75));

        numpad_Grid->addWidget(blank_Button, 3, 2, 1, 1);

        six_Button = new QPushButton(numpad_Page);
        six_Button->setObjectName("six_Button");
        six_Button->setMinimumSize(QSize(75, 75));

        numpad_Grid->addWidget(six_Button, 1, 2, 1, 1);

        one_Button = new QPushButton(numpad_Page);
        one_Button->setObjectName("one_Button");
        one_Button->setMinimumSize(QSize(75, 75));

        numpad_Grid->addWidget(one_Button, 0, 0, 1, 1);


        verticalLayout_10->addLayout(numpad_Grid);

        verticalSpacer_6 = new QSpacerItem(20, 40, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Expanding);

        verticalLayout_10->addItem(verticalSpacer_6);

        verticalLayout_10->setStretch(0, 1);
        verticalLayout_10->setStretch(1, 2);
        verticalLayout_10->setStretch(2, 4);
        verticalLayout_10->setStretch(3, 1);

        horizontalLayout_6->addLayout(verticalLayout_10);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout_6->addItem(horizontalSpacer_2);

        stackedWidget->addWidget(numpad_Page);

        horizontalLayout->addWidget(stackedWidget);

        MainWindow->setCentralWidget(centralwidget);

        retranslateUi(MainWindow);

        stackedWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        BankalLums->setText(QCoreApplication::translate("MainWindow", "Bank al LUMS", nullptr));
        username_Label->setText(QCoreApplication::translate("MainWindow", "UserName:", nullptr));
        password_Label->setText(QCoreApplication::translate("MainWindow", "Password:", nullptr));
        login_button->setText(QCoreApplication::translate("MainWindow", "Login", nullptr));
        createAccount_Button->setText(QCoreApplication::translate("MainWindow", "Create New account", nullptr));
        enterPass_Label->setText(QCoreApplication::translate("MainWindow", "Enter password", nullptr));
        enterPassConfirm_Label->setText(QCoreApplication::translate("MainWindow", "Enter password again", nullptr));
        deletion_Label->setText(QCoreApplication::translate("MainWindow", "Slide to the right end to confirm deletion of your account!", nullptr));
        current_acc_button->setText(QCoreApplication::translate("MainWindow", "Current Account", nullptr));
        savings_acc_button->setText(QCoreApplication::translate("MainWindow", "Savings Account", nullptr));
        default_acc_button->setText(QCoreApplication::translate("MainWindow", "Default Account", nullptr));
        amount1000_Button->setText(QCoreApplication::translate("MainWindow", "1,000", nullptr));
        amount5000_Button->setText(QCoreApplication::translate("MainWindow", "5,000", nullptr));
        amount10000_Button->setText(QCoreApplication::translate("MainWindow", "10,000", nullptr));
        amount20000_Button->setText(QCoreApplication::translate("MainWindow", "20,000", nullptr));
        label_2->setText(QString());
        amount25000_Button->setText(QCoreApplication::translate("MainWindow", "25,000", nullptr));
        otherAmount_Button->setText(QCoreApplication::translate("MainWindow", "Other\n"
"Amount", nullptr));
        deposit_Button->setText(QCoreApplication::translate("MainWindow", "Deposit", nullptr));
        checkBalance_Button->setText(QCoreApplication::translate("MainWindow", "Check\n"
"Balance", nullptr));
        settings_Button->setText(QCoreApplication::translate("MainWindow", "Settings", nullptr));
        newUser_Line_2->setText(QCoreApplication::translate("MainWindow", "Enter UserName", nullptr));
        confirmPassword_Label->setText(QCoreApplication::translate("MainWindow", "Confirm Password", nullptr));
        newPassword_Label->setText(QCoreApplication::translate("MainWindow", "Enter Password", nullptr));
        submitApplication_Button->setText(QCoreApplication::translate("MainWindow", "Create account", nullptr));
        acc_Cancel_Button->setText(QCoreApplication::translate("MainWindow", "Cancel", nullptr));
        depositEnter_Button->setText(QCoreApplication::translate("MainWindow", "Enter", nullptr));
        blank_Button_2->setText(QString());
        four_Button->setText(QCoreApplication::translate("MainWindow", "4", nullptr));
        blank_Button_3->setText(QString());
        eight_Button->setText(QCoreApplication::translate("MainWindow", "8", nullptr));
        cancel_Button->setText(QCoreApplication::translate("MainWindow", "Cancel", nullptr));
        seven_Button->setText(QCoreApplication::translate("MainWindow", "7", nullptr));
        three_Button->setText(QCoreApplication::translate("MainWindow", "3", nullptr));
        five_Button->setText(QCoreApplication::translate("MainWindow", "5", nullptr));
        clear_Button->setText(QCoreApplication::translate("MainWindow", "Clear", nullptr));
        nine_Button->setText(QCoreApplication::translate("MainWindow", "9", nullptr));
        zero_Button->setText(QCoreApplication::translate("MainWindow", "0", nullptr));
        two_Button->setText(QCoreApplication::translate("MainWindow", "2", nullptr));
        blank_Button->setText(QString());
        six_Button->setText(QCoreApplication::translate("MainWindow", "6", nullptr));
        one_Button->setText(QCoreApplication::translate("MainWindow", "1", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
