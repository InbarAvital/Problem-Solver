//
// Created by noam on 27/01/2020.
//

#include "MatrixRouteSearchable.h"

State<string> *MatrixRouteSearchable::GetInitialState() {
  int x = this->initial_point.GetX(), y = this->initial_point.GetY();
  return new State<string>(this->initial_point.ToString(), this->matrix[x][y]);
}

bool MatrixRouteSearchable::IsGoalState(State<string> *state) {
  return state->GetState() == this->goal_point.ToString();
}

string MatrixRouteSearchable::RouteToString(list<State<string> *> route) {
  string result;

  // Iterates the list of states.
  list<State<string>*>::iterator it = route.begin();
  string previous = route.front()->GetState();
  for (it++; it != route.end(); it++) {
    // Gets the current state.
    string current = (*it)->GetState();

    // Gets the direction from the previous state to the current.
    string dir = Point(previous).GetDirectionToPoint(Point(current));

    result += dir + " (" + to_string((int) (*it)->GetCost()) + ") ,";

    // Continue to the next state in the list;
    previous = current;
  }

  // Removes the last ", " characters.
  result = result.substr(0, result.size() - 2);

  return result;
}

list<State<string>*> MatrixRouteSearchable::GetAllPossibleStates(State<string> *state) {
  list<State<string>*> successors;

  // Get the state's point.
  Point point = Point(state->GetState());
  int x = point.GetX(), y = point.GetY();

  if (x > 0) {
    // Not on the upper row.
    if (this->matrix[x - 1][y] != -1) {
      string upper_point(Point(x - 1, y).ToString());
      State<string> *successor = new State<string>(upper_point);
      successor->SetPreviousState(state, this->matrix[x - 1][y]);
      successor->SetHeuristicCost(this->heuristic_function(upper_point));
      successors.push_back(successor);
    }
  }

  if (x < this->column_length - 1) {
    // Not on the lower row.
    if (this->matrix[x + 1][y] != -1) {
      string lower_point(Point(x + 1, y).ToString());
      State<string> *successor = new State<string>(lower_point);
      successor->SetPreviousState(state, this->matrix[x + 1][y]);
      successor->SetHeuristicCost(this->heuristic_function(lower_point));
      successors.push_back(successor);
    }
  }

  if (y > 0) {
    // Not on the left column.
    if (this->matrix[x][y - 1] != -1) {
      string left_point(Point(x, y - 1).ToString());
      State<string> *successor = new State<string>(left_point);
      successor->SetPreviousState(state, this->matrix[x][y - 1]);
      successor->SetHeuristicCost(this->heuristic_function(left_point));
      successors.push_back(successor);
    }
  }

  if (y < this->row_length - 1) {
    // Not on the right column.
    if (this->matrix[x][y + 1] != -1) {
      string right_point(Point(x, y + 1).ToString());
      State<string> *successor = new State<string>(right_point);
      successor->SetPreviousState(state, this->matrix[x][y + 1]);
      successor->SetHeuristicCost(this->heuristic_function(right_point));
      successors.push_back(successor);
    }
  }

  return successors;
}

int MatrixRouteSearchable::GetRows() {
  return this->matrix.size();
}

int MatrixRouteSearchable::GetColumns() {
  return this->matrix[0].size();
}
