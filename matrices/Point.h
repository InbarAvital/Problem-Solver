//
// Created by noam on 27/01/2020.
//

#ifndef EX4_ALGORITHMS_POINT_H_
#define EX4_ALGORITHMS_POINT_H_

#include <string>
#include <vector>

using namespace std;

// A point on the Cartesian coordinate system.
class Point {
 public:
  // Input: x - The x value.
  //        y - The y value.
  // Constructs a point at the coordinates (x, y).
  Point(int x, int y): x_val(x), y_val(y) {}

  // Input: str - The point "<x>,<y>".
  // Constructs a point at the coordinates (x, y).
  explicit Point(string str);

  // Output:  The x value of this point.
  int GetX() {
    return this->x_val;
  }

  // Output:  The y value of this point.
  int GetY() {
    return this->y_val;
  }

  // Input: point - A point to compare.
  // Output:  True or false whether this point is equal to the other point.
  bool operator==(const Point &point) const;

  // Output: The point as string "<x>,<y>".
  string ToString();

  // Input: point - A point.
  // Output:  A string represents the direction from this point to the other point if they are near each other.
  string GetDirectionToPoint(Point point);

 private:
  int x_val;
  int y_val;
};

#endif //EX4_ALGORITHMS_POINT_H_
