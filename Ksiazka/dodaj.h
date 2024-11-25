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
    QLabel *label_opis;
    QLabel *label_nazwa;
    QLabel *label_rodzaj;
    QLabel *label_inne;




};

#endif // DODAJ_H
