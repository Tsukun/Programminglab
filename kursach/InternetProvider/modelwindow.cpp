#include "modelwindow.h"
#include "ui_modelwindow.h"

modelwindow::modelwindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::modelwindow)
{
    ui->setupUi(this);
}

modelwindow::~modelwindow()
{
    delete ui;
}

void modelwindow::generate(int chance,int count,int ratio,int maxDistance,int maxFloor,int maxCount)
{
   int x;
   comp=new company();
   indiv=new individual();
   QFile file("C:\\Users\\tsuku\\Documents\\InternetProvider\\test.txt");
   QTextStream out(&file);
   if (!file.open(QIODevice::WriteOnly | QIODevice::Text))
   {
       qDebug() << "Error";
   }
   srand(time(0));
   for(int i=0;i<count;i++)
   {
      x=rand()%100;
      if(x<ratio)
      {
       comp->randEquip(chance);
       comp->randDistance(maxDistance);
       comp->setServ(maxDistance);
       comp->randomCount(maxCount);
       out<<"Company#"<<i+1<<" ChanceEquip:"<<comp->getEquip()<<" ChanceServ:"<<comp->getServ();
       out<<" Distance:"<<comp->getDistance()<<" Count:"<<comp->getCount()<<" \n";
      }
      else
      {
       indiv->randEquip(chance);
       indiv->randDistance(maxDistance);
       indiv->setServ(maxDistance);
       indiv->randomFloor(maxFloor);
       out<<"Individual#"<<i+1<<" ChanceEquip:"<<indiv->getEquip()<<" ChanceServ:"<<indiv->getServ();
       out<<" Distance:"<<indiv->getDistance()<<" Floor:"<<indiv->getFloor()<<" \n";
      }
    }
   file.close();
}
void modelwindow::calcSuccesAccount()
{
  //QString str = QFileDialog::getOpenFileName(0, "Open Dialog", "", "*.txt");
  int countSuccesComp=0;
  int countSuccesIndiv=0;
  int countEquipComp=0;
  int countEquipIndiv=0;
  QStringList list;
  QFile file("C:\\Users\\tsuku\\Documents\\InternetProvider\\test.txt");
  if (!file.open(QIODevice::ReadOnly|QIODevice::Text))
  {
      qDebug() << "Error";
  }
  while(!file.atEnd())
  {
  QString s=file.readLine();
  list=s.split(" ");
  QString nameAcc=list.at(0).left(7);
  QString chanceServ=list.at(2).right(1);
  if(nameAcc=="Company"&&chanceServ!="0")
  {
      countEquipComp++;
      countSuccesComp++;
    qDebug()<<"Company";
  }
  else if(chanceServ!="0")
  {
       qDebug()<<"Individual";
       countSuccesIndiv++;
       countEquipIndiv++;
  }
  }
  file.close();
}
void modelwindow::on_pushButton_clicked()
{
 int chance,count,ratio,maxDistance,maxFloor,maxCount;
 chance=ui->chanceEquip->text().toInt();
 count=ui->countAccount->text().toInt();
 ratio=ui->ratioAccount->text().toInt();
 maxDistance=ui->maxDistance->text().toInt();
 maxFloor=ui->maxFloor->text().toInt();
 maxCount=ui->maxCount->text().toInt();
 generate(chance,count,ratio,maxDistance,maxFloor,maxCount);
 calcSuccesAccount();
}
