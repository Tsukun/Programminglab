#include "individual.h"

void individual::randomFloor(int MaxFloor)
{
   floor=1+rand()%MaxFloor;
}
int individual::getFloor()
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
