/********************************************************************************
** Form generated from reading UI file 'create_user_page.ui'
**
** Created by: Qt User Interface Compiler version 6.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CREATE_USER_PAGE_H
#define UI_CREATE_USER_PAGE_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_create_user_page
{
public:
    QWidget *centralwidget;

    void setupUi(QMainWindow *create_user_page)
    {
        if (create_user_page->objectName().isEmpty())
            create_user_page->setObjectName("create_user_page");
        create_user_page->resize(800, 600);
        centralwidget = new QWidget(create_user_page);
        centralwidget->setObjectName("centralwidget");
        create_user_page->setCentralWidget(centralwidget);

        retranslateUi(create_user_page);

        QMetaObject::connectSlotsByName(create_user_page);
    } // setupUi

    void retranslateUi(QMainWindow *create_user_page)
    {
        create_user_page->setWindowTitle(QCoreApplication::translate("create_user_page", "MainWindow", nullptr));
    } // retranslateUi

};

namespace Ui {
    class create_user_page: public Ui_create_user_page {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CREATE_USER_PAGE_H
