#ifndef BULLET_H
#define BULLET_H

#include "librerias.h"

class Bullet : public QObject, public QGraphicsItem
{
    Q_OBJECT
private:
    //atributos
    QPixmap *pixmap;
    int Pos_X, Pos_Y;
    int Ancho, Alto;
    QTimer *timer_bullet;
    QString direction;
    QString Balas;

public:
    Bullet(int x, int y,QString, QString, QObject *parent = nullptr);
    //pintar la imagen
    QRectF boundingRect() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);

    //metodos Get
    QString getdirection();
    int getposx();
    QString get_Balas();

signals:

public slots:
    //mover el objeto
     void move();

};

#endif // BULLET_H
