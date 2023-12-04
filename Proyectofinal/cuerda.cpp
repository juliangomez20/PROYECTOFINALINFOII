#include "cuerda.h"

// Constructor de la clase Cuerda
Cuerda::Cuerda(int x, int y, QObject *parent) : QObject(parent)
{
    // Inicialización de atributos
    Pos_X = x;
    Pos_Y = y;
    Ancho = 60;
    Alto = 140;
    angulo = 315;

    // Cargar la imagen de la cuerda
    pixmap = new QPixmap(":/Personaje/objetos/blade.png");

    // Configuración del temporizador para la rotación continua
    timercuerda = new QTimer;
    connect(timercuerda, SIGNAL(timeout()), this, SLOT(moveRotation()));
    timercuerda->start(5); // Establecer la velocidad de rotación

    // Establecer la posición inicial
    setPos(Pos_X, Pos_Y);
}

// Método para obtener el rectángulo delimitador de la cuerda
QRectF Cuerda::boundingRect() const
{
    return QRectF(-Ancho / 2, 0, Ancho, Alto);
}

// Método para pintar la cuerda en la escena
void Cuerda::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    painter->drawPixmap(boundingRect(), *pixmap, pixmap->rect());
    UNUSED(option);
    UNUSED(widget);
}

// Ranura (slot) para realizar la rotación continua de la cuerda
void Cuerda::moveRotation()
{
    // Rotar la imagen dependiendo del ángulo
    this->setRotation(angulo);

    // Cambiar la dirección de la rotación cuando se alcanzan ciertos límites
    if (angulo <= 270.0)
    {
        sumaAngulo *= -1;
    }
    if (angulo >= 450.0)
    {
        sumaAngulo *= -1;
    }

    // Actualizar el ángulo para la próxima iteración
    angulo += sumaAngulo;
}
