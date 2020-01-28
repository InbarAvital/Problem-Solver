//
// Created by noam on 27/01/2020.
//

#ifndef EX4_ALGORITHMS_ASTAR_H_
#define EX4_ALGORITHMS_ASTAR_H_

#include "PriorityQueueBasedSearcher.h"
#include "StateCostPlusHeuristicComparator.h"

// A* searching algorithm with a heuristic function H.
template <class T, class H>
class Astar : public PriorityQueueBasedSearcher<T, StateCostPlusHeuristicComparator<T, H>> {
 public:
  list<State<T>*> Search(Searchable<T> *searchable) override;
};

template <class T, class H>
list<State<T>*> Astar<T, H>::Search(Searchable<T> *searchable) {
  this->AddToOpenList(searchable->GetInitialState());
  unordered_map<T, State<T>*> closed;

  // Keep evaluate nodes until there are no more nodes.
  while (!this->OpenListIsEmpty()) {
    State<T> *n = this->PopOpenList();
    closed.insert({n->GetState(), n});

    if (searchable->IsGoalState(n)) {
      // We reached a goal state.
      return n->BacktracePath();
    }

    // Checks the evaluated node's successors.
    list<State<T>*> successors = searchable->GetAllPossibleStates(n);
    for (auto s : successors) {
      if (closed.count(s->GetState()) != 1 && !this->OpenListContains(s)) {
        // New unevaluated node
        this->AddToOpenList(s);
      } else if (!this->OpenListContains(s) && closed.find(s->GetState())->second->GetCost() > s->GetCost()) {
        // The new path is better then the previous.
        this->AddToOpenList(s);
        closed.erase(s->GetState());
      } else if (this->OpenListContains(s) && this->GetFromOpenList(s)->GetCost() > s->GetCost()) {
        // The new path is better then the previous.
        this->UpdateInOpenList(this->GetFromOpenList(s), s);
      }
    }
  }
}

#endif //EX4_ALGORITHMS_ASTAR_H_
