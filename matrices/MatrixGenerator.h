//
// Created by noam on 27/01/2020.
//

#ifndef EX4_ALGORITHMS_MATRIXGENERATOR_H_
#define EX4_ALGORITHMS_MATRIXGENERATOR_H_

#include "MatrixRouteSearchable.h"

// Generator of matrix rote searchable object.
class MatrixGenerator {
 public:
  MatrixRouteSearchable GenerateMatrix(const string &matrix_data);

 private:
  // Input: str - The string to split.
  //        split_by - The delimiter to split by.
  // Output:  A vector of strings from the given string, after splitting it.
  static vector<string> Split(string str, string split_by);
};

#endif //EX4_ALGORITHMS_MATRIXGENERATOR_H_
