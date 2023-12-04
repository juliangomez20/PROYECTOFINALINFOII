#ifndef ENEMIGOS_H
#define ENEMIGOS_H

#include "librerias.h"

class Enemigos : public QObject, public QGraphicsItem
{
    Q_OBJECT
private:
    //atribustos principales
    int Pos_X;
    int Pos_Y;
    int Ancho;
    int Alto;
    QString Direction;
    //variables secundarias
    QTimer *TimerMover;
    QPixmap *pixmap;
public:
    explicit Enemigos(int x, int y, QString direcion, QObject *parent = nullptr);
    // pinta el objeto
    QRectF boundingRect() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);

    //Metodos set modificar
    void set_Direcion(QString);
    void set_Pos_X(int);
    void set_Pos_Y(int);

    //Metodos get Obtener
    QString get_Direccion();
    int get_Pos_X();
    int get_Pos_Y();

signals:

public slots:
    void Mover();

};

#endif // ENEMIGOS_H
