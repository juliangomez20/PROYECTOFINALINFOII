#ifndef INICIODESESION_H
#define INICIODESESION_H

#include <QWidget>
#include <QFile>
#include <QDebug>
#include <QMessageBox>

#include "juego.h"
#include "registrarse.h"

namespace Ui {
class Iniciodesesion;
}

class Iniciodesesion : public QWidget
{
    Q_OBJECT

public:
    explicit Iniciodesesion(QWidget *parent = nullptr);
    ~Iniciodesesion();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::Iniciodesesion *ui;
    bool des;
    Juego *juego;
    Registrarse *registrarse;

    int PosXJ, PosYJ,PosXP,PosYP, vidas,score,score_maxi;
    short int cont = 0, espacios =0;
};

#endif // INICIODESESION_H
