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
    explicit karta(int id,QWidget *parent = nullptr);
    ~karta();


private:
    Ui::karta *ui;
    int id;


private slots:
    void close_window();
    void open_edycja();
    QString getBaza(QString Plik);
    void wyszukaj_w_bazie(int id, QStringList *lista_nazwy);

};



#endif // KARTA_H
