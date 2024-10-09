#include "login.h"
#include "./ui_login.h"

#include <QDebug>

#include "usuario.h"
#include "cadastrar_usuario.h"

int variavel_global::id_usuario;
QString variavel_global::nome;
QString variavel_global::email;
QString variavel_global::cpf;
QString variavel_global::senha;
QString variavel_global::tipoStr;
QString variavel_global::telefone;
QDate variavel_global::dataCadastro;
float variavel_global::mediaAvaliacao;
bool variavel_global::logado;

login::login(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::login)
{
    ui->setupUi(this);
    variavel_global::logado = false;
    conexao.conectar();
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
    QString nome_usuario = ui->campo_usuario->text();
    QString senha_usuario = ui->campo_senha->text();

    // qDebug() << "Nome: " << nome_usuario;
    // qDebug() << "Senha: " << senha_usuario;
    QSqlQuery query;
    query.prepare("SELECT * FROM usuario WHERE nome ='"+nome_usuario+"' AND senha='"+senha_usuario+"'");

    if(query.exec())
    {
        query.first();
        // qDebug() << "query.first() retornou true. Usuário encontrado:";
        // qDebug() << "ID:" << query.value("id_usuario").toInt();
        // qDebug() << "Nome:" << query.value("nome").toString();
        // qDebug() << "Email:" << query.value("email").toString();
        if(query.value(1).toString() != "")
        {
            variavel_global::id_usuario = query.value("id_usuario").toInt();
            variavel_global::nome = query.value("nome").toString();
            variavel_global::email = query.value("email").toString();
            variavel_global::cpf = query.value("cpf").toString();
            variavel_global::senha = query.value("senha").toString();
            variavel_global::tipoStr = query.value("tipo_usuario").toString().trimmed();
            variavel_global::dataCadastro = query.value("data_cadastro").toDate();
            variavel_global::telefone = query.value("telefone").toString();
            variavel_global::mediaAvaliacao = query.value("media_avaliacao").toFloat();

            variavel_global::logado = true;
            QMessageBox::information(this, "Login Realizado", "Você está conectado");

            usuario user;
            this->close();
            user.exec();

            // // //Debug para mostrar os valores obtidos
            // qDebug() << "ID:" << variavel_global::id_usuario;
            // qDebug() << "Nome:" << variavel_global::nome;
            // qDebug() << "Senha:" << variavel_global::senha;
            // qDebug() << "Email:" << variavel_global::email;
            // qDebug() << "CPF:" << variavel_global::cpf;
            // qDebug() << "Tipo:" << variavel_global::tipoStr;
            // qDebug() << "Data de Cadastro:" << variavel_global::dataCadastro;
            // qDebug() << "Telefone:" << variavel_global::telefone;
            // qDebug() << "Média de Avaliação:" << variavel_global::mediaAvaliacao;
            // qDebug() << "AHOY";
        }
        else{
            QMessageBox::critical(this,"Falha no Login", "Usuário ou Senha incorretos");
        }
    }
    else{
        QMessageBox::critical(this,"Falha no Login","Busca não Realizada");
        qDebug() << "Erro ao executar a query:" << query.lastError().text();
    }
    limpar_login();
}


void login::on_btn_cadastro_clicked()
{
    cadastrar_usuario cadastro;
    cadastro.exec();
}

