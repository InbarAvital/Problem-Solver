//
// Created by noam on 27/01/2020.
//

#ifndef EX4_ALGORITHMS_MATRIXROUTESEARCHABLE_H_
#define EX4_ALGORITHMS_MATRIXROUTESEARCHABLE_H_

#include <utility>
#include <vector>
#include "../algorithms/Searchable.h"
#include "Point.h"
#include "ManhattanDistanceHeuristic.h"

class MatrixRouteSearchable : public Searchable<string> {
 public:
  // Input: cols - The number of columns in the matrix.
  //        mat - The matrix.
  //        initial - The initial position on the matrix.
  //        goal - The goal position on the matrix.
  MatrixRouteSearchable(vector<vector<int>> mat, Point initial, Point goal):
      matrix(std::move(mat)), row_length(matrix[0].size()), column_length(matrix.size()), initial_point(initial),
      goal_point(goal), heuristic_function(ManhattanDistanceHeuristic(goal)) {}

  State<string> *GetInitialState() override;

  bool IsGoalState(State<string> *state) override;

  list<State<string>*> GetAllPossibleStates(State<string> *state) override;

  // Input: route - A list of state represent a route in the matrix.
  // Output: A string represents the route.
  static string RouteToString(list<State<string>*> route);
  
  // Output: The number of rows in the matrix.
  int GetRows();

  // Output: The number of columns in the matrix.
  int GetColumns();

 private:
  vector<vector<int>> matrix;
  int row_length;
  int column_length;
  Point initial_point;
  Point goal_point;
  ManhattanDistanceHeuristic heuristic_function;
};

#endif //EX4_ALGORITHMS_MATRIXROUTESEARCHABLE_H_
