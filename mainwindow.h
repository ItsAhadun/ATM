#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QMap>
#include <QWidget>

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void login_button();
    void on_current_acc_button_clicked();
    void on_savings_acc_button_clicked();
    void on_default_acc_button_clicked();

    void on_createaccount_button_clicked();
    void on_createAccount_Button_clicked();

    void on_one_Button_clicked();

    void on_login_button_pressed();

    void on_lineEdit_2_returnPressed();

private:
    Ui::MainWindow *ui;
    QMap<QString, QWidget*> screenMap;  // Map to store widgets by name
};

#endif // MAINWINDOW_H
