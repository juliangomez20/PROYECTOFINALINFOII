#include "cuerda.h"

Cuerda::Cuerda(int x, int y, QObject *parent) : QObject(parent)
{
    Pos_X=x;
    Pos_Y=y;
    Ancho=60;
    Alto=140;
    angulo=315;
    // pinta la imagen
    pixmap=new QPixmap(":/Personaje/objetos/blade.png");
    timercuerda=new QTimer;
    connect(timercuerda,SIGNAL(timeout()),this,SLOT(moveRotation()));
    timercuerda->start(5);
    setPos(Pos_X,Pos_Y);
}
// se escapsula la imagen
QRectF Cuerda::boundingRect() const
{
    return QRectF(-Ancho/2,0,Ancho,Alto); // se crea el rectangulo con su centro que son los primeros dos parametros y su ancho y alto
}

void Cuerda::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    painter->drawPixmap(boundingRect(),*pixmap,pixmap->rect()); // Se pinta en el rectangulo usando el pixmap
    UNUSED(option);
    UNUSED(widget);

}

void Cuerda::moveRotation()
{
    // voleta la imange dependiendo del angulo
    this->setRotation(angulo);
    if(angulo<=270.0){
        sumaAngulo*=-1;
    }
    if(angulo>=450.0){
        sumaAngulo*=-1;
    }
    angulo+=sumaAngulo;
}
