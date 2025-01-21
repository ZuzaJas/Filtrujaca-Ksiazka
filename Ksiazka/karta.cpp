#include "karta.h"
#include "ui_karta.h"
#include "dodaj.h"

#include <QPushButton>
#include <QDebug>
#include <QSqlDatabase>
#include <QDir>
#include <QStringList>
#include <QLabel>
#include <QSqlError>
#include<QSqlQuery>

QStringList dane = {};
QStringList *Wdane = &dane;

karta::karta(int id, QWidget *parent)
    : QDialog(parent), id(id)
    , ui(new Ui::karta)
{
    ui->setupUi(this);

    QPushButton *powrot = new QPushButton("powrót", this);
    powrot->setGeometry(10, 10, 80, 20);
    connect(powrot, &QPushButton::clicked, this, &karta::close_window);
    powrot->setObjectName("powrót");

    QPushButton *edycja = new QPushButton("edycja", this);
    edycja->setGeometry(100, 10, 80, 20);
    connect(edycja, &QPushButton::clicked, this, &karta::open_edycja);
    edycja->setObjectName("edycja");


    //odpalanie funkcji---------------------------
    //zebranie danych z bazy o przepisie
    wyszukaj_w_bazie(id, Wdane);

    qDebug()<<"!!!"<<dane[0];
    resize(900,900);
    QLabel *label_nazwa = new QLabel(this);
    label_nazwa->setGeometry(10,30,880,45);
    label_nazwa->setText(dane[0]);
    label_nazwa->setStyleSheet(
        "QLabel "
        "{"
        "font: 40px;"
        "font-family: 'Dancing Script', cursive;"
        "}");
    label_nazwa->setAlignment(Qt::AlignCenter);
    label_nazwa->show();

    QLabel *label_skladnikiCON = new QLabel(this);
    label_skladnikiCON-> setGeometry(10,70,880,20);
    label_skladnikiCON->setText("Składniki: ");
    label_skladnikiCON->setStyleSheet(
        "QLabel "
        "{"
        "font: 20px;"
        "font-family: 'Dancing Script', cursive;"
        "}");
    label_skladnikiCON->show();

    QLabel *label_skladniki = new QLabel(this);
    label_skladniki-> setGeometry(10,100,880,20);
    label_skladniki->setText(dane[1]);
    label_skladniki->setStyleSheet(
        "QLabel "
        "{"
        "font: 16px;"
        "font-family: 'Dancing Script', cursive;"
        "}");
    label_skladniki->setAlignment(Qt::AlignJustify);
    label_skladniki->show();

    QLabel *label_przygotowanieCON = new QLabel(this);
    label_przygotowanieCON-> setGeometry(10,140,880,25);
    label_przygotowanieCON->setText("Przygotowanie: ");
    label_przygotowanieCON->setStyleSheet(
        "QLabel "
        "{"
        "font: 20px;"
        "font-family: 'Dancing Script', cursive;"
        "}");
    label_przygotowanieCON->show();

    QLabel *label_przygotowanie = new QLabel(this);
    label_przygotowanie-> setGeometry(10,175,880,300);
    label_przygotowanie->setText(dane[2]);
    label_przygotowanie->setStyleSheet(
        "QLabel "
        "{"
        "font: 16px;"
        "font-family: 'Dancing Script', cursive;"
        "}");
    label_przygotowanie->setAlignment(Qt::AlignJustify);
    label_przygotowanie->setWordWrap(true);
    label_przygotowanie->show();


}

karta::~karta()
{
    delete ui;
}

void karta::close_window()
{
    close(); // Zamykamy bieżące okno dialogowe

}

void karta::open_edycja()
{
    close();
    Dialog okno("edycja", id);
    okno.setModal(true);
    okno.exec();
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

void karta::wyszukaj_w_bazie(int id, QStringList *lista_nazwy){
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
    // Konwersja `int` na QString i użycie w zapytaniu
    QString baseQuery = QString("SELECT nazwa, przygotowanie, opis FROM przepisy WHERE id = %1;").arg(id);

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




