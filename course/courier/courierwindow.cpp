#include "courierwindow.h"
#include "ui_courierwindow.h"

courierwindow::courierwindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::courierwindow)
{
    ui->setupUi(this);
}

courierwindow::~courierwindow()
{
    delete ui;
}
