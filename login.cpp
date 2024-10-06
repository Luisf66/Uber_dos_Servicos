#include "login.h"
#include "./ui_login.h"

login::login(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::login)
{
    ui->setupUi(this);

    if(conexao.conectar())
    {
        ui->label_conexao->setText("Conectado");
    }
    else{
        ui->label_conexao->setText("Desconectado");
    }

}

login::~login()
{
    delete ui;
}
