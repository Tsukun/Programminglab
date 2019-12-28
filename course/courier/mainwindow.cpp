#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    dispwindow=new dispatcherwindow();
    courwindow=new courierwindow();
    manwindow=new managerwindow();
     connect(dispwindow, &dispatcherwindow::window, this, &MainWindow::show);
     connect(courwindow, &courierwindow::window, this, &MainWindow::show);
     connect(manwindow, &managerwindow::window, this, &MainWindow::show);
    setWindowTitle("Служба доставки");
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_dispButton_clicked()
{
    dispwindow->show();
    this->close();

}

void MainWindow::on_manButton_clicked()
{
    manwindow->show();
    this->close();
}

void MainWindow::on_courButton_clicked()
{
    courwindow->show();
    this->close();
}
