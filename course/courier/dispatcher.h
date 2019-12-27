#ifndef DISPATCHER_H
#define DISPATCHER_H
#include "employee.h"
#include <QDebug>
class dispatcher:public employee
{
public:
    dispatcher();
    void work(QString str) override;
    void writeinfile(QString path,QString str) override;
    QStringList getinf();
private:
    QStringList inf;
};

#endif // DISPATCHER_H
