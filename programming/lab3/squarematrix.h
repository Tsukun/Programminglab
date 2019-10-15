#ifndef SQUAREMATRIX_H
#define SQUAREMATRIX_H
#include <iostream>

class SquareMatrix
{
    int dimension;
    double **value;
public:
    SquareMatrix(int n);
    SquareMatrix(SquareMatrix& a);
    ~SquareMatrix();
     friend std::ostream& operator<< (std::ostream &out, const SquareMatrix& sm );
      friend std::istream& operator>> (std::istream &in,  SquareMatrix& sm );
     friend SquareMatrix operator+(SquareMatrix&m1,SquareMatrix&m2);
     SquareMatrix&  operator=(SquareMatrix&m1);
     friend SquareMatrix operator-(SquareMatrix&m1,SquareMatrix&m2);
     friend double operator*(SquareMatrix,SquareMatrix);
     void reverse (SquareMatrix);
     void compareDeterm (SquareMatrix,SquareMatrix);
     void determinate (SquareMatrix);
     void matrixTrace (SquareMatrix);
     void createTwoMatrix(SquareMatrix& sm);

};
#endif // SQUAREMATRIX_H
