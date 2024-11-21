#ifndef NUMPAD_PAGE_H
#define NUMPAD_PAGE_H

#include <QMainWindow>

namespace Ui {
class numpad_page;
}

class numpad_page : public QMainWindow
{
    Q_OBJECT

public:
    explicit numpad_page(QWidget *parent = nullptr);
    ~numpad_page();

private:
    Ui::numpad_page *ui;
};

#endif // NUMPAD_PAGE_H
