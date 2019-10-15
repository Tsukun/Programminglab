#include "squarematrix.h"
#include <iostream>
using namespace std;
SquareMatrix::SquareMatrix(int n)
{
    dimension=n;
    value= new double*[n];
      for (int i = 0; i < n; i++)
           value[i] = new double[n];
}
SquareMatrix::SquareMatrix(SquareMatrix& a)
{
    dimension=a.dimension;
    value=new double*[a.dimension];
    for(int i=0;i<a.dimension;i++)
        value[i]=new double[a.dimension];
    value=a.value;
    for(int i=0;i<a.dimension;i++)
        value[i]=a.value[i];


}
SquareMatrix::~SquareMatrix()
{
    for (int i = 0; i < dimension; i++)
         delete []value[i];
}

std::ostream& operator<< (std::ostream &out, const SquareMatrix& sm )
{
    out<<"\n";
    for (int i = 0; i < sm.dimension; i++){
          for (int j = 0; j < sm.dimension; j++)
              out<<sm.value[i][j]<<" ";

          out<<"\n";
    }
}
std::istream& operator>> (std::istream &in,  SquareMatrix& sm )
{
        for (int i = 0; i < sm.dimension; i++)
              for (int j = 0; j < sm.dimension; j++){
                   cout<<"Vvedite "<<i+1<<" stolbec "<<j+1<<" stroku = ";
                  in>> sm.value[i][j];
              }
}

void SquareMatrix::createTwoMatrix(SquareMatrix& sm)
{
    cout<<"Vvedite rasmernost` = ";
    cin>>sm.dimension;
    sm.value= new double*[sm.dimension];
      for (int i = 0; i < sm.dimension; i++)
           sm.value[i] = new double[sm.dimension];

        for (int i = 0; i < sm.dimension; i++)
              for (int j = 0; j < sm.dimension; j++){
                   cout<<"Vvedite "<<i+1<<" stolbec "<<j+1<<" stroku = ";
                  cin>> sm.value[i][j];
              }
}

 SquareMatrix operator+(SquareMatrix&m1,SquareMatrix&m2)
{
     SquareMatrix m3(m1.dimension);
    for(int i=0 ;i<m1.dimension;i++)
         for(int j=0 ;j<m1.dimension;j++)
          m3.value[i][j]=m1.value[i][j]+m2.value[i][j];

    return m3;
}
SquareMatrix operator-(SquareMatrix&m1,SquareMatrix&m2)
 {
     SquareMatrix m3(m1.dimension);
    for(int i=0 ;i<m1.dimension;i++)
         for(int j=0 ;j<m1.dimension;j++)
          m3.value[i][j]=m1.value[i][j]-m2.value[i][j];

    return m3;
 }
 SquareMatrix& SquareMatrix::operator=(SquareMatrix&m1)
 {
     this->dimension=m1.dimension;
     this->value= new double*[this->dimension];
       for(int i=0 ;i<m1.dimension;i++)
       {
            value[i] = new double[this->dimension];
            for(int j=0 ;j<m1.dimension;j++)
                this->value[i][j]=m1.value[i][j];
       }
       return *this;
 }
