#include "diagnosticwindow.h"
#include "ui_diagnosticwindow.h"

diagnosticwindow::diagnosticwindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::diagnosticwindow)
{
    ui->setupUi(this);
}

diagnosticwindow::~diagnosticwindow()
{
    delete ui;
}

void diagnosticwindow::on_backButton_clicked()
{
    window();
    this->close();
}

void diagnosticwindow::on_addButton_clicked()
{
    QStringList list;
    QString str;
    pers=new mechanic();
    str+="ФИО Мастера: "+ui->fmasternameEdit->text()+" ";
    str+="ФИО: "+ui->fnameEdit->text()+" ";
    str+="Телефон: "+ui->telnumberEdit->text()+" ";
    str+="Машина: "+ui->carEdit->text();
    if(ui->kuzovButton->isChecked())
    str+=" Кузовные Работы: 1";
    else
    str+=" Кузовные Работы: 0";
    if(ui->paintButton->isChecked())
    str+=" Покраска: 1";
    else
    str+=" Покраска: 0";
    if(ui->washButton->isChecked())
    str+=" Техническая мойка: 1";
    else
    str+=" Техническая мойка: 0";
    if(ui->balancButton->isChecked())
    str+=" Балансировка колёс: 1";
    else
    str+=" Балансировка колёс: 0";
    if(ui->replaceButton->isChecked())
    str+=" Замена шин: 1";
    else
    str+=" Замена шин: 0";
    if(ui->defsysButton->isChecked())
    str+=" Установка систем безопасности: 1";
    else
    str+=" Установка систем безопасности: 0";
    if(ui->replacediskButton->isChecked())
    str+=" Замена дисков: 1";
    else
    str+=" Замена дисков: 0";
    list=str.split(" ");
    pers->workFile("D:\\githubpr\\Programminglab\\course\\autorepairshop\\diagnostic.txt",list);
}
