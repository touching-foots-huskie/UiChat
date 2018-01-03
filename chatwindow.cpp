#include "chatwindow.h"
#include "ui_chatwindow.h"

chatWindow::chatWindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::chatWindow)
{
    ui->setupUi(this);
}

chatWindow& chatWindow::operator =(const chatWindow& c)
{
    this->ui = c.ui;
    this->emtypyStatus = c.emtypyStatus;
    this->targetName = c.targetName;
    return *this;
}

chatWindow::~chatWindow()
{
    delete ui;
}

void chatWindow::on_sendBtn_clicked()
{
    //send function
    QString content = this->ui->inputtextEdit->toPlainText();
    this->ui->DisplaytextEdit->append(
                QString("\n%1%2%3")
                .arg(tr(this->myclient->name.c_str()))
                .arg(tr(" says: "))
                .arg(content)
                );
    char* msg = this->myclient->webSendMsg(this->targetName.toStdString(), content.toStdString());
    this->myclient->send_packet(msg);
    this->ui->inputtextEdit->clear();
    return;
}

void chatWindow::on_inputtextEdit_textChanged()
{
    //change status
    this->emtypyStatus = this->ui->inputtextEdit->toPlainText().isEmpty();
    this->ui->sendBtn->setDisabled(this->emtypyStatus);
}

void chatWindow::write(QString content)
{
    this->ui->DisplaytextEdit->append(
                QString("\n%1%2%3")
                .arg(this->targetName)
                .arg(tr(" says: "))
                .arg(content)
                );
    return;
}
