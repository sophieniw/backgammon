#ifndef __TREE_H__
#define __TREE_H__

#include "board.h"

using namespace std;

class Tree {
public:
    Tree();
    Tree(int a);

    Board<string> getdata() { return board; }
    void set_board(Board<string> board1){board = board1;}

    void set_child(Tree* input, int pos) { children[pos] = input; }
    Tree* get_child(int pos) { return children[pos]; }
    void set_parent(Tree* input) { parent = input; }
    Tree* get_parent() { return parent; }
    Tree** get_children() { return children; }
	void remove_children();
	
    void set_num_children(size_t a) {numChildren = a;}
    size_t get_numChildren() { return numChildren; }
    int re_row(){return board.re_row();} //return the next row that has a movable checker
    int re_col(){return board.re_col();} //return the next col that has a movable checker
    void init(int numBranches);

    void print() { board.print(); }

    void move_checker_step(int originRow, int originCol, int steps) { board.move_checker_step(originRow, originCol, steps);}
    void bear_off(int dice_num){board.bear_off(dice_num);}

	size_t pieces_to_move(){return board.pieces_to_move();}
	void set_surface_checker_pos(){board.set_surface_checker_pos(board.surface_checker_cols, board.surface_checker_rows);}


private:
    size_t numChildren=6;
    Tree* parent;
    Tree** children = new Tree*[numChildren];
    Board <string> board;
};


//below is for minimax search algo
bool isInBearOff(Tree* t); //to set a state that terminate the minimax search
int evaluate(Tree* child); //evaluate each child and return a score for minimax search
void minimax(Tree* t, bool isMaximizing, int count);







#include "tree.cpp"

#endif 
