#include "account.h"

account::account()
{
    distance=0;
    chanceEquip=0;
    limitServ=0;
}
account::~account(){}
account::account(const account * s)
{
 chanceEquip=s->chanceEquip;
}
void account::randEquip(int chance)
{
    int x;
    x=rand()%100;
    if(x<chance)
        chanceEquip=1;
    else
        chanceEquip=0;
}
void account::randDistance(int maxdistance)
{   int x=1+rand()%10;
    distance=rand()%maxdistance*x;
}
void account::setServ(int dist)
{   if(distance>dist)
    limitServ=0;
    else
    limitServ=1;
}
int account::getDistance()
{
    return distance;
}
bool account::getEquip()
{
    return chanceEquip;
}
bool account::getServ()
{
    return limitServ;
}
