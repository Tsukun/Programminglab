#include "mechanic.h"

mechanic::mechanic()
{
finalprice=0;
}
void mechanic::workFile(QString path, QStringList str)
{
    QFile file(path);
        if(!file.open(QIODevice::WriteOnly | QIODevice::Append | QIODevice::Text))
            {
                qDebug()<<"Error";
            }
        QTextStream stream(&file);
            for(int i=0;i<str.length();i++)
            stream<<str.at(i)<<" ";
        stream<<'\n';

    file.close();
}
void mechanic::calcPrice(double price)
{
    finalprice+=price;
}
double mechanic::getPrice()
{
    return finalprice;
}
