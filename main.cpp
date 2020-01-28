//
// Created by inbar on 21/01/2020.
//

#include "server/MySerialServer.h"
#include "algorithms/PriorityQueue.h"
#include "algorithms/Astar.h"
#include "protocol/SearcherSolver.h"
#include "protocol/MyClientHandler.h"
#include "server/MyParallelServer.h"

using namespace server_side::boot;

using namespace std;

int main(int argc, char *argv[]) {
  int port = argc > 1 ? atoi(argv[1]) : 5600;
  Solver<string, string> *solver = new SearcherSolver(new Astar<string>());
  CacheManager<string, string> *cache_manager = new FileCacheManager();
  ClientHandler *handler = new MyClientHandler(solver, cache_manager);
  Server *server = new MyParallelServer();
  server->open(port, handler);
}
