#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    model=new modelwindow();
   connect(model, &modelwindow::window, this, &MainWindow::show);
   setWindowIcon(QIcon(":/resource/resource/icon.png"));
   setWindowTitle("Internet Provider");
   QPixmap pix(":/resource/resource/background.gif");
   this->setMaximumSize(QSize(pix.width(),pix.height()));
   this->setMinimumSize(QSize(pix.width(),pix.height()));
   movie.setFileName(":/resource/resource/background.gif");
   ui->background->setMovie(&movie);
   movie.setSpeed(100);
   movie.setScaledSize(QSize(this->width(),this->height()));
   movie.start();

}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_clicked()
{
   model->show();
   this->close();
}
