#ifndef DODAJ_H
#define DODAJ_H

#include <QDialog>

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
};

#endif // DODAJ_H
