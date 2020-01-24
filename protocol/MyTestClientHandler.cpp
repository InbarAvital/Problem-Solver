//
// Created by Inbar on 21/01/2020.
//
#include <unistd.h>
#include <cstring>
#include <sys/socket.h>
#include "MyTestClientHandler.h"

using namespace std;
void MyTestClientHandler::handleClient(int input_stream) {
    char buffer[1024] = { 0 };
    //reading from client
    read(input_stream, buffer, 1024);
    while (strcmp(buffer, "end\n") != 0) {
        string prob = convertToString(buffer, 1024);
        string sol;
        if(cm->doesHaveSol(prob)) {
            sol = cm->getSol(prob);
        }
        else {
            sol = solver->solve(prob);
            cm->setSol(prob, sol);
        }
        send(input_stream, sol.c_str(), strlen(sol.c_str()), 0);
        read(input_stream, buffer, 1024);
    }
    cout<<buffer<<endl;
}

/**
 * @param as_char
 * @param size - the size of as_char
 * @return as_char as a atring
 */
string MyTestClientHandler::convertToString(char* as_char, int size)
{
    int i;
    string as_str;
    for (i = 0; i < size; i++) {
        if(as_char[i] == '\n') {
            break;
        }
        as_str += as_char[i];
    }
    return as_str;
}
