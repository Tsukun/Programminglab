#include "squarematrix.h"
#include <iostream>
#include <math.h>
using namespace std;
/*SquareMatrix::SquareMatrix()
{
    this->value= new double*[dimension];
      for (int i = 0; i < dimension; i++)
           this->value[i] = new double[dimension];
}*/
/*SquareMatrix::SquareMatrix(int n)
{
    this->dimension=n;
    this->value= new double*[n];
      for (int i = 0; i < n; i++)
           this->value[i] = new double[n];
}*/
SquareMatrix::SquareMatrix(double**val, int dim ) // конструктор с параметрами и по умолчанию
{
    value = val;
    dimension = dim;
}
SquareMatrix::SquareMatrix(SquareMatrix& a)
{
    dimension=a.get_dim();
    value=new double*[dimension];
    for(int i=0;i<a.dimension;i++)
        value[i]=new double[dimension];
    value=a.get_val();
    for(int i=0;i<a.get_dim();i++)
        value[i]=a.get_val()[i];


}
SquareMatrix::~SquareMatrix()
{
    for (int i = 0; i < dimension; i++)
         delete []value[i];
}

void SquareMatrix::show(QTextBrowser*& textBrowser)
{
       QString s;
for(int i=0;i<this->dimension;i++){
    s+="\n";
    for(int j=0;j<this->dimension;j++){
        s+=QString::number(this->value[i][j]) + " ";
    }
}
    textBrowser->setText(s);
}
void SquareMatrix::set_val(double val,int i ,int j)
{
               value[i][j]=val;

}

void SquareMatrix::set_dim (int dim)
{

    this->dimension=dim;
    value=new double*[dimension];
    for(int i=0;i<dimension;i++)
        value[i]=new double[dimension];
}
int SquareMatrix::get_dim()
{
    return  dimension;
}
double** SquareMatrix::get_val()
{
    return value;
}

 SquareMatrix operator+(SquareMatrix&m1,SquareMatrix&m2)
{
     SquareMatrix m3;
     m3.set_dim(m1.get_dim());
    for(int i=0 ;i<m1.get_dim();i++)
         for(int j=0 ;j<m1.get_dim();j++)
          m3.value[i][j]=m1.get_val()[i][j]+m2.get_val()[i][j];

    return m3;
}
SquareMatrix operator-(SquareMatrix&m1,SquareMatrix&m2)
 {
     SquareMatrix m3;
     m3.set_dim(m1.get_dim());
    for(int i=0 ;i<m1.dimension;i++)
         for(int j=0 ;j<m1.dimension;j++)
          m3.value[i][j]=m1.value[i][j]-m2.value[i][j];

    return m3;
 }
SquareMatrix operator*(SquareMatrix&m1,SquareMatrix&m2)
{
SquareMatrix m3;
m3.set_dim(m1.get_dim());

for(int i=0 ;i<m1.get_dim();i++)
for(int j=0 ;j<m1.get_dim();j++)
for(int k=0; k < m1.get_dim(); k++)
m3.value[i][j]+=m1.get_val()[i][k]*m2.get_val()[k][j];

return m3;
}
 SquareMatrix& SquareMatrix::operator=(const SquareMatrix&m1 )
 {
     this->dimension=m1.dimension;
     this->value=new double*[this->dimension];
       for(int i=0 ;i<m1.dimension;i++)
       {
            this->value[i] = new double[this->dimension];
            for(int j=0 ;j<m1.dimension;j++)
                this->value[i][j]=m1.value[i][j];
       }
       return *this;
 }
 double SquareMatrix::matrixTrace(SquareMatrix&m1)
 {
   double Trace=0;
   for (int i=0; i<m1.get_dim(); i++)
       Trace+=m1.get_val()[i][i];
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
   SquareMatrix m2;
   m2.set_dim(m);
   j = 0; d = 0;
   k = 1; //(-1) в степени i
   n = m-1;
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
 SquareMatrix SquareMatrix::inverseMatrix (SquareMatrix&m1,double det)
 {

    SquareMatrix m2;
    m2.set_dim(m1.get_dim());
    SquareMatrix obrmatrix;
    obrmatrix.set_dim(m1.get_dim());
    if(m1.get_dim()==2)
    {
           transp(m1);
           for (int i = 0; i<m2.get_dim(); i++) {
               for (int j = 0; j<m2.get_dim(); j++) {
                  m1.value[i][j]/=pow(-1.0,i+j)*determinant(m1, m1.get_dim());
               }
           }
    }
    else
    {
           transp(m1);
        for (int i = 0; i<m2.get_dim(); i++) {
            for (int j = 0; j<m2.get_dim(); j++) {
        GetMatr(m1, m2, i, j);
        obrmatrix.value[i][j] = (pow(-1.0,i+j+2)*determinant(m2, m2.get_dim()-1))/det;

      }
    }
        for (int i = 0; i<m2.get_dim(); i++)
      for (int j = 0; j<m2.get_dim(); j++)
          m1.value[i][j]=obrmatrix.get_val()[i][j];
    }
return m1;
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
