#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlError>
#include <QInputDialog>
#include <QFile>
#include <QTextStream>
#include <QDateTime>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
    , loginButtonAnimation(new QPropertyAnimation(ui->login_Button, "styleSheet"))
{
    ui->setupUi(this);
    ui->stackedWidget->setCurrentWidget(ui->login_Page);

    // Set up SQLite database
    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("bankingApp.db");

    if (!db.open()) {
        QMessageBox::critical(this, "Database Error", "Failed to open the database: " + db.lastError().text());
        return;
    }

    // Initialize database schema
    QSqlQuery query;
    if (!query.exec(R"(
        CREATE TABLE IF NOT EXISTS users (
            id INTEGER PRIMARY KEY AUTOINCREMENT,
            username TEXT UNIQUE,
            password TEXT,
            pin INTEGER,
            balance REAL DEFAULT 0,
            account_type TEXT
        )
    )")) {
        QMessageBox::critical(this, "Database Error", "Failed to initialize database: " + query.lastError().text());
    }

    // Connect UI elements to functions
    connect(ui->login_Button, &QPushButton::clicked, this, &MainWindow::login_button);
    connect(ui->submitApplication_Button, &QPushButton::clicked, this, &MainWindow::on_submitApplication_Button_clicked);
    connect(ui->deposit_Button, &QPushButton::clicked, this, &MainWindow::on_deposit_Button_clicked);
    connect(ui->withdraw_Button, &QPushButton::clicked, this, &MainWindow::on_withdraw_Button_clicked);
}

MainWindow::~MainWindow()
{
    delete ui;
    QSqlDatabase::database().close();
}

bool MainWindow::eventFilter(QObject *watched, QEvent *event)
{
    if (watched == ui->login_Button) {
        if (event->type() == QEvent::Enter) {
            loginButtonAnimation->setDirection(QPropertyAnimation::Forward);
            loginButtonAnimation->start();
            return true;
        } else if (event->type() == QEvent::Leave) {
            loginButtonAnimation->setDirection(QPropertyAnimation::Backward);
            loginButtonAnimation->start();
            return true;
        }
    }
    return QMainWindow::eventFilter(watched, event);
}

void MainWindow::login_button()
{
    static int loginAttempts = 0;
    QString uName = ui->username_Line->text();
    QString uPin = ui->password_Line->text();

    QSqlQuery query;
    query.prepare("SELECT * FROM users WHERE username = :username AND pin = :pin");
    query.bindValue(":username", uName);
    query.bindValue(":pin", uPin.toInt());

    if (query.exec() && query.next()) {
        loginAttempts = 0;
        currentUser = uName;
        ui->stackedWidget->setCurrentWidget(ui->accounts_Page);
        QMessageBox::information(this, "Login Successful", "Welcome, " + uName + "!");
    } else {
        loginAttempts++;
        if (loginAttempts >= 3) {
            QMessageBox::warning(this, "Account Locked", "Too many failed attempts. Try again later.");
            QTimer::singleShot(60000, [&]() { loginAttempts = 0; });
        } else {
            QMessageBox::warning(this, "Login Failed", "Invalid username or PIN.");
        }
    }
}

void MainWindow::on_submitApplication_Button_clicked()
{
    QString newUsername = ui->newUser_Line->text();
    QString newPassword = ui->newPassword_Line->text();
    int pin = ui->confirmPassword_Line->text().toInt();

    if (newUsername.isEmpty() || newPassword.isEmpty() || pin <= 0) {
        QMessageBox::warning(this, "Input Error", "Please enter valid credentials.");
        return;
    }

    QSqlQuery query;
    query.prepare("INSERT INTO users (username, password, pin, balance, account_type) VALUES (:username, :password, :pin, 0, 'default')");
    query.bindValue(":username", newUsername);
    query.bindValue(":password", newPassword);
    query.bindValue(":pin", pin);

    if (query.exec()) {
        QMessageBox::information(this, "Account Created", "Account created successfully!");
        ui->stackedWidget->setCurrentWidget(ui->login_Page);
    } else {
        QMessageBox::critical(this, "Database Error", "Failed to create account: " + query.lastError().text());
    }
}

void MainWindow::on_deposit_Button_clicked()
{
    double amount = QInputDialog::getDouble(this, "Deposit", "Enter deposit amount:");
    if (amount <= 0) {
        QMessageBox::warning(this, "Invalid Amount", "Deposit amount must be greater than zero.");
        return;
    }

    QSqlQuery query;
    query.prepare("UPDATE users SET balance = balance + :amount WHERE username = :username");
    query.bindValue(":amount", amount);
    query.bindValue(":username", currentUser);

    if (query.exec()) {
        logTransaction(currentUser, "Deposit", amount);
        QMessageBox::information(this, "Deposit Successful", "Amount deposited successfully!");
    } else {
        QMessageBox::critical(this, "Database Error", "Failed to deposit amount.");
    }
}

void MainWindow::on_withdraw_Button_clicked()
{
    double amount = QInputDialog::getDouble(this, "Withdraw", "Enter withdrawal amount:");
    QSqlQuery query;
    query.prepare("SELECT balance FROM users WHERE username = :username");
    query.bindValue(":username", currentUser);

    if (query.exec() && query.next()) {
        double balance = query.value(0).toDouble();
        if (amount > balance) {
            QMessageBox::warning(this, "Insufficient Funds", "Not enough balance.");
            return;
        }

        query.prepare("UPDATE users SET balance = balance - :amount WHERE username = :username");
        query.bindValue(":amount", amount);
        query.bindValue(":username", currentUser);

        if (query.exec()) {
            logTransaction(currentUser, "Withdraw", amount);
            QMessageBox::information(this, "Withdrawal Successful", "Amount withdrawn successfully!");
        } else {
            QMessageBox::critical(this, "Database Error", "Failed to withdraw amount.");
        }
    }
}

void MainWindow::logTransaction(const QString &username, const QString &action, double amount)
{
    QFile file("transactions.log");
    if (file.open(QIODevice::Append | QIODevice::Text)) {
        QTextStream stream(&file);
        stream << username << ", " << action << ", " << amount << ", " << QDateTime::currentDateTime().toString() << "\n";
        file.close();
    }
}
