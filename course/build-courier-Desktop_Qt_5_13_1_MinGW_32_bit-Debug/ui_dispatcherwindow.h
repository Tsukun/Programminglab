/********************************************************************************
** Form generated from reading UI file 'dispatcherwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.13.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DISPATCHERWINDOW_H
#define UI_DISPATCHERWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_dispatcherwindow
{
public:
    QLineEdit *fnameEdit;
    QLabel *label;
    QLabel *label_2;
    QLineEdit *addressEdit;
    QLineEdit *categoryEdit;
    QLabel *label_3;
    QLineEdit *weightEdit;
    QLabel *label_4;
    QLineEdit *srokEdit;
    QLabel *label_5;
    QLineEdit *dutyEdit;
    QLabel *label_6;
    QLabel *label_7;
    QPushButton *checkoutButton;
    QPushButton *backButton;

    void setupUi(QDialog *dispatcherwindow)
    {
        if (dispatcherwindow->objectName().isEmpty())
            dispatcherwindow->setObjectName(QString::fromUtf8("dispatcherwindow"));
        dispatcherwindow->resize(437, 262);
        fnameEdit = new QLineEdit(dispatcherwindow);
        fnameEdit->setObjectName(QString::fromUtf8("fnameEdit"));
        fnameEdit->setGeometry(QRect(20, 50, 151, 21));
        label = new QLabel(dispatcherwindow);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(180, 50, 31, 16));
        label_2 = new QLabel(dispatcherwindow);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(240, 80, 31, 16));
        addressEdit = new QLineEdit(dispatcherwindow);
        addressEdit->setObjectName(QString::fromUtf8("addressEdit"));
        addressEdit->setGeometry(QRect(20, 80, 211, 21));
        categoryEdit = new QLineEdit(dispatcherwindow);
        categoryEdit->setObjectName(QString::fromUtf8("categoryEdit"));
        categoryEdit->setGeometry(QRect(20, 110, 151, 21));
        label_3 = new QLabel(dispatcherwindow);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(180, 110, 91, 16));
        weightEdit = new QLineEdit(dispatcherwindow);
        weightEdit->setObjectName(QString::fromUtf8("weightEdit"));
        weightEdit->setGeometry(QRect(180, 140, 81, 21));
        label_4 = new QLabel(dispatcherwindow);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(270, 140, 31, 16));
        srokEdit = new QLineEdit(dispatcherwindow);
        srokEdit->setObjectName(QString::fromUtf8("srokEdit"));
        srokEdit->setGeometry(QRect(20, 140, 61, 21));
        label_5 = new QLabel(dispatcherwindow);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setGeometry(QRect(90, 140, 81, 16));
        dutyEdit = new QLineEdit(dispatcherwindow);
        dutyEdit->setObjectName(QString::fromUtf8("dutyEdit"));
        dutyEdit->setGeometry(QRect(20, 170, 61, 21));
        label_6 = new QLabel(dispatcherwindow);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        label_6->setGeometry(QRect(90, 170, 111, 16));
        label_7 = new QLabel(dispatcherwindow);
        label_7->setObjectName(QString::fromUtf8("label_7"));
        label_7->setGeometry(QRect(130, 10, 181, 21));
        QFont font;
        font.setPointSize(14);
        label_7->setFont(font);
        checkoutButton = new QPushButton(dispatcherwindow);
        checkoutButton->setObjectName(QString::fromUtf8("checkoutButton"));
        checkoutButton->setGeometry(QRect(10, 230, 80, 22));
        backButton = new QPushButton(dispatcherwindow);
        backButton->setObjectName(QString::fromUtf8("backButton"));
        backButton->setGeometry(QRect(100, 230, 80, 22));

        retranslateUi(dispatcherwindow);

        QMetaObject::connectSlotsByName(dispatcherwindow);
    } // setupUi

    void retranslateUi(QDialog *dispatcherwindow)
    {
        dispatcherwindow->setWindowTitle(QCoreApplication::translate("dispatcherwindow", "Dialog", nullptr));
        fnameEdit->setText(QCoreApplication::translate("dispatcherwindow", "\320\230\320\262\320\260\320\275\320\276\320\262 \320\230\320\262\320\260\320\275 \320\230\320\262\320\260\320\275\320\276\320\262\320\270\321\207", nullptr));
        label->setText(QCoreApplication::translate("dispatcherwindow", "\320\244\320\230\320\236", nullptr));
        label_2->setText(QCoreApplication::translate("dispatcherwindow", "\320\220\320\264\321\200\320\265\321\201", nullptr));
        addressEdit->setText(QCoreApplication::translate("dispatcherwindow", "\320\263. \320\235\320\276\320\262\320\276\321\201\320\270\320\261\320\270\321\200\321\201\320\272 \321\203\320\273\320\270\321\206\320\260 \320\235\320\276\320\262\320\276\321\201\320\270\320\261\320\270\321\200\321\201\320\272\320\260\321\217", nullptr));
        categoryEdit->setText(QCoreApplication::translate("dispatcherwindow", "\320\245\321\200\321\203\320\277\320\272\320\276\320\265", nullptr));
        label_3->setText(QCoreApplication::translate("dispatcherwindow", "\320\222\320\270\320\264 \320\270 \320\272\320\260\321\202\320\265\320\263\320\276\321\200\320\270\321\217", nullptr));
        weightEdit->setText(QCoreApplication::translate("dispatcherwindow", "200 \320\263", nullptr));
        label_4->setText(QCoreApplication::translate("dispatcherwindow", "\320\234\320\260\321\201\321\201\320\260", nullptr));
        srokEdit->setText(QCoreApplication::translate("dispatcherwindow", "-", nullptr));
        label_5->setText(QCoreApplication::translate("dispatcherwindow", "\320\241\321\200\320\276\320\272 \321\205\321\200\320\260\320\275\320\265\320\275\320\270\321\217", nullptr));
        dutyEdit->setText(QCoreApplication::translate("dispatcherwindow", "100", nullptr));
        label_6->setText(QCoreApplication::translate("dispatcherwindow", "\320\242\320\260\320\274\320\276\320\266\320\265\320\275\320\275\320\260\321\217 \320\277\320\276\321\210\320\273\320\270\320\275\320\260", nullptr));
        label_7->setText(QCoreApplication::translate("dispatcherwindow", "\320\236\321\204\320\276\321\200\320\274\320\273\320\265\320\275\320\270\320\265 \320\267\320\260\320\272\320\260\320\267\320\260", nullptr));
        checkoutButton->setText(QCoreApplication::translate("dispatcherwindow", "\320\276\321\204\320\276\321\200\320\274\320\270\321\202\321\214", nullptr));
        backButton->setText(QCoreApplication::translate("dispatcherwindow", "\320\275\320\260\320\267\320\260\320\264", nullptr));
    } // retranslateUi

};

namespace Ui {
    class dispatcherwindow: public Ui_dispatcherwindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DISPATCHERWINDOW_H
