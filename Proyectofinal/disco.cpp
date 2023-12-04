#include "disco.h"

Disco::Disco(int x, int y, QString clase, QObject *parent) : QObject(parent)
{
    Pos_X=x;
    Pos_Y=y;
    Vel_X=4;
    Alto=40;
    Ancho=40;
    angulo=300;
    Clase=clase;
    direction="derecha";

    //pinta la imagne del disco
    pixmap=new QPixmap(":/Personaje/objetos/cierra.png");

    //contectra el tiempo con la funcion para rotar el disco
    timermove=new QTimer;
    connect(timermove,SIGNAL(timeout()),this,SLOT(moveRotation()));
    timermove->start(20);
    if(Clase=="Mov_X"){
        timermoveX=new QTimer;
        connect(timermoveX,SIGNAL(timeout()),this,SLOT(mover_X()));
        timermoveX->start(20);
    }
    setPos(Pos_X,Pos_Y);

}
//encja la imagne eun rectangulo
QRectF Disco::boundingRect() const
{
    return QRectF(-Ancho/2,-Alto/2,Alto,Ancho); // se crea el rectangulo con su centro que son los primeros dos parametros y su ancho y alto
}

void Disco::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    painter->drawPixmap(boundingRect(),*pixmap,pixmap->rect()); // Se pinta en el rectangulo usando el pixmap
    UNUSED(option);
    UNUSED(widget);
}

void Disco::setVelX(int vel)
{
    Vel_X=vel;
}

void Disco::set_Pos_X(int x)
{
    Pos_X=x;
    setX(Pos_X);
}

int Disco::getVelX()
{
    return Vel_X;
}

int Disco::getWidth()
{
    return Alto;
}

int Disco::get_Pos_X()
{
    return Pos_X;
}

void Disco::setDirection(QString direc)
{
    direction=direc;
}

QString Disco::getDirection()
{
    return direction;
}

void Disco::moveRotation()
{
    //gira la imagne
    this->setRotation(angulo);
    angulo -= 5;
}

void Disco::mover_X()
{
    if(Vel_X<0) direction="Izquierda";
    if(Vel_X>0) direction="Derecha";
    Pos_X -= Vel_X;
    setX(Pos_X);
}
