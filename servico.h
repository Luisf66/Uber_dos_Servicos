#ifndef SERVICO_H
#define SERVICO_H

#include <QDialog>

namespace Ui {
class servico;
}

class servico : public QDialog
{
    Q_OBJECT

public:
    explicit servico(QWidget *parent = nullptr);
    ~servico();

private slots:
    void on_btn_menu_usuario_clicked();

private:
    Ui::servico *ui;
};

#endif // SERVICO_H
