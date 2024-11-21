#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QMap>
#include <QPropertyAnimation>
#include <QTimer>
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
    void on_submitApplication_Button_clicked();
    void on_deposit_Button_clicked();
    void on_withdraw_Button_clicked();
    void on_checkBalance_Button_clicked();

protected:
    bool eventFilter(QObject *watched, QEvent *event) override;

private:
    void logTransaction(const QString &username, const QString &action, double amount);

    Ui::MainWindow *ui;
    QMap<QString, QWidget*> screenMap;
    QPropertyAnimation *loginButtonAnimation;
    QString currentUser;  // Store the username of the currently logged-in user
};

#endif // MAINWINDOW_H
