#ifndef INDIVIDUAL_H
#define INDIVIDUAL_H
#include "account.h"

class individual:public account
{
public:
   void randomFloor(int maxFloor);
   int getFloor();
private:
   int floor;
};

#endif // INDIVIDUAL_H
