#ifndef EMPLOYEE_H
#define EMPLOYEE_H
#include <QString>
#include <QStringList>
#include <QFile>
#include <QTextStream>
class employee
{
public:
    employee();
    virtual void work(QString str)=0;
    virtual void writeinfile(QString path,QString str)=0;
private:
};

#endif // EMPLOYEE_H
