/********************************************************************************
** Form generated from reading UI file 'applicwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.13.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_APPLICWINDOW_H
#define UI_APPLICWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTableWidget>

QT_BEGIN_NAMESPACE

class Ui_applicwindow
{
public:
    QTableWidget *applictable;
    QPushButton *backButton;
    QPushButton *pathButton;
    QPushButton *updateButton;
    QLabel *label;

    void setupUi(QDialog *applicwindow)
    {
        if (applicwindow->objectName().isEmpty())
            applicwindow->setObjectName(QString::fromUtf8("applicwindow"));
        applicwindow->resize(736, 353);
        applictable = new QTableWidget(applicwindow);
        applictable->setObjectName(QString::fromUtf8("applictable"));
        applictable->setGeometry(QRect(20, 50, 691, 251));
        backButton = new QPushButton(applicwindow);
        backButton->setObjectName(QString::fromUtf8("backButton"));
        backButton->setGeometry(QRect(20, 320, 80, 22));
        pathButton = new QPushButton(applicwindow);
        pathButton->setObjectName(QString::fromUtf8("pathButton"));
        pathButton->setGeometry(QRect(110, 320, 81, 22));
        updateButton = new QPushButton(applicwindow);
        updateButton->setObjectName(QString::fromUtf8("updateButton"));
        updateButton->setGeometry(QRect(200, 320, 81, 22));
        label = new QLabel(applicwindow);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(280, 10, 181, 31));
        QFont font;
        font.setPointSize(16);
        label->setFont(font);

        retranslateUi(applicwindow);

        QMetaObject::connectSlotsByName(applicwindow);
    } // setupUi

    void retranslateUi(QDialog *applicwindow)
    {
        applicwindow->setWindowTitle(QCoreApplication::translate("applicwindow", "Dialog", nullptr));
        backButton->setText(QCoreApplication::translate("applicwindow", "\320\275\320\260\320\267\320\260\320\264", nullptr));
        pathButton->setText(QCoreApplication::translate("applicwindow", "\320\262\321\213\320\261\321\200\320\260\321\202\321\214 \321\204\320\260\320\271\320\273", nullptr));
        updateButton->setText(QCoreApplication::translate("applicwindow", "\320\276\320\261\320\275\320\276\320\262\320\270\321\202\321\214", nullptr));
        label->setText(QCoreApplication::translate("applicwindow", "\320\227\320\260\321\217\320\262\320\272\320\270 \320\275\320\260 \321\200\320\265\320\274\320\276\320\275\321\202", nullptr));
    } // retranslateUi

};

namespace Ui {
    class applicwindow: public Ui_applicwindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_APPLICWINDOW_H
