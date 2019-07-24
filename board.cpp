#ifndef __BOARD_CPP__
#define __BOARD_CPP__

#include "board.h"
using namespace std;

template <class Item>
Board<Item>::Board(){ 
    //default constructor to layout the origin board state
    // B W B W B W B W B W B W
    // 2       1   1         2
    // 2       1   1         2
    // 2       1   1
    // 2           1
    // 2           1
    //
    // 1           2
    // 1           2
    // 1       2   2
    // 1       2   2         1
    // 1       2   2         1
    // B W B W B W B W B W B W

    checker_removed=0;
    board_moved=false;

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
void Board<Item>::print(){ // to print out the board
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
void Board<Item>::move_checker_step(int originRow, int originCol, int steps){
    //PRE CONDITION: index position of one checker: originRow, originCol, and steps for the checker to move towards home board
    //POST CONDITION: the board is changed based on the checker moved; move_steps and board_moved would be updated too 
    board_moved=false;
    moved_steps=0;
    if (board[originCol][originRow]=="1" && board[originCol+steps][1]!="2" && board[originCol+steps][5]!="1"){
        size_t i =1;
        while(board[originCol+steps][i]!=" "){
            i++; //find the row that can be stacked
        }
        board[originCol][originRow]=" ";
        board[originCol+steps][i]="1"; 

        board_moved=true;
        moved_steps=steps;
    }
    //if there's invalid move, the board will stay the same
}

template <class Item>
void Board<Item>::bear_off(int dice_num){
    //PRE CONDITION: an integer from 1-6
    //POST CONDITION: a checker on the column of (24-dice_num) would be removed
    board_moved=false;
    if(board[24-dice_num][1]=="1"){
        int row=1;
        while (board[24-dice_num][row+1]=="1"){
            row++;
        }
        board[24-dice_num][row]=" ";
       checker_removed+=1;
       board_moved=true;

    }

}

template <class Item>
void Board<Item>::isWin(){
    //check if all checkers are borne off
   if (checker_removed==15){
       cout << "You won the game!\n";
   }
}

template <class Item>
size_t Board<Item>::pieces_to_move(){
    //
    size_t count=0;
    for(int i =0;i<18;i++){
        if (board[i][1]=="1"){
            count++;
        }
    }
    return count;
}

template <class Item>
void Board<Item>::set_surface_checker_pos(vector<int>& surface_checkers_cols, vector<int>& surface_checkers_rows){
    //PRE CONDITION:  2 vectors that store rows and cols for surface checkers for the previous board state
    //POST CONDITION: the 2 vectors are updated according to the updeated board state
    surface_checkers_cols.clear();
    surface_checkers_rows.clear();
    for(int i =0;i<18;i++){
        int col=0;
        int row=1;
        if (board[i][1]=="1"){
            while (board[i][row+1]=="1"){
                row++;
            }
            surface_checkers_cols.push_back(i);
            surface_checkers_rows.push_back(row);
        }
    }
}

template <class Item>
int Board<Item>::re_col(){
    //return the next col that has a movable checker
    for (int i = 0; i < 24; i++){
        for (int j = 5; j > 0; j--){
            if (board[i][j] == "1"){
                return i;
            }
        }
    }
}

template<class Item>
int Board<Item>::re_row(){
    //return the next row that has a movable checker
    for (int i = 0; i < 24; i++){
        for (int j = 5; j > 0; j--){
            if (board[i][j] == "1"){
                return j;
            }
        }
    }
}



#endif