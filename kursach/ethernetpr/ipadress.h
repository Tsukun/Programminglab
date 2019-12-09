#ifndef IPADRESS_H
#define IPADRESS_H
#include <iostream>
#include <ctime>
#include <cmath>
using namespace std;
class ipadress
{
public:
    ipadress();
    ipadress(const ipadress & ip);
    ~ipadress();
    unsigned int *getip();
    unsigned int *getmask();
    //unsigned int genip(char ipc,int coun);
    void classX(char xcl);
private:
    unsigned int *ip;
    unsigned int *mask;
    char X;
    int count;
};

#endif // IPADRESS_H
