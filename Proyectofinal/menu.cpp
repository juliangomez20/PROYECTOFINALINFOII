#include "menu.h"
#include "ui_menu.h"

Menu::Menu(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Menu)
{
    ui->setupUi(this);
    iniciodesesion = new Iniciodesesion();
    multijugador = new Multijugador();
}

Menu::~Menu()
{
    delete ui;
}

void Menu::on_pushButton_clicked()
// al clikear un boton abre ell modo logiarse
{
    hide();
    iniciodesesion->show();


}

void Menu::on_pushButton_2_clicked()//al cliclear un boto muestra el modo multijugador
{
    hide();
    multijugador->show();
}



void Menu::on_pushButton_3_clicked() // al clikear el boto abre un achivo y estrae el nombre y el puntaje del jugador
{
    int espacios =0;
    QString Informacion = "";
    QFile archivo("hola.txt");
    QString Linea;
    QString Palabra;
    if(!archivo.open(QFile::ReadOnly | QFile::Text)){
        return;
    }
    while (! archivo.atEnd() ) {
        Linea = archivo.readLine();
        for (int i=0; i < Linea.size();i++) {
            if(Linea[i] == ' ' or Linea[i] == '\n'){
                if(espacios ==0){
                    espacios +=1;
                    Informacion += Palabra + ' ';
                }

                else if(espacios ==9 ) {
                    espacios +=1;
                    Informacion += Palabra + '\n';

                }
                espacios +=1;
                Palabra = "";

            }
            else {
                Palabra += Linea[i];

            }
        }
        espacios = 0;
    }
    QMessageBox::about(this, "Bloc de notas",Informacion);
    archivo.flush();
    archivo.close();
    Informacion ="";
    QString txt;

}
