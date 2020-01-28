//
// Created by noam on 27/01/2020.
//

#include "Point.h"

bool Point::operator==(const Point &point) const {
  return this->x_val == point.x_val && this->y_val == point.y_val;
}

string Point::ToString() {
  return to_string(this->x_val) + "," + to_string(this->y_val);
}

Point::Point(string str) {
  vector<string> coordinates = Point::Split(str, ",");
  this->x_val = stoi(coordinates[0]);
  this->y_val = stoi(coordinates[1]);
}

vector<string> Point::Split(string str, string split_by) {
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

string Point::GetDirectionToPoint(Point point) {
  if (point.x_val == this->x_val - 1) {
    return "Up";
  } else if (point.x_val == this->x_val + 1) {
    return "Down";
  } else if (point.y_val == this->y_val - 1) {
    return "Left";
  } else if (point.y_val == this->y_val + 1) {
    return "Right";
  } else {
    return "";
  }
}
