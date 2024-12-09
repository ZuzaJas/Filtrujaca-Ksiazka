#ifndef DODAJ_H
#define DODAJ_H

#include <QDialog>
#include <QLineEdit>
#include <QTextEdit>
#include <QLabel>
#include <QComboBox>

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

private:
    Ui::Dialog *ui;
    QLineEdit *nazwa;
    QTextEdit *opis;
    QComboBox *rodzaj;
    QComboBox *inne;
    QLineEdit *dodatkowe_skladniki;
    QLabel *label_opis;
    QLabel *label_nazwa;
    QLabel *label_rodzaj;
    QLabel *label_inne;
    QLabel *label_skladniki;
    QLabel *label_dodatkowe_skladniki;




};

#endif // DODAJ_H
