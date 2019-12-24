#ifndef ACCOUNT_H
#define ACCOUNT_H
#include <ctime>
#include <cstdlib>

class account
{
public:
    account();
    ~account();
    account(const account * s);
    void randEquip(int chance);
    void randDistance(int maxdistance);
    void setServ(int dist);
    bool getEquip();
    bool getServ();
    int getDistance();
    virtual double priceCalc(int criterion)=0;
    virtual double priceCalc(int countNotEquiped, int countAccount,int startprice)=0;
private:
 bool chanceEquip;
 bool limitServ;
 int distance;
};

#endif // ACCOUNT_H
