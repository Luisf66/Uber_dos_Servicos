#include "servico.h"
#include "ui_servico.h"

#include "usuario.h"

servico::servico(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::servico)
{
    ui->setupUi(this);
}

servico::~servico()
{
    delete ui;
}

void servico::on_btn_menu_usuario_clicked()
{
    usuario user;
    this->close();
    user.exec();
}

