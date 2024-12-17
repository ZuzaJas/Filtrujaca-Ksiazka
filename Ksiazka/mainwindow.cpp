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

QStringList lista_skladniki = {
    "wolowe","ryba","jajko","kurczak",
    "makaron", "ryz", "pieczywo", "maka",
    "marchew", "cebula","ogorek", "papryka", "pomidor", "ziemniak",
    "banan","cytryna","jablko","malina","pomarancza","truskawka",
    "mleko", "ser","smietana", "jogurt",
    "cynamon","tymianek","galka_muszkatowa","kminek"
};
QList<int> index_skladniki(lista_skladniki.size(), 0);


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
    //SQL
    QSqlDatabase baza = QSqlDatabase::addDatabase("QSQLITE");
    baza.setDatabaseName("C:\\test.db");
    if(baza.open())
        ui->label_2->setText("[+] POŁĄCZONO ");
    else
        ui->label_2->setText("[-] NIE POŁĄCZONO Z BAZĄ DANYCH");

//---------------GUZIKI---------------------------------------------------------------------------------------------------------------------------------

    //wolowe
    QPushButton *wolowe = new QPushButton("Wołowe", this);
    wolowe->setGeometry(520, 60, 80, 20);
    connect(wolowe, &QPushButton::clicked, this, &MainWindow::skladnik_clicked);
    wolowe->setObjectName("wolowe");

    //ryba
    QPushButton *ryba = new QPushButton("Ryba", this);
    ryba->setGeometry(650, 60, 80, 20);
    connect(ryba, &QPushButton::clicked, this, &MainWindow::skladnik_clicked);
    ryba->setObjectName("ryba");

    //jajko
    QPushButton *jajko = new QPushButton("Jajko", this);
    jajko->setGeometry(770, 60, 80, 20);
    connect(jajko, &QPushButton::clicked, this, &MainWindow::skladnik_clicked);
    jajko->setObjectName("jajko");

    //kurczak
    QPushButton *kurczak = new QPushButton("Kurczak", this);
    kurczak->setGeometry(900, 60, 80, 20);
    connect(kurczak, &QPushButton::clicked, this, &MainWindow::skladnik_clicked);
    kurczak->setObjectName("kurczak");

    //makaron
    QPushButton *makaron = new QPushButton("Makaron", this);
    makaron->setGeometry(520, 160, 80, 20);
    connect(makaron, &QPushButton::clicked, this, &MainWindow::skladnik_clicked);
    makaron->setObjectName("makaron");

    //ryz
    QPushButton *ryz = new QPushButton("Ryż", this);
    ryz->setGeometry(650, 160, 80, 20);
    connect(ryz, &QPushButton::clicked, this, &MainWindow::skladnik_clicked);
    ryz->setObjectName("ryz");

    //pieczywo
    QPushButton *pieczywo = new QPushButton("Pieczywo", this);
    pieczywo->setGeometry(770, 160, 80, 20);
    connect(pieczywo, &QPushButton::clicked, this, &MainWindow::skladnik_clicked);
    pieczywo->setObjectName("pieczywo");

    //mąka
    QPushButton *maka = new QPushButton("Mąka", this);
    maka->setGeometry(900, 160, 80, 20);
    connect(maka, &QPushButton::clicked, this, &MainWindow::skladnik_clicked);
    maka->setObjectName("maka");

    //marchew
    QPushButton *marchew = new QPushButton("Marchew", this);
    marchew->setGeometry(520, 260, 80, 20);
    connect(marchew, &QPushButton::clicked, this, &MainWindow::skladnik_clicked);
    marchew->setObjectName("marchew");

    //cebula
    QPushButton *cebula = new QPushButton("Cebula", this);
    cebula->setGeometry(710, 260, 80, 20);
    connect(cebula, &QPushButton::clicked, this, &MainWindow::skladnik_clicked);
    cebula->setObjectName("cebula");

    //ogorek
    QPushButton *ogorek = new QPushButton("Ogorek", this);
    ogorek->setGeometry(900, 260, 80, 20);
    connect(ogorek, &QPushButton::clicked, this, &MainWindow::skladnik_clicked);
    ogorek->setObjectName("ogorek");

    //papryka
    QPushButton *papryka = new QPushButton("Papryka", this);
    papryka->setGeometry(520, 290, 80, 20);
    connect(papryka, &QPushButton::clicked, this, &MainWindow::skladnik_clicked);
    papryka->setObjectName("papryka");

    //pomidor
    QPushButton *pomidor = new QPushButton("Pomidor", this);
    pomidor->setGeometry(710, 290, 80, 20);
    connect(pomidor, &QPushButton::clicked, this, &MainWindow::skladnik_clicked);
    pomidor->setObjectName("pomidor");

    //ziemniak
    QPushButton *ziemniak = new QPushButton("Ziemniak", this);
    ziemniak->setGeometry(900, 290, 80, 20);
    connect(ziemniak, &QPushButton::clicked, this, &MainWindow::skladnik_clicked);
    ziemniak->setObjectName("ziemniak");

    //banan
    QPushButton *banan = new QPushButton("Banan", this);
    banan->setGeometry(520, 370, 80, 20);
    connect(banan, &QPushButton::clicked, this, &MainWindow::skladnik_clicked);
    banan->setObjectName("banan");

    //cytryna
    QPushButton *cytryna = new QPushButton("Cytryna", this);
    cytryna->setGeometry(710, 370, 80, 20);
    connect(cytryna, &QPushButton::clicked, this, &MainWindow::skladnik_clicked);
    cytryna->setObjectName("cytryna");

    //jablko
    QPushButton *jablko = new QPushButton("Jablko", this);
    jablko->setGeometry(900, 370, 80, 20);
    connect(jablko, &QPushButton::clicked, this, &MainWindow::skladnik_clicked);
    jablko->setObjectName("jablko");

    //malina
    QPushButton *malina = new QPushButton("Malina", this);
    malina->setGeometry(520, 400, 80, 20);
    connect(malina, &QPushButton::clicked, this, &MainWindow::skladnik_clicked);
    malina->setObjectName("malina");

    //pomarancza
    QPushButton *pomarancza = new QPushButton("Pomarancza", this);
    pomarancza->setGeometry(710, 400, 80, 20);
    connect(pomarancza, &QPushButton::clicked, this, &MainWindow::skladnik_clicked);
    pomarancza->setObjectName("pomarancza");

    //truskawka
    QPushButton *truskawka = new QPushButton("Truskawka", this);
    truskawka->setGeometry(900, 400, 80, 20);
    connect(truskawka, &QPushButton::clicked, this, &MainWindow::skladnik_clicked);
    truskawka->setObjectName("truskawka");


    //mleko
    QPushButton *mleko = new QPushButton("Mleko", this);
    mleko->setGeometry(520, 520, 80, 20);
    connect(mleko, &QPushButton::clicked, this, &MainWindow::skladnik_clicked);
    mleko->setObjectName("mleko");

    //ser
    QPushButton *ser = new QPushButton("Ser", this);
    ser->setGeometry(650, 520, 80, 20);
    connect(ser, &QPushButton::clicked, this, &MainWindow::skladnik_clicked);
    ser->setObjectName("ser");

    //smietana
    QPushButton *smietana = new QPushButton("Śmietana", this);
    smietana->setGeometry(770, 520, 80, 20);
    connect(smietana, &QPushButton::clicked, this, &MainWindow::skladnik_clicked);
    smietana->setObjectName("smietana");

    //jogurt
    QPushButton *jogurt = new QPushButton("Jogurt", this);
    jogurt->setGeometry(900, 520, 80, 20);
    connect(jogurt, &QPushButton::clicked, this, &MainWindow::skladnik_clicked);
    jogurt->setObjectName("jogurt");

    //cynamon
    QPushButton *cynamon = new QPushButton("Cynamon", this);
    cynamon->setGeometry(520, 670, 80, 20);
    connect(cynamon, &QPushButton::clicked, this, &MainWindow::skladnik_clicked);
    cynamon->setObjectName("cynamon");

    //tymianek
    QPushButton *tymianek = new QPushButton("Tymianek", this);
    tymianek->setGeometry(650, 670, 80, 20);
    connect(tymianek, &QPushButton::clicked, this, &MainWindow::skladnik_clicked);
    tymianek->setObjectName("tymianek");

    //galka_muszkatowa
    QPushButton *galka_muszkatowa = new QPushButton("Gałka Muszk.", this);
    galka_muszkatowa->setGeometry(770, 670, 80, 20);
    connect(galka_muszkatowa, &QPushButton::clicked, this, &MainWindow::skladnik_clicked);
    galka_muszkatowa->setObjectName("galka_muszkatowa");

    //kminek
    QPushButton *kminek = new QPushButton("Kminek", this);
    kminek->setGeometry(900, 670, 80, 20);
    connect(kminek, &QPushButton::clicked, this, &MainWindow::skladnik_clicked);
    kminek->setObjectName("kminek");

//------------------------------------------------------------------------------------------------------------------------------------------------------


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


void MainWindow::skladnik_clicked()
{
    QPushButton *button = qobject_cast<QPushButton *>(sender());
    QString wyraz_id = button->objectName();
    int index = lista_skladniki.indexOf(wyraz_id);
    if (button) {
        if (index != -1) {
            if(index_skladniki[index] == 1)
            {
                index_skladniki[index] = 0;
                button->setStyleSheet("color: black;");
            }else{
                index_skladniki[index] = 1;
                button->setStyleSheet("color: rgb(50, 205, 50);");
            }
            qDebug() << "Index List:" << index_skladniki[index];

        } else {
            qDebug() << "Nie znaleziono";
        }
        qDebug() << "Index:" << index;


    }
}




