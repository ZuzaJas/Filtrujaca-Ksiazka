#ifndef WYSZUKIWANIE_H
#define WYSZUKIWANIE_H

#include <QDialog>
#include "mainwindow.h"



namespace Ui {
class wyszukiwanie;
}

class wyszukiwanie : public QDialog
{
    Q_OBJECT

public:
    explicit wyszukiwanie(QList<int> idx_rodzaj,QList<int> idx_inne,QList<int>idx_bialko,QList<int>idx_nabial,QList<int>idx_baza,
                          QList<int>idx_warzywa,QList<int>idx_owoce,QList<int>idx_przyprawy,QWidget *parent = nullptr);
    ~wyszukiwanie();
    void ustawMainWindow(MainWindow* mw) { mainWindow = mw; }

private:
    Ui::wyszukiwanie *ui;
    MainWindow* mainWindow;
    QList<int> idx_rodzaj;
    QList<int> idx_inne;
    QList<int> idx_bialko;
    QList<int> idx_nabial;
    QList<int> idx_baza;
    QList<int> idx_warzywa;
    QList<int> idx_owoce;
    QList<int> idx_przyprawy;

private slots:
    void close_window();
    QString getBaza(QString Plik);
    void wyszukaj_w_bazie(QList<int>idx_rodzaj, QStringList *adres_rodzaj);
    void stworz_guzik(QStringList nazwa);

};



#endif // WYSZUKIWANIE_H
