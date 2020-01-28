//
// Created by Inbar on 21/01/2020.
//

#include "FileCacheManager.h"
#include <iostream>
#include <string>
#include <fstream>

bool FileCacheManager::doesHaveSol(string prob) {
    hash<string> hash_string;
    ifstream file;
    file.open(to_string(hash_string(prob)));
    if(file) {
        file.close();
        return true;
    }
    return false;
}

string FileCacheManager::getSol(string prob) {
    hash<string> hash_string;
    if(doesHaveSol(prob)) {
        string sol;
        ifstream file;
        file.open(to_string(hash_string(prob)));
        string line;
        while (!file.eof()) {
          getline(file, line);
          sol += line;
        }
        file.close();
        return sol;
    }
    return "";
}

void FileCacheManager::setSol(string prob, string sol) {
    hash<string> hash_string;
    ofstream new_file;
    new_file.open(to_string(hash_string(prob)));
    new_file << sol;
    new_file.close();
}
