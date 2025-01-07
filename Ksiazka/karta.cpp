#include "karta.h"
#include "ui_karta.h"
#include "wyszukiwanie.h"

#include <QPushButton>
#include <QDebug>
#include <QSqlDatabase>
#include <QDir>
#include <QStringList>
#include <QLabel>

QStringList dane = {};
QStringList *Wdane = &dane;

karta::karta(QString nazwa, QWidget *parent)
    : QDialog(parent), nazwa(nazwa)
    , ui(new Ui::karta)
{

    QPushButton *powrot = new QPushButton("powrot", this);
    powrot->setGeometry(10, 880, 80, 20);
    connect(powrot, &QPushButton::clicked, this, &karta::close_window);
    powrot->setObjectName("Szukaj");


    ui->setupUi(this);
    //odpalanie funkcji---------------------------
    //zebranie danych z bazy o przepisie
    wyszukaj_w_bazie(nazwa, Wdane);

    qDebug()<<"!!!"<<dane[0];
    resize(900,900);
    QLabel *label_nazwa = new QLabel(this);
    label_nazwa->setGeometry(10,10,880,40);
    label_nazwa->setText(dane[0]);
    setStyleSheet(
        "QLabel "
        "{"
        "font: 40px;"
        "font-family: 'Dancing Script', cursive;"
        "}");
    label_nazwa->setAlignment(Qt::AlignCenter);
    label_nazwa->show();
}

karta::~karta()
{
    delete ui;
}

void karta::close_window()
{
    close(); // Zamykamy bieżące okno dialogowe

}

QString karta::getBaza(QString Plik) {
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

void karta::wyszukaj_w_bazie(QString nazwa, QStringList *lista_nazwy){
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



    QStringList nazwy_przepisow;
    //!!!!!!! Spróbowac zamiast where nazwa robić po id wtedy mniejsze ryzyko powtórzenia
    QString baseQuery = "SELECT nazwa, przygotowanie, opis FROM przepisy WHERE nazwa ='"+nazwa+"';";

    QSqlQuery query(baza_przepisy);
    if (!query.exec(baseQuery)) {
        qDebug() << "Błąd zapytania SQL:" << query.lastError().text();
    } else {
        query.next();
        nazwy_przepisow.append(query.value("nazwa").toString());
        nazwy_przepisow.append(query.value("przygotowanie").toString());
        nazwy_przepisow.append(query.value("opis").toString());
    }

    //qDebug()<<"NAZWA "<<nazwy_przepisow[0];
    //qDebug()<<"PRZEPIS "<<nazwy_przepisow[1];
    //qDebug()<<"OPIS "<<nazwy_przepisow[2];

    //dane dostępne dla całego kodu
    (*lista_nazwy) = nazwy_przepisow;
    baza_przepisy.close();

}




