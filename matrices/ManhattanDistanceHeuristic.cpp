//
// Created by noam on 27/01/2020.
//

#include <cstdlib>
#include "ManhattanDistanceHeuristic.h"

Point ManhattanDistanceHeuristic::goal_point(0, 0);

double ManhattanDistanceHeuristic::operator()(const string &str_point) {
  Point point(str_point);
  return abs(ManhattanDistanceHeuristic::goal_point.GetX() - point.GetX()) + abs(ManhattanDistanceHeuristic::goal_point.GetY() - point.GetY());
}
