# backgammon-search-tree
## About
The goal of Backgammon Search Tree project is to implement search algorithms into the game backgammon. 
So far, the search algos implemented are BFS and Minimax. DFS is in progress.
* [About](#about)
* [Files Explained](#files-explained)
  * [board.h and board.cpp](#board.h-and-board.cpp)
  * [tree.h and tree.cpp](#tree.h-and-tree.cpp)
  * [implement.cpp](#implement.cpp)
* [Examples](#examples)
* [Installation](#installation)
* [Implementation](#implementation)
* [License](#license)

## Files Explained
### board.h and board.cpp 
Board files contain board class used to display board states and control the movement of checkers.
### tree.h and tree.cpp
Tree files contain a tree class that create nodes and link them with parent nodes and children nodes. 
Nodes are used to store different board states.
Outside of the tree class, there are functions used to do search algos, such as evaluate, BFS, and minimax functions.

### implement.cpp
This file contains a program that shows a header of backgammon and a menu for users to choose which search algos they wish to see.
When the specific search algo is chosen, the program will then run the algo and show the board states as the computer is playing the
game itself.

## Examples

## Installation
* Git clone this repository to your preferred directory 
**or**
* Download this repository

## Implementation
In your console, type
`g++ implement.cpp`
and then
`./a.exe` for windows or `./a.out` for macOS.
## License 
Apache License 2.0
