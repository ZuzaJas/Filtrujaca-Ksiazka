#include "mainwindow.h"
#include <QPixmap>

#include "./ui_mainwindow.h"
#include "dodaj.h"

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

