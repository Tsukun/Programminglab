#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    connect(ui->plusbutton, SIGNAL(clicked()), this, SLOT(on_plusbutton_clicked()));
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
    SquareMatrix m1;
    m1.set_dim(ui->dimensionset->value());
        SquareMatrix m2;
        m2.set_dim(ui->dimensionset->value());
        for(int i=0;i<ui->dimensionset->value();i++){
             for(int j=0;j<ui->dimensionset->value();j++){
        m1.set_val(m1,ui->matrix2->item(i,j)->text().toDouble(),i,j);
          m2.set_val(m2,ui->matrix2->item(i,j)->text().toDouble(),i,j);
             }

on_plusbutton_clicked(m1,m2);
}
}
 void MainWindow::on_plusbutton_clicked(SquareMatrix&m1,SquareMatrix&m2)
 {
            SquareMatrix m3;
            m3.set_dim(m1.get_dim());
            m3=m1+m2;
            m3.show(ui->matrix3);

 }

void MainWindow::on_minusbutton_clicked()
{
    /*m3.set_dim(m1.get_dim());
    m3=m1-m2;
    m3.show(ui->matrix3);*/
}


void MainWindow::on_multibutton_clicked()
{
   /* m3.set_dim(m1.get_dim());
    m3=m1*m2;
    m3.show(ui->matrix3);*/
}

void MainWindow::on_compbutton_clicked(SquareMatrix&m1,SquareMatrix&m2)
{
    if(m1==m2)
        ui->matrix3->setText("true");
    else
        ui->matrix3->setText("false");

}

void MainWindow::on_lessequalbutton_clicked(SquareMatrix&m1,SquareMatrix&m2)
{
    if(m1<=m2)
        ui->matrix3->setText("true");
    else
        ui->matrix3->setText("false");

}

void MainWindow::on_moreequalbutton_clicked(SquareMatrix&m1,SquareMatrix&m2)
{
    if(m1<=m2)
        ui->matrix3->setText("true");
    else
        ui->matrix3->setText("false");

}

void MainWindow::on_morebutton_clicked(SquareMatrix&m1,SquareMatrix&m2)
{
    if(m1>m2)
        ui->matrix3->setText("true");
    else
        ui->matrix3->setText("false");

}

void MainWindow::on_lessbutton_clicked(SquareMatrix&m1,SquareMatrix&m2)
{
    if(m1<m2)
        ui->matrix3->setText("true");
    else
        ui->matrix3->setText("false");

}

void MainWindow::on_nequalbutton_clicked(SquareMatrix&m1,SquareMatrix&m2)
{
    if(m1!=m2)
        ui->matrix3->setText("true");
    else
        ui->matrix3->setText("false");

}

void MainWindow::on_detbutton_clicked(SquareMatrix&m1)
{
}

void MainWindow::on_tracebutton_clicked(SquareMatrix&m1)
{

}

void MainWindow::on_inversembutton_clicked(SquareMatrix&m1)
{

}
