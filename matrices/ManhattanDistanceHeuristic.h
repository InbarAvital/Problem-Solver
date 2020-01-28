//
// Created by noam on 27/01/2020.
//

#ifndef EX4_ALGORITHMS_MANHATTANDISTANCEHEURISTIC_H_
#define EX4_ALGORITHMS_MANHATTANDISTANCEHEURISTIC_H_

#include <iostream>
#include "Point.h"

// Heuristic function based on Manhattan Distance between the current point and the goal point.
class ManhattanDistanceHeuristic {
 public:
  // Input: goal - A goal position coordinates.
  // Sets the goal position for Manhattan Distance Heuristic.
  static void SetGoalPoint(Point goal) {
    ManhattanDistanceHeuristic::goal_point = goal;
  }

  // Input: str_point - A string represents point.
  // Output:  The heuristic value of that point.
  double operator()(const string &str_point);

 private:
  static Point goal_point;
};

#endif //EX4_ALGORITHMS_MANHATTANDISTANCEHEURISTIC_H_
