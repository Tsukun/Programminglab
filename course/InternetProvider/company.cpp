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
double company::priceCalc(int criterion)
{
    if(criterion<1000)
        return 0;
    if(criterion>=1000&&criterion<=5000)
        return 300;
    if(criterion>5000)
        return 600;

    return 0;
}

double company::priceCalc(int countNotEquiped, int countAccount,int startprice)
{
    double calc=0;
    calc+=countNotEquiped*startprice*4+(countAccount-countNotEquiped)*startprice;
    return calc;
}