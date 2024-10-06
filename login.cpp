#include "login.h"
#include "./ui_login.h"

#include <QDebug>

login::login(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::login)
{
    ui->setupUi(this);
}

login::~login()
{
    delete ui;
}
void login::limpar_login(){
    ui->campo_usuario->clear();
    ui->campo_senha->clear();
    ui->campo_usuario->setFocus();
}


void login::on_btn_login_clicked()
{
    conexao.conectar();
    QString nome_usuario = ui->campo_usuario->text();
    QString senha_usuario = ui->campo_senha->text();
    bool logado = false;

    // qDebug() << "Nome: " << nome_usuario;
    // qDebug() << "Senha: " << senha_usuario;
    QSqlQuery query;
    QString busca = "SELECT id_usuario, nome, senha FROM usuario WHERE nome ='"+nome_usuario+"' AND senha='"+senha_usuario+"'";
    query.prepare(busca);
    //qDebug() << "Busca: " << busca;
    if(query.exec())
    {
        query.first();
        if(query.value(1).toString() != "")
        {
            logado = true;
            QMessageBox::information(this,"Login Realizado","Você está conectado");
            //qDebug() << "Logado com sucesso";
            //conexao.desconectar();
            //return logado;
        }
        else{
            QMessageBox::critical(this,"Falha no Login", "Usuário ou Senha incorretos");
        }
    }
    else{
        QMessageBox::critical(this,"Falha no Login","Busca não Realizada");
    }
    limpar_login();
}

