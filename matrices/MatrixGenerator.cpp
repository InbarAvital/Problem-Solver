//
// Created by noam on 27/01/2020.
//

#include <fstream>
#include "MatrixGenerator.h"
#include "../Utility.h"

MatrixRouteSearchable *MatrixGenerator::GenerateMatrix(const string &matrix_data) {
  vector<vector<int>> matrix;

  vector<string> splitted_lines = Utility::Split(matrix_data, "\n");
  for (int i = 0; i < splitted_lines.size() - 2; i++) {
    // Separates the lines to matrix rows.
    vector<string> string_costs = Utility::Split(splitted_lines[i], ",");

    // Converts the costs to integers.
    vector<int> costs;
    for (auto string_cost : string_costs) {
      vector<string> without_spaces = Utility::Split(string_cost, " ");
      costs.push_back(stoi(without_spaces[0]));
    }

    // Add the row to the matrix.
    matrix.push_back(costs);
  }

  // Parse the initial and goal points for the search problem.
  Point initial(splitted_lines[splitted_lines.size() - 2]);
  Point goal(splitted_lines[splitted_lines.size() - 1]);

  return new MatrixRouteSearchable(matrix, initial, goal);
}
