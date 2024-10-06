#ifndef CONEXAO_H
#define CONEXAO_H

#include <QtSql>
#include <QMessageBox>
#include <QDebug>

class Conexao {
public:
    QSqlDatabase banco_db;
    QString host;
    QString database;
    QString user;
    QString password;
    int port;

    Conexao() {
        // Definir os parâmetros de conexão usando as informações do Supabase
        host = "aws-0-us-east-1.pooler.supabase.com";    // Host fornecido pelo Supabase
        database = "postgres";                           // Nome do banco de dados fornecido
        user = "postgres.bbysunfvxjwcsyaakily";           // Nome de usuário fornecido
        password = "1fSjooZ7XSc1YgXn";                  // Substitua pela senha real
        port = 6543;                                      // Porta fornecida pelo Supabase

        // Adiciona o driver do PostgreSQL
        banco_db = QSqlDatabase::addDatabase("QPSQL");
        banco_db.setHostName(host);
        banco_db.setDatabaseName(database);
        banco_db.setUserName(user);
        banco_db.setPassword(password);
        banco_db.setPort(port);
    }

    bool conectar() {
        if (!banco_db.open()) {
            qDebug() << "Erro ao conectar ao banco de dados PostgreSQL: " << banco_db.lastError().text();
            return false;
        } else {
            qDebug() << "Conexão com banco de dados PostgreSQL bem-sucedida!";
            return true;
        }
    }

    void desconectar() {
        banco_db.close();
        qDebug() << "Conexão com o banco de dados foi fechada.";
    }

    bool verifica_conexao() {
        return banco_db.isOpen();
    }
};

#endif // CONEXAO_H
