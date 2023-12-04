#ifndef REGISTRARSE_H
#define REGISTRARSE_H

#include <QWidget>
#include <QFile>
#include <QDebug>
#include <QMessageBox>

namespace Ui {
class Registrarse;
}

class Registrarse : public QWidget
{
    Q_OBJECT

public:
    explicit Registrarse(QWidget *parent = nullptr);
    ~Registrarse();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::Registrarse *ui;
    //atributos
    bool des;
    short int cont = 0, espacios =0;
};

#endif // REGISTRARSE_H
