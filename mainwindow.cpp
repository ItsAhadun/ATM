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
    ui->stackedWidget->setCurrentWidget(ui->dashboard_Page);
}

