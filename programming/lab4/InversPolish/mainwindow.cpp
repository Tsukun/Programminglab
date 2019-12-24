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
    list=ui->polishin->text().split(" ");
    stack<double> st(list.size());
    for(int i=0;i<list.size();i++)
    {
        for(int j=0;j<list.at(i).size();j++)
        {
        if(list.at(i)[j]>=48 && list.at(i)[j]<=57)
        {
           st.push(list.at(i).toInt());
           break;
        }
        else
        {
           char op=list.at(i).toStdString()[0];
            switch(op)
            {
            case '*':
                double a,b,c;
                b=st.pop();
                a=st.pop();
                s+=QString::number(a)+"*"+QString::number(b);
                c=a*b;
                s+="="+QString::number(c)+'\n';
                st.push(c);
                break;
            case '+':
                b=st.pop();
                a=st.pop();
                s+=QString::number(a)+"+"+QString::number(b);
                c=a+b;
                s+="="+QString::number(c)+'\n';
                st.push(c);
                break;
            case '-':
                b=st.pop();
                a=st.pop();
                s+=QString::number(a)+"-"+QString::number(b);
                c=a-b;
                s+="="+QString::number(c)+'\n';
                st.push(c);
                break;
            case '/':
                b=st.pop();
                a=st.pop();
                s+=QString::number(a)+"/"+QString::number(b);
                c=a/b;
                s+="="+QString::number(c)+'\n';
                st.push(c);
                break;
            case '^':
                b=st.pop();
                a=st.pop();
                s+=QString::number(a)+"^"+QString::number(b);
                c=pow(a,b);
                s+="="+QString::number(c)+'\n';
                st.push(c);
                break;
            default:
                s="Incorrect input";
                break;

            }
        }
    }

}
 ui->polishout->setText(s);
}
