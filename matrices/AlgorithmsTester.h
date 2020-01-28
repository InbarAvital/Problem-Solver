//
// Created by noam on 27/01/2020.
//

#ifndef EX4_MATRICES_ALGORITHMSTESTER_H_
#define EX4_MATRICES_ALGORITHMSTESTER_H_

#import "../algorithms/BestFirstSearch.h"
#import "../algorithms/DepthFirstSearch.h"
#import "../algorithms/BreadthFirstSearch.h"
#import "../algorithms/Astar.h"
#include "MatrixRouteSearchable.h"

class AlgorithmsTester {
 public:
  void Test(const string &matrices_file_name);
 private:
  list<MatrixRouteSearchable> LoadMatrices(const string &input_file_name);
  void TestAlgorithmOnMatrices(Searcher<string> *algorithm, list<MatrixRouteSearchable> matrices, const string &output_file_name);
};

#endif //EX4_MATRICES_ALGORITHMSTESTER_H_
