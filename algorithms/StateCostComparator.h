//
// Created by noam on 26/01/2020.
//

#ifndef EX4_ALGORITHMS_STATECOSTCOMPARATOR_H_
#define EX4_ALGORITHMS_STATECOSTCOMPARATOR_H_

#include "Comparator.h"
#include "State.h"

// Compares two states by their costs.
template <class T>
class StateCostComparator : public Comparator<State<T>*> {
 public:
  bool operator()(State<T> *first, State<T> *second) override;
};

template<class T>
bool StateCostComparator<T>::operator()(State<T> *first, State<T> *second) {
  return first->GetCost() > second->GetCost();
}

#endif //EX4_ALGORITHMS_STATECOSTCOMPARATOR_H_
