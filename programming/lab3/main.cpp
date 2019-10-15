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
    SquareMatrix test2(3);
    SquareMatrix test3(3);
    cin>>test;
    cin>>test2;
    //test3=test+test2;
    cout<<test-test2;
    return a.exec();
}
