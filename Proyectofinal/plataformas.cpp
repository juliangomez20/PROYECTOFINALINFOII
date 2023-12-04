#include "plataformas.h"


Plataformas::Plataformas(int x, int y, QString clase, QObject *parent): QObject(parent)
{
    Clase = clase;
    Pos_X = x;
    Pos_Y = y;
    Alto = 40;
    Ancho = 40;
    Salto = -110;
    if (Clase == "Piso"){
        pixmap=new QPixmap(":/Personaje/Fondo/01.png");
    }
    else if (Clase == "Hueco"){
        pixmap=new QPixmap("");
    }
    else if (Clase== "Pared"){
        pixmap = new QPixmap(":/Personaje/Fondo/01.png");
    }
    else if (Clase == "Tranpolin"){
        pixmap = new QPixmap(":/Personaje/objetos/Mushroom_2.png");
    }
    else if (Clase == "Moneda"){
        pixmap = new QPixmap(":/Personaje/objetos/coin.png");
        Alto = 30;
        Ancho = 30;
    }
    else if (Clase == "Door") {
        pixmap = new QPixmap(":/Personaje/objetos/door.png");
        Alto =80;
        Ancho =40;
    }
    else if (Clase == "Rebote"){
         pixmap = new QPixmap("");
    }
    else if (Clase == "Pinchos") {
        pixmap = new QPixmap(":/Personaje/objetos/thorns1.png");
    }
    setPos(Pos_X,Pos_Y);
}

// se encapsula la imagen
QRectF Plataformas::boundingRect() const
{
    return QRectF(0,0,Ancho,Alto); // se crea el rectangulo con su centro que son los primeros dos parametros y su ancho y alto
}

void Plataformas::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    painter->drawPixmap(boundingRect(),*pixmap,pixmap->rect()); // Se pinta en el rectangulo usando el pixmap
    UNUSED(option);
    UNUSED(widget);

}

void Plataformas::Actualizar_Pos_Per(Jugador *personaje)
{
    int Pos_iz_pla =Pos_X, Pos_der_pla =Pos_X+Ancho;
    int Pos_ari_pla =Pos_Y, Pos_aba_pla =Pos_Y +Alto;
    int Pos_iz_per =personaje->getPos_X(), Pos_der_per =personaje->getPos_X()+personaje->getAncho();
    int Pos_ari_per =personaje->getPos_Y(), Pos_aba_per =personaje->getPos_Y() +personaje->getAlto();

    if(personaje->getfalling()==true && Clase == "Piso" && Pos_der_per >= Pos_iz_pla+5 && Pos_iz_per <= Pos_der_pla-5 && Pos_aba_per >= Pos_ari_pla && Pos_ari_per <=Pos_aba_pla-40 ){

        personaje->setPosBase(Pos_ari_pla-personaje->getAlto());
        personaje->set_Y(Pos_ari_pla-personaje->getAlto());


    }
    if(personaje->getEstadoPosBase()==true && Clase == "Hueco" && Pos_der_per >= Pos_iz_pla-20 && Pos_iz_per <= Pos_der_pla+20 && Pos_aba_per >= Pos_ari_pla && Pos_ari_per <=Pos_aba_pla ){
        personaje->setPosBase(553);
        personaje->caidaLibre();
    }
    if(Clase == "Pared" && Pos_der_per >= Pos_iz_pla && Pos_iz_per <= Pos_der_pla && Pos_aba_per >= Pos_ari_pla && Pos_ari_per <=Pos_aba_pla){
        if (personaje->getDireccion()=="derecha"){
           personaje->set_X(Pos_iz_pla-personaje->getAncho());
        }
        if (personaje->getDireccion()=="izquierda"){
           personaje->set_X(Pos_der_pla);
        }
    }
     if(Clase == "Tranpolin" && Pos_der_per >= Pos_iz_pla && Pos_iz_per <= Pos_der_pla && Pos_aba_per >= Pos_ari_pla && Pos_ari_per <=Pos_aba_pla){
         personaje->set_Vel_Y(Salto);
         Salto +=1;
         if(Salto >= 0){
             personaje->set_Y(Pos_ari_pla-personaje->getAlto());
             Salto = -110;
         }
     }
}

QString Plataformas::getClase()
{
    return Clase;
}

int Plataformas::get_Pos_X()
{
    return Pos_X;
}
