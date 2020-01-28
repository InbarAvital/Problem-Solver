//
// Created by noam on 27/01/2020.
//

#ifndef EX4_ALGORITHMS_MATRIXGENERATOR_H_
#define EX4_ALGORITHMS_MATRIXGENERATOR_H_

#include "MatrixRouteSearchable.h"

// Generator of matrix rote searchable object.
class MatrixGenerator {
 public:
  MatrixRouteSearchable *GenerateMatrix(const string &matrix_data);
};

#endif //EX4_ALGORITHMS_MATRIXGENERATOR_H_
