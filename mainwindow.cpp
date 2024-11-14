#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlError>
#include <QVariant>
#include <QPropertyAnimation>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
    , loginButtonAnimation(new QPropertyAnimation(ui->login_button, "styleSheet"))
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
    if (!query.exec("CREATE TABLE IF NOT EXISTS users (id INTEGER PRIMARY KEY AUTOINCREMENT, username TEXT UNIQUE, password TEXT)")) {
        QMessageBox::critical(this, "Database Error", "Failed to create table: " + query.lastError().text());
    }

    connect(ui->login_button, &QPushButton::clicked, this, &MainWindow::login_button);

    // Set initial solid color style for login_button
    ui->login_button->setStyleSheet("background-color: rgb(0, 120, 215);");

    // Configure animation properties for hover effect with solid colors
    loginButtonAnimation->setDuration(300);  // Duration in milliseconds
    loginButtonAnimation->setStartValue("background-color: rgb(0, 120, 215);");  // Original color
    loginButtonAnimation->setEndValue("background-color: rgb(255, 85, 85);");    // Hover color

    // Install event filter on login_button to handle hover animations
    ui->login_button->installEventFilter(this);
}

MainWindow::~MainWindow()
{
    delete ui;
    QSqlDatabase::database().close();
}

// Event filter to handle hover events specifically for login_button
bool MainWindow::eventFilter(QObject *watched, QEvent *event)
{
    if (watched == ui->login_button) {
        if (event->type() == QEvent::Enter) {
            // Start animation on hover
            loginButtonAnimation->setDirection(QPropertyAnimation::Forward);
            loginButtonAnimation->start();
            return true;
        } else if (event->type() == QEvent::Leave) {
            // Reverse animation when leaving the button area
            loginButtonAnimation->setDirection(QPropertyAnimation::Backward);
            loginButtonAnimation->start();
            return true;
        }
    }
    return QMainWindow::eventFilter(watched, event);
}

// Slot to handle login button click event
void MainWindow::login_button()
{
    QString uName = ui->lineEdit->text();
    QString uCode = ui->lineEdit_2->text();

    QSqlQuery query;
    query.prepare("SELECT * FROM users WHERE username = :username AND password = :password");
    query.bindValue(":username", uName);
    query.bindValue(":password", uCode);

    if (query.exec() && query.next()) {
        ui->stackedWidget->setCurrentWidget(ui->accounts_Page);
        QMessageBox::information(this, "Welcome Message", "User: " + uName + "\nWelcome to Bank Al LUMS");
    } else {
        QMessageBox::information(this, "Error Box", "Invalid Username or Password");
    }
}

// Slot implementations for other button clicks
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

void MainWindow::on_one_Button_clicked()
{
    // Placeholder for the one_Button functionality if needed
}

void MainWindow::on_login_button_pressed()
{
    // Placeholder for the login_button pressed event if needed
}

void MainWindow::on_lineEdit_2_returnPressed()
{
    ui->login_button->click();
}

void MainWindow::on_createAccount_Button_clicked()
{
    ui->stackedWidget->setCurrentWidget(ui->createUser_Page);
}
