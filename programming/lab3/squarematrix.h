#ifndef SQUAREMATRIX_H
#define SQUAREMATRIX_H


class SquareMatrix
{
    int dimension;
    double **value;
public:
    SquareMatrix();
    SquareMatrix CreateMatrix();
    SquareMatrix plus(SquareMatrix,SquareMatrix);
    SquareMatrix minus(SquareMatrix,SquareMatrix);
    SquareMatrix multi (SquareMatrix,SquareMatrix);
    SquareMatrix reverse (SquareMatrix);
    SquareMatrix compareDeterm (SquareMatrix,SquareMatrix);
    SquareMatrix determinate (SquareMatrix);
    SquareMatrix matrixTrace (SquareMatrix);
};

#endif // SQUAREMATRIX_H
