#ifndef DISPATCHER_H
#define DISPATCHER_H
#include "employee.h"

class dispatcher:public employee
{
public:
    dispatcher();
    void work(QString str) override;
    QStringList getinf();
private:
    QStringList inf;
};

#endif // DISPATCHER_H
