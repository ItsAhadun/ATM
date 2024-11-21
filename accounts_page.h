#ifndef ACCOUNTS_PAGE_H
#define ACCOUNTS_PAGE_H

#include <QMainWindow>

namespace Ui {
class accounts_page;
}

class accounts_page : public QMainWindow
{
    Q_OBJECT

public:
    explicit accounts_page(QWidget *parent = nullptr);
    ~accounts_page();

private:
    Ui::accounts_page *ui;
};

#endif // ACCOUNTS_PAGE_H
