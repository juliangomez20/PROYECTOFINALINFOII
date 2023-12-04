#ifndef BULLET_H
#define BULLET_H

#include "librerias.h"

// Declaración de la clase Bullet que hereda de QObject y QGraphicsItem
class Bullet : public QObject, public QGraphicsItem
{
    Q_OBJECT // Se marca como un objeto de Qt para admitir señales y ranuras
private:
    //atributos
    QPixmap *pixmap;
    int Pos_X, Pos_Y;
    int Ancho, Alto;
    QTimer *timer_bullet;
    QString direction;
    QString Balas;

public:
    // Constructor de la clase Bullet que recibe coordenadas x e y, y dos cadenas
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

    // Ranuras (slots) - método para mover el objeto
     void move();

};

#endif // BULLET_H
