#ifndef MANAGERWINDOW_H
#define MANAGERWINDOW_H

#include <QDialog>
#include <QFile>
#include <QTextStream>
#include <QDebug>
#include <QFileDialog>
namespace Ui {
class managerwindow;
}

class managerwindow : public QDialog
{
    Q_OBJECT
signals:
  void window();
public:
    explicit managerwindow(QWidget *parent = nullptr);
    ~managerwindow();
    void updateinf(QString path);
private slots:
    void on_backButton_clicked();

    void on_updateButton_clicked();

    void on_pathButton_clicked();

private:
    Ui::managerwindow *ui;
    QString path;
};

#endif // MANAGERWINDOW_H
