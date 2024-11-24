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
    // User Authentication
    void on_login_button_clicked();
    void on_loginPass_Line_returnPressed();

    // Helper functions
    bool isValidPin(const QString& pin);
    void handleInvalidPin(const QString& username);
    bool isAccountLocked(const QString& username);
    bool validateLogin(const QString& username, const QString& password);
    void handleSuccessfulLogin(const QString& username);
    void handleFailedLogin(const QString& username);
    void lockAccount(const QString& username);

    // Account Management
    void on_createAccount_Button_clicked();
    void on_submitApplication_Button_clicked();
    void on_acc_Cancel_Button_clicked();

    // Account Selection
    void on_current_acc_button_clicked();
    void on_savings_acc_button_clicked();
    void on_default_acc_button_clicked();

    // Transactions
    void on_deposit_Button_clicked();
    void on_depositEnter_Button_clicked();
    void processWithdrawal(double amount);
    void on_checkBalance_Button_clicked();
    void on_otherAmount_Button_clicked();
    void on_amount1000_Button_clicked();
    void on_amount5000_Button_clicked();
    void on_amount10000_Button_clicked();
    void on_amount20000_Button_clicked();
    void on_amount25000_Button_clicked();

    // Numpad Operations
    void num_pressed();
    void on_clear_Button_clicked();
    void on_cancel_Button_clicked();

    // Settings and Actions
    void on_settings_Button_triggered(QAction *arg1);
    void on_horizontalSlider_valueChanged(int value);
    void on_deleteAccount_action();


protected:


private:
    Ui::MainWindow *ui;
    QMap<QString, QWidget*> screenMap;
    QString loggedInUsername;
    QString currentInput;
    enum OperationMode { Deposit, Withdrawal };
    OperationMode currentMode;
    enum AccountMode { Savings, Current };
    AccountMode currentAccountMode;
    QMenu *settingsMenu;
    void setupSettingsButton();
    void logoutAction();
    void settingsAction();
    bool isAmountValid(double amount);
};

#endif
