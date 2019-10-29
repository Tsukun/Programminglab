#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <QMainWindow>
#include <QTextBrowser>
#include "squarematrix.h"
QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
void on_tableWidget_cellChanged(int row, int column);

private slots:
    void on_setdimbutton_clicked();

    void on_setmatrix_clicked();

    void on_plusbutton_clicked(SquareMatrix&m1,SquareMatrix&m2);

private:
   Ui::MainWindow *ui;

};
#endif // MAINWINDOW_H
