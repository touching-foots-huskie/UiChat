#include "login.h"
#include "ui_login.h"

login::login(client_core* myclient, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::login)
{
    ui->setupUi(this);
    this->myclient = myclient;
}

login::~login()
{
    delete ui;
}

void login::on_sendButton_clicked()
{
    int flag = 0;
    //this function is the login function
    this->mynk.name = this->ui->userlineEdit->text().toInt();
    this->mynk.password = this->ui->pwdlineEdit->text().toInt();
    if(this->myclient->iv_friend_list.count(this->mynk.name)==0)
    {
        this->relogin();
        return;
    }
    else
    {
        char* login_data = this->myclient->webLoginWrap(this->mynk.name,
                                                    this->mynk.password);
        this->myclient->name = this->myclient->iv_friend_list[this->mynk.name];
        this->myclient->send_packet(login_data);
        return;
    }
}

void login::relogin()
{
    QMessageBox::warning(this, tr("warning"), tr("username or password wrong"),QMessageBox::Yes);
    this->ui->userlineEdit->clear();
    this->ui->pwdlineEdit->clear();
    this->ui->userlineEdit->setFocus();
    return;
}
