#ifndef CUERDA_H
#define CUERDA_H

#include "librerias.h"

class Cuerda : public QObject, public QGraphicsItem
{
    Q_OBJECT
private:
    //atributos
    int Pos_X, Pos_Y;
    double angulo;
    int Ancho, Alto;
    double sumaAngulo=-0.5;
    QPixmap *pixmap;
    QTimer *timercuerda;

public:
    explicit Cuerda(int x, int y, QObject *parent = nullptr);
    //pita la imgange
    QRectF boundingRect() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);

signals:

public slots:
    //rota el ovjeto
    void moveRotation();
};

#endif // CUERDA_H
