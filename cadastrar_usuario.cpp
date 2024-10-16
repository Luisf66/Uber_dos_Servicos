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
    query.prepare("INSERT INTO usuario (nome, email, senha, telefone, cpf, tipo_usuario, ativo) "
                  "VALUES (:nome, :email, :senha, :telefone, :cpf, :tipo_usuario, '1')");

    query.bindValue(":nome", variavel_global::nome);
    query.bindValue(":email", variavel_global::email);
    query.bindValue(":senha", variavel_global::senha);
    query.bindValue(":telefone", variavel_global::telefone);
    query.bindValue(":cpf", variavel_global::cpf);
    query.bindValue(":tipo_usuario", variavel_global::tipoStr);

    if (!query.exec()) {
        //qDebug() << "Erro ao inserir no banco de dados:" << query.lastError().text();
        QMessageBox::critical(this, "Erro", "Não foi possível cadastrar o usuário.");
    } else {
        QMessageBox::information(this, "Sucesso", "Usuário cadastrado com sucesso.");
        variavel_global::logado = true;
        usuario user;
        this->close();
        user.exec();
    }
}


void cadastrar_usuario::on_btn_cancelar_cadastrar_clicked()
{
    close();
}

