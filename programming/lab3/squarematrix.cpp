#include "squarematrix.h"
#include <iostream>
using namespace std;
SquareMatrix::SquareMatrix(int n)
{
    dimension=n;
    value=nullptr;

}

SquareMatrix::~SquareMatrix()
{
    for (int i = 0; i < dimension; i++)
         delete []value[i];
}

 void SquareMatrix::createTwoDimMatrix(SquareMatrix& sm)
{
  sm.value= new double*[sm.dimension];
    for (int i = 0; i < sm.dimension; i++)
         sm.value[i] = new double[sm.dimension];

      for (int i = 0; i < sm.dimension; i++)
            for (int j = 0; j < sm.dimension; j++){
                 cout<<"Vvedite "<<i+1<<" stolbec "<<j+1<<" stroku = ";
                cin>> sm.value[i][j];
            }

}

void SquareMatrix::printMatrix(SquareMatrix& sm)
{
    cout<<"\n";
    for (int i = 0; i < sm.dimension; i++){
          for (int j = 0; j < sm.dimension; j++)
              cout<<sm.value[i][j]<<" ";

          cout<<"\n";
    }


}



void SquareMatrix::CreateMatrix(SquareMatrix& sm)
{
 createTwoDimMatrix(sm);

}
