//
// Created by Inbar on 21/01/2020.
//

#include <iostream>
#include "../headers/StringReverser.h"

string StringReverser::solve(string to_reverse) {
    string reversed;
    for(int i = signed(to_reverse.size() - 1); i >= 0; i--) {
        reversed += to_reverse[i];
    }
    return reversed;
}
