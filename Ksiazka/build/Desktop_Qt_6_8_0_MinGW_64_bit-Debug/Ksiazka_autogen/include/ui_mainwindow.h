/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.8.0
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
    QLabel *label;
    QPushButton *kminek;
    QPushButton *galka_muszkatowa;
    QPushButton *cynamon;
    QPushButton *tymianek;
    QPushButton *nowe_okno;
    QLabel *zdjecie;
    QLabel *label_2;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(1000, 800);
        QFont font;
        font.setPointSize(9);
        font.setBold(false);
        MainWindow->setFont(font);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        label = new QLabel(centralwidget);
        label->setObjectName("label");
        label->setGeometry(QRect(500, 400, 20, 20));
        label->setBaseSize(QSize(0, 0));
        QFont font1;
        font1.setPointSize(10);
        font1.setBold(false);
        label->setFont(font1);
        label->setLineWidth(5);
        label->setTextFormat(Qt::TextFormat::RichText);
        label->setAlignment(Qt::AlignmentFlag::AlignCenter);
        kminek = new QPushButton(centralwidget);
        kminek->setObjectName("kminek");
        kminek->setGeometry(QRect(520, 670, 80, 20));
        galka_muszkatowa = new QPushButton(centralwidget);
        galka_muszkatowa->setObjectName("galka_muszkatowa");
        galka_muszkatowa->setGeometry(QRect(900, 670, 80, 20));
        cynamon = new QPushButton(centralwidget);
        cynamon->setObjectName("cynamon");
        cynamon->setGeometry(QRect(770, 670, 80, 20));
        tymianek = new QPushButton(centralwidget);
        tymianek->setObjectName("tymianek");
        tymianek->setGeometry(QRect(650, 670, 80, 20));
        nowe_okno = new QPushButton(centralwidget);
        nowe_okno->setObjectName("nowe_okno");
        nowe_okno->setGeometry(QRect(50, 620, 80, 24));
        zdjecie = new QLabel(centralwidget);
        zdjecie->setObjectName("zdjecie");
        zdjecie->setGeometry(QRect(170, 480, 248, 283));
        label_2 = new QLabel(centralwidget);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(60, 360, 201, 31));
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 1000, 17));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName("statusbar");
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        label->setText(QCoreApplication::translate("MainWindow", "+", nullptr));
        kminek->setText(QCoreApplication::translate("MainWindow", "Kminek", nullptr));
        galka_muszkatowa->setText(QCoreApplication::translate("MainWindow", "Ga\305\202ka muszk.", nullptr));
        cynamon->setText(QCoreApplication::translate("MainWindow", "Cynamon", nullptr));
        tymianek->setText(QCoreApplication::translate("MainWindow", "Tymianek", nullptr));
        nowe_okno->setText(QCoreApplication::translate("MainWindow", "Nowe Okno", nullptr));
        zdjecie->setText(QString());
        label_2->setText(QCoreApplication::translate("MainWindow", "Baza danych", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
