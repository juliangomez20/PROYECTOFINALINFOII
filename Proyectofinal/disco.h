#ifndef DISCO_H
#define DISCO_H

#include "librerias.h"

// Declaración de la clase Disco que hereda de QObject y QGraphicsItem
class Disco : public QObject, public QGraphicsItem
{
    Q_OBJECT  // Se marca como un objeto de Qt para admitir señales y ranuras

private:
    // Atributos privados de la clase Disco
    int Pos_X, Pos_Y;
    int Vel_X;
    int Alto, Ancho;
    int angulo;
    QString Clase;
    QString direction;
    QPixmap *pixmap;
    QTimer *timermove;
    QTimer *timermoveX;

public:
    // Constructor de la clase Disco
    explicit Disco(int x, int y, QString clase, QObject *parent = nullptr);

    // Métodos públicos para pintar la imagen y obtener información
    QRectF boundingRect() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);

    // Métodos Get para obtener información sobre el Disco
    int getVelX();
    int getWidth();
    int get_Pos_X();
    QString getDirection();

    // Métodos Set para establecer valores en el Disco
    void setVelX(int);
    void set_Pos_X(int);
    void setDirection(QString);

signals:


public slots:
    // Ranuras (slots) para funciones específicas
    void moveRotation();  // Función para rotar el disco
    void mover_X();       // Función para mover el disco en el eje X
};

#endif // DISCO_H

