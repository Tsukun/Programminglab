#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>
#include "squarematrix.h"
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_setdimbutton_clicked()
{
    ui->matrix1->setRowCount(ui->dimensionset->value());
    ui->matrix1->setColumnCount(ui->dimensionset->value());
    ui->matrix2->setRowCount(ui->dimensionset->value());
    ui->matrix2->setColumnCount(ui->dimensionset->value());

}

void MainWindow::on_setmatrix_clicked()
{
    SquareMatrix m1(ui->dimensionset->value());
    SquareMatrix m2(ui->dimensionset->value());
    for(int i=0;i<ui->dimensionset->value();i++){
         for(int j=0;j<ui->dimensionset->value();j++){
    m1.get_val()[i][j]=ui->matrix1->item(i,j)->text().toDouble();
       m2.get_val()[i][j]=ui->matrix2->item(i,j)->text().toDouble();
         }
    }


}

void MainWindow::on_plusbutton_clicked(SquareMatrix&m1,SquareMatrix&m2)
{

}
