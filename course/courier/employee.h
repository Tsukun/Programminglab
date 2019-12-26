#ifndef EMPLOYEE_H
#define EMPLOYEE_H
#include <QString>
#include <QStringList>

class employee
{
public:
    employee();
    virtual void work(QString str)=0;
private:
};

#endif // EMPLOYEE_H
