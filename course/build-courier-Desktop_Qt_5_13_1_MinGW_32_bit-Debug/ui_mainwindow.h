/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.13.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QPushButton *dispButton;
    QPushButton *manButton;
    QPushButton *courButton;
    QLabel *label;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(531, 337);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        dispButton = new QPushButton(centralwidget);
        dispButton->setObjectName(QString::fromUtf8("dispButton"));
        dispButton->setGeometry(QRect(120, 110, 291, 41));
        manButton = new QPushButton(centralwidget);
        manButton->setObjectName(QString::fromUtf8("manButton"));
        manButton->setGeometry(QRect(120, 160, 291, 41));
        courButton = new QPushButton(centralwidget);
        courButton->setObjectName(QString::fromUtf8("courButton"));
        courButton->setGeometry(QRect(120, 210, 291, 41));
        label = new QLabel(centralwidget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(190, 10, 151, 41));
        QFont font;
        font.setPointSize(14);
        label->setFont(font);
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 531, 21));
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
        dispButton->setText(QCoreApplication::translate("MainWindow", "\320\264\320\270\321\201\320\277\320\265\321\202\321\207\320\265\321\200", nullptr));
        manButton->setText(QCoreApplication::translate("MainWindow", "\320\277\321\200\320\276\321\201\320\274\320\276\321\202\321\200 \320\267\320\260\321\217\320\262\320\276\320\272", nullptr));
        courButton->setText(QCoreApplication::translate("MainWindow", "\320\272\321\203\321\200\321\214\320\265\321\200", nullptr));
        label->setText(QCoreApplication::translate("MainWindow", "\320\241\320\273\321\203\320\266\320\261\320\260 \320\264\320\276\321\201\321\202\320\260\320\262\320\272\320\270", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
