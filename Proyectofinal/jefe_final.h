#ifndef JEFE_FINAL_H
#define JEFE_FINAL_H

#include "librerias.h"
#include "enemigos.h"


class Jefe_final: public Enemigos
{
    Q_OBJECT
private:
    int Ancho;
    int Alto;
    //variables secundarias
    QTimer *TimerMover;
    QPixmap *pixmap;
public:
    explicit Jefe_final(int x, int y, QString direcion);
    QRectF boundingRect() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
    // metodos get obtener
    int get_Alto();

signals:

public slots:
    void Mover_Jefe();
};



#endif // JEFE_FINAL_H
