#ifndef MANAGER_H
#define MANAGER_H
#include "employee.h"

class manager:public employee
{
public:
    manager();
    void work(QString str) override;
private:

};

#endif // MANAGER_H
