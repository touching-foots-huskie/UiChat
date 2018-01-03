#ifndef CLIENT_H
#define CLIENT_H
#include <stdio.h>
#include <sys/socket.h>
#include <stdlib.h>
#include <netinet/in.h>
#include <errno.h>
#include <string.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <iostream>
#include <map>
#include <list>
#include <boost/algorithm/string.hpp>
#include "entry.h"
#define MAXLINE 1024

using namespace std;
using namespace boost;

class client_core
{
  public:
    const char* servInetAddr;  // address of the server
    int userId;
    string name;
    //friend list:
    map<string, int> friend_list;
    map<int, string> iv_friend_list;
    // socket address is a address
    struct sockaddr_in sockaddr;       //socket address
    struct sockaddr_in socklisten;  //listen address
    int n;
    int condition;

    const char* MynetAddr;
    // sending socket
    int socketfd;                      //socket fd

    // listen socket
    int listenfd;
    int connfd;

    // save buffer:
    char recvline[MAXLINE], sendline[MAXLINE];
    char content[164];
    // for sending
    int fd_connect();
    int send_packet(char* stream);
    int fd_close();

    // for recieving:
    int fd_listen();
    int packet_catch(); // catch a packet
    entry* webpacket_catch();
    int fd_listen_close();
    //functions: Constructor:
    client_core();

    //Other functions:
    char* loginWrap();
    char* webLoginWrap(int username, int password);
    char* sendMsg();
    char* webSendMsg(string name, string msg);
    char* logoutWrap();

    //Assembled Functions:
    int Login();
};
#endif // CLIENT_H
