#include <QCoreApplication>
#include "squarematrix.h"
#include "string.h"
#include <iostream>
using namespace std;

int main(int argc, char *argv[])
{
    int d;
    QCoreApplication a(argc, argv);
    setlocale(LC_ALL,"Russian");
    SquareMatrix test(3);
    cin>>test;
 // cout<<test.determinant(test,test.dimension);
    test.transp(test);
    return a.exec();
}
