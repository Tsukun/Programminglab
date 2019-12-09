#ifndef ACCOUNT_H
#define ACCOUNT_H
#include <iostream>
using namespace std;
class account
{
public:
    account();
    ~account();
    account(const account &s);
   void setcount(int count);
   void setaccname(string c);
   void setphnumber(string p);
   void setadress(string a);
    void setemail(string e);
    int getcount();
    string getaccname();
    string getphnumber();
    string getadress();
    string getemail();
private:
    string accountname;
    string phonenumber;
    string adress;
    string email;
    int count;
};
#endif // ACCOUNT_H
