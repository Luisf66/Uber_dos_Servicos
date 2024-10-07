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
    QString busca = "SELECT * FROM usuario WHERE nome ='"+nome_usuario+"' AND senha='"+senha_usuario+"'";
    query.prepare(busca);
    //qDebug() << "Busca: " << busca;
    if(query.exec())
    {
        query.first();
        if(query.value(1).toString() != "")
        {
            int id = query.value("id_usuario").toInt();
            QString nome = query.value("nome").toString();
            QString email = query.value("email").toString();
            QString cpf = query.value("cpf").toString();
            QString senha = query.value("senha").toString();
            QString tipoStr = query.value("tipo_usuario").toString().trimmed();
            QDate dataCadastro = query.value("data_cadastro").toDate();
            QString telefone = query.value("telefone").toString();
            float mediaAvaliacao = query.value("media_avaliacao").toFloat();

            logado = true;
            QMessageBox::information(this, "Login Realizado", "Você está conectado");
            usuario.show();
            this->close();

            // Debug para mostrar os valores obtidos
            qDebug() << "ID:" << id;
            qDebug() << "Nome:" << nome;
            qDebug() << "Email:" << email;
            qDebug() << "CPF:" << cpf;
            qDebug() << "Tipo:" << tipoStr;
            qDebug() << "Data de Cadastro:" << dataCadastro;
            qDebug() << "Telefone:" << telefone;
            qDebug() << "Média de Avaliação:" << mediaAvaliacao;
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

