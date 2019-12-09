#include "indvwindow.h"
#include "ui_indvwindow.h"

indvwindow::indvwindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::indvwindow)
{
    ui->setupUi(this);
    final=new finalwindow();
    connect(final ,&finalwindow::bwindow, this, &indvwindow::show);
}

indvwindow::~indvwindow()
{
    delete ui;
}

void indvwindow::on_backbutton_clicked()
{
    this->close();
    emit requestwindow();
}

void indvwindow::on_sendbutton_clicked()
{
    final->show();
    this->close();
}
