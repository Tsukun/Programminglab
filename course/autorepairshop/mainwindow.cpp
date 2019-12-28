#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    diagnost=new diagnosticwindow();
    applic=new applicwindow();
    connect(diagnost, &diagnosticwindow::window, this, &MainWindow::show);
     connect(applic, &applicwindow::window, this, &MainWindow::show);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_diagnostikButton_clicked()
{
    diagnost->show();
    this->close();
}

void MainWindow::on_viewButton_clicked()
{
    applic->show();
    this->close();
}
