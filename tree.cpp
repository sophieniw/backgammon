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




void Tree::init(int numBranches){
    delete []children;
    numChildren=numBranches;
    children=new Tree*[numChildren];
    for (int i = 0; i < numChildren; i ++){
        children[i] = new Tree();
        children[i]->set_parent(this);
        children[i]->set_board(board);
    } 
    
}


void Tree::remove_children(){
    delete[] children;
}


//the function below takes in a tree node and set the children node according to the parent node
void set_children_boards(Tree* parent){
    parent->set_surface_checker_pos(); //to collect positions of surface checkers that can be moved
    vector<int> surface_checker_cols=parent->getdata().surface_checker_cols; //to store the column index of surface checkers
    vector<int>surface_checker_rows=parent->getdata().surface_checker_rows;  //to store the row index of surface checkers
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
            parent->set_child(curr,i);
        }
    }

    else if (parent->getdata().get_checker_removed_num()==15){//if all checkers are born off, remove the child nodes created under default 
        parent->remove_children();
    }
    
}


bool isInBearOff(Tree* t){ //see if the board in the tree node is in the bear off stage
    Board<string> board=t->getdata();
    if (board.get_checker_removed_num()<15 && board.pieces_to_move()==0){
        return true;
    }
    else if (board.get_checker_removed_num()==15){
        return false;
    }
    else{
        return false;
    }
}

//for MiniMax Searching Algo
int evaluate(Tree* t){ //evaluate function to return scores for different board state

    Board<string> board=t->getdata();

    if (!board.get_board_moved()){ //if child board is the same as parent board
        return 0;
    }
    else if (isInBearOff(t)){ //if in bear off stage
        return 1;
    }
    else { //if not in bear off stage, score = steps moved
        return (t->getdata().get_moved_steps());
    }
}

void minimax(Tree* t, bool isMaximizing, int count){
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
        t=c;
        t->print();
        cout << "\nTree nodes traversed: "<<count<<endl;
        cout << "========================================\n";
        //cout << value << endl;
        //cout << t->pieces_to_move()<<endl;
        minimax(t,true,count);
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
        minimax(t,true,count);
    }
}



#endif
