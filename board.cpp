#ifndef __BOARD_CPP__
#define __BOARD_CPP__

#include "board.h"
using namespace std;

template <class Item>
Board<Item>::Board(){
   for (int i = 0; i < 24; i ++){
       int count = i;
       if (count > 11){
           count ++;
       }
       if (count % 2 == 0){
           board[i][0] = "W";
       }
       else {
           board[i][0] = "B";
       }
   }
   for (int i = 0; i < 24; i++){
       for (int j = 1; j <6; j++){
           board[i][j] = " ";
       }
   }

   //2D arrays for board:
   //[0][1]: col 0 and row 1
   // col 0 is the 1st to the right
   // col 23 is the last (upper right col)
   board[0][1] = "1"; board[0][2] = "1"; // black = 1
   board[23][1] = "2"; board[23][2] = "2"; // white = 2
   for (int i = 1; i < 6; i ++){board[5][i] = "2";}
   for (int i = 1; i < 6; i ++){board[18][i] = "1";}
   for (int i = 1; i < 6; i ++){board[12][i] = "2";}
   for (int i = 1; i < 6; i ++){board[11][i] = "1";}
   for (int i = 1; i < 4; i ++){board[7][i] = "2";}
   for (int i = 1; i < 4; i ++){board[16][i] = "1";}
}

template <class Item>
void Board<Item>::print(){
   for (int i = 0; i < 6; i ++){

       for (int j = 12; j < 24; j ++){
           cout << board[j][i];
           if (j != 23){cout << " ";}
       }
       cout << endl;
   }
   cout << endl;
   for (int k = 5; k >= 0; k --){
       for (int m = 11; m >= 0; m --){
           cout << board[m][k];
           if (m != 0){cout << " ";}
       }
       cout << endl;
   }
}

template <class Item>
void Board<Item>::move_checker(int row, int col, int to_row, int to_col){
   if (board[col][row]=="1" && board[to_col][to_row]!="2"){
       board[col][row]=" ";
       board[to_col][to_row]="1";
   }
   else{
       cout << "Not a valid move. Please try again.";
   }
  
}

template <class Item>
void Board<Item>::move_checker_step(int originRow, int originCol, int steps){
    if (board[originCol][originRow]=="1" && board[originCol+steps][1]!="2"){
        size_t i =1;
        while(board[originCol+steps][i]!=" "){
            i++; //find the row that can be stacked
        }
        board[originCol][originRow]=" ";
        board[originCol+steps][i]="1"; 
    }
    //if there's invalid move, the board will stay the same
}

template <class Item>
void Board<Item>::bear_off(int row, int col){
   if (board[col][row]=="1"&&checker_removed!=15){
       board[col][row]=" ";
       checker_removed+=1;
   }
   else{
       cout << "Not a valid move. Please try again.";
   }
}

template <class Item>
void Board<Item>::isWin(){
   if (checker_removed==15){
       cout << "You won the game!\n";
   }
}

#endif