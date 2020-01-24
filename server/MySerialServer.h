//
// Created by Inbar on 21/01/2020.
//
#ifndef PROJ2_MYSERIALSERVER_H
#define PROJ2_MYSERIALSERVER_H
#include "Server.h"
#include <iostream>
#include <string>
#include <sys/socket.h>
#include <vector>
#include <map>
#include <unistd.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <thread>

using namespace server_side;

class MySerialServer : public Server
{
private:
    static void runServer(MySerialServer *server, int socket, ClientHandler* c, sockaddr_in address);
public:
    void open(int port, ClientHandler* c) override;
    void stop() override;
    virtual ~MySerialServer(){}
};
#endif
