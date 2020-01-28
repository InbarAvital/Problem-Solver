//
// Created by noam on 28/01/2020.
//

#include "Utility.h"

vector<string> Utility::Split(string str, string split_by) {
  // true every time we find a split_by string
  bool found;
  // a string to add until we find a split_by string
  string to_add = "";
  // the splitted list we send in the end
  vector<string> splitted;
  // for loop on each char in "str"
  for (int i = 0; i < str.length(); i++) {
    found = true;
    // for loop to check if this current char is the beginning of "split_by"
    int i_copy = i;
    for (int j = 0; j < split_by.length(); j++) {
      if (str[i_copy + j] != split_by[j]) {
        found = false;
        i_copy += j;
        break;
      }
    }
    // if we find a "split_by", we add what was before the it and not yes
    // added to the list, ignore the "split_by", and continue
    if (found) {
      i += split_by.length() - 1;
      if (to_add != "")
        splitted.push_back(to_add);
      to_add = "";
    }
    else {
      to_add += str[i];
      if (i == str.length() - 1) {
        splitted.push_back(to_add);
      }
    }
  }
  return splitted;
}
