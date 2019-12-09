#ifndef INDIVIDUAL_H
#define INDIVIDUAL_H
#include "account.h"

class individual:public account
{
public:
   void sethousenum(string h);
   void setfloor(string f);
   string gethousenum();
   string getfloor();
private:
    string housenum;
    string floor;
};

#endif // INDIVIDUAL_H
