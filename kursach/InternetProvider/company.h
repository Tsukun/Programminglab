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
private:
 int count;
};

#endif // COMPANY_H
