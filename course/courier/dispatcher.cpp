#include "dispatcher.h"
dispatcher::dispatcher()
{
    inf.clear();
}
void dispatcher::work(QString str)
{
  inf+=str;
}
void dispatcher::writeinfile(QFile file, QString str)
{
    QTextStream stream(&file);
    stream<<str;
}
QStringList dispatcher::getinf()
{
    return inf;
}
