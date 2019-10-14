#ifndef SQUAREMATRIX_H
#define SQUAREMATRIX_H


class SquareMatrix
{
    int dimension;
    double **value;
public:
    SquareMatrix(int n);
    ~SquareMatrix();
    void CreateMatrix(SquareMatrix& sm);
    void printMatrix(SquareMatrix& sm);
     void plus(SquareMatrix,SquareMatrix);
    void minus(SquareMatrix,SquareMatrix);
     void multi (SquareMatrix,SquareMatrix);
     void reverse (SquareMatrix);
     void compareDeterm (SquareMatrix,SquareMatrix);
     void determinate (SquareMatrix);
     void matrixTrace (SquareMatrix);
     void createTwoDimMatrix(SquareMatrix& sm);

};
#endif // SQUAREMATRIX_H
