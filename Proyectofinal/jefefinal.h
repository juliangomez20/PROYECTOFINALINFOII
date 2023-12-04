#ifndef JEFEFINAL_H
#define JEFEFINAL_H

#include <QWidget>
#include "librerias.h"

namespace Ui {
class Jefefinal;
}

class Jefefinal : public QObject, public QGraphicsItem
{
    Q_OBJECT

public:
    explicit Jefefinal(QWidget *parent = nullptr);
    ~Jefefinal();

private:
    Ui::Jefefinal *ui;
};

#endif // JEFEFINAL_H
