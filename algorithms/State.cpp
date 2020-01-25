//
// Created by noam on 24/01/2020.
//

#include "State.h"

template<class T>
bool State<T>::operator==(const State<T> &s) const {
  return this->state == s.state;
}

template<class T>
list<T> State<T>::BacktracePath() const {
  list<T> path;

  if (this->previous_state != nullptr) {
    // Backtraces the path until the previous state.
    path = this->previous_state->BacktracePath();
  }

  // Adds this state to the path.
  path.push_back(this->state);
  return path;
}
