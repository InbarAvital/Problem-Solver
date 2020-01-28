//
// Created by noam on 27/01/2020.
//

#include "Point.h"
#include "../Utility.h"

bool Point::operator==(const Point &point) const {
  return this->x_val == point.x_val && this->y_val == point.y_val;
}

string Point::ToString() {
  return to_string(this->x_val) + "," + to_string(this->y_val);
}

Point::Point(string str) {
  vector<string> coordinates = Utility::Split(str, ",");
  this->x_val = stoi(coordinates[0]);
  this->y_val = stoi(coordinates[1]);
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
