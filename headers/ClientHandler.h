//
// Created by Inbar on 21/01/2020.
//
#ifndef PROJ2_CLIENTHANDLER_H
#define PROJ2_CLIENTHANDLER_H
#include <iostream>
class ClientHandler
{
public:
	// gets input stream and output stream
	virtual void handleClient(int input_stream) = 0;
	virtual ~ClientHandler(){}
};
#endif
