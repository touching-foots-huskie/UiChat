# include "mainwindow.h"
#include "entry.h"
#include "login.h"
#include "client.h"
#include "listenthread.h"
#include "filesend.h"
#include "controller.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Controller c;
    c.Listen();
    c.Login();
    //start listen:
    c.Show();
    return a.exec();
}
