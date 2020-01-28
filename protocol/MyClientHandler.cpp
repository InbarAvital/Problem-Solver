//
// Created by noam on 28/01/2020.
//

#include <unistd.h>
#include <cstring>
#include <sys/socket.h>
#include "MyClientHandler.h"
#include "../Utility.h"

void MyClientHandler::handleClient(int input_stream) {
  bool should_stop = false;
  string problem;

  // Keep until finished reading the problem from the client.
  while (!should_stop) {
    char buffer[1024] = { 0 };

    //reading from client
    read(input_stream, buffer, 1024);
    string message(buffer);

    // Splits the client message to lines.
    vector<string> lines = Utility::Split(message, "\n");
    for (auto line : lines) {
      if (line != "end") {
        // Finished reading lines of problem.
        should_stop = true;
        break;
      } else {
        // Adds the line to the problem.
        problem += line + "\n";
      }
    }
  }

  string solution;

  // Solves the problem.
  if(this->cache_manager->doesHaveSol(problem)) {
    // We already have the solution for this problem in our cache.
    solution = this->cache_manager->getSol(problem);
  } else {
    // We don't have the solution for this problem in our cache.
    solution = this->solver->solve(problem);

    // Saves the solution for this problem in our cache.
    this->cache_manager->setSol(problem, solution);
  }

  // Sends the solution back to the client.
  send(input_stream, solution.c_str(), strlen(solution.c_str()), 0);
}
