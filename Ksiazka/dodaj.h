#ifndef DODAJ_H
#define DODAJ_H

#include <QDialog>
#include <QLineEdit>
#include <QTextEdit>
#include <QLabel>
#include <QComboBox>
#include <QStringList>
#include <QString>
#include <QSqlDatabase>




namespace Ui {
class Dialog;
}

class Dialog : public QDialog
{
    Q_OBJECT

public:
    explicit Dialog(QWidget *parent = nullptr);
    ~Dialog();

private slots:
    void close_window();
    void stworz_checkbox(QStringList nazwa,QList<int> *index, float x, float y);
    int checkTrue(int value);
    void zatwierdz_clicked();
    QString getBaza(QString Plik);
    QString ListaNaString(const QList<int> &lista);
    void dodatkowe(QString skladnik);

private:
    Ui::Dialog *ui;
    QLineEdit *nazwa;
    QTextEdit *opis;
    QTextEdit *przepis;
    QLineEdit *dodatkowe_skladniki;
    QLabel *label_opis;
    QLabel *label_przepis;
    QLabel *label_nazwa;
    QLabel *label_rodzaj;
    QLabel *label_inne;
    QLabel *label_skladniki;
    QLabel *label_dodatkowe_skladniki;
    QTextEdit* label_lista_dodatkowe;
};

extern QList<int> sql_rodzaj;

#endif // DODAJ_H
