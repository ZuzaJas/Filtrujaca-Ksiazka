#include "dodaj.h"
#include "ui_dodaj.h"
#include "mainwindow.h"
#include "karta.h"

#include <QApplication>
#include <QWidget>
#include <QVBoxLayout>
#include <QLineEdit>
#include <QTextEdit>
#include <QLabel>
#include <QComboBox>
#include <QStringList>
#include <QCheckBox>
#include <QtMath>
#include <QDir>
#include <QString>
#include <algorithm>
#include <QSqlDatabase>
#include <QDebug>

//Listy odpowiedzialne za zapisywanie danych do dodania do przepisu
QList<int> sql_rodzaj = {0, 0, 0, 0, 0,0};
QList<int> *wsk_sql_rodzaj = &sql_rodzaj;

QList<int> sql_inne = {0, 0};
QList<int> *wsk_sql_inne = &sql_inne;

QList<int> sql_skl_bialko = {0, 0, 0, 0};
QList<int> *wsk_sql_skl_bialko = &sql_skl_bialko;
QList<int> sql_skl_nabial = {0, 0, 0, 0};
QList<int> *wsk_sql_skl_nabial = &sql_skl_nabial;
QList<int> sql_skl_baza = {0, 0, 0, 0};
QList<int> *wsk_sql_skl_baza = &sql_skl_baza;
QList<int> sql_skl_warzywa = {0, 0, 0, 0, 0, 0};
QList<int> *wsk_sql_skl_warzywa = &sql_skl_warzywa;
QList<int> sql_skl_owoce = {0, 0, 0, 0, 0, 0};
QList<int> *wsk_sql_skl_owoce = &sql_skl_owoce;
QList<int> sql_skl_przyprawy = {0, 0, 0, 0};
QList<int> *wsk_sql_skl_przyprawy = &sql_skl_przyprawy;

QList<QString> lista_dodatkowe = {};



Dialog::Dialog(QString typ,int id, QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::Dialog)
    , nazwa(new QLineEdit(this))
    , opis(new QTextEdit(this))
    , przepis(new QTextEdit(this))
    , dodatkowe_skladniki(new QLineEdit(this))
    , label_opis(new QLabel(this))
    , label_przepis(new QLabel(this))
    , label_nazwa(new QLabel(this))
    , label_rodzaj(new QLabel(this))
    , label_inne(new QLabel(this))
    , label_skladniki(new QLabel(this))
    , label_dodatkowe_skladniki(new QLabel(this))
    , id(id), typ(typ)

{
    ui->setupUi(this);

    qDebug()<< "!!! ID"<<id;
    qDebug()<<"!!! TYP"<<typ;



    nazwa->setPlaceholderText("Wprowadź jednowierszowy tekst...");
    label_nazwa->setText("NAZWA");


    QStringList lista_rodzaj = {"śniadaniowe", "lunch", "obiadowe","napoje","desery","sosy i dodatki"};
    label_rodzaj->setText("RODZAJ DANIA");

    label_skladniki->setText("SKŁADNIKI");
    QStringList lista_bialko = {"wołowe", "ryba", "jajko", "kurczak"};
    QStringList lista_baza = {"makaron", "ryż", "pieczywo", "mąka"};
    QStringList lista_warzywa = {"marchew", "cebula", "ogórek", "papryka", "pomidor", "ziemniak"};
    QStringList lista_owoce = {"banan", "cytryna", "jabłko", "malina", "pomarańcza", "truskawka"};
    QStringList lista_nabial = {"mleko", "ser", "smietana", "jogurt"};
    QStringList lista_przyprawy = {"cynamon","tymianek","galka_muszkatowa","kminek"};

    QStringList lista_inne = {"wegetariańskie", "ostre"};
    label_inne->setText("INNE");

    dodatkowe_skladniki->setPlaceholderText("Wprowadź jednowierszowy tekst...");
    label_dodatkowe_skladniki->setText("DODATKOWE SKLADNIKI");

    label_przepis->setText("PROPORCJE SKŁADNIKÓW");

    opis->setPlaceholderText("Wprowadź wielowierszowy opis...");
    label_opis->setText("PRZYGOTOWANIE PRZEPISU");


    //rozstawienie

    nazwa->setFixedSize(450,30);  // szerokość, wysok
    nazwa->setStyleSheet("border: 2px solid black; border-radius: 5px;");
    nazwa->move(10,60); //x, y

    label_nazwa->setFixedSize(450, 10);
    label_nazwa->move(10,40);

    stworz_checkbox(lista_rodzaj, wsk_sql_rodzaj,10, 120);
    label_rodzaj->setFixedSize(450, 10);
    label_rodzaj->move(10,100);


    stworz_checkbox(lista_inne, wsk_sql_inne, 10,220);
    label_inne->setFixedSize(450, 10);
    label_inne->move(10,190);
\
    stworz_checkbox(lista_bialko, wsk_sql_skl_bialko, 10,270);
    stworz_checkbox(lista_baza, wsk_sql_skl_baza, 10,300);
    stworz_checkbox(lista_warzywa, wsk_sql_skl_warzywa, 10,330);
    stworz_checkbox(lista_owoce, wsk_sql_skl_owoce, 10,390);
    stworz_checkbox(lista_nabial, wsk_sql_skl_nabial, 10,450);
    stworz_checkbox(lista_przyprawy, wsk_sql_skl_przyprawy, 10,480);

    label_skladniki->setFixedSize(450, 10);
    label_skladniki->move(10,250);


    dodatkowe_skladniki->setFixedSize(350,30);
    dodatkowe_skladniki->setStyleSheet("border: 2px solid black; border-radius: 5px;");
    dodatkowe_skladniki->move(10,540);

    label_dodatkowe_skladniki->setFixedSize(450, 10);
    label_dodatkowe_skladniki->move(10,520);

    label_lista_dodatkowe = new QTextEdit(this);
    label_lista_dodatkowe->setReadOnly(true);
    label_lista_dodatkowe->setFixedSize(450, 100);
    label_lista_dodatkowe->setStyleSheet("border: 2px solid black; border-radius: 5px;");
    label_lista_dodatkowe->move(10, 580);
    label_lista_dodatkowe->update();


    QPushButton *guzik_dodatkowe_dodaj = new QPushButton("dodaj", this);
    QPushButton *guzik_dodatkowe_usun = new QPushButton("usuń",this);
    guzik_dodatkowe_dodaj->setFixedSize(45,30);
    guzik_dodatkowe_usun->setFixedSize(45,30);
    guzik_dodatkowe_dodaj->move(370,540);
    guzik_dodatkowe_usun->move(425,540);
    guzik_dodatkowe_dodaj->setObjectName("guzik_dodatkowe_dodaj");
    guzik_dodatkowe_usun->setObjectName("guzik_dodatkowe_usun");
    connect(guzik_dodatkowe_dodaj, &QPushButton::clicked, this, [=]() {
        dodatkowe(dodatkowe_skladniki->text(),0);
    });
    connect(guzik_dodatkowe_usun, &QPushButton::clicked, this, [=]() {
        dodatkowe(dodatkowe_skladniki->text(), 0);
    });

    przepis->setFixedSize(450,120);
    przepis->move(520,60);
    przepis->setStyleSheet("border: 2px solid black; border-radius: 5px;");

    label_przepis->setFixedSize(450, 10);
    label_przepis->move(520, 40);

    opis->setFixedSize(450,450);
    opis->move(520,230);
    opis->setStyleSheet("border: 2px solid black; border-radius: 5px;");

    label_opis->setFixedSize(450, 10);
    label_opis->move(520,210);

    ui->powrot->setFixedSize(80,24);
    ui->powrot->move(890,740);

    resize(1000, 800);

    connect(ui->powrot, &QPushButton::clicked, this, &Dialog::close_window);
    connect(ui->zatwierdz, &QPushButton::clicked, this, &Dialog::zatwierdz_clicked);

    if (typ=="edycja")
    {
        wczytaj_dane();
    }
}


Dialog::~Dialog()
{
    delete ui;
}

void Dialog::close_window()
{
    close(); // Zamykamy bieżące okno dialogowe
    if (typ=="dodaj"){
        MainWindow *okno = new MainWindow(); // Tworzymy nowe okno główne
        okno->show();
    }else if (typ=="edycja"){
        karta *okno = new karta(id);
        okno->show();
    }

}



//zrobić wszystko na checkboxy
void Dialog::stworz_checkbox(QStringList nazwa, QList<int> *index, float x, float y) {

    int liczbaElementow = nazwa.size();
    int elementyNaRzad = liczbaElementow <= 4 ? liczbaElementow : (liczbaElementow <= 6 ? 3 : qCeil(liczbaElementow / 2.0)); // Maksymalnie 3–6 w rzędzie
    float rzadOffset = 30;  // Odstęp między rzędami
    float kolumnaOffset = ((600 / elementyNaRzad) - x); // Dynamiczny odstęp w poziomie

    for (int i = 0; i < liczbaElementow; ++i) {
        //qDebug() << "Tworzenie checkboxa: " << nazwa[i];

        QCheckBox *checkBox = new QCheckBox(nazwa[i], this);

        // Obliczanie pozycji checkboxa w rzędach
        int rzad = i / elementyNaRzad;  // Indeks rzędu
        int kolumna = i % elementyNaRzad; // Indeks w rzędzie

        float xPos = x + kolumna * kolumnaOffset;
        float yPos = y + rzad * rzadOffset;

        checkBox->setGeometry(xPos, yPos, 150, 20);
        //qDebug() << "Pozycja x:" << xPos << " Pozycja y:" << yPos;

        // Obsługa zdarzenia
        connect(checkBox, &QCheckBox::toggled, this, [this, i, index] {
            if (i < index->size()) {
                qDebug() << "Checkbox toggled: indeks" << i;
                (*index)[i] = checkTrue((*index)[i]);  // Poprawione użycie wskaźnika
                qDebug() << "Nowa wartość indeksu" << i << ":" << (*index)[i];
            } else {
                qDebug() << "Błąd: Indeks poza zakresem!";
                qDebug() << "Rozmiar rodzaj przed iteracją:" << index->size();
            }
        });
        checkBoxMap.insert(nazwa[i], checkBox);
        qDebug()<<"n: "<<nazwa[i];

    }

}



int Dialog::checkTrue(int value) {
    return value == 0 ? 1 : 0;
}

void Dialog::zatwierdz_clicked() {


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

    QSqlQuery query(baza_przepisy);

    if (typ=="dodaj"){

        if (!query.prepare(R"(
            INSERT INTO przepisy
            (Nazwa, Rodzaj, inne, bialko, baza, warzywa, owoce, nabial, przyprawy, opis, dodatkowe, przygotowanie)
            VALUES (:Nazwa, :Rodzaj, :inne, :bialko, :baza, :warzywa, :owoce, :nabial, :przyprawy, :opis, :dodatkowe, :przygotowanie)
        )")) {
            qDebug() << "Błąd przygotowania zapytania: " << query.lastError().text();
            return;
        }

        query.bindValue(":Nazwa", nazwa->text());
        query.bindValue(":Rodzaj", ListaNaString(sql_rodzaj));
        query.bindValue(":inne", ListaNaString(sql_inne));
        query.bindValue(":bialko", ListaNaString(sql_skl_bialko));
        query.bindValue(":baza", ListaNaString(sql_skl_baza));
        query.bindValue(":warzywa", ListaNaString(sql_skl_warzywa));
        query.bindValue(":owoce", ListaNaString(sql_skl_owoce));
        query.bindValue(":nabial", ListaNaString(sql_skl_nabial));
        query.bindValue(":przyprawy", ListaNaString(sql_skl_przyprawy));
        query.bindValue(":opis", opis->toPlainText());
        query.bindValue(":dodatkowe", lista_dodatkowe.join(";"));
        query.bindValue(":przygotowanie", przepis->toPlainText());

        qDebug() << "Wykonuję zapytanie SQL...";
        if (!query.exec()) {
            qDebug() << "Błąd wykonania zapytania: " << query.lastError().text();
            return;
        }

        nazwa->clear();
        lista_dodatkowe = {};
        label_lista_dodatkowe->clear();
        opis->clear();
        przepis->clear();

    }

    if (typ=="edycja"){
        //tutaj miejsce na zapytanie na edycje

        // Przygotowanie zapytania SQL UPDATE
        if (!query.prepare(R"(
            UPDATE przepisy
            SET
                Nazwa = :Nazwa,
                Rodzaj = :Rodzaj,
                inne = :inne,
                bialko = :bialko,
                baza = :baza,
                warzywa = :warzywa,
                owoce = :owoce,
                nabial = :nabial,
                przyprawy = :przyprawy,
                opis = :opis,
                dodatkowe = :dodatkowe,
                przygotowanie = :przygotowanie
            WHERE id = :id
        )")){
            qDebug() << "Błąd przygotowania zapytania: " << query.lastError().text();
            return;
        }

        // Przypisanie wartości do zapytania
        query.bindValue(":Nazwa", nazwa->text());
        query.bindValue(":Rodzaj", ListaNaString(sql_rodzaj));
        query.bindValue(":inne", ListaNaString(sql_inne));
        query.bindValue(":bialko", ListaNaString(sql_skl_bialko));
        query.bindValue(":baza", ListaNaString(sql_skl_baza));
        query.bindValue(":warzywa", ListaNaString(sql_skl_warzywa));
        query.bindValue(":owoce", ListaNaString(sql_skl_owoce));
        query.bindValue(":nabial", ListaNaString(sql_skl_nabial));
        query.bindValue(":przyprawy", ListaNaString(sql_skl_przyprawy));
        query.bindValue(":opis", opis->toPlainText());
        query.bindValue(":dodatkowe", lista_dodatkowe.join(";"));
        query.bindValue(":przygotowanie", przepis->toPlainText());
        query.bindValue(":id", id); // Warunek WHERE - aktualizujemy rekord o ID = wartosc

        // Wykonanie zapytania
        if (!query.exec()) {
            qDebug() << "Błąd wykonania zapytania: " << query.lastError().text();
        } else {
            qDebug() << "Rekord zaktualizowany pomyślnie!";
        }


    }
    qDebug() << "Dane zostały zapisane!";
    baza_przepisy.close();
    qDebug() << "Baza zamknięta!";
    if(typ=="edycja"){
        close(); // Zamykamy bieżące okno dialogowe
        karta *okno = new karta(id);
        okno->show();

    }
}


QString Dialog::ListaNaString(const QList<int> &lista) {
    QStringList stringElements;

    // Konwertuj elementy QList<int> na QString i przechowaj w QStringList
    std::transform(lista.begin(), lista.end(), std::back_inserter(stringElements),
                   [](int liczba) { return QString::number(liczba); });

    // Połącz elementy w jeden ciąg znaków
    return stringElements.join("");
}

QString Dialog::getBaza(QString Plik) {
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

void Dialog::dodatkowe(QString skladnik, int type) {
    // Sprawdź, który przycisk wywołał akcję
    QPushButton* clickedButton = qobject_cast<QPushButton*>(sender());
    if (clickedButton) {
        if (clickedButton->objectName() == "guzik_dodatkowe_dodaj") {
            qDebug() << "Kliknięto przycisk 'dodaj'  ";
            if (!lista_dodatkowe.contains(skladnik)) {
                lista_dodatkowe.append(skladnik);
                qDebug() << "Dodano składnik:" << skladnik;
            } else {
                qDebug() << "Składnik już istnieje w liście:" << skladnik;
            }

        } else if (clickedButton->objectName() == "guzik_dodatkowe_usun") {
            qDebug() << "Kliknięto przycisk 'usun'";
            if (lista_dodatkowe.contains(skladnik)) {
                lista_dodatkowe.removeAll(skladnik);
                qDebug() << "Usunięto składnik:" << skladnik;
            } else {
                qDebug() << "Nie znaleziono składnika w liście:" << skladnik;
            }

        }
    }else if(type==1){
        lista_dodatkowe.append(skladnik);
    }
    dodatkowe_skladniki->clear();
    QString zawartoscListy = lista_dodatkowe.join(" ");
    label_lista_dodatkowe->setText(zawartoscListy);
    QString testListy = lista_dodatkowe.join(";");
    qDebug()<<"Lista do bazy: "<<testListy;



}

void Dialog::wczytaj_dane()
{
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

    QString baseQuery = QString("SELECT * FROM przepisy WHERE id = %1;").arg(id);

    QSqlQuery query(baza_przepisy);
    if (!query.exec(baseQuery)) {
        qDebug() << "Błąd zapytania SQL:" << query.lastError().text();
    } else {
        query.next();
        //wypełnienie tekstowych rzeczy
        nazwa->setText(query.value("nazwa").toString());
        opis->setText(query.value("opis").toString());
        przepis->setText(query.value("przygotowanie").toString());
        //wypełnienie checkboxów
        QStringList index = {"rodzaj", "inne", "bialko", "baza", "warzywa", "owoce", "nabial", "przyprawy"};
        QStringList rodzaj = String_na_Lista(query.value("Rodzaj").toString());
        zmien_checkboxy(index[0], rodzaj);
        // inne, bialko, baza, warzywa, owoce, nabial, przyprawy, opis, dodatkowe, przygotowanie
        QStringList inne = String_na_Lista(query.value("inne").toString());
        zmien_checkboxy(index[1], inne);

        QStringList bialko = String_na_Lista(query.value("bialko").toString());
        zmien_checkboxy(index[2], bialko);

        QStringList baza = String_na_Lista(query.value("baza").toString());
        zmien_checkboxy(index[3], baza);

        QStringList warzywa = String_na_Lista(query.value("warzywa").toString());
        zmien_checkboxy(index[4], warzywa);

        QStringList owoce = String_na_Lista(query.value("owoce").toString());
        zmien_checkboxy(index[5], owoce);

        QStringList nabial = String_na_Lista(query.value("nabial").toString());
        zmien_checkboxy(index[6], nabial);

        QStringList przyprawy = String_na_Lista(query.value("przyprawy").toString());
        zmien_checkboxy(index[7], przyprawy);

        QString dodatkowe_string = query.value("dodatkowe").toString();
        QStringList dodatek = dodatkowe_string.split(";");

        for (int i=0;i<dodatek.size();++i){
            qDebug()<<"Lista dodatkowe"<<dodatek[i];
            dodatkowe(dodatek[i], 1);

        }
    }


    qDebug() << "Dane zostały wczytane!";
    baza_przepisy.close();
    qDebug() << "Baza zamknięta!";



}

QStringList Dialog::String_na_Lista(QString index){
    QStringList wynik;

    for (QChar c : index)
    {
        wynik.append(QString(c));

    }
    return wynik;
}
//dla edycji ->
void Dialog::zmien_checkboxy(QString index, QStringList rodzaj)
{
    QStringList dane_listy;
    QList<int> idxLista;
    if (index=="rodzaj"){
        dane_listy = lista_rodzaj;
    }else if(index=="inne"){
        dane_listy = lista_inne;
    }else if(index=="bialko"){
        dane_listy = lista_bialko;
    }else if(index=="baza"){
        dane_listy = lista_baza;
    }else if(index=="warzywa"){
        dane_listy = lista_warzywa;
    }else if(index=="owoce"){
        dane_listy = lista_owoce;
    }else if(index=="nabial"){
        dane_listy = lista_nabial;
    }else if(index=="przyprawy"){
        dane_listy = lista_przyprawy;
    }

    for (int i=0;i<rodzaj.size();++i){
        if (rodzaj[i]=="1")
        {
            idxLista.append(i);
        }
    }

    for(int i=0;i<idxLista.size();++i){
        QString nazwa = dane_listy[idxLista[i]];
        qDebug()<<"NAZWA!!"<<nazwa;
        if (checkBoxMap.contains(nazwa)) {
            QCheckBox* checkbox = checkBoxMap.value(nazwa); // Pobierz checkbox na podstawie klucza
            if (checkbox) {
                checkbox->toggle(); // Zmień stan checkboxa
                qDebug() << "Zmieniono stan checkboxa:" << nazwa;
            }
        } else {
            qDebug() << "Nie znaleziono checkboxa o nazwie:" << nazwa;
        }

    }

    //qDebug() << "Klucze w checkBoxMap: " << checkBoxMap.keys();
}
