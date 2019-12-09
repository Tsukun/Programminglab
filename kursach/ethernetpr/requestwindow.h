#ifndef REQUESTWINDOW_H
#define REQUESTWINDOW_H
#include "compwindown.h"
#include "indvwindow.h"
#include <QDialog>

namespace Ui {
class requestwindow;
}

class requestwindow : public QDialog
{
    Q_OBJECT

public:
    explicit requestwindow(QWidget *parent = nullptr);
    ~requestwindow();

private slots:
    void on_pushButton_clicked();

private:
    Ui::requestwindow *ui;
     compwindown *com;
     indvwindow *ind;
};

#endif // REQUESTWINDOW_H
