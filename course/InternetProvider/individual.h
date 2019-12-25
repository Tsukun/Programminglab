#ifndef INDIVIDUAL_H
#define INDIVIDUAL_H
#include "account.h"

class individual:public account
{
public:
   void random(int x) override;
   int getrandom() override;
   double priceCalc(int criterion) override;
   double priceCalc(int countNotEquiped, int countAccount,int startprice) override;
private:
   int floor;
};

#endif // INDIVIDUAL_H
