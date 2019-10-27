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
    return out;
}
std::istream& operator>> (std::istream &in,  SquareMatrix& sm )
{
        for (int i = 0; i < sm.dimension; i++)
              for (int j = 0; j < sm.dimension; j++){
                   cout<<"Vvedite "<<i+1<<" stolbec "<<j+1<<" stroku = ";
                  in>> sm.value[i][j];
              }
        return in;
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
 double SquareMatrix::matrixTrace(SquareMatrix&m1)
 {
   double Trace;
   for (int i=0; i<m1.dimension; i++)
       Trace+=m1.value[i][i];
   return Trace;
 }

 void SquareMatrix::GetMatr(SquareMatrix&m1, SquareMatrix&m2, int i, int j) {
   int ki, kj, di, dj;
   di = 0;
   for (ki = 0; ki<m1.dimension-1; ki++) { // проверка индекса строки
     if (ki == i) di = 1;
     dj = 0;
     for (kj = 0; kj<m1.dimension-1; kj++) { // проверка индекса столбца
       if (kj == j) dj = 1;
       m2.value[ki][kj] = m1.value[ki + di][kj + dj];
     }
   }
 }
 // Рекурсивное вычисление определителя
 int SquareMatrix::determinant(SquareMatrix&m1, int m) {
   int i, j, d, k, n;
   SquareMatrix m2(m);
   j = 0; d = 0;
   k = 1; //(-1) в степени i
   n = m-1;
   if (m2.dimension<1) cout << "Opredilitel vischislit nevozmohno!";
   if (m2.dimension == 1) {
     d = m2.value[0][0];
     return d;
   }
   if (m2.dimension == 2) {
     d = m1.value[0][0] * m1.value[1][1]-(m1.value[1][0] * m1.value[0][1]);
     return d;
   }
   if (m2.dimension>2) {
     for (i = 0; i<m2.dimension; i++) {
       GetMatr(m1, m2, i, 0);
       d = d + k * m1.value[i][0] * determinant(m2, n);
       k = -k;
     }
   }
   return d;
 }
 void SquareMatrix::algdop(SquareMatrix&m1,int m)
 {
     int i, j, d, k, n;
     SquareMatrix m2(m);
     j = 0; d = 0;
     k = 1; //(-1) в степени i
     n = m-1;
     if (m2.dimension<1) cout << "Opredilitel vischislit nevozmohno!";
     if (m2.dimension == 1) {
       d = m2.value[0][0];
     }
     if (m2.dimension == 2) {
       d = m1.value[0][0] * m1.value[1][1]-(m1.value[1][0] * m1.value[0][1]);
     }
     if (m2.dimension>2) {
       for (i = 0; i<m2.dimension; i++) {
         GetMatr(m1, m2, i, 0);
         d = k * m1.value[i][0] * determinant(m2, n);
         k = -k;
       }
     }

 }
void SquareMatrix::transp(SquareMatrix&m1)
{
    double temp;
    for(int i=0;i<m1.dimension;i++){
         for(int j=0;j<m1.dimension;j++)
         {
             temp=m1.value[i][j];
             m1.value[i][j]=m1.value[j][i];
             m1.value[i][j]=temp;
         }
        }
    for(int i=0;i<m1.dimension;i++){
        cout<<"\n";
         for(int j=0;j<m1.dimension;j++)
             cout<<m1.value[i][j]<<" ";
    }
}
 void SquareMatrix::reverse(SquareMatrix&sm)
 {

 }
