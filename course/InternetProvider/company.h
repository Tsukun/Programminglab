#ifndef COMPANY_H
#define COMPANY_H
#include "account.h"

class company:public account
{
public:
 company();
 ~company();
 void randomCount(int maxCount);
 int getCount();
 double priceCalc(int criterion) override;
 double priceCalc(int countNotEquiped, int countAccount,int startprice) override;
private:
 int count;
};

#endif // COMPANY_H
