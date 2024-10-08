#include "usuario.h"
#include "ui_usuario.h"

usuario::usuario(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::usuario)
{
    ui->setupUi(this);
    info_user();
}

usuario::~usuario()
{
    delete ui;
}

void usuario::info_user()
{
    QString tipo;
    if(variavel_global::tipoStr == 'P')
    {
        tipo = "Prestador de Serviço";
    }
    else{
        tipo = "Usuário comum";
    }

    ui->nome_usuario->setText(variavel_global::nome);
    ui->cpf_usuario->setText(variavel_global::cpf);
    ui->email_usuario->setText(variavel_global::email);
    ui->telefone_usuario->setText(variavel_global::telefone);
    ui->tipo_usuario->setText(tipo);
    ui->avaliacao_usuario->setText(QString::number(variavel_global::mediaAvaliacao, 'f', 2));
}
