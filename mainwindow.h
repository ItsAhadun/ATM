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
    void on_createAccount_Button_clicked();
    void on_one_Button_clicked();
    void on_login_button_pressed();
    void on_lineEdit_2_returnPressed();
    void on_submitApplication_Button_clicked();
    void on_deposit_Button_clicked();
    void on_two_Button_clicked();


    void num_pressed(); //numpad buttons
    void on_cancel_Button_clicked();
    void on_clear_Button_clicked();

    void on_checkBalance_Button_clicked();

    void on_depositEnter_Button_clicked();

protected:


private:
    Ui::MainWindow *ui;
    QMap<QString, QWidget*> screenMap;
    QString loggedInUsername;
    QString currentInput;
};

#endif
