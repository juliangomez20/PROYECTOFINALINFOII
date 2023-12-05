#include "bullet.h"

// Constructor de la clase Bullet
Bullet::Bullet(int x, int y, QString direc, QString balas, QObject *parent) : QObject(parent)
{
    // Inicialización de atributos
    Pos_X = x;
    Pos_Y = y;
    direction = direc;
    Balas = balas;
    Ancho = 20;
    Alto = 10;

    // Selecciona la imagen de la bala según la dirección
    if (direction == "derecha")
    {
        pixmap = new QPixmap(":/Personaje/objetos/Lama_der.png");
    }
    if (direction == "izquierda")
    {
        pixmap = new QPixmap(":/Personaje/objetos/Llama_Iz.png");
    }

    // Inicializa un temporizador para mover la bala después de ser creada
    timer_bullet = new QTimer();
    connect(timer_bullet, SIGNAL(timeout()), this, SLOT(move())); //Se llama move()
    timer_bullet->start(10); // Velocidad de la bala
    setPos(Pos_X, Pos_Y);
}

// Método que devuelve el rectángulo delimitador de la bala
QRectF Bullet::boundingRect() const
{
    return QRectF(0, 0, Ancho, Alto);
}

// Método para pintar la bala en la escena
void Bullet::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    painter->drawPixmap(boundingRect(), *pixmap, pixmap->rect());
    UNUSED(option);
    UNUSED(widget);
}

// Método para obtener la dirección de la bala
QString Bullet::getdirection()
{
    return direction;
}

// Método para obtener la posición X de la bala
int Bullet::getposx()
{
    return Pos_X;
}

// Método para obtener información sobre las balas
QString Bullet::get_Balas()
{
    return Balas;
}

// Método para mover la bala dependiendo de la dirección
void Bullet::move()
{
    if (direction == "derecha")
    {
        Pos_X += 5;
        setX(Pos_X);
    }
    if (direction == "izquierda")
    {
        Pos_X -= 5;
        setX(Pos_X);
    }
}

