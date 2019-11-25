#include "mainwindow.h"
#include "ui_mainwindow.h"

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


void MainWindow::on_pushButton_clicked()
{
    string s;
    s=ui->polishin->text().toStdString();
    for(int i=0;i < s.size();i++)
    {
        //if(s[i]>=)
    }
    ui->polishout->setText( QString::fromStdString(s));
}
