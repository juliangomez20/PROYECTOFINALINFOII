#ifndef JUGADOR_H
#define JUGADOR_H

#include "librerias.h"

class Jugador : public QObject, public QGraphicsItem
{
    Q_OBJECT
private:
    //atribustos principales
    int Pos_X, Pos_X_Base;
    int Pos_Y, Pos_Y_Base;
    int Pos_Base;
    int Ancho;
    int Alto;
    int velY;
    int velX;
    int velCaida;
    QString direction;
    short int Aux_Derecha_Run = 1;
    short int Aux_Izquierda_Run = 1;

    //variables secundarias
    bool EstadoPosicionBase;
    bool falling;
    bool escalera;
    bool Mov_De =  true;
    bool Mov_Iz = true;

    //variables a parte
    clock_t tiempo;
    QPixmap *pixmap;
    QTimer *timerSalto, *timerCaida, *timerfricion;

public:
    explicit Jugador(int x, int y, QObject *parent = nullptr);
    // pinta el objeto
    QRectF boundingRect() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
    Jugador();

    //metodes get:obtener
    bool getfalling();
    int getPos_X ();
    int getPos_Y ();
    int getAncho ();
    int getAlto ();
    QString getDireccion ();
    bool getEstadoPosBase();
    //metodos set:modificar
    void setPosBase(int);
    void set_Y(int);
    void set_X(int);
    void set_Vel_Y(int);
    void set_Y_Ini(int);
    void set_X_Ini(int);
    //metodos de movimientos
    void Mover_De();
    void Mover_iz();
    void Animacion_Run_Derecha2();
    void Animacion_Run_Izquierda2();
    void Animacion_Run_Derecha();
    void Animacion_Run_Izquierda();
    void AnimaSaltar();
    void AnimaSaltar2();
    void Retur_Pos_inicial ();

signals:

public slots:
    //para que el jugador salte y caiga
    void fricion();
    void salto();
    void caidaLibre();

};

#endif // JUGADOR_H
