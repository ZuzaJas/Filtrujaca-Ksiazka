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
    void on_nowe_okno_clicked();

    void on_marchew_clicked();
    void on_cebula_clicked();
    void on_banan_clicked();
    void on_cynamon_clicked();
    void on_jablko_clicked();
    void on_jajko_clicked();
    void on_kurczak_clicked();
    void on_cytryna_clicked();
    void on_makaron_clicked();
    void on_malina_clicked();
    void on_mleko_clicked();
    void on_ogorek_clicked();
    void on_papryka_clicked();

private:
    Ui::MainWindow *ui;
    QListWidget *listWidget;
    QSlider *slider;

};
#endif // MAINWINDOW_H
