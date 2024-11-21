/********************************************************************************
** Form generated from reading UI file 'accounts_page.ui'
**
** Created by: Qt User Interface Compiler version 6.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ACCOUNTS_PAGE_H
#define UI_ACCOUNTS_PAGE_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_accounts_page
{
public:
    QWidget *centralwidget;

    void setupUi(QMainWindow *accounts_page)
    {
        if (accounts_page->objectName().isEmpty())
            accounts_page->setObjectName("accounts_page");
        accounts_page->resize(800, 600);
        centralwidget = new QWidget(accounts_page);
        centralwidget->setObjectName("centralwidget");
        accounts_page->setCentralWidget(centralwidget);

        retranslateUi(accounts_page);

        QMetaObject::connectSlotsByName(accounts_page);
    } // setupUi

    void retranslateUi(QMainWindow *accounts_page)
    {
        accounts_page->setWindowTitle(QCoreApplication::translate("accounts_page", "MainWindow", nullptr));
    } // retranslateUi

};

namespace Ui {
    class accounts_page: public Ui_accounts_page {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ACCOUNTS_PAGE_H
