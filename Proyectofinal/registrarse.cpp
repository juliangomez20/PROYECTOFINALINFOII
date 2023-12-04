#include "registrarse.h"
#include "ui_registrarse.h"
#include "iniciodesesion.h"

Registrarse::Registrarse(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Registrarse)
{
    ui->setupUi(this);
}

Registrarse::~Registrarse()
{
    delete ui;
}

void Registrarse::on_pushButton_clicked()// cuando presionas el boton abre guarda el nombre del jugador y el usuario y verifica si ya esta reguittrado
{
    QFile archivo("hola.txt");

    QString Linea = "", Palbra = "";
    QString usuario = ui->lineEdit_Usuario->text();
    QString contrasea = ui->lineEdit_Contrasea->text();

    if(!archivo.open(QIODevice::ReadWrite | QIODevice::Text)){
        return;
    }
    while (!archivo.atEnd() ) {
        Linea = archivo.readLine();
        for (int i=0; i < Linea.size();i++) {
            if(Linea[i] == ' ' or Linea[i] == '\n'){
                if(espacios ==0){
                    if(usuario == Palbra){cont++;des=true;}
                }
                else if (espacios==1) {
                    if(contrasea == Palbra){cont++;des =false;}
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
    if(cont ==0){
        QTextStream out(&archivo);
        out << usuario + ' ' + contrasea + ' ' + "45"+' '+"14"+' '+'0'+' '+'0'+' '+'0' + '\n';
        QMessageBox::warning(this,"Iniciar sesion","Usuario creado");
    }
    else if (cont ==1){
        if(des){QMessageBox::warning(this,"Iniciar sesion","Usuario Existente");}
        else{QMessageBox::warning(this,"Iniciar sesion","Constraseña  Existente");}
    }
    else{QMessageBox::warning(this,"Iniciar sesion","Usuario y Contraseña Existentes");}
    cont =0;
    archivo.close();
}

// si ya te registrastte para logiarte

void Registrarse::on_pushButton_2_clicked()
{
    Iniciodesesion *iniciodesesion =new Iniciodesesion;
    hide();
    iniciodesesion->show();
}
