//
// Created by noam on 25/01/2020.
//

#ifndef EX4_ALGORITHMS_PRIORITYQUEUEBASEDSEARCHER_H_
#define EX4_ALGORITHMS_PRIORITYQUEUEBASEDSEARCHER_H_

#include "Searcher.h"
#include "MinPriorityQueue.h"

template <class T>
class PriorityQueueBasedSearcher : public Searcher<T> {
 public:
  // Constructs a priority queue based searching algorithm and initializes
  // its number of evaluated nodes.
  PriorityQueueBasedSearcher(): evaluated_nodes(0) {}

  int GetNumberOfNodesEvaluated() const override;

 protected:
  // Output: The state with the smallest cost in the open list.
  // Removes The state with the smallest cost from the open list and returns it.
  State<T> PopOpenList();

 private:
  MinPriorityQueue<State<T>> open_list;
  int evaluated_nodes;
};

template<class T>
State<T> PriorityQueueBasedSearcher<T>::PopOpenList() {
  // Gets the state with the smallest cost in the open list.
  State<T> smallest_state = this->open_list.Top();

  // Pops that state from the open list.
  this->open_list.Pop();

  // Increases the number of the evaluated nodes by 1.
  this->evaluated_nodes++;

  return smallest_state;
}

template<class T>
int PriorityQueueBasedSearcher<T>::GetNumberOfNodesEvaluated() const {
  return this->evaluated_nodes;
}

#endif //EX4_ALGORITHMS_PRIORITYQUEUEBASEDSEARCHER_H_
