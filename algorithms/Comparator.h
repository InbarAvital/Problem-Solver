//
// Created by noam on 26/01/2020.
//

#ifndef EX4_ALGORITHMS_COMPARATOR_H_
#define EX4_ALGORITHMS_COMPARATOR_H_

// Compares two object.
template <class T>
class Comparator {
 public:
  virtual bool operator()(T first, T second) = 0;
};

#endif //EX4_ALGORITHMS_COMPARATOR_H_
