#ifndef KARTA_H
#define KARTA_H

#include <QDialog>
#include <QString>

namespace Ui {
class karta;
}

class karta : public QDialog
{
    Q_OBJECT

public:
    explicit karta(QString nazwa,QWidget *parent = nullptr);
    ~karta();


private:
    Ui::karta *ui;
    QString nazwa;


private slots:
    void close_window();
    QString getBaza(QString Plik);
    void wyszukaj_w_bazie(QString nazwa, QStringList *lista_nazwy);

};



#endif // KARTA_H
