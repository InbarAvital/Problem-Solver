//
// Created by noam on 28/01/2020.
//

#ifndef EX4_PROTOCOL_MYCLIENTHANDLER_H_
#define EX4_PROTOCOL_MYCLIENTHANDLER_H_

#include "ClientHandler.h"
#include "../cache/CacheManager.h"
#include "Solver.h"
#include "../algorithms/Searchable.h"

// Client handler that solves matrices route searching problems.
class MyClientHandler : public ClientHandler {
 public:
  // Input: s - A solver for the problems.
  //        cm - The cache manager for the problems' solutions.
  // Constructs a client handler that solves matrices routing searching problems, with those
  // solver and cache manager.
  MyClientHandler(Solver<string, string> *s, CacheManager<string, string> *cm) : solver(s), cache_manager(cm) {}

  void handleClient(int input_stream) override;

 private:
  Solver<string, string> *solver;
  CacheManager<string, string> *cache_manager;
};

#endif //EX4_PROTOCOL_MYCLIENTHANDLER_H_
