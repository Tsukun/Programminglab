#include "squarematrix.h"
#include <iostream>
using namespace std;
SquareMatrix::SquareMatrix()
{
    this->dimension=0;
    this->value=nullptr;
}
SquareMatrix::SquareMatrix(int n)
{
    this->dimension=n;
    this->value= new double*[n];
      for (int i = 0; i < n; i++)
           this->value[i] = new double[n];
}
SquareMatrix::SquareMatrix(SquareMatrix& a)
{
    dimension=a.dimension;
    value=new double*[a.get_dim()];
    for(int i=0;i<a.dimension;i++)
        value[i]=new double[a.get_dim()];
    value=a.value;
    for(int i=0;i<a.dimension;i++)
        value[i]=a.value[i];


}
SquareMatrix::~SquareMatrix()
{
    for (int i = 0; i < dimension; i++)
         delete []value[i];
}

void SquareMatrix::show(QTextBrowser*& textBrowser)
{

for(int i=0;i<this->dimension;i++){
    for(int j=0;j<this->dimension;j++){
    textBrowser->setText(QString::number(this->value[i][j])+" ");
    }
}

}
void SquareMatrix::set_val(double val)
{
        for(int i=0;i<this->dimension;i++)
             for(int j=0;j<this->dimension;j++)
                 this->value[i][j]=val;

}

int SquareMatrix::get_dim()
{
    return  this->dimension;
}
double** SquareMatrix::get_val()
{
    return this->value;
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
SquareMatrix operator*(SquareMatrix&m1,SquareMatrix&m2)
{
SquareMatrix m3(m1.dimension);
for(int i=0 ;i<m1.dimension;i++)
for(int j=0 ;j<m1.dimension;j++)
for(int k=0; k < m1.dimension; k++)
m3.value[i][j]+=m1.value[i][k]*m2.value[k][j];
return m3;
}
 SquareMatrix& SquareMatrix::operator=(SquareMatrix&m1 )
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

 void SquareMatrix::GetMatr(SquareMatrix&m1, SquareMatrix&m2, int i, int  j) {
   int ki, kj, di, dj;
   di = 0;
   for (ki = 0; ki<m1.dimension-1; ki++) {
     if (ki == i) di = 1;
     dj = 0;
     for (kj = 0; kj<m1.dimension-1; kj++) {
       if (kj == j) dj = 1;
       m2.value[ki][kj] = m1.value[ki + di][kj + dj];
     }
   }
 }

double SquareMatrix::determinant(SquareMatrix&m1, int m) {
   int i, j, k, n;
   double d;
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
 }
 SquareMatrix SquareMatrix::reverseMatrix (SquareMatrix&m1,double det)
 {
    if(det==0)
    {
    cout<<"net obratnoi matrici";
    return m1;
    }
    else
    {
    SquareMatrix m2(m1.dimension);
    SquareMatrix obrmatrix(m1.dimension);
    transp(m1);
        for (int i = 0; i<m2.dimension; i++) {
            for (int j = 0; j<m2.dimension; j++) {
        GetMatr(m1, m2, i, j);
        obrmatrix.value[i][j] = (pow(-1.0,i+j+2)*determinant(m2, m2.dimension-1))/det;

      }
    }
        for (int i = 0; i<m2.dimension; i++)
      for (int j = 0; j<m2.dimension; j++)
          m1.value[i][j]=obrmatrix.value[i][j];
return m1;
    }
}
 bool operator==(SquareMatrix&m1,SquareMatrix&m2)
 {
     bool check=true;
     if(m1.determinant(m1,m1.dimension)==m2.determinant(m2,m2.dimension))
         return check;
     else
        return !check;

 }
 bool operator>=(SquareMatrix&m1,SquareMatrix&m2)
 {
     bool check=true;
     if(m1.determinant(m1,m1.dimension)>=m2.determinant(m2,m2.dimension))
         return check;
     else
        return !check;

 }
 bool operator<=(SquareMatrix&m1,SquareMatrix&m2)
 {
     bool check=true;
     if(m1.determinant(m1,m1.dimension)<=m2.determinant(m2,m2.dimension))
         return check;
     else
        return !check;

 }
 bool operator!=(SquareMatrix&m1,SquareMatrix&m2)
 {
     bool check=true;
     if(m1.determinant(m1,m1.dimension)!=m2.determinant(m2,m2.dimension))
         return check;
     else
        return !check;

 }
 bool operator>(SquareMatrix&m1,SquareMatrix&m2)
 {
     bool check=true;
     if(m1.determinant(m1,m1.dimension)>m2.determinant(m2,m2.dimension))
         return check;
     else
        return !check;

 }
 bool operator<(SquareMatrix&m1,SquareMatrix&m2)
 {
     bool check=true;
     if(m1.determinant(m1,m1.dimension)<m2.determinant(m2,m2.dimension))
         return check;
     else
        return !check;

 }
