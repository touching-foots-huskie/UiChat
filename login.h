#ifndef LOGIN_H
#define LOGIN_H

#include <QDialog>
#include "client.h"
#include <QMessageBox>
#include <stdlib.h>

namespace Ui {
class login;
struct nk;
}

struct nk
{
    int name;
    int password;
};

class login : public QDialog
{
    Q_OBJECT

public:
    client_core* myclient;
    nk mynk;
    login(client_core* myclient, QWidget *parent);
    ~login();


private slots:
    void on_sendButton_clicked();

public slots:
    void relogin();
private:
    Ui::login *ui;
};

#endif // LOGIN_H
