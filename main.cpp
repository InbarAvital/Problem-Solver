//
// Created by inbar on 21/01/2020.
//


#include "server/MySerialServer.h"
#include "algorithms/State.h"
#include "algorithms/MinPriorityQueue.h"

using namespace server_side::boot;

using namespace std;

class Tester {
 public:
  void TestState() {
    State<string> s1("A");
    State<string> s2("B");
    State<string> s3("C");
    State<string> s4("C");

    s2.SetPreviousState(&s1, 10);
    s3.SetPreviousState(&s2, 3);

    cout << (s3 == s4) << endl;
    cout << (s2 == s4) << endl;

    cout << s2.GetCost() << endl;
    cout << s3.GetCost() << endl;

    cout << s2.GetState() << endl;
    cout << s3.GetState() << endl;

    list<State<string>> path = s3.BacktracePath();
    cout << "Path:";
    for (auto s : path) {
      cout << " " << s.GetState() << "(" << s.GetCost() << ")";
    }
  }

  void TestPriorityQueue() {
    MinPriorityQueue<int> queue;

    cout << queue.IsEmpty() << "\t(1)" << endl;

    queue.Push(3);
    queue.Push(6);
    queue.Push(1);
    queue.Push(39);
    queue.Push(8);

    cout << queue.GetSize() << "\t(5)" << endl;
    cout << queue.IsEmpty() << "\t(0)" << endl;

    int e = queue.Top();

    cout << e << "\t(1)" << endl;
    cout << queue.GetSize() << "\t(5)" << endl;

    queue.Pop();
    queue.Pop();

    cout << queue.GetSize() << "\t(3)" << endl;

    e = queue.Top();

    cout << e << "\t(6)" << endl;

    queue.Push(40);
    queue.Push(20);

    MinPriorityQueue<int> tmp = queue;
    while (!tmp.IsEmpty()) {
      cout << " " << tmp.Top();
      tmp.Pop();
    }
    cout << endl;

    queue.Update(20, 200);

    tmp = queue;
    while (!tmp.IsEmpty()) {
      cout << " " << tmp.Top();
      tmp.Pop();
    }
    cout << endl;
  }
};

int main(int argc, char *argv[]) {
  Tester t;
  t.TestPriorityQueue();
//    Main m;
//    m.main(argc, argv);
}