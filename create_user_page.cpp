#include "create_user_page.h"
#include "ui_create_user_page.h"

create_user_page::create_user_page(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::create_user_page)
{
    ui->setupUi(this);
}

create_user_page::~create_user_page()
{
    delete ui;
}
