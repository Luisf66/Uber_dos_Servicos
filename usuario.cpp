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

void usuario::on_btn_salvar_editar_clicked()
{
    QString nome = ui->campo_editar_nome->text();
    QString email = ui->campo_editar_email->text();
    QString senha = ui->campo_editar_senha->text();
    QString cpf = ui->campo_editar_cpf->text();
    QString telefone = ui->campo_editar_telefone->text();

    QSqlQuery query;
    query.prepare("UPDATE usuario SET nome = '"+nome+"', email = '"+email+"', senha = '"+senha+"',"
    " cpf = '"+cpf+"', telefone = '"+telefone+"' WHERE id_usuario =" + QString::number(variavel_global::id_usuario));
    if(query.exec())
    {
        QMessageBox::information(this,"Dados Alterados","Suas informações foram atualizadas");
        ui->nome_usuario->setText(nome);
        ui->cpf_usuario->setText(cpf);
        ui->email_usuario->setText(email);
        ui->telefone_usuario->setText(telefone);

        on_btn_cancelar_editar_clicked();
    }
    else{
        QMessageBox::critical(this,"Falha na edição","Não foi possivel modificar os dados");
    }
}


void usuario::on_btn_cancelar_editar_clicked()
{
    ui->campo_editar_nome->clear();
    ui->campo_editar_email->clear();
    ui->campo_editar_senha->clear();
    ui->campo_editar_cpf->clear();
    ui->campo_editar_telefone->clear();
    ui->campo_editar_nome->setFocus();
}

