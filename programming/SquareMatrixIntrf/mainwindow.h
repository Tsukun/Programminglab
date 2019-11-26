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
    virtual void resizeEvent(QResizeEvent*f);
    void on_tableWidget_cellChanged(int row, int column);

private slots:
    void on_setdimbutton_clicked();

    void setmatrix();

    void on_plusbutton_clicked();

    void on_minusbutton_clicked();

    void on_multibutton_clicked();

    void on_compbutton_clicked();

    void on_lessequalbutton_clicked();

    void on_moreequalbutton_clicked();

    void on_morebutton_clicked();

    void on_lessbutton_clicked();

    void on_nequalbutton_clicked();

    void on_detbutton_clicked();

    void on_tracebutton_clicked();

    void on_inversembutton_clicked();
private:
    SquareMatrix m1;
    SquareMatrix m2;
    SquareMatrix m3;

   Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
