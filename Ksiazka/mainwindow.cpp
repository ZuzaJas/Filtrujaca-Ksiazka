#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include "dodaj.h"
#include "wyszukiwanie.h"


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



//zmienne skladniki
///







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


    stworz_guzik(lista_bialko, Widx_bialko, 520, 60);

    stworze_guzik(lista_baza, Widx_baza, 520, 160);

    //marchew
    QPushButton *marchew = new QPushButton("Marchew", this);
    marchew->setGeometry(520, 260, 80, 20);
    connect(marchew, &QPushButton::clicked, this, [this]() {
        skladnik_clicked(lista_warzywa, Widx_warzywa);
    });
    marchew->setObjectName("marchew");

    //cebula
    QPushButton *cebula = new QPushButton("Cebula", this);
    cebula->setGeometry(710, 260, 80, 20);
    connect(cebula, &QPushButton::clicked, this, [this]() {
        skladnik_clicked(lista_warzywa, Widx_warzywa);
    });
    cebula->setObjectName("cebula");

    //ogorek
    QPushButton *ogorek = new QPushButton("Ogorek", this);
    ogorek->setGeometry(900, 260, 80, 20);
    connect(ogorek, &QPushButton::clicked, this, [this]() {
        skladnik_clicked(lista_warzywa, Widx_warzywa);
    });
    ogorek->setObjectName("ogorek");

    //papryka
    QPushButton *papryka = new QPushButton("Papryka", this);
    papryka->setGeometry(520, 290, 80, 20);
    connect(papryka, &QPushButton::clicked, this, [this]() {
        skladnik_clicked(lista_warzywa, Widx_warzywa);
    });
    papryka->setObjectName("papryka");

    //pomidor
    QPushButton *pomidor = new QPushButton("Pomidor", this);
    pomidor->setGeometry(710, 290, 80, 20);
    connect(pomidor, &QPushButton::clicked, this, [this]() {
        skladnik_clicked(lista_warzywa, Widx_warzywa);
    });
    pomidor->setObjectName("pomidor");

    //ziemniak
    QPushButton *ziemniak = new QPushButton("Ziemniak", this);
    ziemniak->setGeometry(900, 290, 80, 20);
    connect(ziemniak, &QPushButton::clicked, this, [this]() {
        skladnik_clicked(lista_warzywa, Widx_warzywa);
    });
    ziemniak->setObjectName("ziemniak");

    //banan
    QPushButton *banan = new QPushButton("Banan", this);
    banan->setGeometry(520, 370, 80, 20);
    connect(banan, &QPushButton::clicked, this, [this]() {
        skladnik_clicked(lista_owoce, Widx_owoce);
    });
    banan->setObjectName("banan");

    //cytryna
    QPushButton *cytryna = new QPushButton("Cytryna", this);
    cytryna->setGeometry(710, 370, 80, 20);
    connect(cytryna, &QPushButton::clicked, this, [this]() {
        skladnik_clicked(lista_owoce, Widx_owoce);
    });
    cytryna->setObjectName("cytryna");

    //jablko
    QPushButton *jablko = new QPushButton("Jablko", this);
    jablko->setGeometry(900, 370, 80, 20);
    connect(jablko, &QPushButton::clicked, this, [this]() {
        skladnik_clicked(lista_owoce, Widx_owoce);
    });
    jablko->setObjectName("jablko");

    //malina
    QPushButton *malina = new QPushButton("Malina", this);
    malina->setGeometry(520, 400, 80, 20);
    connect(malina, &QPushButton::clicked, this, [this]() {
        skladnik_clicked(lista_owoce, Widx_owoce);
    });
    malina->setObjectName("malina");

    //pomarancza
    QPushButton *pomarancza = new QPushButton("Pomarancza", this);
    pomarancza->setGeometry(710, 400, 80, 20);
    connect(pomarancza, &QPushButton::clicked, this, [this]() {
        skladnik_clicked(lista_owoce, Widx_owoce);
    });
    pomarancza->setObjectName("pomarancza");

    //truskawka
    QPushButton *truskawka = new QPushButton("Truskawka", this);
    truskawka->setGeometry(900, 400, 80, 20);
    connect(truskawka, &QPushButton::clicked, this, [this]() {
        skladnik_clicked(lista_owoce, Widx_owoce);
    });
    truskawka->setObjectName("truskawka");


    //mleko
    QPushButton *mleko = new QPushButton("Mleko", this);
    mleko->setGeometry(520, 520, 80, 20);
    connect(mleko, &QPushButton::clicked, this, [this]() {
        skladnik_clicked(lista_nabial, Widx_nabial);
    });
    mleko->setObjectName("mleko");

    //ser
    QPushButton *ser = new QPushButton("Ser", this);
    ser->setGeometry(650, 520, 80, 20);
    connect(ser, &QPushButton::clicked, this, [this]() {
        skladnik_clicked(lista_nabial, Widx_nabial);
    });
    ser->setObjectName("ser");

    //smietana
    QPushButton *smietana = new QPushButton("Śmietana", this);
    smietana->setGeometry(770, 520, 80, 20);
    connect(smietana, &QPushButton::clicked, this, [this]() {
        skladnik_clicked(lista_nabial, Widx_nabial);
    });
    smietana->setObjectName("smietana");

    //jogurt
    QPushButton *jogurt = new QPushButton("Jogurt", this);
    jogurt->setGeometry(900, 520, 80, 20);
    connect(jogurt, &QPushButton::clicked, this, [this]() {
        skladnik_clicked(lista_nabial, Widx_nabial);
    });
    jogurt->setObjectName("jogurt");

    //cynamon
    QPushButton *cynamon = new QPushButton("Cynamon", this);
    cynamon->setGeometry(520, 620, 80, 20);
    connect(cynamon, &QPushButton::clicked, this, [this]() {
        skladnik_clicked(lista_przyprawy, Widx_przyprawy);
    });
    cynamon->setObjectName("cynamon");

    //tymianek
    QPushButton *tymianek = new QPushButton("Tymianek", this);
    tymianek->setGeometry(650, 620, 80, 20);
    connect(tymianek, &QPushButton::clicked, this, [this]() {
        skladnik_clicked(lista_przyprawy, Widx_przyprawy);
    });
    tymianek->setObjectName("tymianek");

    //galka_muszkatowa
    QPushButton *galka_muszkatowa = new QPushButton("Gałka Muszk.", this);
    galka_muszkatowa->setGeometry(770, 620, 80, 20);
    connect(galka_muszkatowa, &QPushButton::clicked, this, [this]() {
        skladnik_clicked(lista_przyprawy, Widx_przyprawy);
    });
    galka_muszkatowa->setObjectName("galka_muszkatowa");

    //kminek
    QPushButton *kminek = new QPushButton("Kminek", this);
    kminek->setGeometry(900, 620, 80, 20);
    connect(kminek, &QPushButton::clicked, this, [this]() {
        skladnik_clicked(lista_przyprawy, Widx_przyprawy);
    });
    kminek->setObjectName("kminek");


//------------------------------------------------------------------------------------------------------------------------------------------------------

    QCheckBox *sniadaniowe = new QCheckBox("Śniadaniowe", this);
    sniadaniowe->setGeometry(20, 160, 150, 20);
    connect(sniadaniowe, &QCheckBox::toggled, this, [this]() {
        skladnik_clicked_2(lista_rodzaje, Widx_rodzaj);
    });
    sniadaniowe->setObjectName("sniadaniowe");

    QCheckBox *lunch = new QCheckBox("Lunch", this);
    lunch->setGeometry(210, 160, 150, 20);
    connect(lunch, &QCheckBox::toggled, this, [this]() {
        skladnik_clicked_2(lista_rodzaje, Widx_rodzaj);
    });
    lunch->setObjectName("lunch");

    QCheckBox *obiadowe = new QCheckBox("Obiadowe", this);
    obiadowe->setGeometry(400, 160, 150, 20);
    connect(obiadowe, &QCheckBox::toggled, this, [this]() {
        skladnik_clicked_2(lista_rodzaje, Widx_rodzaj);
    });
    obiadowe->setObjectName("obiadowe");

    QCheckBox *napoje = new QCheckBox("Napoje", this);
    napoje->setGeometry(20, 180, 150, 20);
    connect(napoje, &QCheckBox::toggled, this, [this]() {
        skladnik_clicked_2(lista_rodzaje, Widx_rodzaj);
    });
    napoje->setObjectName("napoje");

    QCheckBox *desery = new QCheckBox("Desery", this);
    desery->setGeometry(210, 180, 150, 20);
    connect(desery, &QCheckBox::toggled, this, [this]() {
        skladnik_clicked_2(lista_rodzaje, Widx_rodzaj);
    });
    desery->setObjectName("desery");

    QCheckBox *sosy = new QCheckBox("Sosy i dodatki", this);
    sosy->setGeometry(400, 180, 150, 20);
    connect(sosy, &QCheckBox::toggled, this, [this]() {
        skladnik_clicked_2(lista_rodzaje, Widx_rodzaj);
    });
    sosy->setObjectName("sosy i dodatki");

    QCheckBox *wege = new QCheckBox("Wegetariańskie", this);
    wege->setGeometry(20, 260, 150, 20);
    connect(wege, &QCheckBox::toggled, this, [this]() {
        skladnik_clicked_2(lista_inne, Widx_inne);
    });
    wege->setObjectName("wegetarianskie");

    QCheckBox *ostre = new QCheckBox("Ostre", this);
    ostre->setGeometry(400, 260, 150, 20);
    connect(ostre, &QCheckBox::toggled, this, [this]() {
        skladnik_clicked_2(lista_inne, Widx_inne);
    });
    ostre->setObjectName("ostre");



    QPushButton *szukaj = new QPushButton("szukaj", this);
    szukaj->setGeometry(900, 720, 80, 20);
    connect(szukaj, &QPushButton::clicked, this, &MainWindow::wyszukaj_clicked);
    szukaj->setObjectName("Szukaj");

    //nowe okna
    connect(ui->okno_dodaj, &QPushButton::clicked, this, &MainWindow::nowe_okno_clicked);

    //listWidget = new QListWidget(this);

    // Dodanie przykładowych elementów do listy
    //for (int i = 1; i <= 100; i++) {
     //   listWidget->addItem("Element " + QString::number(i));
    //}

    // Ustawienie początkowej geometrii listy i dodanie jej do głównego okna
    //listWidget->setGeometry(10, 10, 200, 300);
    //listWidget->setHorizontalScrollMode(QAbstractItemView::ScrollPerItem);

    // Tworzenie suwaka (QSlider) do sterowania przewijaniem listy
    //slider = new QSlider(Qt::Horizontal, this);
    //slider->setGeometry(220, 10, 30, 300);
    //->setRange(0, listWidget->count() - 1); // zakres odpowiada liczbie elementów na liście

    // Łączenie suwaka z listą, aby przewijać do wybranego elementu
    //connect(slider, &QSlider::valueChanged, this, [this](int value) {
    //    listWidget->scrollToItem(listWidget->item(value));
    //});



}





MainWindow::~MainWindow()
{
    delete ui;

}



void MainWindow::nowe_okno_clicked()
{
    close();
    Dialog okno;
    okno.setModal(true);
    okno.exec();


}


void MainWindow::wyszukaj_clicked() {
    close(); // Zamykamy MainWindow

    // Tworzymy dialog wyszukiwania i przekazujemy dane
    wyszukiwanie dialog(idx_rodzaj,idx_inne,idx_bialko,idx_nabial,idx_baza,idx_warzywa,idx_owoce,idx_przyprawy ,this);

    // Ustawiamy modalność i uruchamiamy dialog
    dialog.setModal(true);
    dialog.exec();
}


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

void MainWindow::skladnik_clicked_2(QStringList skladniki_lista, QList<int> *idx_lista)
{
    QCheckBox *button = qobject_cast<QCheckBox *>(sender());
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

void MainWindow::stworz_guzik(QStringList nazwa, QList<int> *index, float x, float y) {
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
        float yPos = y + rzad * rzadOffset;
        qDebug()<<"float pos x"<<kolumna * kolumnaOffset;


        button->setGeometry(xPos, yPos, 80, 20);
        button->setObjectName(nazwa[i]);
        qDebug()<<"Guzik ["<<nazwa[i]<<"] Pozycja["<<xPos<<","<<yPos<<"]";

        // Obsługa zdarzenia
        connect(button, &QPushButton::clicked, this, [this, nazwa, index] {
            skladnik_clicked(nazwa, index);
        });
    }
}


