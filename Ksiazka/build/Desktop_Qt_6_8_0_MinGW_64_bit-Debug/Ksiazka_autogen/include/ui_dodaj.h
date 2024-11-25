/********************************************************************************
** Form generated from reading UI file 'dodaj.ui'
**
** Created by: Qt User Interface Compiler version 6.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DODAJ_H
#define UI_DODAJ_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_Dialog
{
public:
    QPushButton *powrot;
    QPushButton *zatwierdz;

    void setupUi(QDialog *Dialog)
    {
        if (Dialog->objectName().isEmpty())
            Dialog->setObjectName("Dialog");
        Dialog->resize(1000, 800);
        powrot = new QPushButton(Dialog);
        powrot->setObjectName("powrot");
        powrot->setGeometry(QRect(890, 740, 80, 24));
        zatwierdz = new QPushButton(Dialog);
        zatwierdz->setObjectName("zatwierdz");
        zatwierdz->setGeometry(QRect(800, 740, 80, 24));

        retranslateUi(Dialog);

        QMetaObject::connectSlotsByName(Dialog);
    } // setupUi

    void retranslateUi(QDialog *Dialog)
    {
        Dialog->setWindowTitle(QCoreApplication::translate("Dialog", "Dialog", nullptr));
        powrot->setText(QCoreApplication::translate("Dialog", "Powr\303\263t", nullptr));
        zatwierdz->setText(QCoreApplication::translate("Dialog", "Zatwierd\305\272", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Dialog: public Ui_Dialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DODAJ_H
