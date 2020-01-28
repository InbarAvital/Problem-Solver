//
// Created by noam on 28/01/2020.
//

#include "MyParallelServer.h"

#define TIME 120

void MyParallelServer::open(int port, ClientHandler* c) {
  //create socket
  int socketfd = socket(AF_INET, SOCK_STREAM, 0);
  if (socketfd == -1) {
    //error
    std::cerr << "Could not create a socket" << std::endl;
    exit(1);
  }
  // timeout
  struct timeval tv;
  tv.tv_sec = TIME;
  tv.tv_usec = 0;
  setsockopt(socketfd, SOL_SOCKET, SO_RCVTIMEO, (const char*)&tv, sizeof (tv));
  //bind socket to IP address
  // we first need to create the sockaddr obj.
  sockaddr_in address; //in means IP4
  address.sin_family = AF_INET;
  address.sin_addr.s_addr = INADDR_ANY; //give me any IP allocated for my machine
  address.sin_port = htons(port);
  //we need to convert our number
  // to a number that the network understands.

  //the actual bind command
  if (bind(socketfd, (struct sockaddr*) & address, sizeof(address)) == -1) {
    std::cerr << "Could not bind the socket to an IP" << std::endl;
    exit(1);
  }

  //making socket listen to the port
  if (listen(socketfd, 10) == -1) { //can also set to SOMAXCON (max connections)
    std::cerr << "Error during listening command" << std::endl;
    exit(1);
  }
  else {
    std::cout << "Server is now listening ..." << std::endl;
  }
  // thread creation
  std::thread server_thread(runServer, this, socketfd, c, address);
  server_thread.join();
}

void MyParallelServer::stop() {
  this->stop_server = true; //closing the listening socket
}

void MyParallelServer::runServer(MyParallelServer *server, int socketfd, ClientHandler *c, sockaddr_in address) {
  while (!server->stop_server) {
    // accepting a client
    int client_socket = accept(socketfd, (struct sockaddr*) & address,
                               (socklen_t*)&address);

    if (client_socket == -1) {
      // Reached time-out.
      server->stop();
      break;
    }

    thread client_handler_thread(HandleClient, client_socket, c);
    client_handler_thread.detach();
  }
  close(socketfd);
}

void MyParallelServer::HandleClient(int client_socket, ClientHandler *c) {
  c->handleClient(client_socket);
  close(client_socket); // Closes the socket when finish.
}
