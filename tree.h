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
	void print_data() { board.print(); }

	void move_checker_step(int originRow, int originCol, int steps) {
		board.move_checker_step(originRow, originCol, steps);
	}
	void bear_off(int row, int col, int step);
	void isWin();

	void set_child(Tree* input, int pos) { children[pos] = input; }
	void set_parent(Tree* input) { parent = input; }
	Tree* get_child(int pos) { return children[pos]; }
	Tree* get_parent() { return parent; }
	Tree** get_children() { return children; }
	size_t get_numChildren() { return numChildren; }
	//void init();

private:
	size_t numChildren = 6;
	Tree* parent;
	Tree** children = new Tree*[numChildren];
	Board <string> board;
};

void set_parent_to_children(Tree* inP);//set the tree object itself to all the children


#include "tree.cpp"
#endif 