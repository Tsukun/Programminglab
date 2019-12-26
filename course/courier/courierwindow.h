#ifndef COURIERWINDOW_H
#define COURIERWINDOW_H

#include <QDialog>

namespace Ui {
class courierwindow;
}

class courierwindow : public QDialog
{
    Q_OBJECT

public:
    explicit courierwindow(QWidget *parent = nullptr);
    ~courierwindow();

private:
    Ui::courierwindow *ui;
};

#endif // COURIERWINDOW_H
