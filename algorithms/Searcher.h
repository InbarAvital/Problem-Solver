//
// Created by noam on 25/01/2020.
//

#ifndef EX4_ALGORITHMS_SEARCHER_H_
#define EX4_ALGORITHMS_SEARCHER_H_

#include "Searchable.h"

// A searching algorithm - "a solver".
template <class T>
class Searcher {
 public:
  // Input: searchable - A searching problem.
  // Output: A solution for this problem.
  // Solves the searching problem and returns (one of) its solution(s).
  string search(Searchable<T> searchable) = 0;

  // Output: The number of nodes evaluated during the searching process.
  int GetNumberOfNodesEvaluated() = 0;
};

#endif //EX4_ALGORITHMS_SEARCHER_H_
