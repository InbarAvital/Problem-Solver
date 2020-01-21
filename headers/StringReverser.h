//
// Created by Inbar on 21/01/2020.
//

#ifndef PROJ2_STRINGREVERSER_H
#define PROJ2_STRINGREVERSER_H
#include "Solver.h"
#include <string>

using namespace std;

class StringReverser : public Solver<string, string> {

    /*****************************
     * gets a string
     * @return the rotated string
     *****************************/
    string solve(string) override;
};


#endif //PROJ2_STRINGREVERSER_H
