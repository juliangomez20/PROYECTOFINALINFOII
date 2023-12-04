#ifndef DISCO_H
#define DISCO_H

#include "librerias.h"

class Disco : public QObject, public QGraphicsItem
{
    Q_OBJECT
private:
    //atributos
    int Pos_X, Pos_Y;
    int Vel_X;
    int Alto, Ancho;
    int angulo;
    QString Clase;
    QString direction;
    QPixmap *pixmap;
    QTimer *timermove;
    QTimer *timermoveX;
public:
    explicit Disco(int x, int y, QString clase,QObject *parent = nullptr);

    //pinto la imaagen
    QRectF boundingRect() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);

    //metodos get
    int getVelX();
    int getWidth();
    int get_Pos_X();
    QString getDirection();


    //metodos set
    void setVelX(int );
    void set_Pos_X(int);
    void setDirection(QString);


signals:

public slots:

    //funciones para rotarlo y moverlo
    void moveRotation();
    void mover_X();
};


#endif // DISCO_H
