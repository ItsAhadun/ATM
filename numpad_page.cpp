#include "numpad_page.h"
#include "ui_numpad_page.h"

numpad_page::numpad_page(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::numpad_page)
{
    ui->setupUi(this);
}

numpad_page::~numpad_page()
{
    delete ui;
}
