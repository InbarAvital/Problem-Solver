//
// Created by inbar on 21/01/2020.
//

#include "headers/MySerialServer.h"

int server_side::boot::Main::main(int argc, char **argv) {
    int port = atoi(argv[1]);
    Solver<string, string> *reverser = new StringReverser();
    CacheManager<string, string> *fcm = new FileCacheManager();
    ClientHandler *handler = new MyTestClientHandler(reverser, fcm);
    MySerialServer server;
    server.open(port, handler);
    return argc;
}
