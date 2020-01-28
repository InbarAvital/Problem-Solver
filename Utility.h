//
// Created by noam on 28/01/2020.
//

#ifndef EX4__UTILITY_H_
#define EX4__UTILITY_H_

#include <string>
#include <vector>

using namespace std;

// Class for general useful function.
class Utility {
 public:
  // Input: str - The string to split.
  //        split_by - The delimiter to split by.
  // Output:  A vector of strings from the given string, after splitting it.
  static vector<string> Split(string str, string split_by);
};

#endif //EX4__UTILITY_H_
