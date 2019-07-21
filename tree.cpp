#ifndef __TREE_CPP__
#define __TREE_CPP__

#include "board.h"  
#include "tree.h"

using namespace std;

Tree::Tree(){
}
Tree::Tree(int a){
    numChildren=a;
    for (int i = 0; i < a; i ++)
    {children[i] = new Tree();}
}
Tree::Tree(Tree* input){
    parent = input -> get_parent();
    for(int i = 0; i < 6; i++){
        children[i] = input -> get_child(i);
    }
    board = input -> getdata();
}

/*
void Tree::init(){
    for (int i = 0; i < 6; i ++)
    {children[i] = new Tree();}
}
*/

void set_parent_to_children(Tree* inP){
    for (int i =0;i<inP->get_numChildren();i++){
        inP->get_child(i)->set_parent(inP);
    }
}

#endif
