#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlError>
#include <QVariant>
#include <QDebug>
#include <QDateTime>
#include <QMenu>
#include <QToolButton>
using namespace std;

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)

{

    ui->setupUi(this);
    ui->stackedWidget->setCurrentWidget(ui->login_Page);

    setupSettingsButton();

    // Set up the SQLite database
    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("bankingApp.db");

    if (!db.open()) {
        QMessageBox::critical(this, "Database Error", "Failed to open the database: " + db.lastError().text());
        return;
    }

    QSqlQuery query;
    if (!query.exec(R"(
    CREATE TABLE IF NOT EXISTS users (
        id INTEGER PRIMARY KEY AUTOINCREMENT,
        username TEXT UNIQUE,
        password TEXT,
        savings_balance REAL DEFAULT 0,
        current_balance REAL DEFAULT 0,
        failed_attempts INTEGER DEFAULT 0,
        is_locked INTEGER DEFAULT 0,
        last_failed_login DATETIME
    )
    )")) {
        QMessageBox::critical(this, "Database Error", "Failed to create table: " + query.lastError().text());
    }

    currentInput = ""; // Start with an empty string

    //numpad connections
    connect(ui->zero_Button, &QPushButton::released, this, &MainWindow::num_pressed);
    connect(ui->one_Button, &QPushButton::released, this, &MainWindow::num_pressed);
    connect(ui->two_Button, &QPushButton::released, this, &MainWindow::num_pressed);
    connect(ui->three_Button, &QPushButton::released, this, &MainWindow::num_pressed);
    connect(ui->four_Button, &QPushButton::released, this, &MainWindow::num_pressed);
    connect(ui->five_Button, &QPushButton::released, this, &MainWindow::num_pressed);
    connect(ui->six_Button, &QPushButton::released, this, &MainWindow::num_pressed);
    connect(ui->seven_Button, &QPushButton::released, this, &MainWindow::num_pressed);
    connect(ui->eight_Button, &QPushButton::released, this, &MainWindow::num_pressed);
    connect(ui->nine_Button, &QPushButton::released, this, &MainWindow::num_pressed);

}

MainWindow::~MainWindow()
{
    delete ui;
    QSqlDatabase::database().close();

}


bool isValidPin(const QString &pin)
{
    string pinStr = pin.toStdString();

    if (pinStr.length() != 4) {
        return false;
    }

    for (size_t i = 0; i < 4; ++i) {
        char ch = pinStr.substr(i, 1)[0];
        if (ch < 48 || ch > 57)
        {
            return false;
        }
    }
    return true;
}


void MainWindow::on_login_button_clicked()
{
    QString uName = ui->loginUser_Line->text();
    QString uCode = ui->loginPass_Line->text();

    // Validate PIN
    if (!isValidPin(uCode))
    {
        QMessageBox::warning(this, "Input Error", "Password must be a 4-digit PIN.");
        return;
    }

    QSqlQuery query;

    // Check if the account is locked
    query.prepare("SELECT is_locked, last_failed_login, failed_attempts FROM users WHERE username = :username");
    query.bindValue(":username", uName);

    if (query.exec() && query.next()) {
        bool isLocked = query.value("is_locked").toBool();
        QDateTime lastFailedLogin = query.value("last_failed_login").toDateTime();

        if (isLocked) {
            // Timeout duration (e.g., 5 minutes)
            int timeoutMinutes = 5;
            QDateTime unlockTime = lastFailedLogin.addSecs(timeoutMinutes * 60);
            QDateTime currentTime = QDateTime::currentDateTime();

            if (currentTime < unlockTime) {
                // Calculate remaining time
                int remainingSeconds = currentTime.secsTo(unlockTime);
                int minutes = remainingSeconds / 60;
                int seconds = remainingSeconds % 60;

                QMessageBox::warning(this, "Account Locked",
                                     QString("Your account is locked. Please try again in %1 minutes and %2 seconds.")
                                         .arg(minutes)
                                         .arg(seconds));
                return;
            } else {
                // Unlock the account
                QSqlQuery unlockQuery;
                unlockQuery.prepare("UPDATE users SET is_locked = 0, failed_attempts = 0 WHERE username = :username");
                unlockQuery.bindValue(":username", uName);
                if (!unlockQuery.exec()) {
                    QMessageBox::critical(this, "Database Error", "Failed to unlock account: " + unlockQuery.lastError().text());
                    return;
                }
            }
        }
    }
    else
    {
        QMessageBox::critical(this, "Invalid Info", "Entered Username or Password is incorrect");

    }

    // Proceed with login validation
    query.prepare("SELECT * FROM users WHERE username = :username AND password = :password");
    query.bindValue(":username", uName);
    query.bindValue(":password", uCode);

    if (query.exec() && query.next())
    {
        // Successful login
        loggedInUsername = uName;
        ui->stackedWidget->setCurrentWidget(ui->accounts_Page);
        QMessageBox::information(this, "Welcome", "Welcome to Bank al LUMS, " + uName + "!");
        ui->loginUser_Line->clear();
        ui->loginPass_Line->clear();
        // Reset failed attempts and unlock account
        QSqlQuery resetQuery;
        resetQuery.prepare("UPDATE users SET failed_attempts = 0, is_locked = 0 WHERE username = :username");
        resetQuery.bindValue(":username", uName);
        if (!resetQuery.exec()) {
            QMessageBox::critical(this, "Database Error", "Failed to reset login attempts: " + resetQuery.lastError().text());

        }

    } else {
        // Failed login
        QSqlQuery updateQuery;
        updateQuery.prepare("UPDATE users SET failed_attempts = failed_attempts + 1 WHERE username = :username");
        updateQuery.bindValue(":username", uName);
        if (!updateQuery.exec()) {
            QMessageBox::critical(this, "Database Error", "Failed to update failed attempts: " + updateQuery.lastError().text());
            return;
        }

        // Check if failed attempts exceed threshold
        query.prepare("SELECT failed_attempts FROM users WHERE username = :username");
        query.bindValue(":username", uName);
        if (query.exec() && query.next()) {
            int failedAttempts = query.value("failed_attempts").toInt();
            if (failedAttempts >= 3) {
                QSqlQuery lockQuery;
                lockQuery.prepare("UPDATE users SET is_locked = 1, last_failed_login = :timestamp WHERE username = :username");
                lockQuery.bindValue(":username", uName);
                lockQuery.bindValue(":timestamp", QDateTime::currentDateTime().toString(Qt::ISODate));
                if (lockQuery.exec()) {
                    QMessageBox::warning(this, "Account Locked", "Your account has been locked due to multiple failed login attempts. Please try again later.");
                } else {
                    QMessageBox::critical(this, "Database Error", "Failed to lock account: " + lockQuery.lastError().text());
                }
            } else {
                QMessageBox::warning(this, "Login Failed", "Invalid username or password. Remaining attempts: " + QString::number(3 - failedAttempts));
            }
        }
    }

}


void MainWindow::on_current_acc_button_clicked()
{
    currentAccountMode = Current;
    ui->stackedWidget->setCurrentWidget(ui->dashboard_Page);
}

void MainWindow::on_savings_acc_button_clicked()
{
    currentAccountMode = Savings;
    ui->stackedWidget->setCurrentWidget(ui->dashboard_Page);
}

void MainWindow::on_default_acc_button_clicked()
{
    currentAccountMode = Savings;
    ui->stackedWidget->setCurrentWidget(ui->dashboard_Page);
}

void MainWindow::on_submitApplication_Button_clicked()
{
    QString newUsername = ui->newUser_Line->text();
    QString newPassword = ui->newPassword_Line->text();
    QString confirmPassword = ui->confirmPassword_Line->text();

    if (newUsername.isEmpty() || newPassword.isEmpty()) {
        QMessageBox::warning(this, "Input Error", "Please enter both a username and a password.");
        return;
    }

    if (newPassword != confirmPassword)
    {
        QMessageBox::warning(this, "Input Error", "Passwords do not match.");
        return;
    }
    // Validate PIN
    if (!isValidPin(newPassword))
    {
        QMessageBox::warning(this, "Input Error", "Password must be a 4-digit PIN.");
        return;
    }

    QSqlQuery query;
    query.prepare("INSERT INTO users (username, password) VALUES (:username, :password)");
    query.bindValue(":username", newUsername);
    query.bindValue(":password", newPassword);

    if (query.exec()) {
        QMessageBox::information(this, "Success", "Account created successfully!");
        ui->stackedWidget->setCurrentWidget(ui->login_Page);
    } else {
        QMessageBox::critical(this, "Database Error", "Failed to create account: " + query.lastError().text());
    }

    ui->confirmPassword_Line->clear();
    ui->newPassword_Line->clear();
    ui->newUser_Line->clear();
}


void MainWindow::on_createAccount_Button_clicked()
{
    ui->loginUser_Line->clear();
    ui->loginPass_Line->clear();
    ui->stackedWidget->setCurrentWidget(ui->createUser_Page);
}

void MainWindow::on_loginPass_Line_returnPressed()
{
    ui->login_button->click();
}


void MainWindow::on_deposit_Button_clicked()
{
    ui->stackedWidget->setCurrentWidget(ui->numpad_Page);
    currentMode = Deposit;
}

void MainWindow::num_pressed()
{
    // Cast sender to QPushButton (BANE OF MY EXISTANCE TO UNDERSTAND)
    QPushButton *button = qobject_cast<QPushButton*>(sender());
    if (!button) return; // Ensure sender is a QPushButton

    // Use a member variable (QString) to accumulate input
    currentInput += button->text(); // Append the button text (number) to the input

    // Display the accumulated input in the LCD
    ui->lcdNumber->display(currentInput.toDouble()); // Convert to double for display
}


void MainWindow::on_clear_Button_clicked()
{
    currentInput = 0;
    ui->lcdNumber->display(currentInput.toDouble());
}


void MainWindow::on_cancel_Button_clicked()
{
    currentInput = 0;
    ui->lcdNumber->display(currentInput.toDouble());
    ui->stackedWidget->setCurrentWidget(ui->dashboard_Page);
}


void MainWindow::on_checkBalance_Button_clicked()
{
    QString balanceColumn = (currentAccountMode == Savings) ? "savings_balance" : "current_balance";

    QSqlQuery query;
    query.prepare(QString("SELECT %1 FROM users WHERE username = :username").arg(balanceColumn));
    query.bindValue(":username", loggedInUsername);

    if (query.exec() && query.next()) {
        double balance = query.value(balanceColumn).toDouble();
        QMessageBox::information(this, "Account Balance", QString("Your balance is: Rs%1  ").arg(balance));
    } else {
        QMessageBox::critical(this, "Database Error", "Failed to retrieve balance.");
    }
}

bool MainWindow::isAmountValid(double amount) {
    if (amount <= 0) {
        QMessageBox::warning(this, "Invalid Input", "Amount must be greater than zero.");
        return false;
    }

    if (static_cast<int>(amount) % 500 != 0) {
        QMessageBox::warning(this, "Invalid Input", "Amount must be in multiples of 500.");
        return false;
    }

    return true;
}


void MainWindow::on_depositEnter_Button_clicked() {
    double amount = currentInput.toDouble();

    if (!isAmountValid(amount))
    {
        currentInput=0;
        return;
    }

    QString balanceColumn = (currentAccountMode == Savings) ? "savings_balance" : "current_balance";
    QString operation = (currentMode == Deposit) ? "+" : "-";

    QSqlQuery query;
    query.prepare(QString("UPDATE users SET %1 = %1 %2 :amount WHERE username = :username")
                      .arg(balanceColumn).arg(operation));
    query.bindValue(":amount", amount);
    query.bindValue(":username", loggedInUsername);

    if (query.exec()) {
        QString action = (currentMode == Deposit) ? "Deposited" : "Withdrawn";
        QMessageBox::information(this, "Success", QString("%1 Rs%2 to your %3 account.")
                                                      .arg(action).arg(amount)
                                                      .arg((currentAccountMode == Savings) ? "Savings" : "Current"));
    } else {
        QMessageBox::critical(this, "Database Error", "Failed to update balance.");
    }

    currentInput.clear();
    ui->lcdNumber->display(0);
    ui->stackedWidget->setCurrentWidget(ui->dashboard_Page);
}

void MainWindow::processWithdrawal(double amount)
{
    if (loggedInUsername.isEmpty())
    {
        QMessageBox::warning(this, "Error", "No user is logged in. Please log in to proceed.");
        return;
    }

    if (!isAmountValid(amount))
    {
        currentInput=0;
        return;
    }

    QString balanceColumn = (currentAccountMode == Savings) ? "savings_balance" : "current_balance";

    QSqlQuery query;
    query.prepare(QString("SELECT %1 FROM users WHERE username = :username").arg(balanceColumn));
    query.bindValue(":username", loggedInUsername);

    if (!query.exec() || !query.next()) {
        QMessageBox::critical(this, "Database Error", "Failed to retrieve account balance.");
        return;
    }

    double currentBalance = query.value(balanceColumn).toDouble();

    if (currentBalance < amount) {
        QMessageBox::warning(this, "Insufficient Funds", "You do not have enough balance for this withdrawal.");
        return;
    }

    query.prepare(QString("UPDATE users SET %1 = %1 - :amount WHERE username = :username").arg(balanceColumn));
    query.bindValue(":amount", amount);
    query.bindValue(":username", loggedInUsername);

    if (query.exec()) {
        QMessageBox::information(this, "Withdrawal Successful",
                                 QString("You have withdrawn Rs%1  from your %2 account. Your new balance is Rs%3.")
                                     .arg(amount)
                                     .arg((currentAccountMode == Savings) ? "Savings" : "Current")
                                     .arg(currentBalance - amount));
        ui->lcdNumber->display(0);
        currentInput.clear();
    } else {
        QMessageBox::critical(this, "Database Error", "Failed to update balance. Please try again.");
    }
}

void MainWindow::on_amount1000_Button_clicked()
{
    processWithdrawal(1000);
}

void MainWindow::on_amount5000_Button_clicked()
{
    processWithdrawal(5000);
}

void MainWindow::on_amount10000_Button_clicked()
{
    processWithdrawal(10000);
}

void MainWindow::on_amount20000_Button_clicked()
{
    processWithdrawal(20000);
}

void MainWindow::on_amount25000_Button_clicked()
{
    processWithdrawal(25000);
}

void MainWindow::on_otherAmount_Button_clicked()
{
    currentMode = Withdrawal;
    ui->stackedWidget->setCurrentWidget(ui->numpad_Page);
}

void MainWindow::logoutAction()
{
    // Clear the logged-in user's session
    loggedInUsername.clear();
    currentInput.clear();

    // Redirect to the login page
    ui->stackedWidget->setCurrentWidget(ui->login_Page);
    ui->loginUser_Line->setFocus();
    // show a message
    QMessageBox::information(this, "Logout", "You have successfully logged out.");
}

void MainWindow::settingsAction()
{
    ui->stackedWidget->setCurrentWidget(ui->accounts_Page);
}

void MainWindow::setupSettingsButton()
{
    // Create a popup menu
    QMenu *settingsMenu = new QMenu(this);
    settingsMenu->addAction("Logout", this, &MainWindow::logoutAction);
    settingsMenu->addAction("Change Account", this, &MainWindow::settingsAction);
    settingsMenu->addAction("Delete Account", this, &MainWindow::on_deleteAccount_action);


    // Configure the tool button
    QToolButton *settingsButton = ui->settings_Button;
    settingsButton->setMenu(settingsMenu);
    settingsButton->setPopupMode(QToolButton::MenuButtonPopup);
}

void MainWindow::on_settings_Button_triggered(QAction *)
{

}

void MainWindow::on_deleteAccount_action()
{
    if (loggedInUsername.isEmpty())
    {
        QMessageBox::warning(this, "Error", "No user is logged in. Please log in to proceed.");
        return;
    }

    QSqlQuery query;
    // Query for both savings_balance and current_balance
    query.prepare("SELECT savings_balance, current_balance FROM users WHERE username = :username");
    query.bindValue(":username", loggedInUsername);

    if (query.exec() && query.next())
    {
        double savingsBalance = query.value("savings_balance").toDouble();
        double currentBalance = query.value("current_balance").toDouble();

        // Check if either balance is non-zero
        if (savingsBalance > 0 || currentBalance > 0) {
            QMessageBox::warning(this, "Cannot Delete Account",
                                 QString("Your account balances are not zero.\n"
                                         "Savings Balance: Rs%1  \n"
                                         "Current Balance: Rs%2\n"
                                         "Please withdraw all funds before deleting your account.")
                                     .arg(savingsBalance, 0, 'f', 2) // Format balances to 2 decimal places
                                     .arg(currentBalance, 0, 'f', 2));
            return;
        }

        ui->stackedWidget->setCurrentWidget(ui->deleteAccount_Page);
    }
}


void MainWindow::on_horizontalSlider_valueChanged(int value)
{


    if (value == 20)
    {
        QString password = ui->deletePass_Line->text();
        QString confirmPassword = ui->deletePassConfirm_Line->text();

        if (password.isEmpty() || confirmPassword.isEmpty()) {
            QMessageBox::warning(this, "Input Error", "Please fill in both password fields.");
            return;
        }

        if (password != confirmPassword) {
            QMessageBox::warning(this, "Input Error", "Passwords do not match.");
            return;
        }

        // Verify password in the database
        QSqlQuery query;
        query.prepare("SELECT password FROM users WHERE username = :username");
        query.bindValue(":username", loggedInUsername);

        if (query.exec() && query.next()) {
            QString storedPassword = query.value("password").toString();
            if (storedPassword != password) {
                QMessageBox::warning(this, "Authentication Failed", "Incorrect password. Please try again.");
                return;
            }

            // Delete the account
            QSqlQuery deleteQuery;
            deleteQuery.prepare("DELETE FROM users WHERE username = :username");
            deleteQuery.bindValue(":username", loggedInUsername);

            if (deleteQuery.exec()) {
                QMessageBox::information(this, "Account Deleted", "Your account has been successfully deleted.");
                logoutAction(); // Log out the user
            } else {
                QMessageBox::critical(this, "Database Error", "Failed to delete the account. Please try again.");
            }
        } else {
            QMessageBox::critical(this, "Database Error", "Failed to validate password. Please try again.");
        }

        ui->deletePass_Line->clear();
        ui->deletePassConfirm_Line->clear();
        ui->horizontalSlider->setValue(0);
        //qDebug() << "slider triggerred";
    }
}


void MainWindow::on_acc_Cancel_Button_clicked()
{
    ui->stackedWidget->setCurrentWidget(ui->login_Page);
    ui->newPassword_Line->clear();
    ui->newUser_Line->clear();
    ui->confirmPassword_Line->clear();
}


