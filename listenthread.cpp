#include "listenthread.h"

listenthread::listenthread(client_core *cc, QObject *parent) : QObject(parent)
{
    this->cc = cc;
}

//realize of listenthread:
void listenthread::listen()
{
    QString msg;
    QString name;
    string sname;
    entry* Entry;
    while(1)
    {
        Entry = this->cc->webpacket_catch();
        if((Entry->EntryHead.etype==1)||(Entry->EntryHead.etype==6))
        {
            msg = tr((const char*) Entry->data);
            sname = this->cc->iv_friend_list[Entry->EntryHead.userId];
            name = tr(sname.c_str());
            emit msgRecved(msg, name);
        }
        else if(Entry->EntryHead.etype==-1)
        {
            emit logfail();
        }
        else if(Entry->EntryHead.etype==4)
        {
            emit logsuccess();
        }
    }
}
