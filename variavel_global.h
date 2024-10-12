#ifndef VARIAVEL_GLOBAL_H
#define VARIAVEL_GLOBAL_H

#include <QString>
#include <QDate>

class variavel_global {
public:
    static bool logado;
    static int id_usuario;
    static QString nome, email, cpf, senha, tipoStr, telefone, ativo;
    static QDate dataCadastro;
    static float mediaAvaliacao;
};

#endif // VARIAVEL_GLOBAL_H
