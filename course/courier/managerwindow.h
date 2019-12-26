#ifndef MANAGERWINDOW_H
#define MANAGERWINDOW_H

#include <QDialog>
#include <QFile>
#include <QTextStream>
#include <QDebug>
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
    void updateinf();
private slots:
    void on_backButton_clicked();

private:
    Ui::managerwindow *ui;
};

#endif // MANAGERWINDOW_H
