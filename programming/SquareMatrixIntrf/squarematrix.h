#ifndef SQUAREMATRIX_H
#define SQUAREMATRIX_H
#include <iostream>
#include "ui_mainwindow.h"
#include <QMainWindow>
#include <QTextBrowser>
class SquareMatrix
{

public:

   SquareMatrix(double**value=nullptr,int dimension=0);
   SquareMatrix(SquareMatrix& a);
   ~SquareMatrix();
     void show(QTextBrowser*& textBrowser);
     void set_val (double val,int i,int j);
     void set_dim (int dim);
     int get_dim();
     double **get_val();
     friend SquareMatrix operator+(SquareMatrix&m1,SquareMatrix&m2);
     SquareMatrix&  operator=(const SquareMatrix&m1);
     friend SquareMatrix operator-(SquareMatrix&m1,SquareMatrix&m2);
     friend SquareMatrix operator*(SquareMatrix&m1,SquareMatrix&m2);
     friend bool operator==(SquareMatrix&m1,SquareMatrix&m2);
     friend bool operator>(SquareMatrix&m1,SquareMatrix&m2);
     friend bool operator<(SquareMatrix&m1,SquareMatrix&m2);
     friend bool operator<=(SquareMatrix&m1,SquareMatrix&m2);
     friend bool operator>=(SquareMatrix&m1,SquareMatrix&m2);
     friend bool operator!=(SquareMatrix&m1,SquareMatrix&m2);
     SquareMatrix inverseMatrix (SquareMatrix&m1,double det);
     double determinant(SquareMatrix&m1,int m);
     double matrixTrace (SquareMatrix &sm);
     void GetMatr(SquareMatrix&m1, SquareMatrix&m2, int i, int j);
     void transp(SquareMatrix&m1);
private:
     double **value;
     int dimension;



};
#endif // SQUAREMATRIX_H
