//
// Created by noam on 28/01/2020.
//

#ifndef EX4_PROTOCOL_SEARCHERSOLVER_H_
#define EX4_PROTOCOL_SEARCHERSOLVER_H_

#include <string>
#include "Solver.h"
#include "../algorithms/Searcher.h"

using namespace std;

class SearcherSolver : public Solver<string, string> {
 public:
  // Input: s - The searcher of this searcher solver object.
  // Constructs a searcher solver with that searcher.
  explicit SearcherSolver(Searcher<string> *s) : searcher(s) {}

  string solve(string problem) override;

 private:
  Searcher<string> *searcher;
};

#endif //EX4_PROTOCOL_SEARCHERSOLVER_H_
