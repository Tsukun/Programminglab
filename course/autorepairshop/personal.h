#ifndef PERSONAL_H
#define PERSONAL_H
#include <QString>
#include <QStringList>
#include <QFile>
#include <QTextStream>
#include <QDebug>
class personal
{
public:
    personal();
    virtual void workFile(QString path,QStringList str)=0;
};

#endif // PERSONAL_H
