//
// Created by Inbar on 21/01/2020.
//

#include "FileCacheManager.h"
#include <iostream>
#include <string>
#include <fstream>

bool FileCacheManager::doesHaveSol(string prob) {
    ifstream file;
    file.open(prob);
    if(file) {
        file.close();
        return true;
    }
    return false;
}

string FileCacheManager::getSol(string prob) {
    if(doesHaveSol(prob)) {
        string sol;
        ifstream file;
        file.open(prob);
        getline(file, sol);
        file.close();
        return sol;
    }
    return "";
}

void FileCacheManager::setSol(string prob, string sol) {
    ofstream new_file;
    new_file.open(prob);
    new_file << sol;
    new_file.close();
}
