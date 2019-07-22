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
    {children[i] = new Tree();
     children[i] -> set_parent(this);
    }
}

Tree::Tree(Tree* input){
    parent = input -> get_parent();
    for(int i = 0; i < 6; i++){
        children[i] = input -> get_child(i);
    }
    board = input -> getdata();
}

void Tree::init(int numBranches){
    numChildren=numBranches;
    for (int i = 0; i < numChildren; i ++){
        children[i] = new Tree();
        children[i]->set_parent(this);
        children[i]->set_board(board);

        int checker_removed_num=this->getdata().get_checker_removed_num();
        children[i]->getdata().set_checker_removed_num(checker_removed_num);
    } 
    
}

void Tree::remove_children(){
    delete[] children;
}

void set_parent_to_children(Tree* inP){
    for (int i =0;i < inP -> get_numChildren();i++){
        inP->get_child(i) -> set_parent(inP);
    }
}


//the function below takes in a tree node and set the children node according to the parent node
void set_children_boards(Tree* parent){
    parent->set_surface_checker_pos(); //to collect positions of surface checkers that can be moved
    vector<int> surface_checker_cols=parent->getdata().surface_checker_cols; //to store the column index of surface checkers
    vector<int>surface_checker_rows=parent->getdata().surface_checker_rows;  //to store the row index of surface checkers
    //to get the number of branches for this parent
    size_t numCheckers=parent->pieces_to_move();  //to get how many pieces can be moved according to the board in the parent node

    if(parent->pieces_to_move()!=0){ //if there are pieces that you can move
        size_t numBranches=numCheckers * 6; 
        parent->init(numBranches); 
        //init(int x) function creates x number of child nodes under parent; 
        //in the child nodes, before editing, the board is the same as the parent

        Tree* curr; 
        for (int j = 0;j<numCheckers;j++){ // move every surface checker
            for (int i = 0+(6*j); i<6+(6*j);i++){ //for every 6 positions in the child node array 
                curr=parent->get_child(i); //take the child node out
                curr->move_checker_step(surface_checker_rows[j],surface_checker_cols[j],i-(6*j)+1); //pn the board of the child node, move every surface checker 1-6 steps 
                parent->set_child(curr,i); //put the child node back
            }
        } 
        //set_parent_to_children(parent);
    }
    //something's wrong with this statement
    else if (parent->getdata().get_checker_removed_num()<15){ //if there are no movable pieces, starts bearing off the pieces on the home board
        parent->init(6);
        Tree* curr;
        for(int i =0;i<6;i++){
            curr=parent->get_child(i);
            curr->bear_off(i);
        }
    }

    else if (parent->getdata().get_checker_removed_num()==15){//if all checkers are born off, remove the child nodes created under default 
        parent->remove_children();
    }


}


void set_tree(Tree* parent){
    if (parent->getdata().get_checker_removed_num()==15){
            cout << "you win the game!"<<endl;
            return;
    }
    for(int i=0;i<parent->get_numChildren();i++){
        Tree* p = parent->get_child(i); //access each child as p under parent 
        set_children_boards(p);//set children boards for p, so p has an array of children nodes now
        set_tree(p); //for each p,do the same thing: access each child, set boards for each child, and repeat for each child
    }

}
#endif
