#include "jugador.h"

Jugador::Jugador(int x, int y , QObject *parent): QObject(parent)
{
    pixmap=new QPixmap(":/Personaje/Pesonaje/Stop Derecha.png");
    //pixmap=new QPixmap(":/Personaje/Pesonaje/Jefe Final.png");
    EstadoPosicionBase=true;
    falling=false;
    direction="derecha";
    Pos_X=x;
    Pos_Y=y;
    Pos_X_Base=x;
    Pos_Y_Base=y;
    Ancho=45;
    Alto=65;
    velX=20;
    velY=-50;
    velCaida=0;

    // conecta el timepo con el salto y con la caida libre
    timerSalto=new QTimer;
    connect(timerSalto,SIGNAL(timeout()),this,SLOT(salto()));
    timerCaida=new QTimer;
    connect(timerCaida,SIGNAL(timeout()),this,SLOT(caidaLibre()));
    timerfricion = new QTimer;
    connect(timerfricion,SIGNAL(timeout()),this,SLOT(fricion()));


    //ubicar el persnaje en la poscion que se creo
    setPos(Pos_X,Pos_Y);
}

QRectF Jugador::boundingRect() const
{
    return QRectF(0,0,Ancho,Alto); // se crea el rectangulo con su centro que son los primeros dos parametros y su ancho y alto
}

void Jugador::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    painter->drawPixmap(boundingRect(),*pixmap,pixmap->rect()); // Se pinta en el rectangulo usando el pixmap
    UNUSED(option);
    UNUSED(widget);
}

Jugador::Jugador()
{
    delete timerSalto;
    delete timerCaida;
}

bool Jugador::getfalling()
{
    return falling;
}

int Jugador::getPos_X()
{
    return Pos_X;
}

int Jugador::getPos_Y()
{
    return  Pos_Y;
}

int Jugador::getAncho()
{
    return Ancho;
}

int Jugador::getAlto()
{
    return Alto;
}

QString Jugador::getDireccion()
{
    return direction;
}

bool Jugador::getEstadoPosBase()
{
    return EstadoPosicionBase;
}

void Jugador::setPosBase(int posbase)
{
    Pos_Base=posbase;
}

void Jugador::set_Y(int y)
{
    Pos_Y =y;
    setY(Pos_Y);
}

void Jugador::set_X(int x)
{
    Pos_X=x;
    setX(Pos_X);
}

void Jugador::set_Vel_Y(int Vel_y)
{
    velY=Vel_y;
}

void Jugador::set_Y_Ini(int y)
{
    Pos_Y_Base = y;
}

void Jugador::set_X_Ini(int x)
{
    Pos_X_Base = x;
}

void Jugador::Mover_De()
{

    if(Mov_De){
        direction="derecha";
        Pos_X+=8;
        setX(Pos_X);
        tiempo=clock();
        timerfricion->start(10);


    }
}

void Jugador::Mover_iz()
{
    if(Mov_Iz){
        direction="izquierda";
        Pos_X-=8;
        setX(Pos_X);
        tiempo=clock();
        timerfricion->start(10);
    }

}

void Jugador::Animacion_Run_Derecha2()
{
    if (Aux_Derecha_Run == 1) {
        pixmap=new QPixmap(":/Personaje/Pesonaje/Run__002.png");
    }
    else if (Aux_Derecha_Run == 2) {
        pixmap=new QPixmap(":/Personaje/Pesonaje/Run__008.png");
    }
    if(Aux_Derecha_Run == 2){
        Aux_Derecha_Run=0;
    }
    Aux_Derecha_Run ++;
}

void Jugador::Animacion_Run_Izquierda2()
{
    if (Aux_Izquierda_Run == 1) {
        pixmap=new QPixmap(":/Personaje/Pesonaje/Run__003-ConvertImage.png");
    }
    else if (Aux_Izquierda_Run == 2) {
        pixmap=new QPixmap(":/Personaje/Pesonaje/Run__008-ConvertImage.png");
    }
    if(Aux_Izquierda_Run == 2){
        Aux_Izquierda_Run=0;
    }
}

void Jugador::Animacion_Run_Derecha()
{
    if (Aux_Derecha_Run == 1) {
        pixmap=new QPixmap(":/Personaje/Pesonaje/Run Derecha.png");
    }
    else if (Aux_Derecha_Run == 2) {
        pixmap=new QPixmap(":/Personaje/Pesonaje/Stop Derecha.png");
    }
    else if (Aux_Derecha_Run == 3) {
        pixmap=new QPixmap(":/Personaje/Pesonaje/Run Derecha 2.png");
    }
    if(Aux_Derecha_Run == 3){
        Aux_Derecha_Run=0;
    }
    Aux_Derecha_Run ++;
}

void Jugador::Animacion_Run_Izquierda()
{
    if (Aux_Izquierda_Run == 1) {
        pixmap=new QPixmap(":/Personaje/Pesonaje/Run Izquierda.png");
    }
    else if (Aux_Izquierda_Run == 2) {
        pixmap=new QPixmap(":/Personaje/Pesonaje/Stop Izquierda.png");
    }
    else if (Aux_Izquierda_Run == 3) {
        pixmap=new QPixmap(":/Personaje/Pesonaje/Run Izquierda 2.png");
    }
    if(Aux_Izquierda_Run == 3){
        Aux_Izquierda_Run=0;
    }
    Aux_Izquierda_Run ++;
}

void Jugador::AnimaSaltar()
{
    if(direction=="derecha"){
        pixmap=new QPixmap(":/Personaje/Pesonaje/Jump Derecha.png");
    }
    else {
        pixmap=new QPixmap(":/Personaje/Pesonaje/Jump Izquierda.png");
    }
}

void Jugador::AnimaSaltar2()
{
    if(direction=="derecha"){
        pixmap=new QPixmap(":/Personaje/Pesonaje/Jump__005.png");
    }
    else {
        pixmap=new QPixmap(":/Personaje/Pesonaje/Jump__004-ConvertImage.png");
    }
}

void Jugador::Retur_Pos_inicial()
{
    Pos_X =Pos_X_Base;
    Pos_Y =Pos_Y_Base;
    setPos(Pos_X,Pos_Y);
}



void Jugador::fricion()
{

    if (int (clock() - tiempo) >= 500){
        timerfricion->stop();
    }
    if (direction == "izquierda"){
        Pos_X-=1;
    }
    if (direction == "derecha"){
        Pos_X+=1;
    }

    setX(Pos_X);
}



void Jugador::salto()
{

    timerSalto->start(18);
    EstadoPosicionBase=false;

    if(velY>=0) {
        falling=true;
    }
    if(velY<0) {
        falling=false;
        Pos_Base=523;
    }
    velY+=G*Dt;
    Pos_Y += velY*Dt;
    setY(Pos_Y);

    if(Pos_Y>=Pos_Base){ // donde queda despues del salto

        timerSalto->stop(); // despues de que salte le digo que deje de saltar, sino queda saltando y saltando.
        Pos_Y=Pos_Base;
        EstadoPosicionBase=true;
        setY(Pos_Y);
        velY=-50;
    }
}

void Jugador::caidaLibre()
{
    timerCaida->start(18);
    velCaida+=G*Dt;
    EstadoPosicionBase=false;
    Pos_Y+=velCaida*Dt;
    setY(Pos_Y);

    if(Pos_Y>=Pos_Base) // donde queda despues del salto
    {
        timerCaida->stop();
        Pos_Y=Pos_Base;
        EstadoPosicionBase=true;
        setY(Pos_Y);
        velCaida=0;
    }

}
