//
// Created by Inbar on 21/01/2020.
//
#ifndef PROJ2_CACHEMANAGER_H
#define PROJ2_CACHEMANAGER_H
#include <iostream>
#include <unordered_map>
#include <list>

using namespace std;
template<typename PROB, typename SOL>
class CacheManager
{
public:

    virtual bool doesHaveSol(PROB prob) = 0;

    virtual SOL getSol(PROB prob) = 0;

    virtual void setSol(PROB prob, SOL sol) = 0;

    virtual ~CacheManager(){}
};
#endif

