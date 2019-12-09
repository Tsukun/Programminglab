#ifndef INDVWINDOW_H
#define INDVWINDOW_H
#include "individual.h"
#include "finalwindow.h"
#include <QDialog>

namespace Ui {
class indvwindow;
}
class indvwindow : public QDialog
{
    Q_OBJECT
signals:
void requestwindow();
public:
    explicit indvwindow(QWidget *parent = nullptr);
    ~indvwindow();

private slots:
void on_backbutton_clicked();

void on_sendbutton_clicked();

private:
    Ui::indvwindow *ui;
    finalwindow *final;
};

#endif // INDVWINDOW_H
