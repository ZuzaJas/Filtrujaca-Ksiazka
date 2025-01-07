/********************************************************************************
** Form generated from reading UI file 'wyszukiwanie.ui'
**
** Created by: Qt User Interface Compiler version 6.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WYSZUKIWANIE_H
#define UI_WYSZUKIWANIE_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>

QT_BEGIN_NAMESPACE

class Ui_wyszukiwanie
{
public:

    void setupUi(QDialog *wyszukiwanie)
    {
        if (wyszukiwanie->objectName().isEmpty())
            wyszukiwanie->setObjectName("wyszukiwanie");
        wyszukiwanie->resize(400, 300);

        retranslateUi(wyszukiwanie);

        QMetaObject::connectSlotsByName(wyszukiwanie);
    } // setupUi

    void retranslateUi(QDialog *wyszukiwanie)
    {
        wyszukiwanie->setWindowTitle(QCoreApplication::translate("wyszukiwanie", "Dialog", nullptr));
    } // retranslateUi

};

namespace Ui {
    class wyszukiwanie: public Ui_wyszukiwanie {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WYSZUKIWANIE_H
