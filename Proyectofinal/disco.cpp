#include "disco.h"

// Constructor de la clase Disco
Disco::Disco(int x, int y, QString clase, QObject *parent) : QObject(parent)
{
    // Inicialización de atributos
    Pos_X = x;
    Pos_Y = y;
    Vel_X = 4;
    Alto = 40;
    Ancho = 40;
    angulo = 300;
    Clase = clase;
    direction = "derecha";

    // Carga la imagen del disco
    pixmap = new QPixmap(":/Personaje/objetos/cierra.png");

    // Conecta el temporizador con la función para rotar el disco
    timermove = new QTimer;
    connect(timermove, SIGNAL(timeout()), this, SLOT(moveRotation()));
    timermove->start(20);

    // Si la clase es "Mov_X", conecta otro temporizador con la función para mover el disco en el eje X
    if (Clase == "Mov_X")
    {
        timermoveX = new QTimer;
        connect(timermoveX, SIGNAL(timeout()), this, SLOT(mover_X()));
        timermoveX->start(20);
    }

    // Establece la posición inicial del disco
    setPos(Pos_X, Pos_Y);
}

// Método para obtener el rectángulo delimitador del disco
QRectF Disco::boundingRect() const
{
    return QRectF(-Ancho / 2, -Alto / 2, Alto, Ancho);
}

// Método para pintar la imagen del disco en la escena
void Disco::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    painter->drawPixmap(boundingRect(), *pixmap, pixmap->rect());
    UNUSED(option);
    UNUSED(widget);
}

// Métodos Set para establecer valores en el disco
void Disco::setVelX(int vel)
{
    Vel_X = vel;
}

void Disco::set_Pos_X(int x)
{
    Pos_X = x;
    setX(Pos_X);
}

void Disco::setDirection(QString direc)
{
    direction = direc;
}

// Métodos Get para obtener información sobre el disco
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

QString Disco::getDirection()
{
    return direction;
}

// Función para realizar la rotación del disco
void Disco::moveRotation()
{
    // Rota la imagen del disco
    this->setRotation(angulo);
    angulo -= 5;
}

// Función para mover el disco en el eje X
void Disco::mover_X()
{
    // Determina la dirección del movimiento
    if (Vel_X < 0)
        direction = "Izquierda";
    if (Vel_X > 0)
        direction = "Derecha";

    // Actualiza la posición en el eje X
    Pos_X -= Vel_X;
    setX(Pos_X);
}
