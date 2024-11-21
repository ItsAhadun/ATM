#ifndef CREATE_USER_PAGE_H
#define CREATE_USER_PAGE_H

#include <QMainWindow>

namespace Ui {
class create_user_page;
}

class create_user_page : public QMainWindow
{
    Q_OBJECT

public:
    explicit create_user_page(QWidget *parent = nullptr);
    ~create_user_page();

private:
    Ui::create_user_page *ui;
};

#endif // CREATE_USER_PAGE_H
