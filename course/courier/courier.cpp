#include "courier.h"
courier::courier()
{

}

void courier::writeinfile(QString path, QString str)
{
QFile file1(path);
if(!file1.open(QIODevice::WriteOnly | QIODevice::Append | QIODevice::Text))
    {
        qDebug()<<"Error1";
    }
QTextStream stream1(&file1);
    stream1<<str;
}
void courier::work(QString str){}
