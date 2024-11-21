/********************************************************************************
** Form generated from reading UI file 'numpad_page.ui'
**
** Created by: Qt User Interface Compiler version 6.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_NUMPAD_PAGE_H
#define UI_NUMPAD_PAGE_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_numpad_page
{
public:
    QWidget *centralwidget;

    void setupUi(QMainWindow *numpad_page)
    {
        if (numpad_page->objectName().isEmpty())
            numpad_page->setObjectName("numpad_page");
        numpad_page->resize(800, 600);
        centralwidget = new QWidget(numpad_page);
        centralwidget->setObjectName("centralwidget");
        numpad_page->setCentralWidget(centralwidget);

        retranslateUi(numpad_page);

        QMetaObject::connectSlotsByName(numpad_page);
    } // setupUi

    void retranslateUi(QMainWindow *numpad_page)
    {
        numpad_page->setWindowTitle(QCoreApplication::translate("numpad_page", "MainWindow", nullptr));
    } // retranslateUi

};

namespace Ui {
    class numpad_page: public Ui_numpad_page {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_NUMPAD_PAGE_H
