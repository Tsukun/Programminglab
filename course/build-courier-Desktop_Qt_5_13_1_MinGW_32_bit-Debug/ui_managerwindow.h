/********************************************************************************
** Form generated from reading UI file 'managerwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.13.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MANAGERWINDOW_H
#define UI_MANAGERWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTableWidget>

QT_BEGIN_NAMESPACE

class Ui_managerwindow
{
public:
    QTableWidget *inftable;
    QLabel *label;
    QPushButton *backButton;
    QPushButton *updateButton;
    QPushButton *pathButton;

    void setupUi(QDialog *managerwindow)
    {
        if (managerwindow->objectName().isEmpty())
            managerwindow->setObjectName(QString::fromUtf8("managerwindow"));
        managerwindow->resize(946, 433);
        inftable = new QTableWidget(managerwindow);
        inftable->setObjectName(QString::fromUtf8("inftable"));
        inftable->setGeometry(QRect(10, 50, 921, 331));
        inftable->setRowCount(0);
        inftable->setColumnCount(0);
        inftable->horizontalHeader()->setVisible(false);
        inftable->horizontalHeader()->setDefaultSectionSize(182);
        inftable->horizontalHeader()->setStretchLastSection(false);
        label = new QLabel(managerwindow);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(370, 10, 211, 31));
        QFont font;
        font.setPointSize(14);
        label->setFont(font);
        backButton = new QPushButton(managerwindow);
        backButton->setObjectName(QString::fromUtf8("backButton"));
        backButton->setGeometry(QRect(20, 390, 131, 31));
        updateButton = new QPushButton(managerwindow);
        updateButton->setObjectName(QString::fromUtf8("updateButton"));
        updateButton->setGeometry(QRect(160, 390, 131, 31));
        pathButton = new QPushButton(managerwindow);
        pathButton->setObjectName(QString::fromUtf8("pathButton"));
        pathButton->setGeometry(QRect(300, 390, 131, 31));

        retranslateUi(managerwindow);

        QMetaObject::connectSlotsByName(managerwindow);
    } // setupUi

    void retranslateUi(QDialog *managerwindow)
    {
        managerwindow->setWindowTitle(QCoreApplication::translate("managerwindow", "Dialog", nullptr));
        label->setText(QCoreApplication::translate("managerwindow", "\320\230\320\275\321\204\320\276\321\200\320\274\320\260\321\206\320\270\321\217 \320\276 \320\267\320\260\321\217\320\262\320\272\320\260\321\205", nullptr));
        backButton->setText(QCoreApplication::translate("managerwindow", "\320\275\320\260\320\267\320\260\320\264", nullptr));
        updateButton->setText(QCoreApplication::translate("managerwindow", "\320\276\320\261\320\275\320\276\320\262\320\270\321\202\321\214", nullptr));
        pathButton->setText(QCoreApplication::translate("managerwindow", "\320\262\321\213\320\261\321\200\320\260\321\202\321\214 \321\204\320\260\320\271\320\273", nullptr));
    } // retranslateUi

};

namespace Ui {
    class managerwindow: public Ui_managerwindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MANAGERWINDOW_H
