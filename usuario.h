#ifndef USUARIO_H
#define USUARIO_H

#include <QDialog>

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

private:
    Ui::usuario *ui;
};

#endif // USUARIO_H
