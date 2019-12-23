#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_clicked()
{
    QString s="";
    QStringList list;
     int k;
    list=ui->polishin->text().split(" ");
    stack<int> st(list.size());
    for(int i=0;i<list.size();i++)
    {
        for(int j=0;j<list.at(i).size();j++)
        {
        if(list.at(i)[j]>=48 && list.at(i)[j]<=57)
        {
           st.push(list.at(i).toInt());
           //k=list.at(i).toInt();
           break;
        }
        else
        {
           char op=list.at(i).toStdString()[0];
            switch(op)
            {
            case '*':
                int a,b,c;
                a=st.pop();
                b=st.pop();
                c=a*b;
                st.push(c);
                break;
            }
        }
    }
    for(int i=st.getTop();i!=0;i--)
       k=st.pop();
    //ui->polishout->setText( QString::fromStdString(s));
}
}
