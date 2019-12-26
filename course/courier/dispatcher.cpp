#include "dispatcher.h"
dispatcher::dispatcher()
{
    inf.clear();
}
void dispatcher::work(QString str)
{
  inf+=str;
}
QStringList dispatcher::getinf()
{
    return inf;
}
