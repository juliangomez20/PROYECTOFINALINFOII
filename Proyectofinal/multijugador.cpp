#include "multijugador.h"
#include "ui_multijugador.h"

Multijugador::Multijugador(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Multijugador)
{
    ui->setupUi(this);
    //se da valor a las varaibles
    winer= new Winer;
    findeljuego= new Findeljuego;
    tiempo = clock();

    //se incia el tiempo
    startTimer(2000/60);

    //creo un scena y la agrego a un graphicsView
    scene = new QGraphicsScene(this);
    ui->graphicsView->setScene(scene);
    ui->graphicsView->setBackgroundBrush(QImage(":/Personaje/Fondo/BG.png").scaled(1200,600)); //Intoducir fondo
    scene->setSceneRect(Pos_XP,Pos_YP,3600,600);

    //Recorre la matriz del mapa y agregas los objetos
    for (int i=0;i<15;i++) {
        for (int j=0;j<90;j++) {

             if(mapa[i][j]==1){
                 listDisco.push_back(new Disco(j*40,i*40+40,"Mov_X"));
                 scene->addItem(listDisco.last());
             }
             if(mapa[i][j]==2){
                 listPlataformas.push_back(new Plataformas(j*40,i*40,"Piso"));
                 scene->addItem(listPlataformas.last());
             }
             if(mapa[i][j]==3){
                 listPlataformas.push_back(new Plataformas(j*40,i*40,"Hueco"));
                 scene->addItem(listPlataformas.last());
             }
             if(mapa[i][j]==4){
                 listPlataformas.push_back(new Plataformas(j*40,i*40,"Pared"));
                 scene->addItem(listPlataformas.last());
             }
             if(mapa[i][j]==5){
                 listPlataformas.push_back(new Plataformas(j*40,i*40,"Tranpolin"));
                 scene->addItem(listPlataformas.last());
             }
             if(mapa[i][j]==6){
                 listPlataformas.push_back(new Plataformas(j*40,i*40,"Moneda"));
                 scene->addItem(listPlataformas.last());
             }
             if(mapa[i][j]==7){
                 listEnemigos.push_back(new Enemigos(j*40,i*40+20,"Derecha"));
                 scene->addItem(listEnemigos.last());
             }
             if(mapa[i][j]==8){
                 listEnemigos.push_back(new Enemigos(j*40,i*40+20,"Izquierda"));
                 scene->addItem(listEnemigos.last());
             }
             if(mapa[i][j]==9){
                 listPlataformas.push_back(new Plataformas(j*40,i*40,"Door"));
                 scene->addItem(listPlataformas.last());
             }
             if(mapa[i][j]==10){
                 listPlataformas.push_back(new Plataformas(j*40,i*40,"Rebote"));
                 scene->addItem(listPlataformas.last());
             }
             if(mapa[i][j]==11){
                 listPlataformas.push_back(new Plataformas(j*40,i*40-5,"Pinchos"));
                 scene->addItem(listPlataformas.last());
             }
             if(mapa[i][j]==12){
                 ListCuerda.push_back(new Cuerda(j*40,i*40));
                 scene->addItem(ListCuerda.last());
             }
             if(mapa[i][j]==13){
                 ListJefe_final.push_back(new Jefe_final(j*40,i*40,"Abajo"));
                 scene->addItem(ListJefe_final.last());
             }
        }
    }

    //creo un jugador y lo agrego a la escena
    jugador=new Jugador(Pos_XJ,Pos_YJ); // le doy los valores de x y y
    scene->addItem(jugador);
    jugador2=new Jugador(Pos_XJ,Pos_YJ);//Escondido atras de Rick
    scene->addItem(jugador2);



    //Inicio el tipo de la colociones
    timerColisiones=new QTimer;
    connect(timerColisiones,SIGNAL(timeout()),this,SLOT(colisiones()));
    timerColisiones->start(0);

}
Multijugador::~Multijugador()
{
    delete ui;
    delete timerColisiones;
}

void Multijugador::keyPressEvent(QKeyEvent *event)
    {
    keys[event->key()]=true; QWidget::keyPressEvent(event);
    }


void Multijugador::keyReleaseEvent(QKeyEvent *event)
    {
    keys[event->key()]=false; QWidget::keyReleaseEvent(event);
    }


void Multijugador::timerEvent(QTimerEvent *)
{
    if (Balas ){
        if(keys[Qt::Key_F]){
            if(jugador->getDireccion()=="derecha"){
                listBullet.push_back(new Bullet(jugador->getPos_X()+jugador->getAncho(),jugador->getPos_Y()+jugador->getAlto()/2,jugador->getDireccion(),""));
            }
            if(jugador->getDireccion()=="izquierda"){
                listBullet.push_back(new Bullet(jugador->getPos_X(),jugador->getPos_Y()+jugador->getAlto()/2,jugador->getDireccion(),""));
            }

            scene->addItem(listBullet.last());
            Balas = true;
        }
        if(keys[Qt::Key_P]){
            if(jugador2->getDireccion()=="derecha"){
                listBullet.push_back(new Bullet(jugador2->getPos_X()+jugador2->getAncho(),jugador2->getPos_Y()+jugador2->getAlto()/2,jugador2->getDireccion(),""));
            }
            if(jugador2->getDireccion()=="izquierda"){
                listBullet.push_back(new Bullet(jugador2->getPos_X(),jugador2->getPos_Y()+jugador2->getAlto()/2,jugador2->getDireccion(),""));
            }

            scene->addItem(listBullet.last());
            Balas = true;
        }
    }
    else {
        if(keys[Qt::Key_R]){
            Balas = true;
        }
    }


    if(keys[Qt::Key_A]){
        jugador->Mover_iz();
        jugador->Animacion_Run_Izquierda();
    }

    if(keys[Qt::Key_D]){
        jugador->Mover_De();
        jugador->Animacion_Run_Derecha();
    }
    if(keys[Qt::Key_Space]){
         jugador->salto();

    }
    if(keys[Qt::Key_J]){
        jugador2->Mover_iz();
        jugador2->Animacion_Run_Izquierda2();
    }

    if(keys[Qt::Key_L]){
        jugador2->Mover_De();
        jugador2->Animacion_Run_Derecha2();
    }
    if(keys[Qt::Key_I]){
         jugador2->salto();
         jugador2->AnimaSaltar2();

    }
}
void Multijugador::colisiones()
{
    //colisiones de las paltaformas
    for(int i=0;i<listPlataformas.size();i++)
    {
        //Colisin para que se quede arriba de las plataformas
        listPlataformas.at(i)->Actualizar_Pos_Per(jugador);
        listPlataformas.at(i)->Actualizar_Pos_Per(jugador2);
        //Colision de las moneas
        if(listPlataformas.at(i)->getClase() == "Moneda" && listPlataformas.at(i)->collidesWithItem(jugador)){
            scene->removeItem(listPlataformas.at(i));
            listPlataformas.removeAt(i);
        }
        if(listPlataformas.at(i)->getClase() == "Moneda" && listPlataformas.at(i)->collidesWithItem(jugador2)){
            scene->removeItem(listPlataformas.at(i));
            listPlataformas.removeAt(i);
        }
        //Colision para que desaparescan las balas
        for(int j=0;j<listBullet.size();j++){
            if(listPlataformas.at(i)->getClase() == "Pared" && listPlataformas.at(i)->collidesWithItem(listBullet.at(j))){
                scene->removeItem(listBullet.at(j));
                listBullet.removeAt(j);
            }
        }
        //Colision para pasar de Nivel
        if(listPlataformas.at(i)->collidesWithItem(jugador) && listPlataformas.at(i)->getClase()== "Door"){

            Pos_XJ = jugador->getPos_X()+140;
            Pos_YJ = jugador->getPos_Y();
            Pos_XP = jugador->getPos_X()+100;
            jugador->set_X(Pos_XJ);
            jugador->set_Y(Pos_YJ);
            jugador->set_X_Ini(Pos_XJ);
            jugador->set_Y_Ini(Pos_YJ);
            jugador2->set_X(Pos_XJ);
            jugador2->set_Y(Pos_YJ);
            jugador2->set_X_Ini(Pos_XJ);
            jugador2->set_Y_Ini(Pos_YJ);

            scene->setSceneRect(Pos_XP,Pos_YP,3600,600);
        }
        //colision Para los rebotes de los enemigos
        for (int j=0;j<listEnemigos.size();j++) {
            if (listEnemigos.at(j)->collidesWithItem(listPlataformas.at(i)) && listPlataformas.at(i)->getClase()=="Rebote"){
                if(listEnemigos.at(j)->get_Direccion()=="Derecha"){
                    listEnemigos.at(j)->set_Pos_X(listEnemigos.at(j)->get_Pos_X()- 5);
                    listEnemigos.at(j)->set_Direcion("Izquierda");
                }
                else {
                    listEnemigos.at(j)->set_Pos_X(listEnemigos.at(j)->get_Pos_X()+ 5);
                    listEnemigos.at(j)->set_Direcion("Derecha");
                }
            }
        }
        //colision de los pinchos con el jugador
        if (listPlataformas.at(i)->collidesWithItem(jugador) && listPlataformas.at(i)->getClase()== "Pinchos"){

                jugador->Retur_Pos_inicial();
        }
        if (listPlataformas.at(i)->collidesWithItem(jugador2) && listPlataformas.at(i)->getClase()== "Pinchos"){

                jugador2->Retur_Pos_inicial();
        }
        //colisiones para que rebote el disco
        for (int j=0;j<listDisco.size();j++) {
            if (listDisco.at(j)->collidesWithItem(listPlataformas.at(i)) && listPlataformas.at(i)->getClase()=="Rebote"){
                if (listDisco.at(j)->getDirection()=="Derecha"){
                    listDisco.at(j)->set_Pos_X(listDisco.at(j)->get_Pos_X()+5);
                }
                if (listDisco.at(j)->getDirection()=="Izquierda"){
                  listDisco.at(j)->set_Pos_X(listDisco.at(j)->get_Pos_X()-5);
                }
                listDisco.at(j)->setVelX(listDisco.at(j)->getVelX()*-1);
            }
        }
    }
    //Colision de los enemigos
   for(int i=0;i<listEnemigos.size();i++){
       for (int j=0;j<listBullet.size();j++) {
           if (listBullet.at(j)->collidesWithItem(listEnemigos.at(i))){
                scene->removeItem(listEnemigos.at(i));
                listEnemigos.at(i)->setPos(-100,-100);
                scene->removeItem(listBullet.at(j));
                listBullet.removeAt(j);
           }

       }
       if (jugador->collidesWithItem(listEnemigos.at(i))){

               jugador->Retur_Pos_inicial();

       }
       if (jugador2->collidesWithItem(listEnemigos.at(i))){

               jugador2->Retur_Pos_inicial();

       }
   }
   //Coliones de las sierra
   for (int i =0;i<listDisco.size();i++) {
       if (listDisco.at(i)->collidesWithItem(jugador)){

               jugador->Retur_Pos_inicial();

       }
       if (listDisco.at(i)->collidesWithItem(jugador2)){

               jugador2->Retur_Pos_inicial();

       }
   }
   //colision cuerda
   for (int i=0;i<ListCuerda.size();i++) {
       if(ListCuerda.at(i)->collidesWithItem(jugador)){

               jugador->Retur_Pos_inicial();

       }
       if(ListCuerda.at(i)->collidesWithItem(jugador2)){

               jugador2->Retur_Pos_inicial();

       }
   }
   //colisiones para el jefe final
   for (int j=0;j<ListJefe_final.size();j++) {
       if (int (clock() - tiempo) >= 800){
           listBullet.push_back(new Bullet(ListJefe_final.at(j)->get_Pos_X(),ListJefe_final.at(j)->get_Pos_Y()+ListJefe_final.at(j)->get_Alto()/2,"izquierda","Jefe"));
           scene->addItem(listBullet.last());
           tiempo = clock();

       }
       for (int i = 0;i<listPlataformas.size();i++) {
           if (listPlataformas.at(i)->collidesWithItem(ListJefe_final.at(j)) && listPlataformas.at(i)->getClase()=="Rebote"){

               if (ListJefe_final.at(j)->get_Direccion()=="Arriba"){
                   ListJefe_final.at(j)->set_Pos_Y(ListJefe_final.at(j)->get_Pos_Y()+5);
                   ListJefe_final.at(j)->set_Direcion("Abajo");
               }
               else{
                   ListJefe_final.at(j)->set_Pos_Y(ListJefe_final.at(j)->get_Pos_Y()-5);
                   ListJefe_final.at(j)->set_Direcion("Arriba");
               }
           }
       }
       for (int b=0;b<listBullet.size();b++) {
           if (listBullet.at(b)->collidesWithItem(jugador) && listBullet.at(b)->getdirection() =="izquierda" && listBullet.at(b)->get_Balas()=="Jefe"){

                   jugador->Retur_Pos_inicial();

           }
           if (listBullet.at(b)->collidesWithItem(jugador2) && listBullet.at(b)->getdirection() =="izquierda" && listBullet.at(b)->get_Balas()=="Jefe"){

                   jugador2->Retur_Pos_inicial();

           }
           if(listBullet.at(b)->collidesWithItem(ListJefe_final.at(j)) && listBullet.at(b)->getdirection()=="derecha"){
               jefe_vida --;
               if (jefe_vida ==0){
                    winer->show();
                    hide();
                }
           }
       }
   }
}

