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




private slots:
    void nowe_okno_clicked();
    void skladnik_clicked();

private:
    Ui::MainWindow *ui;
    QListWidget *listWidget;
    QSlider *slider;




};
#endif // MAINWINDOW_H
