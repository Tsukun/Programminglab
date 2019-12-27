#include "dispatcher.h"
dispatcher::dispatcher()
{
    inf.clear();
}
void dispatcher::work(QString str)
{
  inf+=str;
}
void dispatcher::writeinfile(QString path,QString str)
{
    QFile file(path);
    if(!file.open(QIODevice::WriteOnly | QIODevice::Append | QIODevice::Text))
        {
            qDebug()<<"Error";
        }
    QTextStream stream(&file);
    for(int i =0;i<inf.length();i++)
        stream<<inf.at(i)<<" ";
    stream<<'\n';

file.close();
}
QStringList dispatcher::getinf()
{
    return inf;
}
