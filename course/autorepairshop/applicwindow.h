#ifndef APPLICWINDOW_H
#define APPLICWINDOW_H

#include <QDialog>
#include <personal.h>
#include <mechanic.h>
#include <QDialog>
#include <QFile>
#include <QTextStream>
#include <QDebug>
#include <QFileDialog>
#include <ctime>
namespace Ui {
class applicwindow;
}

class applicwindow : public QDialog
{
    Q_OBJECT
signals:
void window();
public:
    explicit applicwindow(QWidget *parent = nullptr);
    ~applicwindow();
    void updateInf(QString str);

private slots:
void on_backButton_clicked();

void on_pathButton_clicked();

void on_updateButton_clicked();

private:
    Ui::applicwindow *ui;
    mechanic*mech;
    QString path;
};

#endif // APPLICWINDOW_H
