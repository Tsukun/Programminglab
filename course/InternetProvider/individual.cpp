#include "individual.h"

void individual::random(int x)
{
   floor=1+rand()%x;
}
int individual::getrandom()
{
    return floor;
}
double individual::priceCalc(int criterion)
{
        return 100*criterion/5;
}

double individual::priceCalc(int countNotEquiped, int countAccount,int startprice)
{
    double calc=0;
    calc+=countNotEquiped*startprice*2+(countAccount-countNotEquiped)*startprice;
    return calc;
}
