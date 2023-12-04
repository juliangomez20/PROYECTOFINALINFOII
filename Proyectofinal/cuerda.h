#ifndef CUERDA_H
#define CUERDA_H

#include "librerias.h"

// Declaración de la clase Cuerda que hereda de QObject y QGraphicsItem
class Cuerda : public QObject, public QGraphicsItem
{
    Q_OBJECT  // Se marca como un objeto de Qt para admitir señales y ranuras

private:
    // Atributos privados de la clase
    int Pos_X, Pos_Y;
    double angulo;
    int Ancho, Alto;
    double sumaAngulo = -0.5;
    QPixmap *pixmap;
    QTimer *timercuerda;

public:
    // Constructor de la clase Cuerda que recibe coordenadas x e y
    explicit Cuerda(int x, int y, QObject *parent = nullptr);

    // Métodos públicos para pintar la imagen y obtener información
    QRectF boundingRect() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);

signals:


public slots:
    // Ranura (slot) para rotar el objeto
    void moveRotation();
};

#endif // CUERDA_H

