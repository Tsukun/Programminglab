#include "managerwindow.h"
#include "ui_managerwindow.h"

managerwindow::managerwindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::managerwindow)
{
    ui->setupUi(this);
    QStringList head;
    head<<"ФИО"<<"Адрес"<<"Категория"<<"Масса"<<"Пошлина";
    ui->inftable->setColumnCount(5);
    ui->inftable->horizontalHeader()->setVisible(1);
    ui->inftable->setHorizontalHeaderLabels(head);
    //updateinf();
}

managerwindow::~managerwindow()
{
    delete ui;
}


void managerwindow::updateinf(QString path)
{
     QStringList list;
     QFile file(path);
     QTextStream stream(&file);
     if(!file.open(QIODevice::ReadOnly|QIODevice::Text))
     {
     qDebug()<<"Error";
     }
     ui->inftable->setRowCount(0);
     while(!stream.atEnd())
     {
         QString str=stream.readLine();
         list=str.split(" ");
         ui->inftable->setRowCount(ui->inftable->rowCount()+1);
         for(int i=0;i<list.length();i++)
         {
             str="";
             if(list.at(i)=="ФИО:")
             {
                 for(int j=i+1;list.at(j)!="Адрес:";j++)
                 {

                     str+=list.at(j)+" ";
                 }
                   ui->inftable->setItem(ui->inftable->rowCount()-1, 0, new QTableWidgetItem());
                   ui->inftable->item(ui->inftable->rowCount()-1,0)->setText(str);
                   ui->inftable->resizeRowToContents(ui->inftable->rowCount()-1);
             }
             if(list.at(i)=="Адрес:")
             {
                 for(int j=i+1;list.at(j)!="Категория:";j++)
                 {
                   str+=list.at(j)+" ";
                 }
                   ui->inftable->setItem(ui->inftable->rowCount()-1, 1, new QTableWidgetItem());
                   ui->inftable->item(ui->inftable->rowCount()-1,1)->setText(str);
                   ui->inftable->resizeRowToContents(ui->inftable->rowCount()-1);

             }
             if(list.at(i)=="Категория:")
             {
                 for(int j=i+1;list.at(j)!="Масса:";j++)
                 {
                   str+=list.at(j)+" ";
                 }
                   ui->inftable->setItem(ui->inftable->rowCount()-1, 2, new QTableWidgetItem());
                   ui->inftable->item(ui->inftable->rowCount()-1,2)->setText(str);
                   ui->inftable->resizeRowToContents(ui->inftable->rowCount()-1);
             }
             if(list.at(i)=="Масса:")
             {
                 for(int j=i+1;list.at(j)!="Пошлина:";j++)
                 {
                   str+=list.at(j)+" ";
                 }
                   ui->inftable->setItem(ui->inftable->rowCount()-1, 3, new QTableWidgetItem());
                   ui->inftable->item(ui->inftable->rowCount()-1,3)->setText(str);
                   ui->inftable->resizeRowToContents(ui->inftable->rowCount()-1);
             }
             if(list.at(i)=="Пошлина:")
             {
                   str+=list.at(list.length()-2);
                   ui->inftable->setItem(ui->inftable->rowCount()-1,4, new QTableWidgetItem());
                   ui->inftable->item(ui->inftable->rowCount()-1,4)->setText(str);
                   ui->inftable->resizeRowToContents(ui->inftable->rowCount()-1);
             }
         }
     }
 file.close();
}


void managerwindow::on_backButton_clicked()
{
    this->close();
    window();
}

void managerwindow::on_updateButton_clicked()
{
 updateinf(path);
}

void managerwindow::on_pathButton_clicked()
{
    path = QFileDialog::getOpenFileName(0, "Open Dialog", "", "*.txt");
}
