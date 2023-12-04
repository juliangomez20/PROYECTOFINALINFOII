#include "winer.h"
#include "ui_winer.h"

Winer::Winer(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Winer)
{
    ui->setupUi(this);
}

Winer::~Winer()
{
    delete ui;
}
