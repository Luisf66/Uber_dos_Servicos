#include "cadastrar_usuario.h"
#include "ui_cadastrar_usuario.h"

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
        qDebug() << "Você é prestador";
    }
    else{
        qDebug() << "Você é comum";
    }
}

