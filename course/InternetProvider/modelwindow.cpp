#include "modelwindow.h"
#include "ui_modelwindow.h"

modelwindow::modelwindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::modelwindow)
{
    ui->setupUi(this);
    setWindowIcon(QIcon(":/resource/resource/icon.png"));
    setWindowTitle("Internet Provider");
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
   QFile file("D:\\githubpr\\Programminglab\\course\\InternetProvider\\systemfile.txt");
   QTextStream out(&file);
   if (!file.open(QIODevice::WriteOnly | QIODevice::Text))
   {
       qDebug() << "Error1";
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
    calcSuccesAccount();
}
void modelwindow::calcSuccesAccount()
{
  comp=new company();
  indiv=new individual();
  int countSuccesComp=0;
  int countSuccesIndiv=0;
  int countNotEquipComp=0;
  int countNotEquipIndiv=0;
  int totalprice=0;
  QStringList list;
  QString out="";
  QFile file("D:\\githubpr\\Programminglab\\course\\InternetProvider\\systemfile.txt");
  if (!file.open(QIODevice::ReadOnly|QIODevice::Text))
  {
      qDebug() << "Error2";
  }
  while(!file.atEnd())
  {
  QString s=file.readLine();
  out+=s;
  list=s.split(" ");
  QString nameAcc=list.at(0).left(7);
  QString chanceServ=list.at(2).right(1);
  QString chanceNotEquip=list.at(1).right(1);

  if(nameAcc=="Company"&&chanceServ!="0")
  {
    QString countWorkers=list.at(4).right(list.at(4).length()-6);
    totalprice+=comp->priceCalc(countWorkers.toInt());

     if(chanceNotEquip=="0")
      countNotEquipComp++;

      countSuccesComp++;
  }
  else if(chanceServ!="0")
  {
      QString countFloors=list.at(4).right(list.at(4).length()-6);
      totalprice+=indiv->priceCalc(countFloors.toInt());

      if(chanceNotEquip=="0")
       countNotEquipIndiv++;

       countSuccesIndiv++;
  }
  }
  totalprice+=comp->priceCalc(countNotEquipComp,countSuccesComp,ui->coeffpricecomp->text().toInt());
  totalprice+=indiv->priceCalc(countNotEquipIndiv,countSuccesIndiv,ui->coeffpriceindiv->text().toInt());
  ui->finalprice->setText(QString::number(totalprice));
  ui->plainTextEdit->setPlainText(out);
  ui->succesaccount->setText("Количество успешных аккаунтов: "+QString::number(countSuccesComp+countSuccesIndiv));
  ui->succescomp->setText("Количество успешных компаний: "+QString::number(countSuccesComp));
  ui->succesindiv->setText("Количество успешных физ.лиц: "+QString::number(countSuccesIndiv));
  ui->countNotEquipC->setText("Количество не оснащенных компаний: "+QString::number(countNotEquipComp));
  ui->countNotEquipI->setText("Количество не оснащенных физ.лиц: "+QString::number(countNotEquipIndiv));
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
}
