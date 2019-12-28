#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include "diagnosticwindow.h"
#include "applicwindow.h"
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

private slots:
    void on_diagnostikButton_clicked();

    void on_viewButton_clicked();

private:
    Ui::MainWindow *ui;
    diagnosticwindow* diagnost;
    applicwindow*applic;
};
#endif // MAINWINDOW_H
