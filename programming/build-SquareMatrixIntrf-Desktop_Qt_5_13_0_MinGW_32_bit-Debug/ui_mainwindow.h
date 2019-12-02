/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.13.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QTableWidget *matrix1;
    QTableWidget *matrix2;
    QPushButton *plusbutton;
    QPushButton *minusbutton;
    QPushButton *multibutton;
    QPushButton *compbutton;
    QPushButton *lessequalbutton;
    QPushButton *moreequalbutton;
    QPushButton *morebutton;
    QPushButton *lessbutton;
    QPushButton *nequalbutton;
    QSpinBox *dimensionset;
    QPushButton *setdimbutton;
    QPushButton *detbutton;
    QPushButton *tracebutton;
    QPushButton *inversembutton;
    QTextBrowser *matrix3;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(800, 600);
        MainWindow->setMinimumSize(QSize(600, 500));
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        matrix1 = new QTableWidget(centralwidget);
        matrix1->setObjectName(QString::fromUtf8("matrix1"));
        matrix1->setGeometry(QRect(50, 80, 251, 191));
        matrix1->horizontalHeader()->setVisible(false);
        matrix1->horizontalHeader()->setDefaultSectionSize(40);
        matrix1->verticalHeader()->setVisible(false);
        matrix1->verticalHeader()->setDefaultSectionSize(23);
        matrix2 = new QTableWidget(centralwidget);
        matrix2->setObjectName(QString::fromUtf8("matrix2"));
        matrix2->setGeometry(QRect(400, 80, 251, 191));
        matrix2->horizontalHeader()->setVisible(false);
        matrix2->horizontalHeader()->setDefaultSectionSize(40);
        matrix2->verticalHeader()->setVisible(false);
        matrix2->verticalHeader()->setDefaultSectionSize(23);
        plusbutton = new QPushButton(centralwidget);
        plusbutton->setObjectName(QString::fromUtf8("plusbutton"));
        plusbutton->setGeometry(QRect(330, 80, 41, 23));
        minusbutton = new QPushButton(centralwidget);
        minusbutton->setObjectName(QString::fromUtf8("minusbutton"));
        minusbutton->setGeometry(QRect(330, 100, 41, 23));
        multibutton = new QPushButton(centralwidget);
        multibutton->setObjectName(QString::fromUtf8("multibutton"));
        multibutton->setGeometry(QRect(330, 120, 41, 23));
        compbutton = new QPushButton(centralwidget);
        compbutton->setObjectName(QString::fromUtf8("compbutton"));
        compbutton->setGeometry(QRect(330, 140, 41, 23));
        lessequalbutton = new QPushButton(centralwidget);
        lessequalbutton->setObjectName(QString::fromUtf8("lessequalbutton"));
        lessequalbutton->setGeometry(QRect(330, 160, 41, 23));
        moreequalbutton = new QPushButton(centralwidget);
        moreequalbutton->setObjectName(QString::fromUtf8("moreequalbutton"));
        moreequalbutton->setGeometry(QRect(330, 180, 41, 23));
        morebutton = new QPushButton(centralwidget);
        morebutton->setObjectName(QString::fromUtf8("morebutton"));
        morebutton->setGeometry(QRect(330, 200, 41, 23));
        lessbutton = new QPushButton(centralwidget);
        lessbutton->setObjectName(QString::fromUtf8("lessbutton"));
        lessbutton->setGeometry(QRect(330, 220, 41, 23));
        nequalbutton = new QPushButton(centralwidget);
        nequalbutton->setObjectName(QString::fromUtf8("nequalbutton"));
        nequalbutton->setGeometry(QRect(330, 240, 41, 23));
        dimensionset = new QSpinBox(centralwidget);
        dimensionset->setObjectName(QString::fromUtf8("dimensionset"));
        dimensionset->setGeometry(QRect(50, 280, 42, 22));
        setdimbutton = new QPushButton(centralwidget);
        setdimbutton->setObjectName(QString::fromUtf8("setdimbutton"));
        setdimbutton->setGeometry(QRect(100, 280, 41, 23));
        detbutton = new QPushButton(centralwidget);
        detbutton->setObjectName(QString::fromUtf8("detbutton"));
        detbutton->setGeometry(QRect(200, 280, 81, 23));
        tracebutton = new QPushButton(centralwidget);
        tracebutton->setObjectName(QString::fromUtf8("tracebutton"));
        tracebutton->setGeometry(QRect(280, 280, 91, 23));
        inversembutton = new QPushButton(centralwidget);
        inversembutton->setObjectName(QString::fromUtf8("inversembutton"));
        inversembutton->setGeometry(QRect(370, 280, 81, 23));
        matrix3 = new QTextBrowser(centralwidget);
        matrix3->setObjectName(QString::fromUtf8("matrix3"));
        matrix3->setGeometry(QRect(240, 330, 251, 191));
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 800, 21));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        plusbutton->setText(QCoreApplication::translate("MainWindow", "+", nullptr));
        minusbutton->setText(QCoreApplication::translate("MainWindow", "-", nullptr));
        multibutton->setText(QCoreApplication::translate("MainWindow", "*", nullptr));
        compbutton->setText(QCoreApplication::translate("MainWindow", "==", nullptr));
        lessequalbutton->setText(QCoreApplication::translate("MainWindow", "<=", nullptr));
        moreequalbutton->setText(QCoreApplication::translate("MainWindow", ">=", nullptr));
        morebutton->setText(QCoreApplication::translate("MainWindow", ">", nullptr));
        lessbutton->setText(QCoreApplication::translate("MainWindow", "<", nullptr));
        nequalbutton->setText(QCoreApplication::translate("MainWindow", "!=", nullptr));
        setdimbutton->setText(QCoreApplication::translate("MainWindow", "set", nullptr));
        detbutton->setText(QCoreApplication::translate("MainWindow", "determinant", nullptr));
        tracebutton->setText(QCoreApplication::translate("MainWindow", "Trace of matrix", nullptr));
        inversembutton->setText(QCoreApplication::translate("MainWindow", "matrix^-1", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
