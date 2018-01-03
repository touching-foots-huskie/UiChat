#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include "client.h"
#include "entry.h"
#include "login.h"
#include "listenthread.h"
#include "chatwindow.h"
#include "filesend.h"
#include <QThread>
#include <string>
#include "QListWidget"
#include <QMainWindow>
#include <QObject>
#include <map>

namespace Ui {
class MainWindow;
class listenthread;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(client_core* cc, QWidget *parent);
    ~MainWindow();
    client_core* cc;
    login* mylogin;
    FileSend* myfilesend;
    QString myname;
    //windows map:
    map<QString, chatWindow> chatlist;
    void get_login(login* mylogin);
    void get_file_send(FileSend* myfilesend);
    void add_friend_list();
    int start_login();
public slots:
    void refreshChat(QString msg, QString name);
private slots:
    void on_friendlist_itemClicked(QListWidgetItem *item);

    int on_sendFileButton_clicked();

    void on_logoutButton_clicked();

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
