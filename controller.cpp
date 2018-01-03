#include "controller.h"

Controller::Controller(QObject *parent) : QObject(parent)
{
    myclient = new client_core();
    mylistentd = new listenthread(myclient);
    mywindow = new MainWindow(myclient, 0);
    mylogin = new login(myclient, 0);
    myfilesend = new FileSend(myclient);

    //GET LOGIN:
    mywindow->get_login(mylogin);
    mywindow->get_file_send(myfilesend);
    mywindow->add_friend_list();

    //distribute thread
    mylistentd->moveToThread(&this->listenThread);
    // connect signal and slots mapping:
    //connect(this->listenThread, &QThread::finished, mylistentd, &QObject::deleteLater);
    connect(mylistentd, &listenthread::msgRecved, mywindow, &MainWindow::refreshChat);
    connect(this, &Controller::startlisten, mylistentd, &listenthread::listen);
    //connect login part:
    connect(mylistentd, &listenthread::logfail, mylogin, &login::relogin);
    connect(mylistentd, &listenthread::logsuccess, mylogin, &login::accept);

    this->listenThread.start();
    myclient->fd_listen();
}

Controller::~Controller()
{
    this->mylistentd->deleteLater();
    this->listenThread.quit();
    myclient->fd_listen_close();
}

void Controller::Login()
{
    mywindow->start_login();
}

void Controller::Show()
{
    mywindow->show();
}

void Controller::Listen()
{
    emit startlisten();
}
