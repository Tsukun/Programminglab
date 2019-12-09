#include "ipadress.h"

ipadress::ipadress()
{
   mask=new unsigned int [4];
   ip=new unsigned int[4];
   for(int i=0;i<4;i++){
       ip[i]=0;
       mask[i]=255;
   }
   count=0;
}
ipadress::~ipadress()
{
    delete mask;
    delete ip;
}
ipadress::ipadress(const ipadress& a)
{
    ip=a.ip;
    mask=a.mask;
    X=a.X;
    count=a.count;
}

unsigned int* mgener(int count)
{
    unsigned int *temp=new unsigned int[4];
    int x=ceil(log2(count));
    for(int i=0;i<4;i++)
        temp[i]=255;

        for (int i = 3; i >= 0; i--)
        {
        for (int j = 0; j < 8; j++)
        {
         if (x != 0)
         {
         temp[i] -= pow(2, j);
          x--;
         }
         else
         break;
        }
        }
        return temp;

}
void ipadress::classX(char xcl)
{
    srand(time(0));
    switch(xcl)
    {
     case 'A':

        ip[0]=1+rand()%125;
        ip[1]=rand()%255;
        ip[2]=rand()%255;
        ip[3]=rand()%255;
        mask=mgener(count);

        break;

    case 'B':
       ip[0]=128+rand()%63;
       ip[1]=rand()%255;
       ip[2]=rand()%255;
       ip[3]=rand()%255;

       break;
    case 'C':
       ip[0]=192+rand()%31;
       ip[1]=rand()%255;
       ip[2]=rand()%255;
       ip[3]=rand()%255;

       break;
    }
}

unsigned int* ipadress::getip()
{
    return ip;
}

unsigned int* ipadress::getmask()
{
    return mask;
}

