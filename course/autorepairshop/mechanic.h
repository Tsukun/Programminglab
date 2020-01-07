#ifndef MECHANIC_H
#define MECHANIC_H
#include "personal.h"

class mechanic:public personal
{
public:
mechanic();
void workFile(QString path, QStringList str) override;
void calcPrice(double price);
double getPrice();
private:
double finalprice;
};

#endif // MECHANIC_H
