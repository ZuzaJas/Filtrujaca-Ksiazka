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

Dialog::Dialog(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::Dialog)
    , nazwa(new QLineEdit(this))
    , opis(new QTextEdit(this))
    , rodzaj(new QComboBox(this))
    , inne(new QComboBox(this))
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
    rodzaj->addItems(lista_rodzaj);
    label_rodzaj->setText("RODZAJ DANIA");

    label_skladniki->setText("SKŁADNIKI");


    QStringList lista_inne = {"wegetariańskie", "ostre"};
    inne->addItems(lista_inne);
    label_inne->setText("INNE");

    dodatkowe_skladniki->setPlaceholderText("Wprowadź jednowierszowy tekst...");
    label_dodatkowe_skladniki->setText("DODATKOWE SKLADNIKI");

    opis->setPlaceholderText("Wprowadź wielowierszowy opis...");
    label_opis->setText("PRZYGOTOWANIE PRZEPISU");

    setLayout(nullptr);


    nazwa->setFixedSize(450,30);  // szerokość, wysok
    nazwa->setStyleSheet("border: 2px solid black; border-radius: 5px;");
    nazwa->move(10,60); //x, y

    label_nazwa->setFixedSize(450, 10);
    label_nazwa->move(10,40);

    rodzaj->setFixedSize(450,30);
    rodzaj->move(10,120);

    label_rodzaj->setFixedSize(450, 10);
    label_rodzaj->move(10,100);

    inne->setFixedSize(450,30);
    inne->move(10,180);

    label_inne->setFixedSize(450, 10);
    label_inne->move(10,160);
\
    label_skladniki->setFixedSize(450, 10);
    label_skladniki->move(10,220);


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

