#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include "dodaj.h"

#include <QPixmap>
#include <QCoreApplication>
#include <QDebug>
#include <QFile>
#include <QTextStream>

//zmienne MainWindow
bool marchew = false;
bool cynamon = false;
bool cebula = false;
bool banan = false;
bool cytryna = false;
bool jablko = false;
bool jajko = false;

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



void MainWindow::on_nowe_okno_clicked()
{
    Dialog okno;
    okno.setModal(true);
    okno.exec();

}

//KLIKNIĘCIE GUZIKÓW SKŁADNIKI----------------------------------------------------------------

void MainWindow::on_marchew_clicked()
{
    if (marchew==true){
        marchew = false;
    }else{
         marchew = true;
    }
    printMessage(QString::number(marchew));
}

void MainWindow::on_banan_clicked()
{
    if (banan==true){
        banan = false;
    }else{
        banan = true;
    }
    printMessage(QString::number(banan));
}

void MainWindow::on_cebula_clicked()
{
    if (cebula==true){
        cebula = false;
    }else{
        cebula = true;
    }
    printMessage(QString::number(cebula));
}

void MainWindow::on_cynamon_clicked()
{
    if (cynamon==true){
        cynamon = false;
    }else{
        cynamon = true;
    }
    printMessage(QString::number(cynamon));
}

void MainWindow::on_cytryna_clicked()
{
    if (cytryna==true){
        cytryna = false;
    }else{
        cytryna = true;
    }
    printMessage(QString::number(cytryna));
}

void MainWindow::on_jablko_clicked()
{
    if (jablko==true){
        jablko = false;
    }else{
        jablko = true;
    }
    printMessage(QString::number(jablko));
}

void MainWindow::on_jajko_clicked()
{
    if (jajko==true){
        jajko = false;
    }else{
        jajko = true;
    }
    printMessage(QString::number(jajko));
}

void MainWindow::on_kurczak_clicked()
{
    if (jajko==true){
        jajko = false;
    }else{
        jajko = true;
    }
    printMessage(QString::number(jajko));
}

void MainWindow::on_makaron_clicked()
{
    if (jajko==true){
        jajko = false;
    }else{
        jajko = true;
    }
    printMessage(QString::number(jajko));
}

void MainWindow::on_malina_clicked()
{
    if (jajko==true){
        jajko = false;
    }else{
        jajko = true;
    }
    printMessage(QString::number(jajko));
}

void MainWindow::on_mleko_clicked()
{
    if (jajko==true){
        jajko = false;
    }else{
        jajko = true;
    }
    printMessage(QString::number(jajko));
}

void MainWindow::on_ogorek_clicked()
{
    if (jajko==true){
        jajko = false;
    }else{
        jajko = true;
    }
    printMessage(QString::number(jajko));
}

void MainWindow::on_papryka_clicked()
{
    if (jajko==true){
        jajko = false;
    }else{
        jajko = true;
    }
    printMessage(QString::number(jajko));
}

void MainWindow::on_jajko_clicked()
{
    if (jajko==true){
        jajko = false;
    }else{
        jajko = true;
    }
    printMessage(QString::number(jajko));
}

void MainWindow::on_jajko_clicked()
{
    if (jajko==true){
        jajko = false;
    }else{
        jajko = true;
    }
    printMessage(QString::number(jajko));
}

void MainWindow::on_jajko_clicked()
{
    if (jajko==true){
        jajko = false;
    }else{
        jajko = true;
    }
    printMessage(QString::number(jajko));
}

void MainWindow::on_jajko_clicked()
{
    if (jajko==true){
        jajko = false;
    }else{
        jajko = true;
    }
    printMessage(QString::number(jajko));
}

void MainWindow::on_jajko_clicked()
{
    if (jajko==true){
        jajko = false;
    }else{
        jajko = true;
    }
    printMessage(QString::number(jajko));
}

void MainWindow::on_jajko_clicked()
{
    if (jajko==true){
        jajko = false;
    }else{
        jajko = true;
    }
    printMessage(QString::number(jajko));
}
