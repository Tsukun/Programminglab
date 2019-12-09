#ifndef FINALWINDOW_H
#define FINALWINDOW_H
#include <QDialog>
#include <iostream>
#include "company.h"
#include "ipadress.h"
using namespace std;
namespace Ui {
class finalwindow;
}

class finalwindow : public QDialog
{
    Q_OBJECT
signals:
 void bwindow();
public:
    explicit finalwindow(QWidget *parent = nullptr);
    ~finalwindow();
 void setcomp(company &s);
 void getip();
private slots:
 void on_pushButton_clicked();
 void on_backbutton_clicked();

private:
    Ui::finalwindow *ui;
    company comp;
    ipadress ip;
};

#endif // FINALWINDOW_H
