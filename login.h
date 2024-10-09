#ifndef LOGIN_H
#define LOGIN_H

#include <QMainWindow>

#include "conexao.h"
#include "variavel_global.h"

QT_BEGIN_NAMESPACE
namespace Ui {
class login;
}
QT_END_NAMESPACE

class login : public QMainWindow
{
    Q_OBJECT
public:
    login(QWidget *parent = nullptr);
    ~login();
    void limpar_login();
private slots:
    void on_btn_login_clicked();

    void on_btn_cadastro_clicked();

private:
    Ui::login *ui;
    Conexao conexao;
    void conectar();
    void desconectar();
    bool verifica_conexao();
};
#endif // LOGIN_H
