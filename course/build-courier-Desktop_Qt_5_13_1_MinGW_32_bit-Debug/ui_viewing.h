/********************************************************************************
** Form generated from reading UI file 'viewing.ui'
**
** Created by: Qt User Interface Compiler version 5.13.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_VIEWING_H
#define UI_VIEWING_H

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

    void setupUi(QDialog *managerwindow)
    {
        if (managerwindow->objectName().isEmpty())
            managerwindow->setObjectName(QString::fromUtf8("managerwindow"));
        managerwindow->resize(946, 433);
        inftable = new QTableWidget(managerwindow);
        if (inftable->columnCount() < 5)
            inftable->setColumnCount(5);
        if (inftable->rowCount() < 1)
            inftable->setRowCount(1);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        inftable->setItem(0, 0, __qtablewidgetitem);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        inftable->setItem(0, 1, __qtablewidgetitem1);
        QTableWidgetItem *__qtablewidgetitem2 = new QTableWidgetItem();
        inftable->setItem(0, 2, __qtablewidgetitem2);
        QTableWidgetItem *__qtablewidgetitem3 = new QTableWidgetItem();
        inftable->setItem(0, 3, __qtablewidgetitem3);
        QTableWidgetItem *__qtablewidgetitem4 = new QTableWidgetItem();
        inftable->setItem(0, 4, __qtablewidgetitem4);
        inftable->setObjectName(QString::fromUtf8("inftable"));
        inftable->setGeometry(QRect(10, 50, 921, 331));
        inftable->setRowCount(1);
        inftable->setColumnCount(5);
        inftable->horizontalHeader()->setVisible(false);
        inftable->horizontalHeader()->setDefaultSectionSize(182);
        inftable->horizontalHeader()->setStretchLastSection(false);
        label = new QLabel(managerwindow);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(310, 10, 211, 31));
        QFont font;
        font.setPointSize(14);
        label->setFont(font);
        backButton = new QPushButton(managerwindow);
        backButton->setObjectName(QString::fromUtf8("backButton"));
        backButton->setGeometry(QRect(20, 390, 131, 31));
        updateButton = new QPushButton(managerwindow);
        updateButton->setObjectName(QString::fromUtf8("updateButton"));
        updateButton->setGeometry(QRect(160, 390, 131, 31));

        retranslateUi(managerwindow);

        QMetaObject::connectSlotsByName(managerwindow);
    } // setupUi

    void retranslateUi(QDialog *managerwindow)
    {
        managerwindow->setWindowTitle(QCoreApplication::translate("managerwindow", "Dialog", nullptr));

        const bool __sortingEnabled = inftable->isSortingEnabled();
        inftable->setSortingEnabled(false);
        QTableWidgetItem *___qtablewidgetitem = inftable->item(0, 0);
        ___qtablewidgetitem->setText(QCoreApplication::translate("managerwindow", "\320\244\320\230\320\236", nullptr));
        QTableWidgetItem *___qtablewidgetitem1 = inftable->item(0, 1);
        ___qtablewidgetitem1->setText(QCoreApplication::translate("managerwindow", "\320\220\320\264\321\200\320\265\321\201", nullptr));
        QTableWidgetItem *___qtablewidgetitem2 = inftable->item(0, 2);
        ___qtablewidgetitem2->setText(QCoreApplication::translate("managerwindow", "\320\232\320\260\321\202\320\265\320\263\320\276\321\200\320\270\321\217", nullptr));
        QTableWidgetItem *___qtablewidgetitem3 = inftable->item(0, 3);
        ___qtablewidgetitem3->setText(QCoreApplication::translate("managerwindow", "\320\241\321\200\320\276\320\272 \321\205\321\200\320\260\320\275\320\265\320\275\320\270\321\217", nullptr));
        QTableWidgetItem *___qtablewidgetitem4 = inftable->item(0, 4);
        ___qtablewidgetitem4->setText(QCoreApplication::translate("managerwindow", "\320\234\320\260\321\201\321\201\320\260", nullptr));
        inftable->setSortingEnabled(__sortingEnabled);

        label->setText(QCoreApplication::translate("managerwindow", "\320\230\320\275\321\204\320\276\321\200\320\274\320\260\321\206\320\270\321\217 \320\276 \320\267\320\260\321\217\320\262\320\272\320\260\321\205", nullptr));
        backButton->setText(QCoreApplication::translate("managerwindow", "\320\275\320\260\320\267\320\260\320\264", nullptr));
        updateButton->setText(QCoreApplication::translate("managerwindow", "\320\276\320\261\320\275\320\276\320\262\320\270\321\202\321\214", nullptr));
    } // retranslateUi

};

namespace Ui {
    class managerwindow: public Ui_managerwindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_VIEWING_H
