#ifndef MODELWINDOW_H
#define MODELWINDOW_H
#include "company.h"
#include "individual.h"
#include <cstdlib>
#include <ctime>
#include <QFile>
#include <QDialog>
#include <QDebug>
#include <iostream>
#include <QFileDialog>

using namespace std;
namespace Ui {
class modelwindow;
}

class modelwindow : public QDialog
{
    Q_OBJECT

public:
    explicit modelwindow(QWidget *parent = nullptr);
    ~modelwindow();
    void generate(int chance,int count,int ratio,int maxDistance,int maxFloor,int maxCount);
    void calcSuccesAccount();
private slots:
    void on_pushButton_clicked();

private:
    Ui::modelwindow *ui;
    company *comp;
    individual *indiv;
};

#endif // MODELWINDOW_H
