#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include "dodaj.h"

#include <QPixmap>
#include <QCoreApplication>
#include <QDebug>
#include <QFile>
#include <QTextStream>

//zmienne skladniki
///
bool wolowe = false;
bool ryba = false;
bool jajko = false;
bool kurczak = false;
///
bool makaron = false;
bool ryz = false;
bool pieczywo = false;
///
bool marchew = false;
bool cebula = false;
bool ogorek = false;
bool papryka = false;
bool pomidor = false;
bool ziemniak = false;
///
bool banan = false;
bool cytryna = false;
bool jablko = false;
bool malina = false;
bool pomarancza = false;
bool truskawka = false;
///
bool jogurt = false;
bool mleko = false;
bool ser = false;
bool smietana = false;
///
bool cynamon = false;
bool tymianek = false;
bool galka_muszkatowa = false;
bool kminek = false;

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
    //guziki skladniki
        ///
        connect(ui->wolowe, &QPushButton::clicked, this, &MainWindow::wolowe_clicked);
        connect(ui->ryba, &QPushButton::clicked, this, &MainWindow::ryba_clicked);
        connect(ui->jajko, &QPushButton::clicked, this, &MainWindow::jajko_clicked);
        connect(ui->kurczak, &QPushButton::clicked, this, &MainWindow::kurczak_clicked);
        ///
        connect(ui->makaron, &QPushButton::clicked, this, &MainWindow::makaron_clicked);
        connect(ui->ryz, &QPushButton::clicked, this, &MainWindow::ryz_clicked);
        connect(ui->pieczywo, &QPushButton::clicked, this, &MainWindow::pieczywo_clicked);
        ///
        connect(ui->marchew, &QPushButton::clicked, this, &MainWindow::marchew_clicked);
        connect(ui->cebula, &QPushButton::clicked, this, &MainWindow::cebula_clicked);
        connect(ui->ogorek, &QPushButton::clicked, this, &MainWindow::ogorek_clicked);
        connect(ui->papryka, &QPushButton::clicked, this, &MainWindow::papryka_clicked);
        connect(ui->pomidor, &QPushButton::clicked, this, &MainWindow::pomidor_clicked);
        connect(ui->ziemniak, &QPushButton::clicked, this, &MainWindow::ziemniak_clicked);
        ///
        connect(ui->banan, &QPushButton::clicked, this, &MainWindow::banan_clicked);
        connect(ui->cytryna, &QPushButton::clicked, this, &MainWindow::cytryna_clicked);
        connect(ui->jablko, &QPushButton::clicked, this, &MainWindow::jablko_clicked);
        connect(ui->malina, &QPushButton::clicked, this, &MainWindow::malina_clicked);
        connect(ui->pomarancza, &QPushButton::clicked, this, &MainWindow::pomarancza_clicked);
        connect(ui->truskawka, &QPushButton::clicked, this, &MainWindow::truskawka_clicked);
        ///
        connect(ui->jogurt, &QPushButton::clicked, this, &MainWindow::jogurt_clicked);
        connect(ui->mleko, &QPushButton::clicked, this, &MainWindow::mleko_clicked);
        connect(ui->ser, &QPushButton::clicked, this, &MainWindow::ser_clicked);
        connect(ui->smietana, &QPushButton::clicked, this, &MainWindow::smietana_clicked);
        ///
        connect(ui->cynamon, &QPushButton::clicked, this, &MainWindow::cynamon_clicked);
        connect(ui->tymianek, &QPushButton::clicked, this, &MainWindow::tymianek_clicked);
        connect(ui->galka_muszkatowa, &QPushButton::clicked, this, &MainWindow::galka_muszkatowa_clicked);
        connect(ui->kminek, &QPushButton::clicked, this, &MainWindow::kminek_clicked);

    //nowe okna
    connect(ui->nowe_okno, &QPushButton::clicked, this, &MainWindow::nowe_okno_clicked);

    QPixmap pix("C:\\Users\\48881\\Documents\\Ksiazka\\Filtrujaca-Ksiazka\\Ksiazka\\Lamb_Eat_Good.gif");
    ui->zdjecie->setPixmap(pix);
    listWidget = new QListWidget(this);

    // Dodanie przykładowych elementów do listy
    for (int i = 1; i <= 100; i++) {
        listWidget->addItem("Element " + QString::number(i));
    }

    // Ustawienie początkowej geometrii listy i dodanie jej do głównego okna
    listWidget->setGeometry(10, 10, 200, 300);
    listWidget->setHorizontalScrollMode(QAbstractItemView::ScrollPerItem);

    // Tworzenie suwaka (QSlider) do sterowania przewijaniem listy
    slider = new QSlider(Qt::Horizontal, this);
    slider->setGeometry(220, 10, 30, 300);
    slider->setRange(0, listWidget->count() - 1); // zakres odpowiada liczbie elementów na liście

    // Łączenie suwaka z listą, aby przewijać do wybranego elementu
    connect(slider, &QSlider::valueChanged, this, [this](int value) {
        listWidget->scrollToItem(listWidget->item(value));
    });


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

//KLIKNIĘCIE GUZIKÓW SKŁADNIKI----------------------------------------------------------------

void MainWindow::wolowe_clicked()
{
    if (wolowe==true){
        wolowe = false;
    }else{
        wolowe = true;
    }
    printMessage(QString::number(wolowe));
}

void MainWindow::ryba_clicked()
{
    if (ryba==true){
        ryba = false;
    }else{
        ryba = true;
    }
    printMessage(QString::number(ryba));
}

void MainWindow::jajko_clicked()
{
    if (jajko==true){
        jajko = false;
    }else{
        jajko = true;
    }
    printMessage(QString::number(jajko));
}

void MainWindow::kurczak_clicked()
{
    if (kurczak==true){
        kurczak = false;
    }else{
        kurczak = true;
    }
    printMessage(QString::number(kurczak));
}
///////

void MainWindow::makaron_clicked()
{
    if (makaron==true){
        makaron = false;
    }else{
        makaron = true;
    }
    printMessage(QString::number(makaron));
}

void MainWindow::ryz_clicked()
{
    if (ryz==true){
        ryz = false;
    }else{
        ryz = true;
    }
    printMessage(QString::number(ryz));
}

void MainWindow::pieczywo_clicked()
{
    if (pieczywo==true){
        pieczywo = false;
    }else{
        pieczywo = true;
    }
    printMessage(QString::number(pieczywo));
}
///////

void MainWindow::marchew_clicked()
{
    if (marchew==true){
        marchew = false;
    }else{
         marchew = true;
    }
    printMessage(QString::number(marchew));
}

void MainWindow::cebula_clicked()
{
    if (cebula==true){
        cebula = false;
    }else{
        cebula = true;
    }
    printMessage(QString::number(cebula));
}

void MainWindow::ogorek_clicked()
{
    if (ogorek==true){
        ogorek = false;
    }else{
        ogorek = true;
    }
    printMessage(QString::number(ogorek));
}

void MainWindow::papryka_clicked()
{
    if (papryka==true){
        papryka = false;
    }else{
        papryka = true;
    }
    printMessage(QString::number(papryka));
}

void MainWindow::pomidor_clicked()
{
    if (pomidor==true){
        pomidor = false;
    }else{
        pomidor = true;
    }
    printMessage(QString::number(pomidor));
}

void MainWindow::ziemniak_clicked()
{
    if (ziemniak==true){
        ziemniak = false;
    }else{
        ziemniak = true;
    }
    printMessage(QString::number(ziemniak));
}
///////

void MainWindow::banan_clicked()
{
    if (banan==true){
        banan = false;
    }else{
        banan = true;
    }
    printMessage(QString::number(banan));
}

void MainWindow::cytryna_clicked()
{
    if (cytryna==true){
        cytryna = false;
    }else{
        cytryna = true;
    }
    printMessage(QString::number(cytryna));
}

void MainWindow::jablko_clicked()
{
    if (jablko==true){
        jablko = false;
    }else{
        jablko = true;
    }
    printMessage(QString::number(jablko));
}

void MainWindow::malina_clicked()
{
    if (malina==true){
        malina = false;
    }else{
        malina = true;
    }
    printMessage(QString::number(malina));
}

void MainWindow::pomarancza_clicked()
{
    if (pomarancza==true){
        pomarancza = false;
    }else{
        pomarancza = true;
    }
    printMessage(QString::number(pomarancza));
}

void MainWindow::truskawka_clicked()
{
    if (truskawka==true){
        truskawka = false;
    }else{
        truskawka = true;
    }
    printMessage(QString::number(truskawka));
}
///////

void MainWindow::jogurt_clicked()
{
    if (jogurt==true){
        jogurt = false;
    }else{
        jogurt = true;
    }
    printMessage(QString::number(jogurt));
}

void MainWindow::mleko_clicked()
{
    if (mleko==true){
        mleko = false;
    }else{
        mleko = true;
    }
    printMessage(QString::number(mleko));
}

void MainWindow::ser_clicked()
{
    if (ser==true){
        ser = false;
    }else{
        ser = true;
    }
    printMessage(QString::number(ser));
}

void MainWindow::smietana_clicked()
{
    if (smietana==true){
        smietana = false;
    }else{
        smietana = true;
    }
    printMessage(QString::number(smietana));
}
///////

void MainWindow::cynamon_clicked()
{
    if (cynamon==true){
        cynamon = false;
    }else{
        cynamon = true;
    }
    printMessage(QString::number(cynamon));
}

void MainWindow::tymianek_clicked()
{
    if (tymianek==true){
        tymianek = false;
    }else{
        tymianek = true;
    }
    printMessage(QString::number(tymianek));
}

void MainWindow::galka_muszkatowa_clicked()
{
    if (galka_muszkatowa==true){
        galka_muszkatowa = false;
    }else{
        galka_muszkatowa = true;
    }
    printMessage(QString::number(galka_muszkatowa));
}

void MainWindow::kminek_clicked()
{
    if (kminek==true){
        kminek = false;
    }else{
        kminek = true;
    }
    printMessage(QString::number(kminek));
}
