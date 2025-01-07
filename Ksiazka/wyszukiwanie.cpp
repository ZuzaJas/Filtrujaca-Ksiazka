#include "wyszukiwanie.h"
#include "ui_wyszukiwanie.h"
#include "mainwindow.h"
#include "karta.h"

#include <QPushButton>
#include <QCoreApplication>
#include <QString>
#include <QSqlQuery>
#include <QSqlError>
#include <QDebug>
#include <QStringList>


QStringList przepisy_nazwa;
QStringList *Wprzepisy_nazwa = &przepisy_nazwa;

wyszukiwanie::wyszukiwanie(QList<int> idx_rodzaj,QList<int> idx_inne,QList<int>idx_bialko,QList<int>idx_nabial,QList<int>idx_baza,
                           QList<int>idx_warzywa,QList<int>idx_owoce,QList<int>idx_przyprawy ,QWidget *parent)
    : QDialog(parent),
    idx_rodzaj(idx_rodzaj), idx_inne(idx_inne), idx_bialko(idx_bialko), idx_nabial(idx_nabial), idx_baza(idx_baza), idx_warzywa(idx_warzywa), idx_owoce(idx_owoce), idx_przyprawy(idx_przyprawy)
    , ui(new Ui::wyszukiwanie)
{
    resize(500, 500);

    QPushButton *powrot = new QPushButton("powrot", this);
    powrot->setGeometry(10, 0, 80, 20);
    connect(powrot, &QPushButton::clicked, this, &wyszukiwanie::close_window);
    powrot->setObjectName("Szukaj");


    ui->setupUi(this);

    qDebug()<<"lista rodzaj:  "<<idx_rodzaj;
    qDebug()<<"lista inne:  "<<idx_inne;
    qDebug()<<"lista bialko:  "<<idx_bialko;
    qDebug()<<"lista nabial:  "<<idx_nabial;
    qDebug()<<"lista baza:  "<<idx_baza;
    qDebug()<<"lista warzywa:  "<<idx_warzywa;
    qDebug()<<"lista owoce:  "<<idx_owoce;
    qDebug()<<"lista przyprawy:  "<<idx_przyprawy;

    wyszukaj_w_bazie(idx_rodzaj, Wprzepisy_nazwa);

    qDebug()<<"NAZWA PRZEPISÓW: "<<przepisy_nazwa;
    stworz_guzik(przepisy_nazwa);


}


wyszukiwanie::~wyszukiwanie()
{
    delete ui;
}


void wyszukiwanie::close_window()
{
    close(); // Zamykamy bieżące okno dialogowe

    MainWindow *okno = new MainWindow(); // Tworzymy nowe okno główne
    okno->show(); // Pokazujemy okno główne
}


QString wyszukiwanie::getBaza(QString Plik) {
    QDir currentDir = QDir::current();
    // Zamień wszystkie ukośniki na odwrotne ukośniki
    QString zmienionaSciezka = currentDir.absolutePath();
    zmienionaSciezka.replace("/", "\\");

    // Usuń część od "build" do końca ścieżki
    int buildIndex = zmienionaSciezka.indexOf("\\build");
    if (buildIndex != -1) {
        zmienionaSciezka = zmienionaSciezka.left(buildIndex);
    }

    // Dodaj brakujące podfoldery
    zmienionaSciezka.append("\\bazy\\");
    zmienionaSciezka.append(Plik);
    return zmienionaSciezka;
}

void wyszukiwanie::wyszukaj_w_bazie(QList<int>idx_rodzaj, QStringList *nazwy_adres){
    //SQL
    QSqlDatabase baza_przepisy = QSqlDatabase::addDatabase("QSQLITE");
    QString sciezka_przepisy = getBaza("przepisy.db");
    qDebug() << "{{ŚCIEŻKA}}  " << sciezka_przepisy;
    baza_przepisy.setDatabaseName(sciezka_przepisy);
    if(baza_przepisy.open()) {
        qDebug() << "[+] POŁĄCZONO ";
        baza_przepisy.open();
    } else {
        qDebug() << "[-] NIE POŁĄCZONO Z BAZĄ DANYCH";
        qDebug() << "Błąd: " << baza_przepisy.lastError().text();
    }


    QStringList warunki;
    QStringList nazwy_przepisow;
    QString baseQuery = "SELECT * FROM przepisy WHERE ";

    for (int i = 0; i < idx_rodzaj.size(); ++i) {
        if (idx_rodzaj[i] == 1) {
            // Dodajemy warunek dla konkretnego indeksu
            warunki.append(QString("SUBSTR(rodzaj, %1, 1) = '1'").arg(i + 1));
        }
    }


    if (!warunki.isEmpty()) {
        baseQuery += warunki.join(" AND ");
    } else {
        qDebug() << "Brak warunków do wyszukiwania.";
        return;
    }


    QSqlQuery query(baza_przepisy);
    if (query.exec(baseQuery)) {

        while (query.next()) {
            nazwy_przepisow.append(query.value(1).toString()); // Zakładamy, że nazwa opcji to kolumna 0
        }
        qDebug() << "Znalezione opcje:" << nazwy_przepisow;
    } else {
        qDebug() << "Błąd zapytania SQL:" << query.lastError().text();
    }

    *nazwy_adres = nazwy_przepisow;

    baza_przepisy.close();

}

void wyszukiwanie::stworz_guzik(QStringList nazwa) {
    int liczbaElementow = nazwa.size();
    float x = 10;
    float y = 20;

    for (int i = 0; i < liczbaElementow; ++i) {
        qDebug() << "Tworzenie guzika: " << nazwa[i];

        QPushButton *nazwa_guzik = new QPushButton(nazwa[i], this);

        nazwa_guzik->setGeometry(x, y, 150, 20);
        qDebug() << "Pozycja x:" << x << " Pozycja y:" << y;
        y += 20;

        // Obsługa zdarzenia

        QString wartosc = nazwa[i];
        connect(nazwa_guzik, &QPushButton::clicked, this, [this, wartosc] {
            karta dialog(wartosc ,this);

            dialog.setModal(true);
            dialog.exec();

        });


    }
}
