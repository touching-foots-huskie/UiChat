#ifndef CONTROLLER_H
#define CONTROLLER_H

#include <QObject>
#include <QThread>
#include "listenthread.h"
#include "mainwindow.h"
#include "client.h"
#include "login.h"
#include "filesend.h"

class Controller : public QObject
{
    Q_OBJECT
    QThread listenThread;
public:
    //data:
    client_core* myclient;
    listenthread* mylistentd;
    MainWindow* mywindow;
    login* mylogin;
    FileSend* myfilesend;
    explicit Controller(QObject *parent = nullptr);
    ~Controller();
    void Login();
    void Show();
    void Listen();
signals:
    void startlisten();
public slots:
};

#endif // CONTROLLER_H
