#include "dodaj.h"
#include "ui_dodaj.h"
#include "mainwindow.h"

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

QList<int> sql_rodzaj = {0, 0, 0, 0, 0,0};
QList<int> *wsk_sql_rodzaj = &sql_rodzaj;

QList<int> sql_inne = {0, 0};
QList<int> *wsk_sql_inne = &sql_inne;

QList<int> sql_skl_nabial = {0, 0, 0, 0};
QList<int> *wsk_sql_skl_nabial = &sql_skl_nabial;
QList<int> sql_skl_baza = {0, 0, 0, 0};
QList<int> *wsk_sql_skl_baza = &sql_skl_baza;
QList<int> sql_skl_warzywa = {0, 0, 0, 0, 0, 0};
QList<int> *wsk_sql_inne = &sql_inne;
QList<int> sql_skl_owoce = {0, 0, 0, 0, 0, 0};
QList<int> *wsk_sql_inne = &sql_inne;
QList<int> sql_skl_nabial = {0, 0, 0, 0};
QList<int> *wsk_sql_inne = &sql_inne;
QList<int> sql_skl_przyprawy = {0, 0, 0, 0};
QList<int> *wsk_sql_inne = &sql_inne;


Dialog::Dialog(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::Dialog)
    , nazwa(new QLineEdit(this))
    , opis(new QTextEdit(this))
    , dodatkowe_skladniki(new QLineEdit(this))
    , label_opis(new QLabel(this))
    , label_nazwa(new QLabel(this))
    , label_rodzaj(new QLabel(this))
    , label_inne(new QLabel(this))
    , label_skladniki(new QLabel(this))
    , label_dodatkowe_skladniki(new QLabel(this))
{
    ui->setupUi(this);

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
    label_skladniki->setFixedSize(450, 10);
    label_skladniki->move(10,250);
    stworz_checkbox(lista_nabial, wsk_sql_inne, 10,220);

    dodatkowe_skladniki->setFixedSize(350,30);
    dodatkowe_skladniki->setStyleSheet("border: 2px solid black; border-radius: 5px;");
    dodatkowe_skladniki->move(10,540);

    label_dodatkowe_skladniki->setFixedSize(450, 10);
    label_dodatkowe_skladniki->move(10,520);

    opis->setFixedSize(450,650);
    opis->move(520,60);

    label_opis->setFixedSize(450, 10);
    label_opis->move(520, 40);

    ui->powrot->setFixedSize(80,24);
    ui->powrot->move(890,740);

    resize(1000, 800);

    connect(ui->powrot, &QPushButton::clicked, this, &Dialog::close_window);
}


Dialog::~Dialog()
{
    delete ui;
}

void Dialog::close_window()
{
    close(); // Zamykamy bieżące okno dialogowe

    MainWindow *okno = new MainWindow(); // Tworzymy nowe okno główne
    okno->show(); // Pokazujemy okno główne
}



//zrobić wszystko na checkboxy
void Dialog::stworz_checkbox(QStringList nazwa, QList<int> *index, float x, float y) {

    int podzial;
    if((nazwa.size())>4){
        podzial = qFloor(nazwa.size()/2);
    }else{
        podzial = 0;
    }

    //qDebug() << "Nazwa" << nazwa.size();
    for (int i = 0; i < nazwa.size(); ++i) {
        qDebug() << "Tworzenie checkboxa: " << nazwa[i];
        QCheckBox *checkBox = new QCheckBox(nazwa[i], this);
        if (i<=podzial){
            float xOffset = ((800/2)-x)/(qFloor(nazwa.size()/2));
            //qDebug() << "Floor" << qFloor(nazwa.size()/2);
            checkBox->setGeometry(x + i * xOffset, y, 150, 20);
            qDebug() << "Pozycja x:" << (x + i * xOffset) << "  Pozycja y:" << y;
        }else if(podzial==0){
            float xOffset = ((800/2)-x)/qCeil(nazwa.size()/2);
            //qDebug() << "Ceil" << qCeil(nazwa.size()/2);
            checkBox->setGeometry((x + i * xOffset), y, 150, 20);
            qDebug() << "Pozycja x:" << (x + i * xOffset) << "  Pozycja y:" << y+30;
        }else{
            float xOffset = ((800/2)-x)/(qFloor(nazwa.size()/2));
            //qDebug() << "Ceil" << qCeil(nazwa.size()/2);
            checkBox->setGeometry(x + ((i-1)%qCeil(nazwa.size()/2)) * xOffset, y+30, 150, 20);
            qDebug() << "Pozycja x:" << x + ((i-1)%qCeil(nazwa.size()/2))*xOffset << "  Pozycja y:" << y+30;
        }
        connect(checkBox, &QCheckBox::toggled, this, [this, i, index]
        {
            if (i < index->size()) {
                qDebug() << "Checkbox toggled: indeks" << i;
                (*index)[i] = checkTrue((*index)[i]);  // Poprawione użycie wskaźnika
                qDebug() << "Nowa wartość indeksu" << i << ":" << (*index)[i];
            } else {
                qDebug() << "Błąd: Indeks poza zakresem!";
                qDebug() << "Rozmiar rodzaj przed iteracją:" << index->size();
            }
        });


    }
}



int Dialog::checkTrue(int value) {
    return value == 0 ? 1 : 0;
}





