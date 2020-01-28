//
// Created by noam on 27/01/2020.
//

#include <cstdlib>
#include "ManhattanDistanceHeuristic.h"

double ManhattanDistanceHeuristic::operator()(const string &str_point) {
  Point point(str_point);
  return abs(this->goal_point.GetX() - point.GetX()) + abs(this->goal_point.GetY() - point.GetY());
}
