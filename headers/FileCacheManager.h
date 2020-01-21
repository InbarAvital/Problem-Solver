//
// Created by Inbar on 21/01/2020.
//
#ifndef PROJ2_FILECACHEMANAGER_H
#define PROJ2_FILECACHEMANAGER_H
#include "CacheManager.h"

class FileCacheManager : public CacheManager<string, string>
{
public:
    bool doesHaveSol(string prob) override;

    string getSol(string prob) override;

    void setSol(string prob, string sol) override;
};
#endif
