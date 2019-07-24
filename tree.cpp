#ifndef __TREE_CPP__
#define __TREE_CPP__

#include "board.h"  
#include "tree.h"
#include <queue>

using namespace std;
//7-24-2019


Tree::Tree(){

}

/*
Tree::Tree(int a){
    //PRE CONDITION: an integer a 
    //POST CONDITION: a tree with integer a number of branches are created
    delete []children;
    numChildren=a;
    for (int i = 0; i < a; i ++)
    {children[i] = new Tree();
     children[i] -> set_parent(this);
    }
}
*/



void Tree::init(int numBranches){
    //PRE CONDITION: an integer numBranches
    //POST CONDITION: a tree object with numBranches amount of children nodes;
    //                the links between the parent and children are also set 
    delete []children;
    numChildren=numBranches;
    children=new Tree*[numChildren];
    for (int i = 0; i < numChildren; i ++){
        children[i] = new Tree();
        children[i]->set_parent(this);
        children[i]->set_board(board);
        children[i]->set_surface_checker_pos();
    } 
    
}


void Tree::remove_children(){
    //delete the Tree** children
    delete[] children;
}


//PRE CONDITION: the function below takes in a parent node with default children nodes with default board states
//POST CONDITION:  the children nodes of that parent now have customized board states derived from the parent
void set_children_boards(Tree* parent){

    parent->set_surface_checker_pos(); //to collect positions of surface checkers that can be moved
    vector<int> surface_checker_cols=parent->getdata().surface_checker_cols; //to store the column index of surface checkers
    vector<int> surface_checker_rows=parent->getdata().surface_checker_rows;  //to store the row index of surface checkers
    //to get the number of branches for this parent
    size_t numCheckers=parent->pieces_to_move();  //to get how many pieces can be moved according to the board in the parent node
    size_t numBranches=numCheckers * 6; 
    parent->init(numBranches); 
    //init(int x) function creates x number of child nodes under parent; 
    //in the child nodes, before editing, the board is the same as the parent

    if(parent->pieces_to_move()!=0){ //if there are pieces that you can move
        size_t numBranches=numCheckers * 6; 
        parent->init(numBranches); 

        Tree* curr; 
        for (int j = 0;j<numCheckers;j++){ // move every surface checker
            for (int i = 0+(6*j); i<6+(6*j);i++){ //for every 6 positions in the child node array 
                curr=parent->get_child(i); //take the child node out
                curr->move_checker_step(surface_checker_rows[j],surface_checker_cols[j],i-(6*j)+1); //pn the board of the child node, move every surface checker 1-6 steps 
                curr->set_surface_checker_pos();
                parent->set_child(curr,i); //put the child node back
            }
        } 
        
    }
    
    else if (isInBearOff(parent)){ //if it's in bear off stage
        parent->init(6);
        Tree* curr;
        for(int i =0;i<6;i++){
            curr=parent->get_child(i);
            curr->bear_off(i+1);
            parent->set_child(curr,i);
        }
    }


    else if (parent->getdata().get_checker_removed_num()==15){//if all checkers are born off, remove the child nodes created under default constructor
        parent->remove_children();
    }
    
}


//BFS
void BFS(Tree* t){ //take in a tree node t to proceed Breadth First Search
    queue<Tree> Q;
    vector<Tree> visited;

    set_children_boards(t);
    visited.push_back(*t);
    t->setVisited(true);
    Q.push(*t);

    while(!Q.empty()){
            Tree front_tree=Q.front();
            front_tree.print();
            Q.pop();

        for(int i =0;i<front_tree.get_numChildren();i++){
            Tree* child=front_tree.get_child(i);
            set_children_boards(child);
            for(int j = 0; j < visited.size();j++){
                if(child->isVisited()==false){
                    visited.push_back(*child);
                    child->setVisited(true);
                    Q.push(*child);
                }
            }

        }
    }
}



//Functions for MiniMax Searching Algo:
// isInBearOff(..), evaluate(..),minimax(..)

bool isInBearOff(Tree* t){ 
    //PRE CONDITION: a pointer to a tree node t
    //POST CONDITION: return true when the board state in t is in bear off stage; return false otherwise

    Board<string> board=t->getdata();
    if (board.get_checker_removed_num()<15 && board.pieces_to_move()==0){ 
        //if all pieces are in home board and there are pieces left to be borne off
        return true;
    }
    else if (board.get_checker_removed_num()==15){
        //if ALL 15 checkers are borne off
        return false;
    }
    else{ //such as when not all checkers are in the home board so that bear off cannot begin
        return false;
    }
}


int evaluate(Tree* t){ 
    //PRE CONDITION: a pointer to a tree node t
    //POST CONDITION: return a score for the board state in t

    Board<string> board=t->getdata();

    if (!board.get_board_moved()){ //if child board is the same as parent board
        return 0;
    }
    else if (isInBearOff(t)){ //if in bear off stage
        return 1; //in the bear off stage, how many steps to move the checker doesn't matter
    }
    else { //if not in bear off stage, score = steps moved since it's getting closer to the home board 
        return (t->getdata().get_moved_steps());
    }
}

//minimax searching algo
//went through 366 nodes
void minimax(Tree* t, bool isMaximizing, int count){
    //PRE CONDITION: a pointer to a tree object t, bool value means if we're finding the max score
    //               among children nodes, integer count to increment nodes traversed
    //POST CONDITION: the minimax function will print out the board states selected based on
    //                the max scores

    set_children_boards(t);
    Tree* bestMove;
    Tree* c;    
    int value=0;

    if (t->getdata().get_checker_removed_num()==15){ //when all checkers are removed from the bear off stage
        cout << "You've won the game!\n";
        cout << "Minimax Search has traversed "<<count <<" tree nodes.\n";
    }   

    if(isMaximizing){
        int bestVal=-10000;
        for(int i =0;i < t->get_numChildren();i++){
            c=t->get_child(i);
            value=evaluate(c);
            count++;
            if(value>=bestVal){
                bestVal=value;
                bestMove=c;
            }
            
        }
        t=bestMove;
        t->print();
        cout << "\nTree nodes traversed: "<<count<<endl;
        cout << "========================================\n";

        minimax(t,isMaximizing,count); //in two players version, it would be minimax(t,!isMaximizng,count)
                                       //but since it's only one player, it would search for the highest possible score move everytime
    }

    else{
        int bestVal=10000;
        for(int i =0;i < t->get_numChildren();i++){
            c=t->get_child(i);
            value=evaluate(c);
            if(value<bestVal){
                bestVal=value;
                bestMove=c;
            }
            count++;
        }
        t=c;
        t->print();
        cout <<endl;
        minimax(t,isMaximizing,count);
    }
}



//alpha-beta pruning searching algo
//very similar to minimax search and will have same steps moved as the minimax search
//however, went through less nodes (355)
void alphabeta(Tree* t, bool isMaximizing, int count, int alpha, int beta){
    //PRE CONDITION: a pointer to a tree object t, bool value means if we're finding the max score
    //               among children nodes, integer count to increment nodes traversed
    //POST CONDITION: the minimax function will print out the board states selected based on
    //                the max scores

    set_children_boards(t);
    Tree* bestMove;
    Tree* c;    
    int value=0;

    if (t->getdata().get_checker_removed_num()==15){ //when all checkers are removed from the bear off stage
        cout << "You've won the game!\n";
        cout << "Minimax Search has traversed "<<count <<" tree nodes.\n";
    }   

    if(isMaximizing){
        int bestVal=-10000;
        for(int i =0;i < t->get_numChildren();i++){
            c=t->get_child(i);
            value=evaluate(c);
            if(value>=bestVal){
                bestVal=value;
                bestMove=c;
                
            }
            if(value>alpha){
                alpha=value;
                count++;
            }
            if(beta<alpha){
                break;
            }
            
        }
        t=bestMove;
        t->print();
        cout << "\nTree nodes traversed: "<<count<<endl;
        cout << "========================================\n";

        minimax(t,isMaximizing,count); //in two players version, it would be minimax(t,!isMaximizng,count)
                                       //but since it's only one player, it would search for the highest possible score move everytime
    }

    else{
        int bestVal=10000;
        for(int i =0;i < t->get_numChildren();i++){
            c=t->get_child(i);
            value=evaluate(c);
            if(value<bestVal){
                bestVal=value;
                bestMove=c;
            }
            if(value<beta){
                beta=value;
                count++;
            }
            if (beta>alpha){
                break;
            }
            
        }
        t=c;
        t->print();
        cout <<endl;
        minimax(t,isMaximizing,count);
    }
}


#endif
