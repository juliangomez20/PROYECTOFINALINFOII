#include "iniciodesesion.h"
#include "ui_iniciodesesion.h"

#include "menu.h"

Iniciodesesion::Iniciodesesion(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Iniciodesesion)
{
    ui->setupUi(this);
}



Iniciodesesion::~Iniciodesesion()
{
    delete ui;
}

void Iniciodesesion::on_pushButton_clicked()// abre un archivo y revisa el los ususuario y contraseñas que hay dentro del archivo para que ejecute el juego con todo lo nesesario
{
    QFile archivo("hola.txt");

    QString Linea = "", Palbra = "";
    QString usuario = ui->lineEdit_Usuario->text();
    QString contrasea = ui->lineEdit_Contrasea->text();
    int aux = 0;

    if(!archivo.open(QIODevice::ReadOnly | QIODevice::Text)){
        return;
    }
    while (!archivo.atEnd() ) {
        Linea = archivo.readLine();
        for (int i=0; i < Linea.size();i++) {
            if(Linea[i] == ' ' or Linea[i] == '\n'){
                if(espacios ==0){
                    if(usuario == Palbra){
                        cont++;
                        des=true;
                    }
                }
                else if (espacios==1) {
                    if(contrasea == Palbra){
                        cont++;
                        des =false;
                    }
                }
                if(cont == 2 and aux==0 ){
                    if (espacios==2) {
                        PosXJ =Palbra.toInt();
                    }
                    else if (espacios==3) {
                        PosYJ =Palbra.toInt();
                    }
                    else if (espacios==4) {
                        PosXP =Palbra.toInt();
                    }
                    else if (espacios==5) {
                        PosYP =Palbra.toInt();
                    }
                    else if(espacios ==6){
                        score_maxi = Palbra.toInt();
                        aux=1;
                    }
                }
                espacios += 1;
                Palbra= "";
            }

            else {
                Palbra += Linea[i];
            }

        }
        espacios = 0;
    }
    if(cont ==2){
        juego = new Juego(PosXJ,PosYJ,PosXP,PosXP,score_maxi,usuario,contrasea);
        juego->show();
        hide();
    }
    else if (cont ==1){
        if(des){QMessageBox::warning(this,"Iniciar sesion","Contraseña Incorrecto");}
        else{QMessageBox::warning(this,"Iniciar sesion","Usuario Incorrecta");}
    }
    else{QMessageBox::warning(this,"Iniciar sesion","Usuario y Contraseña Incorrectas");}
    cont =0;
    archivo.close();
}


// hace que la clikear un boton para ir a reguitrase
void Iniciodesesion::on_pushButton_3_clicked()
{
    Registrarse *registrarse = new Registrarse();
    registrarse->show();
    hide();
}
// hace que la clikear un boton vuelvas al menu
void Iniciodesesion::on_pushButton_2_clicked()
{

    Menu * menu=new Menu();
    menu->show();
    hide();
}
