#include "dispatcherwindow.h"
#include "ui_dispatcherwindow.h"

dispatcherwindow::dispatcherwindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::dispatcherwindow)
{
    ui->setupUi(this);
     setWindowTitle("Диспетчер");
}

dispatcherwindow::~dispatcherwindow()
{
    delete ui;
}

void dispatcherwindow::on_backButton_clicked()
{
 this->close();
 window();
}

void dispatcherwindow::on_checkoutButton_clicked()
{
     disp=new dispatcher();
     disp->work("ФИО: "+ui->fnameEdit->text());
     disp->work("Адрес: "+ui->addressEdit->text());
     disp->work("Категория: "+ui->categoryEdit->text());
     disp->work("Масса: "+ui->weightEdit->text());
     disp->work("Пошлина: "+ui->dutyEdit->text());
     disp->writeinfile("D:\\githubpr\\Programminglab\\course\\courier\\fileout.txt","");

}
