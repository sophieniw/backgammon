#ifndef __BOARD_H__
#define __BOARD_H__

#include <iostream>
#include <vector>
using namespace std;


// Board class
// use to display the layout and control the movement of checkers
template <class Item>
class Board{
 public:
   typedef size_t size_type;
   typedef Item data_type;
   const static size_type point_size = 24;
   const static size_type max_column = 6;

   Board();  // for initial layout for checker
   void print();
   void move_checker(int row, int col, int to_row, int to_col);
   void move_checker_step(int originRow, int originCol, int steps);
   void bear_off(int row, int col);
   void isWin();

private:
   Item board[point_size][max_column];
   size_t checker_removed=0; //when this is 15, that means all checkers have been "bear off"
};

#include "board.cpp"
#endif