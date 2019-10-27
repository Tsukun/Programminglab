#ifndef SQUAREMATRIX_H
#define SQUAREMATRIX_H
#include <iostream>

class SquareMatrix
{
    double **value;
public:
    int dimension;
    SquareMatrix(int n);
    SquareMatrix(SquareMatrix& a);
    ~SquareMatrix();
     friend std::ostream& operator<< (std::ostream &out, const SquareMatrix& sm );
      friend std::istream& operator>> (std::istream &in,  SquareMatrix& sm );
     friend SquareMatrix operator+(SquareMatrix&m1,SquareMatrix&m2);
     SquareMatrix&  operator=(SquareMatrix&m1);
     friend SquareMatrix operator-(SquareMatrix&m1,SquareMatrix&m2);
     friend double operator*(SquareMatrix,SquareMatrix);
     void reverse (SquareMatrix&sm);
     void compareDeterm (SquareMatrix,SquareMatrix);
     int determinant(SquareMatrix&m1,int m);
     double matrixTrace (SquareMatrix &sm);
     void createTwoMatrix(SquareMatrix& sm);
      void GetMatr(SquareMatrix&m1, SquareMatrix&m2, int i, int j);
      void transp(SquareMatrix&m1);
      void algdop(SquareMatrix&m1,int m);

};
#endif // SQUAREMATRIX_H
