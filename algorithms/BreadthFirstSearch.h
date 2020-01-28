//
// Created by noam on 26/01/2020.
//

#ifndef EX4_ALGORITHMS_BREADTHFIRSTSEARCH_H_
#define EX4_ALGORITHMS_BREADTHFIRSTSEARCH_H_

#include <queue>
#include <unordered_map>
#include "Searcher.h"

// Breadth first search algorithm.
template <class T>
class BreadthFirstSearch : public Searcher<T> {
 public:
  // Constructs a BFS searching algorithm and initializes its number of evaluated nodes.
  BreadthFirstSearch<T>(): evaluated_nodes(0) {}

  list<State<T>*> Search(Searchable<T> *searchable) override;

  int GetNumberOfNodesEvaluated() override;

  void Reset();

 private:
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

  int evaluated_nodes;
  queue<State<T>*> open_list;
  unordered_map<T, State<T>*> inside_open_list;
};

template<class T>
int BreadthFirstSearch<T>::GetNumberOfNodesEvaluated() {
  return this->evaluated_nodes;
}

template<class T>
list<State<T>*> BreadthFirstSearch<T>::Search(Searchable<T> *searchable) {
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
    for (State<T> *s : successors) {
      if (closed.count(s->GetState()) != 1) {
        if (!this->OpenListContains(s)) {
          // New unevaluated node
          this->AddToOpenList(s);
        }
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

template<class T>
State<T> *BreadthFirstSearch<T>::PopOpenList() {
  // Gets the next state from the open list.
  State<T> *state = this->open_list.front();

  // Pops that state from the open list.
  this->open_list.pop();
  this->inside_open_list.erase(state->GetState());

  // Increases the number of the evaluated nodes by 1.
  this->evaluated_nodes++;

  return state;
}

template<class T>
void BreadthFirstSearch<T>::AddToOpenList(State<T> *state) {
  this->open_list.push(state);
  this->inside_open_list.insert({state->GetState(), state});
}

template<class T>
bool BreadthFirstSearch<T>::OpenListIsEmpty() {
  return this->open_list.empty();
}

template<class T>
bool BreadthFirstSearch<T>::OpenListContains(State<T> *state) {
  return this->inside_open_list.count(state->GetState()) == 1;
}

template<class T>
State<T> *BreadthFirstSearch<T>::GetFromOpenList(State<T> *state) {
  return this->inside_open_list.find(state->GetState())->second;
}

template<class T>
void BreadthFirstSearch<T>::UpdateInOpenList(State<T> *old_state, State<T> *new_state) {
  queue<State<T>*> updated_open_list;

  while (!this->open_list.empty()) {
    // Removes all the elements from this queue.
    State<T> *state = this->open_list.front();
    this->open_list.pop();

    // Adds the elements to another queue but with the updated values
    updated_open_list.push(*state == *old_state ? new_state : state);
  }

  // Updates this priority queue.
  this->open_list.swap(updated_open_list);

  this->inside_open_list.erase(old_state->GetState());
  this->inside_open_list.insert({new_state->GetState(), new_state});
}

template<class T>
void BreadthFirstSearch<T>::Reset() {
  this->evaluated_nodes = 0;
  this->inside_open_list.clear();

  while (!this->open_list.empty()) {
    this->open_list.pop();
  }
}

#endif //EX4_ALGORITHMS_BREADTHFIRSTSEARCH_H_
