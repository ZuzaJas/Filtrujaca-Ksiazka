/********************************************************************************
** Form generated from reading UI file 'karta.ui'
**
** Created by: Qt User Interface Compiler version 6.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_KARTA_H
#define UI_KARTA_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>

QT_BEGIN_NAMESPACE

class Ui_karta
{
public:

    void setupUi(QDialog *karta)
    {
        if (karta->objectName().isEmpty())
            karta->setObjectName("karta");
        karta->resize(400, 300);

        retranslateUi(karta);

        QMetaObject::connectSlotsByName(karta);
    } // setupUi

    void retranslateUi(QDialog *karta)
    {
        karta->setWindowTitle(QCoreApplication::translate("karta", "Dialog", nullptr));
    } // retranslateUi

};

namespace Ui {
    class karta: public Ui_karta {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_KARTA_H
