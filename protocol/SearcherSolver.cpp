//
// Created by noam on 28/01/2020.
//

#include "SearcherSolver.h"
#include "../matrices/MatrixGenerator.h"

string SearcherSolver::solve(string problem) {
  MatrixGenerator matrix_generator;

  // Generates the searchable matrix.
  Searchable<string> *searchable = matrix_generator.GenerateMatrix(problem);

  // Solves the searchable.
  searchable->GetReadyToSearch();
  this->searcher->Reset();
  list<State<string>*> route = this->searcher->Search(searchable);

  // Returns the solution.
  string solution = MatrixRouteSearchable::RouteToString(route);
  return solution;
}
