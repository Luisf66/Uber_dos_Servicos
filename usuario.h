#ifndef USUARIO_H
#define USUARIO_H

#include <QDialog>

#include "conexao.h"
#include "variavel_global.h"

namespace Ui {
class usuario;
}

class usuario : public QDialog
{
    Q_OBJECT

public:
    explicit usuario(QWidget *parent = nullptr);
    ~usuario();
    void info_user();
private slots:
    void on_btn_salvar_editar_clicked();
    void on_btn_cancelar_editar_clicked();

private:
    Ui::usuario *ui;
};

#endif // USUARIO_H
