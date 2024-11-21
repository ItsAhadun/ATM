/********************************************************************************
** Form generated from reading UI file 'dashboard_page.ui'
**
** Created by: Qt User Interface Compiler version 6.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DASHBOARD_PAGE_H
#define UI_DASHBOARD_PAGE_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_dashboard_page
{
public:
    QWidget *centralwidget;

    void setupUi(QMainWindow *dashboard_page)
    {
        if (dashboard_page->objectName().isEmpty())
            dashboard_page->setObjectName("dashboard_page");
        dashboard_page->resize(800, 600);
        centralwidget = new QWidget(dashboard_page);
        centralwidget->setObjectName("centralwidget");
        dashboard_page->setCentralWidget(centralwidget);

        retranslateUi(dashboard_page);

        QMetaObject::connectSlotsByName(dashboard_page);
    } // setupUi

    void retranslateUi(QMainWindow *dashboard_page)
    {
        dashboard_page->setWindowTitle(QCoreApplication::translate("dashboard_page", "MainWindow", nullptr));
    } // retranslateUi

};

namespace Ui {
    class dashboard_page: public Ui_dashboard_page {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DASHBOARD_PAGE_H
