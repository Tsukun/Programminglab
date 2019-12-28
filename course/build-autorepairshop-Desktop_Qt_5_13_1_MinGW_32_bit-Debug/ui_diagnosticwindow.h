/********************************************************************************
** Form generated from reading UI file 'diagnosticwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.13.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DIAGNOSTICWINDOW_H
#define UI_DIAGNOSTICWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_diagnosticwindow
{
public:
    QLabel *label;
    QLineEdit *fnameEdit;
    QLineEdit *telnumberEdit;
    QLineEdit *carEdit;
    QLabel *label_2;
    QLabel *label_3;
    QLabel *label_4;
    QPushButton *backButton;
    QPushButton *addButton;
    QCheckBox *kuzovButton;
    QCheckBox *paintButton;
    QCheckBox *washButton;
    QCheckBox *balancButton;
    QCheckBox *replaceButton;

    void setupUi(QDialog *diagnosticwindow)
    {
        if (diagnosticwindow->objectName().isEmpty())
            diagnosticwindow->setObjectName(QString::fromUtf8("diagnosticwindow"));
        diagnosticwindow->resize(534, 270);
        label = new QLabel(diagnosticwindow);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(210, 20, 131, 21));
        QFont font;
        font.setPointSize(16);
        label->setFont(font);
        fnameEdit = new QLineEdit(diagnosticwindow);
        fnameEdit->setObjectName(QString::fromUtf8("fnameEdit"));
        fnameEdit->setGeometry(QRect(20, 80, 151, 21));
        telnumberEdit = new QLineEdit(diagnosticwindow);
        telnumberEdit->setObjectName(QString::fromUtf8("telnumberEdit"));
        telnumberEdit->setGeometry(QRect(20, 120, 151, 21));
        carEdit = new QLineEdit(diagnosticwindow);
        carEdit->setObjectName(QString::fromUtf8("carEdit"));
        carEdit->setGeometry(QRect(20, 160, 151, 21));
        label_2 = new QLabel(diagnosticwindow);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(180, 80, 31, 16));
        label_3 = new QLabel(diagnosticwindow);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(180, 120, 51, 16));
        label_4 = new QLabel(diagnosticwindow);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(180, 160, 51, 16));
        backButton = new QPushButton(diagnosticwindow);
        backButton->setObjectName(QString::fromUtf8("backButton"));
        backButton->setGeometry(QRect(10, 240, 80, 22));
        addButton = new QPushButton(diagnosticwindow);
        addButton->setObjectName(QString::fromUtf8("addButton"));
        addButton->setGeometry(QRect(100, 240, 80, 22));
        kuzovButton = new QCheckBox(diagnosticwindow);
        kuzovButton->setObjectName(QString::fromUtf8("kuzovButton"));
        kuzovButton->setGeometry(QRect(340, 70, 111, 20));
        paintButton = new QCheckBox(diagnosticwindow);
        paintButton->setObjectName(QString::fromUtf8("paintButton"));
        paintButton->setGeometry(QRect(340, 100, 72, 20));
        washButton = new QCheckBox(diagnosticwindow);
        washButton->setObjectName(QString::fromUtf8("washButton"));
        washButton->setGeometry(QRect(340, 130, 121, 20));
        balancButton = new QCheckBox(diagnosticwindow);
        balancButton->setObjectName(QString::fromUtf8("balancButton"));
        balancButton->setGeometry(QRect(340, 160, 131, 20));
        replaceButton = new QCheckBox(diagnosticwindow);
        replaceButton->setObjectName(QString::fromUtf8("replaceButton"));
        replaceButton->setGeometry(QRect(340, 190, 91, 20));

        retranslateUi(diagnosticwindow);

        QMetaObject::connectSlotsByName(diagnosticwindow);
    } // setupUi

    void retranslateUi(QDialog *diagnosticwindow)
    {
        diagnosticwindow->setWindowTitle(QCoreApplication::translate("diagnosticwindow", "Dialog", nullptr));
        label->setText(QCoreApplication::translate("diagnosticwindow", "\320\224\320\270\320\260\320\263\320\275\320\276\321\201\321\202\320\270\320\272\320\260 ", nullptr));
        fnameEdit->setText(QCoreApplication::translate("diagnosticwindow", "\320\230\320\262\320\260\320\275\320\276\320\262 \320\230\320\262\320\260\320\275 \320\230\320\262\320\260\320\275\320\276\320\262\320\270\321\207", nullptr));
        telnumberEdit->setText(QCoreApplication::translate("diagnosticwindow", "89998882233", nullptr));
        carEdit->setText(QCoreApplication::translate("diagnosticwindow", "Toyouta", nullptr));
        label_2->setText(QCoreApplication::translate("diagnosticwindow", "\320\244\320\230\320\236", nullptr));
        label_3->setText(QCoreApplication::translate("diagnosticwindow", "\320\242\320\265\320\273\320\265\321\204\320\276\320\275", nullptr));
        label_4->setText(QCoreApplication::translate("diagnosticwindow", "\320\234\320\260\321\210\320\270\320\275\320\260", nullptr));
        backButton->setText(QCoreApplication::translate("diagnosticwindow", "\320\275\320\260\320\267\320\260\320\264", nullptr));
        addButton->setText(QCoreApplication::translate("diagnosticwindow", "\320\264\320\276\320\261\320\260\320\262\320\270\321\202\321\214", nullptr));
        kuzovButton->setText(QCoreApplication::translate("diagnosticwindow", "\320\232\321\203\320\267\320\276\320\262\320\275\321\213\320\265 \321\200\320\260\320\261\320\276\321\202\321\213", nullptr));
        paintButton->setText(QCoreApplication::translate("diagnosticwindow", "\320\237\320\276\320\272\321\200\320\260\321\201\320\272\320\260", nullptr));
        washButton->setText(QCoreApplication::translate("diagnosticwindow", "\320\242\320\265\321\205\320\275\320\270\321\207\320\265\321\201\320\272\320\260\321\217 \320\274\320\276\320\271\320\272\320\260", nullptr));
        balancButton->setText(QCoreApplication::translate("diagnosticwindow", "\320\221\320\260\320\273\320\260\320\275\321\201\320\270\321\200\320\276\320\262\320\272\320\260 \320\272\320\276\320\273\321\221\321\201", nullptr));
        replaceButton->setText(QCoreApplication::translate("diagnosticwindow", "\320\227\320\260\320\274\320\265\320\275\320\260 \321\210\320\270\320\275", nullptr));
    } // retranslateUi

};

namespace Ui {
    class diagnosticwindow: public Ui_diagnosticwindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DIAGNOSTICWINDOW_H
