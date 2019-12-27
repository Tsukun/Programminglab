#ifndef COURIERWINDOW_H
#define COURIERWINDOW_H

#include <QDialog>
#include <QFile>
#include <QTextStream>
#include <QDebug>
#include <QFileDialog>
namespace Ui {
class courierwindow;
}

class courierwindow : public QDialog
{
    Q_OBJECT
signals:
  void window();
public:
    explicit courierwindow(QWidget *parent = nullptr);
    ~courierwindow();
    void updateinf(QString path);

private slots:
    void on_backButton_clicked();

    void on_updateButton_clicked();

    void on_pathButton_clicked();

    void on_confButton_clicked();

private:
    Ui::courierwindow *ui;
    QString path;
};

#endif // COURIERWINDOW_H
