#ifndef TRANSACTION_H
#define TRANSACTION_H

#include <QMainWindow>

namespace Ui {
class transaction;
}

class transaction : public QMainWindow
{
    Q_OBJECT

public:
    explicit transaction(QWidget *parent = nullptr);
    ~transaction();

private:
    Ui::transaction *ui;
};

#endif // TRANSACTION_H
