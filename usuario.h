#ifndef USUARIO_H
#define USUARIO_H

#include <QDialog>

namespace Ui {
class usuario;
}

class usuario : public QDialog
{
    Q_OBJECT

public:
    explicit usuario(QWidget *parent = nullptr);
    ~usuario();

private:
    Ui::usuario *ui;
};

#endif // USUARIO_H
