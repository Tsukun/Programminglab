#ifndef COURIER_H
#define COURIER_H
#include "employee.h"

class courier:public employee
{
public:
    courier();
    void work(QString str) override;
     void writeinfile(QString path, QString str) override;
};

#endif // COURIER_H
