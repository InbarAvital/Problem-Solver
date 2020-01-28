//
// Created by noam on 25/01/2020.
//

#ifndef EX4__SEARCHABLE_H_
#define EX4__SEARCHABLE_H_

#include "State.h"

// A search problem.
template <class T>
class Searchable {
 public:
  // Output:  The initial state of this search problem.
  virtual State<T> *GetInitialState() = 0;

  // Input: state - A state in our universe of states.
  // Output:  True or false whether that state is a goal of this problem or not.
  // Checks if this state is a goal state.
  virtual bool IsGoalState(State<T> *state) = 0;

  // Input: state - A state in our universe of states.
  // Output:  A list of that state's successors.
  virtual list<State<T>*> GetAllPossibleStates(State<T> *state) = 0;
};

#endif //EX4__SEARCHABLE_H_
