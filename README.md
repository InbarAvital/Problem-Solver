# Problem Solver - Part2 C++ Project
### Credit:  Inbar Avital and Noam Yakov
## Description:
This is a C++ project that basicaly solves searching problems using searching algorithm.
This is a server that can handle up to 10 different client simultaneously. Each client sent a searching problem to the server and the server solves the problem and sends the solution back to the client. The server solves the searcing problem using the A* searcing algorithm.
It is using a well designed base-code and structure, so it easy to add any problem we want to, and solve it! :)

## Installation and Running
Install the files clicking the green "***clone or download***" button, and choose the preffered option.

#### Compile the program using this command:
> g++ -std=c++14 \*/*.cpp *.cpp -Wall -Wextra -Wshadow -Wnon-virtual-dtor -pedantic -o a.out -pthread

#### and then run it with:
> ./a.out PORT_NUMBER
```(change the PORT_NUMBER to be the port number you want your server to run on)```


Link to github: https://github.com/InbarAvital/Problem_Solver
