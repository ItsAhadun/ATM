#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlError>
#include <QVariant>
#include <QDebug>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)

{

    ui->setupUi(this);
    ui->stackedWidget->setCurrentWidget(ui->login_Page);

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
            balance REAL DEFAULT 0,
            failed_attempts INTEGER DEFAULT 0,
            is_locked INTEGER DEFAULT 0,
            last_failed_login DATETIME
        )
    )")) {
        QMessageBox::critical(this, "Database Error", "Failed to create table: " + query.lastError().text());
    }

    currentInput = ""; // Start with an empty string

    connect(ui->login_button, &QPushButton::clicked, this, &MainWindow::login_button);
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

void MainWindow::login_button()
{
    QString uName = ui->lineEdit->text();
    QString uCode = ui->lineEdit_2->text();

    QSqlQuery query;
    query.prepare("SELECT * FROM users WHERE username = :username AND password = :password");
    query.bindValue(":username", uName);
    query.bindValue(":password", uCode);

    if (query.exec() && query.next())
    {
        loggedInUsername = uName;
        ui->stackedWidget->setCurrentWidget(ui->accounts_Page);
        QMessageBox::information(this, "Welcome Message", "User: " + uName + "\nWelcome to Bank Al LUMS");
    } else {
        QMessageBox::information(this, "Error Box", "Invalid Username or Password");
    }
}

void MainWindow::on_current_acc_button_clicked()
{
    ui->stackedWidget->setCurrentWidget(ui->dashboard_Page);
}

void MainWindow::on_savings_acc_button_clicked()
{
    ui->stackedWidget->setCurrentWidget(ui->dashboard_Page);
}

void MainWindow::on_default_acc_button_clicked()
{
    ui->stackedWidget->setCurrentWidget(ui->dashboard_Page);
}

void MainWindow::on_submitApplication_Button_clicked()
{
    QString newUsername = ui->newUser_Line->text();
    QString newPassword = ui->newPassword_Line->text();

    if (newUsername.isEmpty() || newPassword.isEmpty()) {
        QMessageBox::warning(this, "Input Error", "Please enter both a username and a password.");
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
}

void MainWindow::on_createAccount_Button_clicked()
{
    ui->stackedWidget->setCurrentWidget(ui->createUser_Page);
}

void MainWindow::on_one_Button_clicked()
{
    // Placeholder for one_Button functionality
}

void MainWindow::on_login_button_pressed()
{
    // Placeholder for login_button pressed event
}

void MainWindow::on_lineEdit_2_returnPressed()
{
    ui->login_button->click();
}


void MainWindow::on_deposit_Button_clicked()
{
    ui->stackedWidget->setCurrentWidget(ui->numpad_Page);
}


void MainWindow::on_two_Button_clicked()
{

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
    QSqlQuery query;
    query.prepare("SELECT balance FROM users WHERE username = :username");
    query.bindValue(":username", loggedInUsername);

    if (query.exec() && query.next()) {
        // Fetch the balance
        double balance = query.value("balance").toDouble();

        // Display the balance to the user
        QMessageBox::information(this, "Account Balance", QString("Your current balance is: $%1").arg(balance));
    } else {
        // Handle database query errors
        QMessageBox::critical(this, "Database Error", "Failed to retrieve account balance.");
    }
}


void MainWindow::on_depositEnter_Button_clicked()
{
    ui->lcdNumber->display(currentInput.toDouble());

    // Check if the input is valid
    if (currentInput.isEmpty() || currentInput.toDouble() <= 0) {
        QMessageBox::warning(this, "Invalid Input", "Please enter a valid deposit amount.");
        return;
    }

    // Convert the input to a double
    double depositAmount = currentInput.toDouble();

    // Prepare the query to update the user's balance
    QSqlQuery query;
    query.prepare("UPDATE users SET balance = balance + :amount WHERE username = :username");
    query.bindValue(":amount", depositAmount);
    query.bindValue(":username", loggedInUsername);

    if (query.exec()) {
        QMessageBox::information(this, "Deposit Successful", QString("Deposited $%1 into your account.").arg(depositAmount));

        // Clear the input and reset the display
        currentInput.clear();
        ui->lcdNumber->display(0);

        // Optionally, navigate back to the dashboard or accounts page
        ui->stackedWidget->setCurrentWidget(ui->dashboard_Page);
    } else {
        QMessageBox::critical(this, "Database Error", "Failed to deposit the amount. Please try again.");
    }
}

void MainWindow::processWithdrawal(double amount) {
    if (loggedInUsername.isEmpty()) {
        QMessageBox::warning(this, "Error", "No user is logged in. Please log in to proceed.");
        return;
    }

    QSqlQuery query;
    query.prepare("SELECT balance FROM users WHERE username = :username");
    query.bindValue(":username", loggedInUsername);

    if (!query.exec() || !query.next()) {
        QMessageBox::critical(this, "Database Error", "Failed to retrieve account balance.");
        return;
    }

    double currentBalance = query.value("balance").toDouble();

    if (currentBalance < amount) {
        QMessageBox::warning(this, "Insufficient Funds", "You do not have enough balance for this withdrawal.");
        return;
    }

    query.prepare("UPDATE users SET balance = balance - :amount WHERE username = :username");
    query.bindValue(":amount", amount);
    query.bindValue(":username", loggedInUsername);

    if (query.exec()) {
        QMessageBox::information(this, "Withdrawal Successful", QString("You have withdrawn $%1. Your new balance is $%2.")
                                     .arg(amount)
                                     .arg(currentBalance - amount));
        ui->lcdNumber->display(0);
        currentInput.clear();
    } else {
        QMessageBox::critical(this, "Database Error", "Failed to update balance. Please try again.");
    }
}

void MainWindow::on_amount1000_Button_clicked() {
    processWithdrawal(1000);
}

void MainWindow::on_amount5000_Button_clicked() {
    processWithdrawal(5000);
}

void MainWindow::on_amount10000_Button_clicked() {
    processWithdrawal(10000);
}

void MainWindow::on_amount20000_Button_clicked() {
    processWithdrawal(20000);
}

void MainWindow::on_amount25000_Button_clicked() {
    processWithdrawal(25000);
}
/*
void MainWindow::on_otherAmount_Button_clicked() {
    double amount = currentInput.toDouble();
    if (amount <= 0) {
        QMessageBox::warning(this, "Invalid Input", "Please enter a valid withdrawal amount.");
        return;
    }
    processWithdrawal(amount);
}
*/
