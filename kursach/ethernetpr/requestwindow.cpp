#include "requestwindow.h"
#include "ui_requestwindow.h"


requestwindow::requestwindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::requestwindow)
{
    ui->setupUi(this);
    com=new compwindown();
    connect(com, &compwindown::requestwindow, this, &requestwindow::show);
    ind=new indvwindow();
    connect(ind, &indvwindow::requestwindow, this, &requestwindow::show);
}

requestwindow::~requestwindow()
{

    delete ui;
}

void requestwindow::on_pushButton_clicked()
{
 if(ui->compbutton->isChecked())
 {
     com->show();
     this->close();

 }
 if(ui->indvbutton->isChecked())
 {
     ind->show();
     this->close();
 }
}
