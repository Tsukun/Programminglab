#include "applicwindow.h"
#include "ui_applicwindow.h"

applicwindow::applicwindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::applicwindow)
{
    ui->setupUi(this);
    QStringList head;
    head<<"ФИО"<<"Телефон"<<"Машина"<<"Кузовные работы"<<"Покраска"
       <<"Техническая мойка"<<"Балансировка колёс"<<"Замена шин"<<"Цена";

    ui->applictable->setColumnCount(9);
    ui->applictable->horizontalHeader()->setVisible(1);
    ui->applictable->setHorizontalHeaderLabels(head);
}

applicwindow::~applicwindow()
{
    delete ui;
}

void applicwindow::updateInf(QString str)
{
         QStringList list;
         QFile file(str);
         QTextStream stream(&file);
         int price=200;
         if(!file.open(QIODevice::ReadOnly|QIODevice::Text))
         {
         qDebug()<<"Error";
         }
         ui->applictable->setRowCount(0);
         while(!stream.atEnd())
         {
             QString str=stream.readLine();
             list=str.split(" ");
             ui->applictable->setRowCount(ui->applictable->rowCount()+1);

             for(int i=0;i<list.length();i++)
             {
             str="";
             if(list.at(i)=="ФИО:")
             {
              for(int j=i+1;list.at(j)!="Телефон:";j++)
             {
             str+=list.at(j)+" ";
             }
               ui->applictable->setItem(ui->applictable->rowCount()-1, 0, new QTableWidgetItem());
               ui->applictable->item(ui->applictable->rowCount()-1,0)->setText(str);
               ui->applictable->resizeRowToContents(ui->applictable->rowCount()-1);
             }
             if(list.at(i)=="Телефон:")
             {
              for(int j=i+1;list.at(j)!="Машина:";j++)
             {

             str+=list.at(j)+" ";
             }
               ui->applictable->setItem(ui->applictable->rowCount()-1, 1, new QTableWidgetItem());
               ui->applictable->item(ui->applictable->rowCount()-1,1)->setText(str);
               ui->applictable->resizeRowToContents(ui->applictable->rowCount()-1);
             }
             if(list.at(i)=="Машина:")
             {
              for(int j=i+1;list.at(j)!="Кузовные";j++)
             {
             str+=list.at(j)+" ";
             }
               ui->applictable->setItem(ui->applictable->rowCount()-1, 2, new QTableWidgetItem());
               ui->applictable->item(ui->applictable->rowCount()-1,2)->setText(str);
               ui->applictable->resizeRowToContents(ui->applictable->rowCount()-1);
             }

             if(list.at(i)=="Работы:")
             {
              for(int j=i+1;list.at(j)!="Покраска:";j++)
             {
             str+=list.at(j)+" ";
             }
               ui->applictable->setItem(ui->applictable->rowCount()-1, 3, new QTableWidgetItem());
               ui->applictable->item(ui->applictable->rowCount()-1,3)->setText(str);
               ui->applictable->resizeRowToContents(ui->applictable->rowCount()-1);
             }
             if(list.at(i)=="Покраска:")
             {
              for(int j=i+1;list.at(j)!="Техническая";j++)
             {
             str+=list.at(j)+" ";
             }
               ui->applictable->setItem(ui->applictable->rowCount()-1, 4, new QTableWidgetItem());
               ui->applictable->item(ui->applictable->rowCount()-1,4)->setText(str);
               ui->applictable->resizeRowToContents(ui->applictable->rowCount()-1);
             }
             if(list.at(i)=="мойка:")
             {
              for(int j=i+1;list.at(j)!="Балансировка";j++)
             {
             str+=list.at(j)+" ";
             }
               ui->applictable->setItem(ui->applictable->rowCount()-1, 5, new QTableWidgetItem());
               ui->applictable->item(ui->applictable->rowCount()-1,5)->setText(str);
               ui->applictable->resizeRowToContents(ui->applictable->rowCount()-1);
             }
             if(list.at(i)=="колёс:")
             {
              for(int j=i+1;list.at(j)!="Замена";j++)
             {
             str+=list.at(j)+" ";
             }
               ui->applictable->setItem(ui->applictable->rowCount()-1, 6, new QTableWidgetItem());
               ui->applictable->item(ui->applictable->rowCount()-1,6)->setText(str);
               ui->applictable->resizeRowToContents(ui->applictable->rowCount()-1);
             }
             if(list.at(i)=="шин:")
             {
                 str+=list.at(list.length()-2);
                 ui->applictable->setItem(ui->applictable->rowCount()-1, 7, new QTableWidgetItem());
                 ui->applictable->item(ui->applictable->rowCount()-1,7)->setText(str+" ");
                 ui->applictable->resizeRowToContents(ui->applictable->rowCount()-1);
             }
             }
             }
         srand(time(0));
         for(int i=0;i<ui->applictable->rowCount();i++)
         {
             mech=new mechanic();
             for(int k=3;k<ui->applictable->columnCount()-1;k++)
             {
                 int random=1+rand()%10;
                 if(ui->applictable->item(i,k)->text()=="1 ")
                     mech->calcPrice(price*(rand()%random));
             }
             ui->applictable->setItem(i, 8, new QTableWidgetItem());
             ui->applictable->item(i,8)->setText(QString::number(mech->getPrice()));
             ui->applictable->resizeRowToContents(i);
         }
  }


void applicwindow::on_backButton_clicked()
{
  window();
  this->close();
}

void applicwindow::on_pathButton_clicked()
{
  path = QFileDialog::getOpenFileName(0, "Open Dialog", "", "*.txt");
}

void applicwindow::on_updateButton_clicked()
{
    updateInf(path);
}
