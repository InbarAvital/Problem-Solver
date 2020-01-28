//
// Created by noam on 28/01/2020.
//

#ifndef EX4_SERVER_MYPARALLELSERVER_H_
#define EX4_SERVER_MYPARALLELSERVER_H_

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

class MyParallelServer : public Server {
 private:
  static void runServer(MyParallelServer *server, int socket, ClientHandler* c, sockaddr_in address);
  static void HandleClient(int client_socket, ClientHandler* c);
 public:
  void open(int port, ClientHandler* c) override;
  void stop() override;
  virtual ~MyParallelServer(){}
};

#endif //EX4_SERVER_MYPARALLELSERVER_H_
