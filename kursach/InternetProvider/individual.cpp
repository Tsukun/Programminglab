#include "individual.h"

void individual::randomFloor(int MaxFloor)
{
   floor=1+rand()%MaxFloor;
}
int individual::getFloor()
{
    return floor;
}
