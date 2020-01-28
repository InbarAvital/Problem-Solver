//
// Created by noam on 25/01/2020.
//

#ifndef EX4_ALGORITHMS_PRIORITYQUEUEBASEDSEARCHER_H_
#define EX4_ALGORITHMS_PRIORITYQUEUEBASEDSEARCHER_H_

#include <unordered_map>
#include "Searcher.h"
#include "PriorityQueue.h"

template <class T, class COMP>
class PriorityQueueBasedSearcher : public Searcher<T> {
 public:
  // Constructs a priority queue based searching algorithm and initializes
  // its number of evaluated nodes.
  PriorityQueueBasedSearcher(): evaluated_nodes(0) {}

  int GetNumberOfNodesEvaluated() override;

  void Reset();

 protected:
  // Output: The state with the smallest cost in the open list.
  // Removes the state with the smallest cost from the open list and returns it.
  State<T> *PopOpenList();

  // Input: state - The state to add to the open list.
  // Adds that state to the open list.
  void AddToOpenList(State<T> *state);

  // Output: True or false whether the open list is empty or not.
  bool OpenListIsEmpty();

  // Input: state - A state.
  // Output: True or false whether the open list contains that state or not.
  bool OpenListContains(State<T> *state);

  // Input: state - A state that the open list contains.
  // Output:  That state from the open list.
  State<T> *GetFromOpenList(State<T> *state);

  // Input: old_state - A state that the open list contains.
  //        new_state - The state to update the old one to in the open list.
  // Updates the old state in this open list to be the new state.
  void UpdateInOpenList(State<T> *old_state, State<T> *new_state);

 private:
  PriorityQueue<State<T>*, COMP> open_list;
  unordered_map<T, State<T>*> inside_open_list;
  int evaluated_nodes;
};

template <class T, class COMP>
State<T> *PriorityQueueBasedSearcher<T, COMP>::PopOpenList() {
  // Gets the state with the smallest cost in the open list.
  State<T> *smallest_state = this->open_list.Top();

  // Pops that state from the open list.
  this->open_list.Pop();
  this->inside_open_list.erase(smallest_state->GetState());

  // Increases the number of the evaluated nodes by 1.
  this->evaluated_nodes++;

  return smallest_state;
}

template <class T, class COMP>
bool PriorityQueueBasedSearcher<T, COMP>::OpenListIsEmpty() {
  return this->open_list.IsEmpty();
}

template <class T, class COMP>
int PriorityQueueBasedSearcher<T, COMP>::GetNumberOfNodesEvaluated() {
  return this->evaluated_nodes;
}

template <class T, class COMP>
void PriorityQueueBasedSearcher<T, COMP>::AddToOpenList(State<T> *state) {
  this->open_list.Push(state);
  this->inside_open_list.insert({state->GetState(), state});
}

template <class T, class COMP>
bool PriorityQueueBasedSearcher<T, COMP>::OpenListContains(State<T> *state) {
  return this->inside_open_list.count(state->GetState()) == 1;
}

template <class T, class COMP>
State<T> *PriorityQueueBasedSearcher<T, COMP>::GetFromOpenList(State<T> *state) {
  return this->inside_open_list.find(state->GetState())->second;
}

template <class T, class COMP>
void PriorityQueueBasedSearcher<T, COMP>::UpdateInOpenList(State<T> *old_state, State<T> *new_state) {
  this->open_list.Update(old_state, new_state);

  this->inside_open_list.erase(old_state->GetState());
  this->inside_open_list.insert({new_state->GetState(), new_state});
}

template<class T, class COMP>
void PriorityQueueBasedSearcher<T, COMP>::Reset() {
  this->evaluated_nodes = 0;
  this->inside_open_list.clear();

  while (!this->open_list.IsEmpty()) {
    this->open_list.Pop();
  }
}

#endif //EX4_ALGORITHMS_PRIORITYQUEUEBASEDSEARCHER_H_
