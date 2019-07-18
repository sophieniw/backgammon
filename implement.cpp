#include "board.h"
#include "tree.h"
using namespace std;

int main(){
    //below is the root of the tree: the beginning state of board == default board constr
    Board<string> root_board;
    //root_board.print();
    const int index=7;

    Board<string> col11_row5[index]; 
    //even tho there're only 6 die numbers, I'd like to create 7 instances so that
    //the step moved matches with the die number(see below)

    for (int i = 1; i <7;i++){
        col11_row5[i].move_checker_step(5,11,i);
    }
    //in this way, col11_checker1[1] moved 1 step, ...[2] moved 2 steps, etc.
    //now, col11_checker1[1]-col11_checker1[6] are 6 board states for col 11 checker 1

    // you can print out the arr element to see if the boards are created correctly
    //col11_row5[2].print();
    //col11_row5[3].print();

    //=================================
    //create board states for col16_row3
    Board<string> col16_row3[index];
    for (int i = 0;i<7;i++){
        col16_row3[i].move_checker_step(3,16,i);
    }
    //to test:
    //col16_row3[1].print();
    
    //****** the print out of the board states are all correct, 
    //but when it's implemented into the node, it doesn't work.

    Node* root;
    //cout << root->getNumChildren();
    //the number of children returned is not correct. It returned a large number 2337559003.
    //so I think the bug is in the tree.h/ tree.cpp node class

    //root->printData();
    // it returned empty space

    return 0;
}