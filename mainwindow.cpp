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


// Constructor for MainWindow
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

    if (!db.open())
    {
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
    )"))
    {
        QMessageBox::critical(this, "Database Error", "Failed to create table: " + query.lastError().text());
    }

    currentInput = ""; // Initialize the global variable

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

// Destructor for MainWindow
MainWindow::~MainWindow()
{
    delete ui;
    QSqlDatabase::database().close();

}



//processes login
void MainWindow::on_login_button_clicked()
{
    QString uName = ui->loginUser_Line->text();
    QString uCode = ui->loginPass_Line->text();

    if (isAccountLocked(uName))
    {
        return;
    }

    if (!isValidPin(uCode)) //check correct format (validation)
    {
        handleInvalidPin(uName);
        return;
    }

    if (validateLogin(uName, uCode)) //check correct pin and username (verification)
    {
        handleSuccessfulLogin(uName);
    }
    else
    {
        handleFailedLogin(uName);
    }
}
//PIN validatation
bool MainWindow::isValidPin(const QString& pin)
{
    string pinStr = pin.toStdString();

    if (pinStr.length() != 4) {
        return false;
    }

    for (int i = 0; i < 4; i++)
    {
        if (pinStr[i] < 48 || pinStr[i] > 57)
        {
            return false;
        }
    }
    return true;
}
//increments failed Attempts
//locks the account after 3 consective attempts
void MainWindow::handleInvalidPin(const QString& username)
{
    QSqlQuery updateQuery;
    updateQuery.prepare("UPDATE users SET failed_attempts = failed_attempts + 1 WHERE username = :username");
    updateQuery.bindValue(":username", username);

    if (!updateQuery.exec())
    {
        QMessageBox::critical(this, "Database Error", "Failed to update failed attempts: " + updateQuery.lastError().text());
        return;
    }



    QSqlQuery query;
    query.prepare("SELECT failed_attempts FROM users WHERE username = :username");
    query.bindValue(":username", username);

    if (query.exec() && query.next())
    {
        int failedAttempts = query.value("failed_attempts").toInt();
        if (failedAttempts >= 3)
        {
            lockAccount(username);
        }
        else
        {
            QMessageBox::warning(this, "Input Error",
                                 "Password must be a 4-digit PIN. Remaining attempts: " + QString::number(3 - failedAttempts));
        }

        }
}
// Check if account's locked
//unlock if it has been 5 minutes since lockout
bool MainWindow::isAccountLocked(const QString& username)
{
    QSqlQuery query;
    query.prepare("SELECT is_locked, last_failed_login, failed_attempts FROM users WHERE username = :username");
    query.bindValue(":username", username);

    if (!query.exec() || !query.next()) {
        QMessageBox::critical(this, "Invalid Info", "Entered Username or Password is incorrect");
        return false;
    }

    bool isLocked = query.value("is_locked").toBool();
    QDateTime lastFailedLogin = query.value("last_failed_login").toDateTime();

    if (isLocked)
    {
        QDateTime unlockTime = lastFailedLogin.addSecs(5 * 60); // 5-minute timeout
        QDateTime currentTime = QDateTime::currentDateTime();

        if (currentTime < unlockTime)
        {
            int remainingSeconds = currentTime.secsTo(unlockTime);
            int minutes = remainingSeconds / 60;
            int seconds = remainingSeconds % 60;

            QMessageBox::warning(this, "Account Locked",
                                 QString("Your account is locked. Please try again in %1 minutes and %2 seconds.")
                                     .arg(minutes)
                                     .arg(seconds));
            return true;
        }
        else //unlocks the account
        {
            QSqlQuery unlockQuery;
            unlockQuery.prepare("UPDATE users SET is_locked = 0, failed_attempts = 0 WHERE username = :username");
            unlockQuery.bindValue(":username", username);

            if (!unlockQuery.exec())
            {
                QMessageBox::critical(this, "Database Error", "Failed to unlock account: " + unlockQuery.lastError().text());
            }
        }
    }
    return false;
}

//checks if username and password are correct
bool MainWindow::validateLogin(const QString& username, const QString& password)
{
    QSqlQuery query;
    query.prepare("SELECT * FROM users WHERE username = :username AND password = :password");
    query.bindValue(":username", username);
    query.bindValue(":password", password);

    return query.exec() && query.next();
}
//logs the user in
//resets failed attempts
//changes to the next page
void MainWindow::handleSuccessfulLogin(const QString& username)
{
    loggedInUsername = username;
    ui->stackedWidget->setCurrentWidget(ui->accounts_Page);
    QMessageBox::information(this, "Welcome", "Welcome to Bank al LUMS, " + username + "!");
    ui->loginUser_Line->clear();
    ui->loginPass_Line->clear();

    QSqlQuery resetQuery;
    resetQuery.prepare("UPDATE users SET failed_attempts = 0, is_locked = 0 WHERE username = :username");
    resetQuery.bindValue(":username", username);

    if (!resetQuery.exec()) {
        QMessageBox::critical(this, "Database Error", "Failed to reset login attempts: " + resetQuery.lastError().text());
    }
}
//if the password is incorrect
//increment failed attempts
void MainWindow::handleFailedLogin(const QString& username)
{
    QSqlQuery updateQuery;
    updateQuery.prepare("UPDATE users SET failed_attempts = failed_attempts + 1 WHERE username = :username");
    updateQuery.bindValue(":username", username);

    if (!updateQuery.exec()) {
        QMessageBox::critical(this, "Database Error", "Failed to update failed attempts: " + updateQuery.lastError().text());
        return;
    }

    QSqlQuery query;
    query.prepare("SELECT failed_attempts FROM users WHERE username = :username");
    query.bindValue(":username", username);

    if (query.exec() && query.next()) {
        int failedAttempts = query.value("failed_attempts").toInt();

        if (failedAttempts >= 3) {
            lockAccount(username);
        } else {
            QMessageBox::warning(this, "Login Failed", "Invalid username or password. Remaining attempts: " + QString::number(3 - failedAttempts));
        }
    }
}

//locks the account
void MainWindow::lockAccount(const QString& username)
{
    QSqlQuery lockQuery;
    lockQuery.prepare("UPDATE users SET is_locked = 1, last_failed_login = :timestamp WHERE username = :username");
    lockQuery.bindValue(":username", username);
    lockQuery.bindValue(":timestamp", QDateTime::currentDateTime().toString(Qt::ISODate));

    if (lockQuery.exec()) {
        QMessageBox::warning(this, "Account Locked", "Your account has been locked due to multiple failed login attempts. Please try again later.");
    } else {
        QMessageBox::critical(this, "Database Error", "Failed to lock account: " + lockQuery.lastError().text());
    }
}

//changees the page to dashboard and account
void MainWindow::on_current_acc_button_clicked()
{

    ui->account_Label->setText("Current Account");
    currentAccountMode = Current;
    ui->stackedWidget->setCurrentWidget(ui->dashboard_Page);
}
//changes the page to dashboard and account
void MainWindow::on_savings_acc_button_clicked()
{
    ui->account_Label->setText("Savings Account");
    currentAccountMode = Savings;
    ui->stackedWidget->setCurrentWidget(ui->dashboard_Page);
}
//changes the page to dashboard and account
void MainWindow::on_default_acc_button_clicked()
{
    ui->account_Label->setText("Savings Account");
    currentAccountMode = Savings;
    ui->stackedWidget->setCurrentWidget(ui->dashboard_Page);
}

// Allows the user to create a new account
//by validating input and storing the details in the database.
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

    //clears the textboexes
    ui->confirmPassword_Line->clear();
    ui->newPassword_Line->clear();
    ui->newUser_Line->clear();
}

//clears the text boxes and returns to login page
void MainWindow::on_acc_Cancel_Button_clicked()
{
    ui->stackedWidget->setCurrentWidget(ui->login_Page);
    ui->newPassword_Line->clear();
    ui->newUser_Line->clear();
    ui->confirmPassword_Line->clear();
}


//changes screen to account creation page
void MainWindow::on_createAccount_Button_clicked()
{
    ui->loginUser_Line->clear();
    ui->loginPass_Line->clear();
    ui->stackedWidget->setCurrentWidget(ui->createUser_Page);
}

//When enter is pressed while in the password text box, the login button is pressed
void MainWindow::on_loginPass_Line_returnPressed()
{
    ui->login_button->click();
}

//
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

// Allows the user to check their account balance
//    (for both savings and current account)
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

// checks if the amount is a multiple of 500
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


// Processes a withdrawal request by validating the amount and updating the database.
void MainWindow::processWithdrawal(double amount)
{
    // Ensure a user is logged in
    if (loggedInUsername.isEmpty())
    {
        QMessageBox::warning(this, "Error", "No user is logged in. Please log in to proceed.");
        return;
    }
    // Ensure the amount is valid
    if (!isAmountValid(amount))
    {
        currentInput=0;
        return;
    }

    //assign the balance colonm according to the account mode
    QString balanceColumn = (currentAccountMode == Savings) ? "savings_balance" : "current_balance";

    // Retrieve the current balance from the database
    QSqlQuery query;
    query.prepare(QString("SELECT %1 FROM users WHERE username = :username").arg(balanceColumn));
    query.bindValue(":username", loggedInUsername);

    if (!query.exec() || !query.next()) {
        QMessageBox::critical(this, "Database Error", "Failed to retrieve account balance.");
        return;
    }

    double currentBalance = query.value(balanceColumn).toDouble();
    // Ensure sufficient funds are available for withdrawal
    if (currentBalance < amount) {
        QMessageBox::warning(this, "Insufficient Funds", "You do not have enough balance for this withdrawal.");
        return;
    }

    // Update the balance after withdrawal
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
        ui->stackedWidget->setCurrentWidget(ui->dashboard_Page);
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

//processes custom amount withdrawal and deposits
void MainWindow::on_numpadEnter_Button_clicked()
{
    double amount = currentInput.toDouble();

    //if withdrawal mode then withdraws moneyyy!!!
    if (currentMode == Withdrawal)
    {
        processWithdrawal(amount);
        ui->lcdNumber->display(0);
        currentInput = 0;
        return;
    }

    // if not in a multiple of 500 stawwpppp
    if (!isAmountValid(amount))
    {
        ui->lcdNumber->display(0);
        currentInput = 0;
        return;
    }

    QString balanceColumn = (currentAccountMode == Savings) ? "savings_balance" : "current_balance";

    // Update the balance for deposits
    QSqlQuery query;
    query.prepare(QString("UPDATE users SET %1 = %1 + :amount WHERE username = :username").arg(balanceColumn));
    query.bindValue(":amount", amount);
    query.bindValue(":username", loggedInUsername);

    //notify the user
    if (query.exec()) {
        QMessageBox::information(this, "Deposit Successful",
                                 QString("Deposited Rs%1 to your %2 account.")
                                     .arg(amount)
                                     .arg((currentAccountMode == Savings) ? "Savings" : "Current"));
    } else {
        QMessageBox::critical(this, "Database Error", "Failed to update balance. Please try again.");
    }

    //clear the numpad and go back to dashboard
    currentInput.clear();
    ui->lcdNumber->display(0);
    ui->stackedWidget->setCurrentWidget(ui->dashboard_Page);
}


void MainWindow::logoutAction()
{
    // Clear the logged-in user's session
    loggedInUsername.clear();
    currentInput.clear();

    // Redirect to the login page
    ui->stackedWidget->setCurrentWidget(ui->login_Page);
    ui->loginUser_Line->setFocus();
    // notify the user
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
// checks if user has money, if yes then prompts to empty it.
// if no then redirects the user to the account deletion page
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

// checks if both pin match the user's pin
//if yes then deletes account upon reach max slider value
//
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

