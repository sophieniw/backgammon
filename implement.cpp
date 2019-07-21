#include "board.h"
#include "tree.h"
using namespace std;

void set_child_board_one_checker(size_t checker_row, size_t checker_col,size_t children_arr_left,size_t children_arr_right,Tree* parent){
    Tree* curr; //the first 6 branches are for checker on col0 row2, dice 1-6
    for (int i = arr_left; i<arr_right;i++){
        curr=parent->get_child(i); 
        curr->move_checker_step(checker_row,checker_col,i-arr_left+1);
        parent->set_child(curr,i);
    }
    set_parent_to_children(parent);
}

int main(){
    size_t numBranches_1=18; // 18 branches from root (6*3)
    Tree* root=new Tree(numBranches_1);
    //cout << root->get_numChildren() <<endl;
    root->set_parent(NULL);

    /*
    below is the first level from root
    the first level has 18 branches, which includes
    dice possibility 1-6 for each checker 1 that is stacked on the surface;
    the column of checker 1 that is in the home board already (col18)
    is ignored, in order to simply the tree and since it's already in the homeboard
    */
    

    set_child_board(2,0,0,6,root);
    set_child_board(5,11,6,12,root);
    set_child_board(3,16,12,18,root);

    //below to test and see if the boards are correctly linked together
    Tree* child0=root->get_child(0);
    Tree* child2=root->get_child(2);
    Tree* child5=root->get_child(4);

    cout << "\nchild 0 of root: moving with dice 1 on checker 1\n===================================\n";
    child0->print_data();
    cout << "\nchild 2 of root: moving with dice 3 on checker 1\n===================================\n";
    child2->print_data();
    cout << "\nchild 4 of root: moving with dice 5 on checker 1\n===================================\n";
    child5->print_data();

    //TO TEST IF CHILDREN->PARENT IS CORRECT
    cout << "\nparent node of children node:\n\n";
    Tree* p0 = child0->get_parent();
    Tree* p2= child2->get_parent();

    p0->print_data();

    /*
    Tree* curr1; //the first 6 branches are for checker on col0 row2, dice 1-6
    for (int i = 0; i<6;i++){
        curr1=root->get_child(i); 
        curr1->move_checker_step(2,0,i+1);
        root->set_child(curr1,i);
    }
    set_parent_to_children(root);

    Tree* curr2; //the 2nd 6 branches are for checker on col11 row5, dice 1-6
    for (int i = 6; i<12;i++){
        curr2=root->get_child(i); 
        curr2->move_checker_step(5,11,i-6+1);
        root->set_child(curr2,i);
    }

    Tree* curr3; //the 3rd 6 branches are for checker on col16 row3, dice 1-6
    for (int i = 12; i<18;i++){
        curr3=root->get_child(i); 
        curr3->move_checker_step(3,16,i-12+1);
        root->set_child(curr3,i);
    }
    */


    /*
    below is the 2nd level from root

    the first level has 24 branches. the 2nd level has 426 branches. 
    */
    //size_t numBranches_2=426;
    
    
    /*
    //TO TEST IF ROOT->CHILDREN ARE CORRECT
    Tree* child0=root->get_child(0);
    Tree* child2=root->get_child(2);
    Tree* child5=root->get_child(4);

    cout << "\nchild 0 of root: moving with dice 1 on checker 1\n===================================\n";
    child0->print_data();
    cout << "\nchild 2 of root: moving with dice 3 on checker 1\n===================================\n";
    child2->print_data();
    cout << "\nchild 4 of root: moving with dice 5 on checker 1\n===================================\n";
    child5->print_data();

    //TO TEST IF CHILDREN->PARENT IS CORRECT
    cout << "\nparent node of children node:\n\n";
    Tree* p0 = child0->get_parent();
    Tree* p2= child2->get_parent();

    p0->print_data();
    cout <<"\n1===========================================\n";
    p2->print_data();

    //root->print_data();
    //cout<<"================================\n";
    //Tree* child0=root->get_child(0);
    //child0->print_data();
    */
    return 0;
}