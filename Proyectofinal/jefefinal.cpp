#include "jefefinal.h"
#include "ui_jefefinal.h"

Jefefinal::Jefefinal(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Jefefinal)
{
    ui->setupUi(this);
}

Jefefinal::~Jefefinal()
{
    delete ui;
}
