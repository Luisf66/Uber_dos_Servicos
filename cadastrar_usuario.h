#ifndef CADASTRAR_USUARIO_H
#define CADASTRAR_USUARIO_H

#include <QDialog>

#include "conexao.h"
#include "variavel_global.h"

namespace Ui {
class cadastrar_usuario;
}

class cadastrar_usuario : public QDialog
{
    Q_OBJECT

public:
    explicit cadastrar_usuario(QWidget *parent = nullptr);
    ~cadastrar_usuario();

private slots:
    void on_btn_salvar_cadastrar_clicked();

private:
    Ui::cadastrar_usuario *ui;
};

#endif // CADASTRAR_USUARIO_H
