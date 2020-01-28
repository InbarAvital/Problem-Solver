//
// Created by noam on 27/01/2020.
//

#include <fstream>
#include <iostream>
#include "AlgorithmsTester.h"
#include "MatrixGenerator.h"

void AlgorithmsTester::Test(const string &matrices_file_name) {
  // Loads the matrices.
  list<MatrixRouteSearchable*> matrices = this->LoadMatrices(matrices_file_name);

  // Tests the algorithms.
  this->TestAlgorithmOnMatrices(new BreadthFirstSearch<string>(), matrices, "Breadth_First_Search.csv");
  this->TestAlgorithmOnMatrices(new BestFirstSearch<string>(), matrices, "Best_First_Search.csv");
  this->TestAlgorithmOnMatrices(new DepthFirstSearch<string>(), matrices, "Depth_First_Search.csv");
  this->TestAlgorithmOnMatrices(new Astar<string, ManhattanDistanceHeuristic>(), matrices, "A_Star.csv");
}

list<MatrixRouteSearchable*> AlgorithmsTester::LoadMatrices(const string &input_file_name) {
  ifstream input_file;

  // Opens the file with the matrices.
  input_file.open(input_file_name);
  if (!input_file) {
    cerr << "Failed to open file: " << input_file_name << endl;
  }

  MatrixGenerator matrix_generator;
  list<MatrixRouteSearchable*> matrices;

  // Reads The lines in the file.
  while (!input_file.eof()) {
    string lines_read, line;

    // Reads one matrix.
    while (line != "end") {
      lines_read += line + "\n";
      getline(input_file, line);
    }

    // Generates the matrix.
    matrices.push_back(matrix_generator.GenerateMatrix(lines_read));
  }

  // Closes the file.
  input_file.close();

  return matrices;
}

void AlgorithmsTester::TestAlgorithmOnMatrices(Searcher<string> *algorithm, list<MatrixRouteSearchable*> matrices, const string &output_file_name) {
  ofstream output_file;

  // Opens a file for the algorithm results.
  output_file.open(output_file_name);
  if (!output_file) {
    cerr << "Failed to open file: " << output_file_name << endl;
  }

  // Solves every matrix problem.
  for (auto matrix_problem : matrices) {
    // Searches for a solution route using the algorithm.
    matrix_problem->GetReadyToSearch();
    algorithm->Reset();
    list<State<string>*> route = algorithm->Search(matrix_problem);

    // Gets the number of evaluated nodes in the algorithm execution.
    int evaluated_nodes = algorithm->GetNumberOfNodesEvaluated();

    // Gets the size of the matrix.
    int matrix_size = matrix_problem->GetRows();

    // Writes the results to the file.
    output_file << matrix_size << "," << evaluated_nodes << endl;
  }

  // Closes the file.
  output_file.close();
}
