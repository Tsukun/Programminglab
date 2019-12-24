#ifndef INDIVIDUAL_H
#define INDIVIDUAL_H
#include "account.h"

class individual:public account
{
public:
   void randomFloor(int maxFloor);
   int getFloor();
   double priceCalc(int criterion) override;
   double priceCalc(int countNotEquiped, int countAccount,int startprice) override;
private:
   int floor;
};

#endif // INDIVIDUAL_H
