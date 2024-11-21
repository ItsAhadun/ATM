#include "accounts_page.h"
#include "ui_accounts_page.h"

accounts_page::accounts_page(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::accounts_page)
{
    ui->setupUi(this);
}

accounts_page::~accounts_page()
{
    delete ui;
}
