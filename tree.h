#ifndef __TREE_H__
#define __TREE_H__

#include "board.h"

using namespace std;

class Tree {
public:
    Tree();
    Tree(int a);
    Tree(Tree* input);

    Board<string> getdata() { return board; }
    void print() { board.print(); }

    void move_checker_step(int originRow, int originCol, int steps) {
        board.move_checker_step(originRow, originCol, steps);
    }
    void bear_off(int dice_num){board.bear_off(dice_num);}
    void isWin();
    
    void set_board(Board<string> board1){board = board1;}
    void set_child(Tree* input, int pos) { children[pos] = input; }
    void set_parent(Tree* input) { parent = input; }
    Tree* get_child(int pos) { return children[pos]; }
    Tree* get_parent() { return parent; }
    Tree** get_children() { return children; }
	void remove_children();
	
    void set_num_children(size_t a) {numChildren = a;}
    size_t get_numChildren() { return numChildren; }
    int re_row(){return board.re_row();}
    int re_col(){return board.re_col();}
    void init(int numBranches);
	size_t pieces_to_move(){return board.pieces_to_move();}
	void set_surface_checker_pos(){board.set_surface_checker_pos(board.surface_checker_cols, board.surface_checker_rows);}

private:
    size_t numChildren = 6;
    Tree* parent;
    Tree** children = new Tree*[numChildren];
    Board <string> board;
};

void set_parent_to_children(Tree* inP);//set the tree object itself to all the children

void set_children_boards(Tree* parent);
void set_tree(Tree* parent);






#include "tree.cpp"

#endif 
