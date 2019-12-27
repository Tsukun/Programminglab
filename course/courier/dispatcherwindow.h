#ifndef DISPATCHERWINDOW_H
#define DISPATCHERWINDOW_H
#include <dispatcher.h>
#include <QDialog>
#include <QFile>
#include <QTextStream>
#include <QDebug>
namespace Ui {
class dispatcherwindow;
}

class dispatcherwindow : public QDialog
{
    Q_OBJECT
signals:
  void window();
public:
    explicit dispatcherwindow(QWidget *parent = nullptr);
    ~dispatcherwindow();

private slots:
void on_backButton_clicked();

void on_checkoutButton_clicked();

private:
    Ui::dispatcherwindow *ui;
    employee* disp;
};

#endif // DISPATCHERWINDOW_H
