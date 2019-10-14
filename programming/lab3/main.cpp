#include <QCoreApplication>
#include "squarematrix.h"
#include "string.h"
#include <iostream>
using namespace std;

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    setlocale(LC_ALL,"Russian");
    SquareMatrix test(3);
    test.CreateMatrix(test);
    test.printMatrix(test);
    return a.exec();
}
