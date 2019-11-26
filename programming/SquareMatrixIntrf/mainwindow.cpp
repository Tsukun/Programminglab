#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>
MainWindow::MainWindow(QWidget *parent):QMainWindow(parent),ui(new Ui::MainWindow)
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
void MainWindow::resizeEvent(QResizeEvent * f)
{
double widht1=this->width();
double height1=this->height();
ui->matrix1->setGeometry(QRect(widht1/14,height1/7.5,widht1/3.5,height1/3.5));
ui->matrix2->setGeometry(QRect(ui->matrix1->width()*2,ui->matrix1->height()/2.05,widht1/3.5,height1/3.5));
ui->matrix3->setGeometry(QRect(ui->matrix1->width()*1.15,ui->matrix1->height()*2,widht1/3.5,height1/3.5));
ui->plusbutton->setGeometry(QRect(ui->matrix1->width()*1.55,height1/7.5,41,23));
ui->minusbutton->setGeometry(QRect(ui->matrix1->width()*1.55,ui->plusbutton->y()+ui->plusbutton->width()/2,41,23));
ui->multibutton->setGeometry(QRect(ui->matrix1->width()*1.55,ui->minusbutton->y()+ui->minusbutton->width()/2,41,23));
ui->compbutton->setGeometry(QRect(ui->matrix1->width()*1.55,ui->multibutton->y()+ui->multibutton->width()/2,41,23));
ui->lessbutton->setGeometry(QRect(ui->matrix1->width()*1.55,ui->compbutton->y()+ui->compbutton->width()/2,41,23));
ui->morebutton->setGeometry(QRect(ui->matrix1->width()*1.55,ui->lessbutton->y()+ui->lessbutton->width()/2,41,23));
ui->lessequalbutton->setGeometry(QRect(ui->matrix1->width()*1.55,ui->morebutton->y()+ui->morebutton->width()/2,41,23));
ui->moreequalbutton->setGeometry(QRect(ui->matrix1->width()*1.55,ui->lessequalbutton->y()+ui->lessequalbutton->width()/2,41,23));
ui->nequalbutton->setGeometry(QRect(ui->matrix1->width()*1.55,ui->moreequalbutton->y()+ui->moreequalbutton->width()/2,41,23));
ui->dimensionset->setGeometry(QRect(ui->matrix1->x(),ui->matrix1->y()+ui->matrix1->height(),41,23));
ui->setdimbutton->setGeometry(QRect(ui->matrix1->x()+ui->dimensionset->width(),ui->matrix1->y()+ui->matrix1->height(),41,23));
ui->detbutton->setGeometry(QRect(ui->setdimbutton->x()+ui->setdimbutton->width(),ui->matrix1->y()+ui->matrix1->height(),81,23));
ui->tracebutton->setGeometry(QRect(ui->matrix1->x(),ui->matrix1->y()+ui->matrix1->height()+23,81,23));
ui->inversembutton->setGeometry(QRect(ui->tracebutton->x()+ui->tracebutton->width(),ui->matrix1->y()+ui->matrix1->height()+23,81,23));
}
void MainWindow::setmatrix()
{

    m1.set_dim(ui->dimensionset->value());
    m2.set_dim(ui->dimensionset->value());
        for(int i=0;i<ui->dimensionset->value();i++)
       {
        for(int j=0;j<ui->dimensionset->value();j++)
        {
        m1.set_val(ui->matrix1->item(i,j)->text().toDouble(),i,j);
        m2.set_val(ui->matrix2->item(i,j)->text().toDouble(),i,j);
        }
       }
}
 void MainWindow::on_plusbutton_clicked()
 {
            setmatrix();
            m3.set_dim(m1.get_dim());
            m3=m1+m2;
            m3.show(ui->matrix3);
            m3.~SquareMatrix();

 }

void MainWindow::on_minusbutton_clicked()
{
    setmatrix();
    m3.set_dim(m1.get_dim());
    m3=m1-m2;
    m3.show(ui->matrix3);
    m3.~SquareMatrix();
}


void MainWindow::on_multibutton_clicked()
{
    setmatrix();
    m3.set_dim(m1.get_dim());
    m3=m1*m2;
    m3.show(ui->matrix3);
    m3.~SquareMatrix();
}

void MainWindow::on_compbutton_clicked()
{
    setmatrix();
    if(m1==m2)
        ui->matrix3->setText("true");
    else
        ui->matrix3->setText("false");

}

void MainWindow::on_lessequalbutton_clicked()
{
    setmatrix();
    if(m1<=m2)
        ui->matrix3->setText("true");
    else
        ui->matrix3->setText("false");

}

void MainWindow::on_moreequalbutton_clicked()
{
    setmatrix();
    if(m1<=m2)
        ui->matrix3->setText("true");
    else
        ui->matrix3->setText("false");

}

void MainWindow::on_morebutton_clicked()
{
    setmatrix();
    if(m1>m2)
        ui->matrix3->setText("true");
    else
        ui->matrix3->setText("false");

}

void MainWindow::on_lessbutton_clicked()
{
    setmatrix();
    if(m1<m2)
        ui->matrix3->setText("true");
    else
        ui->matrix3->setText("false");

}

void MainWindow::on_nequalbutton_clicked()
{
    setmatrix();
    if(m1!=m2)
        ui->matrix3->setText("true");
    else
        ui->matrix3->setText("false");

}

void MainWindow::on_detbutton_clicked()
{
    m1.set_dim(ui->dimensionset->value());
    for(int i=0;i<ui->dimensionset->value();i++)
    for(int j=0;j<ui->dimensionset->value();j++)
    m1.set_val(ui->matrix1->item(i,j)->text().toDouble(),i,j);
    ui->matrix3->setText(QString::number(m1.determinant(m1,m1.get_dim())));
}

void MainWindow::on_tracebutton_clicked()
{
    m1.set_dim(ui->dimensionset->value());
    for(int i=0;i<ui->dimensionset->value();i++)
    for(int j=0;j<ui->dimensionset->value();j++)
    m1.set_val(ui->matrix1->item(i,j)->text().toDouble(),i,j);
    ui->matrix3->setText(QString::number(m1.matrixTrace(m1)));
}

void MainWindow::on_inversembutton_clicked()
{   m1.set_dim(ui->dimensionset->value());
    for(int i=0;i<ui->dimensionset->value();i++)
    for(int j=0;j<ui->dimensionset->value();j++)
    m1.set_val(ui->matrix1->item(i,j)->text().toDouble(),i,j);
    m3.set_dim(m1.get_dim());
    m3=m1.inverseMatrix(m1,m1.determinant(m1,m1.get_dim()));
    m3.show(ui->matrix3);
    m3.~SquareMatrix();
}
