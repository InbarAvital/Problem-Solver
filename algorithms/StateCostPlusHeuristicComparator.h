//
// Created by noam on 27/01/2020.
//

#ifndef EX4_ALGORITHMS_STATECOSTPLUSHEURISTICCOMPARATOR_H_
#define EX4_ALGORITHMS_STATECOSTPLUSHEURISTICCOMPARATOR_H_

#include "State.h"
#include "Comparator.h"

// Compares two states according to the sum of their cost and heuristic.
template <class T>
class StateCostPlusHeuristicComparator : public Comparator<State<T>*> {
 public:
  bool operator()(State<T> *first, State<T> *second) override;
};

template<class T>
bool StateCostPlusHeuristicComparator<T>::operator()(State<T> *first, State<T> *second) {
  return first->GetCost() + first->GetHeuristicCost() > second->GetCost() + second->GetHeuristicCost();
}

#endif //EX4_ALGORITHMS_STATECOSTPLUSHEURISTICCOMPARATOR_H_
