#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include "dodaj.h"
#include "karta.h"


#include <QPixmap>
#include <QCoreApplication>
#include <QDebug>
#include <QFile>
#include <QTextStream>
#include <QDir>
#include <QString>
#include <QList>
#include <QStringList>
#include <QCheckBox>



//odstęp rozstawienia guzików
float y_guziki = 60;
float *Wy_guziki = &y_guziki;


// Funkcja do wyświetlania komunikatu w terminalu
void MainWindow::printMessage(const QString &message)
{
    qDebug() << "Komunikat:" << message;
}



MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)


{

    ui->setupUi(this);


//---------------GUZIKI---------------------------------------------------------------------------------------------------------------------------------

    stworz_guzik(lista_rodzaje, Widx_rodzaj, 520, Wy_guziki);

    stworz_guzik(lista_inne, Widx_inne, 520, Wy_guziki);

    //rzeczy odpowiedzialne za białko: wołowe, ryba, jajko, kurczak
    stworz_guzik(lista_bialko, Widx_bialko, 520, Wy_guziki);

    //rzeczy odpowiedzialne za baze: makaron, ryż, pieczywo, mąkę
    stworz_guzik(lista_baza, Widx_baza, 520, Wy_guziki);

    //rzeczy odpowiedzialne za warzywa: marchew, cebula, ogórek, papryka, pomidor, ziemniak
    stworz_guzik(lista_warzywa, Widx_warzywa, 520, Wy_guziki);

    //rzeczy odpowiedzialne za owoce: banan, cytryna, jabłko, malina, pomarańcza, truskawka
    stworz_guzik(lista_owoce, Widx_owoce, 520, Wy_guziki);

    //rzeczy odpowiedzialne za nabiał: mleko, ser, smietana, jogurt
    stworz_guzik(lista_nabial, Widx_nabial, 520, Wy_guziki);

    //rzeczy odpowiedzialne za przyprawy: cynamon, tymianek, gałk muszkatowa, kminek
    stworz_guzik(lista_przyprawy, Widx_przyprawy, 520, Wy_guziki);

    (*Wy_guziki) = 60;

//------------------------------------------------------------------------------------------------------------------------------------------------------

    //guzik pokazujący rezultaty filtrowania
    QPushButton *szukaj = new QPushButton("SZUKAJ", this);
    szukaj->setGeometry(900, 720, 80, 20);
    connect(szukaj, &QPushButton::clicked, this, [this]() {
        wyszukaj_przepisy(przepisy_nazwa, przepisy_id);

        qDebug()<<"NAZWA!!!"<<przepisy_nazwa;
        qDebug()<<"id"<<przepisy_id;
    });
    szukaj->setObjectName("Szukaj");


    //przechodzi do zakładki z dodaniem przepisu
    QPushButton *dodaj = new QPushButton("DODAJ", this);
    dodaj->setGeometry(520, 720, 80, 20);
    connect(dodaj, &QPushButton::clicked, this, &MainWindow::nowe_okno_clicked);
    dodaj->setObjectName("DODAJ");



}





MainWindow::~MainWindow()
{
    delete ui;

}


//przechodzi do zakładki z dodaniem przepisu
void MainWindow::nowe_okno_clicked()
{
    close();
    Dialog okno("dodaj", 0);
    okno.setModal(true);
    okno.exec();

}


//kliknięcie guzika filtrującego, daje się listy z nazwami i indexem i szuka właściwego
void MainWindow::skladnik_clicked(QStringList skladniki_lista, QList<int> *idx_lista)
{
    QPushButton *button = qobject_cast<QPushButton *>(sender());
    QString wyraz_id = button->objectName();
    int index = skladniki_lista.indexOf(wyraz_id);
    if (button) {
        if (index != -1) {
            if((*idx_lista)[index] == 1)
            {
                (*idx_lista)[index] = 0;
                button->setStyleSheet("color: black;");
            }else{
                (*idx_lista)[index] = 1;
                button->setStyleSheet("color: rgb(50, 205, 50);");
            }
            qDebug() << "Index List:" << (*idx_lista)[index];
            qDebug() << "Zawartość lista string "<<skladniki_lista;

        } else {
            qDebug() << "Nie znaleziono";
        }
        qDebug() << "Index:" << index;


    }
}

//tworzenie guzików z listy oraz regularne ich rozstawienie
void MainWindow::stworz_guzik(QStringList nazwa, QList<int> *index, float x, float *y) {
    int liczbaElementow = nazwa.size();
    int elementyNaRzad = liczbaElementow <= 4 ? liczbaElementow : (liczbaElementow <= 6 ? 3 : qCeil(liczbaElementow / 2.0)); // Maksymalnie 3–6 w rzędzie
    float rzadOffset = 30;  // Odstęp między rzędami
    float kolumnaOffset = ((500 / elementyNaRzad)); // Dynamiczny odstęp w poziomie

    for (int i = 0; i < liczbaElementow; ++i) {
        //qDebug() << "Tworzenie checkboxa: " << nazwa[i];

        QPushButton *button = new QPushButton(nazwa[i], this);

        // Obliczanie pozycji checkboxa w rzędach
        int rzad = i / elementyNaRzad;  // Indeks rzędu
        int kolumna = i % elementyNaRzad; // Indeks w rzędzie
        qDebug()<<"i="<<i<<",element na rząd="<<elementyNaRzad<<"kolumna"<<kolumna;

        float xPos = x + (kolumna * kolumnaOffset);
        float yPos = *y + rzad * rzadOffset;
        qDebug()<<"float pos x"<<kolumna * kolumnaOffset;


        button->setGeometry(xPos, yPos, 80, 25);
        button->setObjectName(nazwa[i]);
        qDebug()<<"Guzik ["<<nazwa[i]<<"] Pozycja["<<xPos<<","<<yPos<<"]";

        // Obsługa zdarzenia
        connect(button, &QPushButton::clicked, this, [this, nazwa, index] {
            skladnik_clicked(nazwa, index);
        });

        if (i==liczbaElementow-1)
        {
            (*y) = yPos+rzadOffset+40;
        }
    }
}

//funkcja gdyby było więcej niż jedna baza danych i dostanie się do jej ścieżki
QString MainWindow::getBaza(QString Plik) {
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

//znajdywanie wszystkich rezultatów pasujących do filtrów poprzez rodzaj
void MainWindow::wyszukaj_przepisy(QStringList &adres_nazwa, QList<int> &adres_id){

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
    QStringList warunki_nabial;
    QStringList warunki_baza;
    QStringList nazwy_przepisow;
    QList<int> id;
    QString baseQuery = "SELECT * FROM przepisy WHERE ";

    // Tworzymy warunki dla idx_rodzaj
    for (int i = 0; i < idx_rodzaj.size(); ++i) {
        if (idx_rodzaj[i] == 1) {
            warunki.append(QString("SUBSTR(rodzaj, %1, 1) = '1'").arg(i + 1));
        }
    }

    // Tworzymy warunki dla idx_nabial
    for (int i = 0; i < idx_nabial.size(); ++i) {
        if (idx_nabial[i] == 1) {
            warunki_nabial.append(QString("SUBSTR(nabial, %1, 1) = '1'").arg(i + 1));
        }
    }

    // Tworzymy warunki dla idx_baza
    for (int i = 0; i < idx_baza.size(); ++i) {
        if (idx_baza[i] == 1) {
            warunki_baza.append(QString("SUBSTR(baza, %1, 1) = '1'").arg(i + 1));
        }
    }

    // Łączymy warunki w logiczną całość
    QString queryPart1 = warunki.join(" OR ");       // Warunki dla idx_rodzaj
    QString queryPart2 = warunki_nabial.join(" AND"); // Warunki dla idx_nabial
    QString queryPart3 = warunki_baza.join(" AND");   // Warunki dla idx_baza

    // Budowanie finalnego zapytania
    QStringList allParts;
    if (!queryPart1.isEmpty()) allParts.append(QString("(%1)").arg(queryPart1));
    if (!queryPart2.isEmpty()) allParts.append(QString("(%1)").arg(queryPart2));
    if (!queryPart3.isEmpty()) allParts.append(QString("(%1)").arg(queryPart3));

    // Połącz warunki z "AND"
    QString finalQuery;
    if (!allParts.isEmpty()) {
        finalQuery = baseQuery + allParts.join(" AND ");
    } else {
        finalQuery = baseQuery + "1 = 1"; // Domyślne zapytanie
    }


    QSqlQuery query(baza_przepisy);
    if (query.exec(finalQuery)) {

        while (query.next()) {  //zmiana, columna 0 to jest ich id więc zrobić 2 listy jedną z id, drugą z nazwą
            nazwy_przepisow.append(query.value(1).toString()); // Zakładamy, że nazwa opcji to kolumna 1
            id.append(query.value(0).toInt());
        }
        qDebug() << "Znalezione opcje:" << nazwy_przepisow;
        qDebug() << "ID znalezionycy" << id;
    } else {
        qDebug() << "Błąd zapytania SQL:" << query.lastError().text();
    }

    adres_nazwa = nazwy_przepisow;
    adres_id = id;

    baza_przepisy.close();
    guziki_wyszukiwanie(adres_nazwa, adres_id);

}
//obiekt testu błędu
void MainWindow::guziki_wyszukiwanie(QStringList nazwa, QList<int> id) {

    if (!mapa_guziki.isEmpty()) {
        for (auto it = mapa_guziki.begin(); it != mapa_guziki.end(); ++it) {
            int klucz = it.key();
            QPushButton *button = it.value();
            delete button;

        }
        mapa_guziki.clear();
    }


    int liczbaElementow = nazwa.size();
    float x = 10;
    float y = 20;

    for (int i = 0; i < liczbaElementow; ++i) {
        qDebug() << "Tworzenie guzika: " << nazwa[i];

        QPushButton *nazwa_guzik = new QPushButton(nazwa[i], this);

        nazwa_guzik->setGeometry(x, y, 150, 30);
        qDebug() << "Pozycja x:" << x << " Pozycja y:" << y;
        y += 35;
        nazwa_guzik->show();
        // Obsługa zdarzenia

        int wartosc = id[i];
        connect(nazwa_guzik, &QPushButton::clicked, this, [this, wartosc] {
            karta dialog(wartosc ,this);

            dialog.setModal(true);
            dialog.exec();

        });
        mapa_guziki.insert(id[i], nazwa_guzik);


    }
}
