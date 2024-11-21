#ifndef DASHBOARD_PAGE_H
#define DASHBOARD_PAGE_H

#include <QMainWindow>

namespace Ui {
class dashboard_page;
}

class dashboard_page : public QMainWindow
{
    Q_OBJECT

public:
    explicit dashboard_page(QWidget *parent = nullptr);
    ~dashboard_page();

private:
    Ui::dashboard_page *ui;
};

#endif // DASHBOARD_PAGE_H
