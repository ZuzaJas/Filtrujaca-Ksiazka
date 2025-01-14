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



    QPushButton *szukaj = new QPushButton("SZUKAJ", this);
    szukaj->setGeometry(900, 720, 80, 20);
    connect(szukaj, &QPushButton::clicked, this, &MainWindow::wyszukaj_clicked);
    szukaj->setObjectName("Szukaj");

    QPushButton *dodaj = new QPushButton("DODAJ", this);
    dodaj->setGeometry(520, 720, 80, 20);
    connect(dodaj, &QPushButton::clicked, this, &MainWindow::nowe_okno_clicked);
    dodaj->setObjectName("DODAJ");



}





MainWindow::~MainWindow()
{
    delete ui;

}



void MainWindow::nowe_okno_clicked()
{
    close();
    Dialog okno("dodaj");
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


        button->setGeometry(xPos, yPos, 80, 20);
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


