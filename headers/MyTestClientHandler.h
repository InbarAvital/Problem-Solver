//
// Created by Inbar on 21/01/2020.
//
#ifndef PROJ2_MYTESTCLIENTHANDLER_H
#define PROJ2_MYTESTCLIENTHANDLER_H
#include "ClientHandler.h"
#include "Solver.h"
#include "CacheManager.h"

class MyTestClientHandler : public ClientHandler
{
	Solver<string, string>* solver;
	CacheManager<string, string>* cm;
public:
    MyTestClientHandler(Solver<string, string>* recv_solver, CacheManager<string, string>* recv_cm) {
        solver = recv_solver;
        cm = recv_cm;
    }
    void handleClient(int input_stream) override;
    static string convertToString(char* as_char, int size);
};
#endif
