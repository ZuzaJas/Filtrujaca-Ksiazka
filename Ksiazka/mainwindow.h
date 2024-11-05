#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QListWidget>
#include <QSlider>

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




private slots:
    void nowe_okno_clicked();
    void marchew_clicked();
    void cebula_clicked();
    void banan_clicked();
    void cynamon_clicked();
    void jablko_clicked();
    void jajko_clicked();
    void kurczak_clicked();
    void cytryna_clicked();
    void makaron_clicked();
    void malina_clicked();
    void mleko_clicked();
    void ogorek_clicked();
    void papryka_clicked();
    void pieczywo_clicked();
    void pomarancza_clicked();
    void pomidor_clicked();
    void ryba_clicked();
    void ryz_clicked();
    void ser_clicked();
    void smietana_clicked();
    void truskawka_clicked();
    void tymianek_clicked();
    void wolowe_clicked();
    void ziemniak_clicked();
    void galka_muszkatowa_clicked();
    void jogurt_clicked();
    void kminek_clicked();

private:
    Ui::MainWindow *ui;
    QListWidget *listWidget;
    QSlider *slider;

};
#endif // MAINWINDOW_H
