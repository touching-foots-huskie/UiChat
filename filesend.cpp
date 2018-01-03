#include "filesend.h"
#include "ui_filesend.h"

FileSend::FileSend(client_core* myclient, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::FileSend)
{
    ui->setupUi(this);
    ui->progressBar->setMaximum(10);
    ui->progressBar->setMinimum(0);
    this->myclient = myclient;
}

FileSend::~FileSend()
{
    delete ui;
}

void FileSend::on_sendButton_clicked()
{
    this->ui->progressBar->setValue(0);
    QString filename = this->ui->lineEdit->text();
    for(int i=0;i<=10;i++)
    {
        this->ui->progressBar->setValue(i);
    }
    accept();
    return;
}
