//
// Created by noam on 25/01/2020.
//

#ifndef EX4_ALGORITHMS_MINPRIORITYQUEUE_H_
#define EX4_ALGORITHMS_MINPRIORITYQUEUE_H_

#include <queue>
using namespace std;

// A priority queue (min heap) that supports updating values.
// The element type E has to implement the ">" and "==" operators.
template <class E>
class MinPriorityQueue {
 public:
  // Removes the smallest element in this priority queue.
  void Pop();

  // Output: The smallest element in this priority queue.
  const E& Top() const;

  // Input: element - An element.
  // Adds that element to this priority queue.
  void Push(const E& element);

  // Input: old_element - An element in this priority queue.
  //        new_element - The element to update the old one.
  // Updates the old element in this priority queue to be the new element.
  void Update(const E& old_element, const E& new_element);

  // Output: True or false whether this priority queue is empty or not.
  bool IsEmpty() const;

  // Output: The number of elements in this priority queue.
  unsigned long GetSize() const;

 private:
  priority_queue<E, vector<E>, greater<E>> queue;
};

template<class E>
void MinPriorityQueue<E>::Pop() {
  this->queue.pop();
}

template<class E>
const E& MinPriorityQueue<E>::Top() const {
  return this->queue.top();
}

template<class E>
void MinPriorityQueue<E>::Push(const E& element) {
  this->queue.push(element);
}

template<class E>
void MinPriorityQueue<E>::Update(const E& old_element, const E& new_element) {
  priority_queue<E, vector<E>, greater<E>> updated_queue;

  while (!this->queue.empty()) {
    // Removes all the elements from this queue.
    E element = this->queue.top();
    this->queue.pop();

    // Adds the elements to another queue but with the updated values
    updated_queue.push(element == old_element ? new_element : element);
  }

  // Updates this priority queue.
  this->queue.swap(updated_queue);
}

template<class E>
bool MinPriorityQueue<E>::IsEmpty() const {
  return this->queue.empty();
}

template<class E>
unsigned long MinPriorityQueue<E>::GetSize() const {
  return this->queue.size();
}

#endif //EX4_ALGORITHMS_MINPRIORITYQUEUE_H_
