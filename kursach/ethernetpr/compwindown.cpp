#include "compwindown.h"
#include "ui_compwindown.h"

compwindown::compwindown(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::compwindown)
{
    ui->setupUi(this);
    final=new finalwindow();
    connect(final ,&finalwindow::bwindow, this, &compwindown::show);

}

compwindown::~compwindown()
{
    delete ui;
}

void compwindown::on_backbutton_clicked()
{
 this->close();
 emit requestwindow();
}

void compwindown::on_sendbutton_clicked()
{
   s.setaccname(ui->cname->text().toStdString());
   s.setphnumber(ui->phnum->text().toStdString());
   s.setadress(ui->adname->text().toStdString());
   s.setcount(ui->countp->text().toInt());
   s.setemail(ui->email->text().toStdString());
   final->show();
   final->setcomp(s);
   this->close();
}


