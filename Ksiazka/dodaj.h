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
#include <QCheckBox>



namespace Ui {
class Dialog;
}

class Dialog : public QDialog
{
    Q_OBJECT

public:
    explicit Dialog(QString rodzaj,int id, QWidget *parent = nullptr);
    ~Dialog();






private slots:
    void close_window();
    void stworz_checkbox(QStringList nazwa,QList<int> *index, float x, float y);
    int checkTrue(int value);
    void zatwierdz_clicked();
    QString getBaza(QString Plik);
    QString ListaNaString(const QList<int> &lista);
    void dodatkowe(QString skladnik, int a);

    //funkcje kiedy edycja
    void wczytaj_dane();
    QStringList String_na_Lista(QString index);
    void zmien_checkboxy(QString index, QStringList rodzaj);

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

    QString typ;
    int id;

    QMap<QString, QCheckBox*> checkBoxMap;


    QStringList lista_rodzaj = {"śniadaniowe", "lunch", "obiadowe","napoje","desery","sosy i dodatki"};
    QStringList lista_inne = {"wegetariańskie", "ostre"};
    QStringList lista_bialko = {"wołowe", "ryba", "jajko", "kurczak"};
    QStringList lista_baza = {"makaron", "ryż", "pieczywo", "mąka"};
    QStringList lista_warzywa = {"marchew", "cebula", "ogórek", "papryka", "pomidor", "ziemniak"};
    QStringList lista_owoce = {"banan", "cytryna", "jabłko", "malina", "pomarańcza", "truskawka"};
    QStringList lista_nabial = {"mleko", "ser", "smietana", "jogurt"};
    QStringList lista_przyprawy = {"cynamon","tymianek","galka_muszkatowa","kminek"};


};

extern QList<int> sql_rodzaj;

#endif // DODAJ_H
