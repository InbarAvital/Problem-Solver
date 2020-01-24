//
// Created by noam on 24/01/2020.
//

#include "State.h"

template<class T>
bool State<T>::operator==(const State &s) const {
  return this->state == s.state;
}
