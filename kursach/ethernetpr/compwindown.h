#ifndef COMPWINDOWN_H
#define COMPWINDOWN_H
#include "company.h"
#include "finalwindow.h"
#include <QDialog>

namespace Ui {
class compwindown;
}
class compwindown : public QDialog
{
    Q_OBJECT
signals:
void requestwindow();
public:
    explicit compwindown(QWidget *parent = nullptr);
    ~compwindown();
private slots:
    void on_backbutton_clicked();

    void on_sendbutton_clicked();

private:
    Ui::compwindown *ui;
    finalwindow *final;
        company s;
};

#endif // COMPWINDOWN_H
