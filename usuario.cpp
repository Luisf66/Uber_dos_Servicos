#include "usuario.h"
#include "ui_usuario.h"

#include "servico.h"

usuario::usuario(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::usuario)
{
    ui->setupUi(this);
    info_user();
    connect(ui->btn_editar_usuario, &QPushButton::clicked, this, &usuario::on_btn_editar_usuario_clicked);
    connect(ui->btn_metodo_pagamento, &QPushButton::clicked, this, &usuario::on_btn_metodo_pagamento_clicked);
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


void usuario::on_btn_excluir_usuario_clicked()
{
    QMessageBox::StandardButton opcao = QMessageBox::question(this,"Excluir conta","Você deseja deletar sua conta permanentemente?",QMessageBox::Yes|QMessageBox::No);
    if(opcao == QMessageBox::Yes)
    {
        QSqlQuery query;
        query.prepare("DELETE FROM usuario WHERE id_usuario ="+QString::number(variavel_global::id_usuario));
        if(query.exec())
        {
            QMessageBox::information(this,"Excluir conta","Seus dados foram deletados");
            this->close();
        }
    }
    else{
        QMessageBox::information(this,"Excluir conta", "Conta não deletada");
    }
}


void usuario::on_btn_menu_servico_clicked()
{
    servico trabalho;
    this->close();
    trabalho.exec();
}


void usuario::on_btn_editar_usuario_clicked()
{
    // Muda o widget visível no QStackedWidget para a página de editar (índice 0)
    ui->stackedWidget->setCurrentIndex(0);
}


void usuario::on_btn_metodo_pagamento_clicked()
{
    // Muda o widget visível no QStackedWidget para a página de pagamento (índice 1)
    ui->stackedWidget->setCurrentIndex(1);
}


void usuario::on_btn_salvar_editar_3_clicked()
{
    QString nome_titular = ui->campo_nome_titular->text();
    QString numero_cartao = ui->campo_numero_cartao->text();
    QString cod_seguranca = ui->campo_codigo_seguranca->text();
    QString validade = ui->campo_validade->text();

    QSqlQuery query;
    query.prepare("INSERT INTO pagamento (id_usuario, nome_titular, numero_cartao, validade, cod_seguranca) "
                  "VALUES ( '"+QString::number(variavel_global::id_usuario)+"' , '"+nome_titular+"', '"+numero_cartao+"',"
                  " '"+validade+"', '"+cod_seguranca+"' )");
    if(query.exec())
    {
        QMessageBox::information(this, "Cadastro Realizado", "Dados do Cartão Salvo com Sucesso");
        on_btn_cancelar_editar_3_clicked();
    }
    else{
        QMessageBox::critical(this,"Operação não Realizada","Dados não cadastrados");
    }
}


void usuario::on_btn_cancelar_editar_3_clicked()
{
    ui->campo_nome_titular->clear();
    ui->campo_numero_cartao->clear();
    ui->campo_codigo_seguranca->clear();
    ui->campo_validade->clear();
    ui->campo_numero_cartao->setFocus();
}

