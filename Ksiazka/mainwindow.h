#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QListWidget>
#include <QSlider>
#include <QtSql>
#include <QFileInfo>
#include <QPushButton>


QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    // Deklaracja funkcji printMessage
    void printMessage(const QString &message);

    //dane do bazy danych
    QList<int> idx_rodzaj = {0, 0, 0, 0, 0,0};
    QList<int> *Widx_rodzaj = &idx_rodzaj;

    QList<int> idx_inne = {0, 0};
    QList<int> *Widx_inne = &idx_inne;

    QList<int> idx_bialko = {0, 0, 0, 0};
    QList<int> *Widx_bialko = &idx_bialko;

    QList<int> idx_nabial = {0, 0, 0, 0};
    QList<int> *Widx_nabial = &idx_nabial;

    QList<int> idx_baza = {0, 0, 0, 0};
    QList<int> *Widx_baza = &idx_baza;

    QList<int> idx_warzywa = {0, 0, 0, 0, 0, 0};
    QList<int> *Widx_warzywa = &idx_warzywa;

    QList<int> idx_owoce = {0, 0, 0, 0, 0, 0};
    QList<int> *Widx_owoce = &idx_owoce;

    QList<int> idx_przyprawy = {0, 0, 0, 0};
    QList<int> *Widx_przyprawy = &idx_przyprawy;




private slots:
    void nowe_okno_clicked();
    void skladnik_clicked(QStringList skladniki_lista, QList<int> *idx_lista);
    void skladnik_clicked_2(QStringList skladniki_lista, QList<int> *idx_lista);
    void wyszukaj_clicked();
    void stworz_guzik(QStringList nazwa, QList<int> *index, float x, float y);

private:
    Ui::MainWindow *ui;
    QListWidget *listWidget;
    QSlider *slider;

    //skladniki - dane do zczytania w bazie danych
    QStringList lista_rodzaje = {"sniadaniowe", "lunch", "obiadowe","napoje","desery","sosy i dodatki"};
    QStringList lista_inne = {"wegetarianskie", "ostre"};
    QStringList lista_bialko = {"wolowe","ryba","jajko","kurczak"};
    QStringList lista_nabial = { "mleko", "ser","smietana", "jogurt"};
    QStringList lista_baza = {"makaron", "ryz", "pieczywo", "maka"};
    QStringList lista_warzywa = {"marchew", "cebula","ogorek", "papryka", "pomidor", "ziemniak"};
    QStringList lista_owoce = { "banan","cytryna","jablko","malina","pomarancza","truskawka"};
    QStringList lista_przyprawy = {"cynamon","tymianek","galka_muszkatowa","kminek"};






};
#endif // MAINWINDOW_H
