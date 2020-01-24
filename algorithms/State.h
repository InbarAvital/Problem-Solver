//
// Created by noam on 24/01/2020.
//

#ifndef EX4__STATE_H_
#define EX4__STATE_H_

template <class T>
class State {
 public:
  // Input: s - The state
  // Constructs a state.
  State(T s): state(s) {}

  // Input: s - A state
  // Output: True or false whether this state is equal to the other state.
  bool operator==(const State &s) const;

  // Input: c - The cost of the path leads to this state.
  // Sets this cost as this state's cost.
  void SetCost(double c) {
    this->cost = c;
  }

  // Input: s - The state before this state in the path leads to this state.
  // Sets that state as this state's previous state.
  void SetPreviousState(State<T> s) {
    this->previous_state = state;
  }

 private:
  T state;
  double cost;
  State<T> previous_state;
};

#endif //EX4__STATE_H_
