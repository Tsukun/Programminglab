#include "account.h"

account::account()
{
    accountname="account_name";
    phonenumber="phone_number";
    adress="adress";
    count=0;
}
account::~account(){}
account::account(const account &s)
{
    accountname=s.accountname;
    phonenumber=s.phonenumber;
    adress=s.adress;
    count=s.count;
}
void account::setcount(int coun)
{
    count=coun;
}
void account::setaccname(string c)
{
    accountname=c;
}

void account::setphnumber(string p)
{
    phonenumber=p;
}
void account::setadress(string a)
{
    adress=a;
}
void account::setemail(string e)
{
    email=e;
}
int account::getcount()
{
    return count;
}
string account::getaccname()
{
    return accountname;
}

string account::getphnumber()
{
    return phonenumber;
}
string account::getadress()
{
    return adress;
}
string account::getemail()
{
    return email;
}
