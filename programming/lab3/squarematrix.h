#ifndef SQUAREMATRIX_H
#define SQUAREMATRIX_H


class SquareMatrix
{
    int dimension;
    double **value;
public:
    SquareMatrix()
    {
    dimension=0;
    createTwoDimMatrix(dimension);
    }
    SquareMatrix CreateMatrix();
    SquareMatrix plus(SquareMatrix,SquareMatrix);
    SquareMatrix minus(SquareMatrix,SquareMatrix);
    SquareMatrix multi (SquareMatrix,SquareMatrix);
    SquareMatrix reverse (SquareMatrix);
    SquareMatrix compareDeterm (SquareMatrix,SquareMatrix);
    SquareMatrix determinate (SquareMatrix);
    SquareMatrix matrixTrace (SquareMatrix);
    int createTwoDimMatrix(int dimension)
    {
        value= new double*[dimension];
        for (int i = 0; i < dimension; i++)
           value[i] = new double[dimension];
    }

};
#endif // SQUAREMATRIX_H
