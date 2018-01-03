#ifndef LISTENTHREAD_H
#define LISTENTHREAD_H

#include <QObject>
#include <string>
#include "entry.h"
#include "client.h"

class listenthread : public QObject
{
    Q_OBJECT
public:
    listenthread(client_core* cc, QObject *parent = nullptr);
    client_core* cc;
signals:
    void msgRecved(QString msg, QString name); //msg: what msg/ from whom
    void logfail();
    void logsuccess();
public slots:
    void listen();
};

#endif // LISTENTHREAD_H
