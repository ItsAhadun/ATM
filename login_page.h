#ifndef LOGIN_PAGE_H
#define LOGIN_PAGE_H

#include <QMainWindow>

namespace Ui {
class login_page;
}

class login_page : public QMainWindow
{
    Q_OBJECT

public:
    explicit login_page(QWidget *parent = nullptr);
    ~login_page();

private:
    Ui::login_page *ui;
};

#endif // LOGIN_PAGE_H
