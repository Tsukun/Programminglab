#ifndef DIAGNOSTICWINDOW_H
#define DIAGNOSTICWINDOW_H
#include "personal.h"
#include "mechanic.h"
#include <QDialog>

namespace Ui {
class diagnosticwindow;
}

class diagnosticwindow : public QDialog
{
    Q_OBJECT
signals:
void window();
public:
    explicit diagnosticwindow(QWidget *parent = nullptr);
    ~diagnosticwindow();

private slots:
void on_backButton_clicked();

void on_addButton_clicked();

private:
    Ui::diagnosticwindow *ui;
    mechanic*pers;
};

#endif // DIAGNOSTICWINDOW_H
