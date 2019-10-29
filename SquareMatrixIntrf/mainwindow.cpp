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
    SquareMatrix m1 (ui->dimensionset->value());
    SquareMatrix m2(ui->dimensionset->value());
    for(int i=0;i<ui->dimensionset->value();i++){
         for(int j=0;j<ui->dimensionset->value();j++){
    m1.set_val(ui->matrix1->item(i,j)->text().toDouble(),i , j);
      m2.set_val(ui->matrix2->item(i,j)->text().toDouble(),i,j);
         }
    }

on_plusbutton_clicked(m1,m2);
}

void MainWindow::on_plusbutton_clicked(SquareMatrix&m1,SquareMatrix&m2)
{
    SquareMatrix m3(m1.get_dim());
    m3=m1+m2;
    m3.show(ui->matrix3);

}
