#include "servico.h"
#include "ui_servico.h"

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
