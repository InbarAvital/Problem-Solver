//
// Created by noam on 27/01/2020.
//

#ifndef EX4_ALGORITHMS_STATECOSTPLUSHEURISTICCOMPARATOR_H_
#define EX4_ALGORITHMS_STATECOSTPLUSHEURISTICCOMPARATOR_H_

#include "State.h"
#include "Comparator.h"

// Compares two states according to the sum of their cost and heuristic.
template <class T, class H>
class StateCostPlusHeuristicComparator : public Comparator<State<T>*> {
 public:
  bool operator()(State<T> *first, State<T> *second) override;
};

template<class T, class H>
bool StateCostPlusHeuristicComparator<T, H>::operator()(State<T> *first, State<T> *second) {
  H heuristic;
  return first->GetCost() + heuristic(first->GetState()) > second->GetCost() + heuristic(second->GetState());
}

#endif //EX4_ALGORITHMS_STATECOSTPLUSHEURISTICCOMPARATOR_H_
