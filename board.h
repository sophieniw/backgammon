#ifndef __BOARD_H__
#define __BOARD_H__

#include <iostream>
#include <vector>
using namespace std;


// Board class
// used to display the layout and control the movement of checkers 
template <class Item>
class Board{
 public:
   typedef size_t size_type; 
   typedef Item data_type;
   const static size_type point_size = 24;
   const static size_type max_column = 6;
  //to store movable checkers' cols and rows for later calculation
   vector<int> surface_checker_cols; 
   vector<int> surface_checker_rows; 


   Board();  // for initial layout for checker
   void print(); //to print out the entire board state

   size_t get_checker_removed_num(){return checker_removed;}
   void set_checker_removed_num(int num){checker_removed=num;}

   bool get_board_moved(){return board_moved;}
   int get_moved_steps(){return moved_steps;}
  
   void move_checker_step(int originRow, int originCol, int steps); //to move checker on originRow and col with steps towards homeboard
   void bear_off(int dice_num); // to bear off checkers in the homeboards 
   void isWin(); 

   int re_col(); //return the next col that has a movable checker
   int re_row(); //return the next row that has a movable checker
   size_t pieces_to_move();  //calculate how many pieces you can move on a board (surface checkers)
   void set_surface_checker_pos(vector<int>& surface_checkers_cols, vector<int>& surface_checkers_rows); 
      // change the 2 vectors so that they store rows and cols for surface checkers for the current board state

private:
   Item board[point_size][max_column]; //board state presentation
   size_t checker_removed; //when this is 15, that means all checkers have been "bear off"
   bool board_moved; //true if this board state is not the same as the parent board
   int moved_steps; //return how many steps the board state has chose to moved compared to its parent board

};


#include "board.cpp"
#endif