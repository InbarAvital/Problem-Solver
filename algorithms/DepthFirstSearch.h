//
// Created by noam on 27/01/2020.
//

#ifndef EX4_ALGORITHMS_DEPTHFIRSTSEARCH_H_
#define EX4_ALGORITHMS_DEPTHFIRSTSEARCH_H_

#include <unordered_map>
#include "Searcher.h"

// Depth first search algorithm.
template <class T>
class DepthFirstSearch : public Searcher<T> {
 public:
  // Constructs a DFS searching algorithm and initializes its number of evaluated nodes.
  DepthFirstSearch<T>(): evaluated_nodes(0) {}

  list<State<T>*> Search(Searchable<T> *searchable) override;

  int GetNumberOfNodesEvaluated() override;

  void Reset();

 private:
  list<State<T>*> DFSVisit(State<T> *state, Searchable<T> *searchable);

  unordered_map<T, State<T>*> discovered;
  int evaluated_nodes;
};

template<class T>
list<State<T>*> DepthFirstSearch<T>::Search(Searchable<T> *searchable) {
  State<T> *s = searchable->GetInitialState();
  return this->DFSVisit(s, searchable);
}

template<class T>
list<State<T>*> DepthFirstSearch<T>::DFSVisit(State<T> *state, Searchable<T> *searchable) {
  this->evaluated_nodes++;

  // The current state was discovered.
  this->discovered.insert({state->GetState(), state});

  if (searchable->IsGoalState(state)) {
    // We reached the goal state.
    return state->BacktracePath();
  }

  list<State<T>*> successors = searchable->GetAllPossibleStates(state);
  for (auto successor : successors) {
    if (this->discovered.count(successor->GetState()) != 1) {
      // The current successor was not discovered yet.
      list<State<T>*> result = this->DFSVisit(successor, searchable);
      if (!result.empty()) {
        return result;
      }
    }
  }
  return list<State<T>*>();
}

template<class T>
int DepthFirstSearch<T>::GetNumberOfNodesEvaluated() {
  return this->evaluated_nodes;
}

template<class T>
void DepthFirstSearch<T>::Reset() {
  this->evaluated_nodes = 0;
  this->discovered.clear();
}

#endif //EX4_ALGORITHMS_DEPTHFIRSTSEARCH_H_
