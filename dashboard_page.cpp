#include "dashboard_page.h"
#include "ui_dashboard_page.h"

dashboard_page::dashboard_page(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::dashboard_page)
{
    ui->setupUi(this);
}

dashboard_page::~dashboard_page()
{
    delete ui;
}
