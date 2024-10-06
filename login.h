#ifndef LOGIN_H
#define LOGIN_H

#include <QMainWindow>

#include "conexao.h"

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

private:
    Ui::login *ui;
    Conexao conexao;
    bool verifica_conexao();
};
#endif // LOGIN_H
