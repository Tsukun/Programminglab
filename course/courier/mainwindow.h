#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include "dispatcherwindow.h"
#include "courierwindow.h"
#include "managerwindow.h"
#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    dispatcherwindow* dispwindow;
    courierwindow* courwindow;
    managerwindow* manwindow;

private slots:
    void on_dispButton_clicked();

    void on_manButton_clicked();

    void on_courButton_clicked();

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
