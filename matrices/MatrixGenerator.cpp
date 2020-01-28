//
// Created by noam on 27/01/2020.
//

#include <fstream>
#include "MatrixGenerator.h"

MatrixRouteSearchable MatrixGenerator::GenerateMatrix(const string &matrix_data) {
  vector<vector<int>> matrix;

  vector<string> splitted_lines = MatrixGenerator::Split(matrix_data, "\n");
  for (int i = 0; i < splitted_lines.size() - 2; i++) {
    // Separates the lines to matrix rows.
    vector<string> string_costs = MatrixGenerator::Split(splitted_lines[i], ",");

    // Converts the costs to integers.
    vector<int> costs;
    for (auto string_cost : string_costs) {
      vector<string> without_spaces = MatrixGenerator::Split(string_cost, " ");
      costs.push_back(stoi(without_spaces[0]));
    }

    // Add the row to the matrix.
    matrix.push_back(costs);
  }

  // Parse the initial and goal points for the search problem.
  Point initial(splitted_lines[splitted_lines.size() - 2]);
  Point goal(splitted_lines[splitted_lines.size() - 1]);

  return MatrixRouteSearchable(matrix, initial, goal);
}

vector<string> MatrixGenerator::Split(string str, string split_by) {
  // true every time we find a split_by string
  bool found;
  // a string to add until we find a split_by string
  string to_add = "";
  // the splitted list we send in the end
  vector<string> splitted;
  // for loop on each char in "str"
  for (int i = 0; i < str.length(); i++) {
    found = true;
    // for loop to check if this current char is the beginning of "split_by"
    int i_copy = i;
    for (int j = 0; j < split_by.length(); j++) {
      if (str[i_copy + j] != split_by[j]) {
        found = false;
        i_copy += j;
        break;
      }
    }
    // if we find a "split_by", we add what was before the it and not yes
    // added to the list, ignore the "split_by", and continue
    if (found) {
      i += split_by.length() - 1;
      if (to_add != "")
        splitted.push_back(to_add);
      to_add = "";
    }
    else {
      to_add += str[i];
      if (i == str.length() - 1) {
        splitted.push_back(to_add);
      }
    }
  }
  return splitted;
}
