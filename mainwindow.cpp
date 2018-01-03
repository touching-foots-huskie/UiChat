#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(client_core* cc, QWidget *parent):
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->cc = cc;
    this->myname = tr(this->cc->name.c_str());   
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::add_friend_list()
{
    for(map<string, int>::iterator i=this->cc->friend_list.begin();
        i!=this->cc->friend_list.end(); i++)
    {
        // auto initialize:
        this->chatlist[tr(i->first.c_str())].targetName = tr(i->first.c_str());
        this->chatlist[tr(i->first.c_str())].myclient = this->cc;
        // add into list:
        this->ui->friendlist->addItem(tr(i->first.c_str()));
    }
}

void MainWindow::get_login(login *mylogin)
{
    this->mylogin = mylogin;
}

void MainWindow::get_file_send(FileSend* myfilesend)
{
    this->myfilesend = myfilesend;
}

int MainWindow::start_login()
{
    this->mylogin->show();
    return this->mylogin->exec();
}

void MainWindow::refreshChat(QString msg, QString name)
{
    this->chatlist[name].write(msg); //write into it.
}

void MainWindow::on_friendlist_itemClicked(QListWidgetItem *item)
{
    QString name = item->text();
    this->chatlist[name].show();
    return;
}

int MainWindow::on_sendFileButton_clicked()
{
    this->myfilesend->show();
    return this->myfilesend->exec();
}

void MainWindow::on_logoutButton_clicked()
{
    char* logout_data = this->cc->logoutWrap();
    this->cc->send_packet(logout_data);
    close();
}
