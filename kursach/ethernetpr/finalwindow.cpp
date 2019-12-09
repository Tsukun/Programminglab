#include "finalwindow.h"
#include "ui_finalwindow.h"
finalwindow::finalwindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::finalwindow)
{
    ui->setupUi(this);
}

finalwindow::~finalwindow()
{
    delete ui;
}


void finalwindow::on_pushButton_clicked()
{

}

void finalwindow::on_backbutton_clicked()
{
    this->close();
    emit bwindow();
}
void finalwindow::setcomp(company &s)
{

    comp.setcount(s.getcount());
    comp.setaccname(s.getaccname());
    comp.setadress(s.getadress());
    comp.setphnumber(s.getphnumber());
    comp.setemail(s.getemail());
    ui->pnum->setText(QString::fromStdString(comp.getphnumber()));
    ui->cname->setText(QString::fromStdString(comp.getaccname()));
    ui->adress->setText(QString::fromStdString(comp.getadress()));
    ui->email->setText(QString::fromStdString(comp.getemail()));
    ui->count->setText(QString::number(comp.getcount()));
    ui->floornum->setText("-");
    ui->housenum->setText("-");
    getip();
}
void finalwindow::getip()
{
    QString temp;
    if(comp.getcount()>65534)
    ip.classX('A');
    else
     ip.classX('B');

    for(int i=0;i<4;i++)
    {
        temp+=QString::number(ip.getip()[i]);
        if(i!=3)
        temp+=".";
    }
      ui->ipnum->setText(temp);
      temp="";
    for(int i=0;i<4;i++)
    {
        temp+=QString::number(ip.getmask()[i]);
        if(i!=3)
        temp+=".";
    }

      ui->masknum->setText(temp);
}
