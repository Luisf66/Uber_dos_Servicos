#include "cadastrar_usuario.h"
#include "ui_cadastrar_usuario.h"

#include "usuario.h"

cadastrar_usuario::cadastrar_usuario(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::cadastrar_usuario)
{
    ui->setupUi(this);
}

cadastrar_usuario::~cadastrar_usuario()
{
    delete ui;
}

void cadastrar_usuario::on_btn_salvar_cadastrar_clicked()
{
    variavel_global::nome = ui->campo_cadastrar_nome->text();
    variavel_global::email = ui->campo_cadastrar_email->text();
    variavel_global::senha = ui->campo_cadastrar_senha->text();
    variavel_global::cpf = ui->campo_cadastrar_cpf->text();
    variavel_global::telefone = ui->campo_cadastrar_telefone->text();
    if(ui->rb_prestador->isChecked())
    {
        variavel_global::tipoStr = "P";
    }
    else{
        variavel_global::tipoStr = "C";
    }

    QSqlQuery query;
    query.prepare("INSERT INTO usuario (nome, email, senha, telefone, cpf, tipo_usuario) values "
                "( '"+variavel_global::nome+"', '"+variavel_global::email+"', '"+variavel_global::senha+"',"
                " '"+variavel_global::telefone+"', '"+variavel_global::cpf+"', '"+variavel_global::tipoStr+"')");
    if(query.exec())
    {
        QMessageBox::information(this,"Usuário Cadastrado","Seus dados foram cadastrados");
        variavel_global::logado = true;
        usuario user;
        this->close();
        user.exec();
    }
    else{
        QMessageBox::critical(this,"Cadastro inválido","Seus dados não foram cadastrados");
    }
}


void cadastrar_usuario::on_btn_cancelar_cadastrar_clicked()
{
    close();
}

