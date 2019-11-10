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

    void on_minusbutton_clicked();

    void on_multibutton_clicked();

    void on_compbutton_clicked(SquareMatrix&m1,SquareMatrix&m2);

    void on_lessequalbutton_clicked(SquareMatrix&m1,SquareMatrix&m2);

    void on_moreequalbutton_clicked(SquareMatrix&m1,SquareMatrix&m2);

    void on_morebutton_clicked(SquareMatrix&m1,SquareMatrix&m2);

    void on_lessbutton_clicked(SquareMatrix&m1,SquareMatrix&m2);

    void on_nequalbutton_clicked(SquareMatrix&m1,SquareMatrix&m2);

    void on_detbutton_clicked(SquareMatrix&m1);

    void on_tracebutton_clicked(SquareMatrix&m1);

    void on_inversembutton_clicked(SquareMatrix&m1);
private:
    //SquareMatrix m1;
    //SquareMatrix m2;
    //SquareMatrix m3;

   Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
