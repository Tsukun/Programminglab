#include <QCoreApplication>
#include "squarematrix.h"
#include "string.h"
#include <iostream>
using namespace std;

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    setlocale(LC_ALL,"Russian");
    SquareMatrix m1(3);
    SquareMatrix m2(3);
    SquareMatrix m3(3);
    cin>>m1>>m2;
    m3=m1+m2;
    cout<<m3;
    return a.exec();
}
