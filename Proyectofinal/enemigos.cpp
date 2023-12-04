#include "enemigos.h"

Enemigos::Enemigos(int x, int y,QString direcion, QObject *parent): QObject(parent)
{

    Pos_X= x;
    Pos_Y= y;
    Direction = direcion;
    Ancho= 45;
    Alto= 65;
    if(Direction=="Derecha"){
        pixmap=new QPixmap(":/Personaje/Pesonaje/Enemigo Derecha.png");
    }
    else{
        pixmap=new QPixmap(":/Personaje/Pesonaje/Enemigo Izquierda.png");
    }


    TimerMover=new QTimer;
    connect(TimerMover,SIGNAL(timeout()),this,SLOT(Mover()));
    TimerMover->start(50);

    setPos(Pos_X,Pos_Y);


}
QRectF Enemigos::boundingRect() const
{
    return QRectF(0,0,Ancho,Alto); // se crea el rectangulo con su centro que son los primeros dos parametros y su ancho y alto
}

void Enemigos::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    painter->drawPixmap(boundingRect(),*pixmap,pixmap->rect()); // Se pinta en el rectangulo usando el pixmap
    UNUSED(option);
    UNUSED(widget);
}

void Enemigos::set_Direcion(QString direcion)
{
    Direction=direcion;

    if(Direction=="Izquierda"){
        pixmap=new QPixmap(":/Personaje/Pesonaje/Enemigo Izquierda.png");
    }
    if(Direction=="Derecha"){
        pixmap=new QPixmap(":/Personaje/Pesonaje/Enemigo Derecha.png");
    }
}

void Enemigos::set_Pos_X(int x)
{
    Pos_X = x;
    setX(Pos_X);
}

void Enemigos::set_Pos_Y(int y)
{
    Pos_Y = y;
    setY(Pos_Y);
}

QString Enemigos::get_Direccion()
{
    return Direction;
}

int Enemigos::get_Pos_X()
{
    return Pos_X;
}

int Enemigos::get_Pos_Y()
{
    return Pos_Y;
}

void Enemigos::Mover()
{

    if(Direction=="Derecha"){
        Pos_X += 5;
        setX(Pos_X);
    }
    if(Direction =="Izquierda"){
        Pos_X -= 5;
        setX(Pos_X);
    }

}
