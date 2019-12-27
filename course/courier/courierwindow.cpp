#include "courierwindow.h"
#include "ui_courierwindow.h"

courierwindow::courierwindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::courierwindow)
{
    ui->setupUi(this);
    QStringList head;
    head<<"Выполнение заказа"<<"ФИО"<<"Адрес"<<"Категория"<<"Масса"<<"Пошлина";
    ui->inftable->setColumnCount(6);
    ui->inftable->horizontalHeader()->setVisible(1);
    ui->inftable->setHorizontalHeaderLabels(head);

}

courierwindow::~courierwindow()
{
    delete ui;
}

void courierwindow::updateinf(QString path)
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

             QTableWidgetItem *item = new QTableWidgetItem();
             item->data(Qt::CheckStateRole);
             item->setCheckState(Qt::Unchecked);
             ui->inftable->setItem(ui->inftable->rowCount()-1,0,item);

             if(list.at(i)=="ФИО:")
             {
                 for(int j=i+1;list.at(j)!="Адрес:";j++)
                 {

                     str+=list.at(j)+" ";
                 }
                   ui->inftable->setItem(ui->inftable->rowCount()-1, 1, new QTableWidgetItem());
                   ui->inftable->item(ui->inftable->rowCount()-1,1)->setText(str);
                   ui->inftable->resizeRowToContents(ui->inftable->rowCount()-1);
             }
             if(list.at(i)=="Адрес:")
             {
                 for(int j=i+1;list.at(j)!="Категория:";j++)
                 {
                   str+=list.at(j)+" ";
                 }
                   ui->inftable->setItem(ui->inftable->rowCount()-1, 2, new QTableWidgetItem());
                   ui->inftable->item(ui->inftable->rowCount()-1,2)->setText(str);
                   ui->inftable->resizeRowToContents(ui->inftable->rowCount()-1);


             }
             if(list.at(i)=="Категория:")
             {
                 for(int j=i+1;list.at(j)!="Масса:";j++)
                 {
                   str+=list.at(j)+" ";
                 }
                   ui->inftable->setItem(ui->inftable->rowCount()-1, 3, new QTableWidgetItem());
                   ui->inftable->item(ui->inftable->rowCount()-1,3)->setText(str);
                   ui->inftable->resizeRowToContents(ui->inftable->rowCount()-1);
             }
             if(list.at(i)=="Масса:")
             {
                 for(int j=i+1;list.at(j)!="Пошлина:";j++)
                 {
                   str+=list.at(j)+" ";
                 }
                   ui->inftable->setItem(ui->inftable->rowCount()-1, 4, new QTableWidgetItem());
                   ui->inftable->item(ui->inftable->rowCount()-1,4)->setText(str);
                   ui->inftable->resizeRowToContents(ui->inftable->rowCount()-1);
             }
             if(list.at(i)=="Пошлина:")
             {
                   str+=list.at(list.length()-2);
                   ui->inftable->setItem(ui->inftable->rowCount()-1,5, new QTableWidgetItem());
                   ui->inftable->item(ui->inftable->rowCount()-1,5)->setText(str);
                   ui->inftable->resizeRowToContents(ui->inftable->rowCount()-1);
             }
         }
     }
 file.close();
}
void courierwindow::on_backButton_clicked()
{
    this->close();
    window();
}


void courierwindow::on_updateButton_clicked()
{
    updateinf(path);
}

void courierwindow::on_pathButton_clicked()
{
   path = QFileDialog::getOpenFileName(0, "Open Dialog", "", "*.txt");
}

void courierwindow::on_confButton_clicked()
{
    //bool k;
    //k=ui->inftable->takeItem(0,0)->checkState();
    QFile file1("D:\\githubpr\\Programminglab\\course\\courier\\doneapplic.txt");
    QFile file2("D:\\githubpr\\Programminglab\\course\\courier\\notdoneapplic.txt");
    QTextStream stream1(&file1);
    QTextStream stream2(&file2);
    QStringList list;
    list<<"ФИО: "<<"Адрес: "<<"Категория: "<<"Масса: "<<"Пошлина: ";
    if(!file1.open(QIODevice::WriteOnly | QIODevice::Append | QIODevice::Text))
        {
            qDebug()<<"Error1";
        }
    if(!file2.open(QIODevice::WriteOnly | QIODevice::Text))
        {
            qDebug()<<"Error2";
        }
    for(int i=0;i<ui->inftable->rowCount();i++)
    {
        if(ui->inftable->item(i,0)->checkState()==0)
        {
         for(int j=1;j<ui->inftable->columnCount();j++)
          ui->inftable->item(i,j)->setBackground(Qt::red);

         stream2<<list.at(0)<<ui->inftable->item(i,1)->text()
               <<list.at(1)<<ui->inftable->item(i,2)->text()
              <<list.at(2)<<ui->inftable->item(i,3)->text()
             <<list.at(3)<<ui->inftable->item(i,4)->text()
            <<list.at(4)<<ui->inftable->item(i,5)->text()<<'\n';

        }
        else
        {
            for(int j=1;j<ui->inftable->columnCount();j++)
            ui->inftable->item(i,j)->setBackground(Qt::green);
           stream1<<list.at(0)<<ui->inftable->item(i,1)->text()
                 <<list.at(1)<<ui->inftable->item(i,2)->text()
                <<list.at(2)<<ui->inftable->item(i,3)->text()
               <<list.at(3)<<ui->inftable->item(i,4)->text()
              <<list.at(4)<<ui->inftable->item(i,5)->text()<<'\n';
        }
    }
}

