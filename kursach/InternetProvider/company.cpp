#include "company.h"

company::company(){}
company::~company(){}
void company::randomCount(int maxCount)
{
 count=rand()%maxCount;
}

int company::getCount()
{
   return count;
}
