#include "dodaj.h"
#include "ui_dodaj.h"
#include "mainwindow.h"


Dialog::Dialog(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::Dialog)
{
    ui->setupUi(this);
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

