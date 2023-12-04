#include "findeljuego.h"
#include "ui_findeljuego.h"

Findeljuego::Findeljuego(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Findeljuego)
{
    ui->setupUi(this);
}

Findeljuego::~Findeljuego()
{
    delete ui;
}
