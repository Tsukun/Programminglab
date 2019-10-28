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
     friend SquareMatrix operator*(SquareMatrix&m1,SquareMatrix&m2);
     friend bool operator==(SquareMatrix&m1,SquareMatrix&m2);
     friend bool operator>(SquareMatrix&m1,SquareMatrix&m2);
     friend bool operator<(SquareMatrix&m1,SquareMatrix&m2);
     friend bool operator<=(SquareMatrix&m1,SquareMatrix&m2);
     friend bool operator>=(SquareMatrix&m1,SquareMatrix&m2);
     friend bool operator!=(SquareMatrix&m1,SquareMatrix&m2);
     SquareMatrix reverseMatrix (SquareMatrix&m1,double det);
     void compareDeterm (SquareMatrix,SquareMatrix);
     double determinant(SquareMatrix&m1,int m);
     double matrixTrace (SquareMatrix &sm);
     void GetMatr(SquareMatrix&m1, SquareMatrix&m2, int i, int j);
     void transp(SquareMatrix&m1);


};
#endif // SQUAREMATRIX_H
