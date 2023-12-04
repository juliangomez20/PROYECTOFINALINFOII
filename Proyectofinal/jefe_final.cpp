#include "jefe_final.h"

Jefe_final::Jefe_final(int x, int y,QString direcion ) : Enemigos( x,  y,direcion )
{

    Ancho= 100;
    Alto= 120;
    pixmap=new QPixmap(":/Personaje/Pesonaje/Jefe Final.png");
    TimerMover=new QTimer;
    connect(TimerMover,SIGNAL(timeout()),this,SLOT(Mover_Jefe()));
    TimerMover->start(50);

    setPos(get_Pos_X(),get_Pos_Y());


}
QRectF Jefe_final::boundingRect() const
{
    return QRectF(0,0,Ancho,Alto); // se crea el rectangulo con su centro que son los primeros dos parametros y su ancho y alto
}

void Jefe_final::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    painter->drawPixmap(boundingRect(),*pixmap,pixmap->rect()); // Se pinta en el rectangulo usando el pixmap
    UNUSED(option);
    UNUSED(widget);
}

int Jefe_final::get_Alto()
{
    return Alto;
}



void Jefe_final::Mover_Jefe()
{
    if(get_Direccion()=="Arriba"){
        set_Pos_Y(get_Pos_Y()-5);
    }
    if(get_Direccion() =="Abajo"){
        set_Pos_Y(get_Pos_Y()+5);
    }
}
