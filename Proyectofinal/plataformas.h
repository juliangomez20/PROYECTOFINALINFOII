#ifndef PLATAFORMAS_H
#define PLATAFORMAS_H

#include "librerias.h"
#include "jugador.h"

class Plataformas : public QObject, public QGraphicsItem
{
    Q_OBJECT
private:
    int Pos_X,Pos_Y,Alto,Ancho,Salto;
    QPixmap *pixmap;
    QString Clase;

public:
    Plataformas(int x, int y, QString clase, QObject *parent = nullptr);
    QRectF boundingRect() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
    //funciones
    void Actualizar_Pos_Per(Jugador *personaje);
    //get obtener
    QString getClase ();
    int get_Pos_X();
};

#endif // PLATAFORMAS_H
