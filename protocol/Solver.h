//
// Created by Inbar on 21/01/2020.
//
#ifndef PROJ2_SOLVER_H
#define PROJ2_SOLVER_H
template<typename PROB, typename SOL>
class Solver
{
public:
    virtual SOL solve(PROB prob) = 0;
    virtual ~Solver(){};
};
#endif