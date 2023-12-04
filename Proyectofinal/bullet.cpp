#include "bullet.h"

Bullet::Bullet (int x, int y, QString direc,QString balas ,QObject *parent) : QObject(parent)
{

    Pos_X=x;
    Pos_Y=y;
    direction=direc;
    Balas =balas;
    Ancho=20;
    Alto=10;
    //pinta una imagen dpendiendo de la derecion
    if(direction=="derecha"){
        pixmap=new QPixmap(":/Personaje/objetos/Lama_der.png");
    }
    if(direction=="izquierda"){
        pixmap=new QPixmap(":/Personaje/objetos/Llama_Iz.png");
    }
    //comienza un timer para que mueva l bala depues de ser creado
    timer_bullet  = new QTimer();
    connect(timer_bullet, SIGNAL(timeout()), this, SLOT(move()));
    timer_bullet->start(100); // Velocidad de la bala
    setPos(Pos_X,Pos_Y);
}

QRectF Bullet::boundingRect() const
{
    return QRectF(0,0,Ancho,Alto); // se crea el rectangulo con su centro que son los primeros dos parametros y su ancho y alto
}

void Bullet::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    painter->drawPixmap(boundingRect(),*pixmap,pixmap->rect()); // Se pinta en el rectangulo usando el pixmap
    UNUSED(option);
    UNUSED(widget);
}

QString Bullet::getdirection()
{
    return  direction;
}

int Bullet::getposx()
{
    return Pos_X;
}

QString Bullet::get_Balas()
{
    return Balas;
}
void Bullet::move() //mueve la bala dependiento de la direcion

{
    if(direction=="derecha"){
        Pos_X+=5;
        setX(Pos_X);  // Cuanto se desplaza la bala en la pantalla. movimiento de la bala
    }
    if(direction=="izquierda"){
        Pos_X-=5;
        setX(Pos_X);  // Cuanto se desplaza la bala en la pantalla. movimiento de la bala
    }
}


