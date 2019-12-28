/********************************************************************************
** Form generated from reading UI file 'courierwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.13.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_COURIERWINDOW_H
#define UI_COURIERWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTableWidget>

QT_BEGIN_NAMESPACE

class Ui_courierwindow
{
public:
    QTableWidget *inftable;
    QPushButton *backButton;
    QPushButton *updateButton;
    QPushButton *pathButton;
    QPushButton *confButton;
    QLabel *label;

    void setupUi(QDialog *courierwindow)
    {
        if (courierwindow->objectName().isEmpty())
            courierwindow->setObjectName(QString::fromUtf8("courierwindow"));
        courierwindow->resize(957, 460);
        inftable = new QTableWidget(courierwindow);
        inftable->setObjectName(QString::fromUtf8("inftable"));
        inftable->setGeometry(QRect(10, 50, 921, 361));
        inftable->horizontalHeader()->setDefaultSectionSize(182);
        backButton = new QPushButton(courierwindow);
        backButton->setObjectName(QString::fromUtf8("backButton"));
        backButton->setGeometry(QRect(10, 420, 131, 31));
        updateButton = new QPushButton(courierwindow);
        updateButton->setObjectName(QString::fromUtf8("updateButton"));
        updateButton->setGeometry(QRect(150, 420, 131, 31));
        pathButton = new QPushButton(courierwindow);
        pathButton->setObjectName(QString::fromUtf8("pathButton"));
        pathButton->setGeometry(QRect(290, 420, 131, 31));
        confButton = new QPushButton(courierwindow);
        confButton->setObjectName(QString::fromUtf8("confButton"));
        confButton->setGeometry(QRect(430, 420, 131, 31));
        label = new QLabel(courierwindow);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(350, 10, 231, 31));
        QFont font;
        font.setPointSize(14);
        label->setFont(font);

        retranslateUi(courierwindow);

        QMetaObject::connectSlotsByName(courierwindow);
    } // setupUi

    void retranslateUi(QDialog *courierwindow)
    {
        courierwindow->setWindowTitle(QCoreApplication::translate("courierwindow", "Dialog", nullptr));
        backButton->setText(QCoreApplication::translate("courierwindow", "\320\275\320\260\320\267\320\260\320\264", nullptr));
        updateButton->setText(QCoreApplication::translate("courierwindow", "\320\276\320\261\320\275\320\276\320\262\320\270\321\202\321\214", nullptr));
        pathButton->setText(QCoreApplication::translate("courierwindow", "\320\262\321\213\320\261\321\200\320\260\321\202\321\214 \321\204\320\260\320\271\320\273", nullptr));
        confButton->setText(QCoreApplication::translate("courierwindow", "\320\277\320\276\320\264\321\202\320\262\320\265\321\200\320\264\320\270\321\202\321\214", nullptr));
        label->setText(QCoreApplication::translate("courierwindow", "\320\237\320\276\320\264\321\202\320\262\320\265\321\200\320\266\320\264\320\265\320\275\320\270\320\265 \320\264\320\276\321\201\321\202\320\260\320\262\320\272\320\270", nullptr));
    } // retranslateUi

};

namespace Ui {
    class courierwindow: public Ui_courierwindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_COURIERWINDOW_H
