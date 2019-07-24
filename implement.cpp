#include "board.h"
#include "tree.h"
using namespace std;

/*
void set_tree(Tree* t, int max_depth,int curr_depth){
    set_children_boards(t);
    while(curr_depth<=max_depth){
        for(int i = 0;i<t->get_numChildren();i++){
            set_children_boards(t->get_child(i));
        }
        curr_depth++;
    }

}
*/

/*
void test_printout(Tree* t, int num){
    Tree* child=t->get_child(num);
    child->print();
    cout<<child->get_numChildren()<<endl;
    cout << child->pieces_to_move()<<endl;
    for(int i = 0;i <child->getdata().surface_checker_cols.size();i++){
        cout << child->getdata().surface_checker_cols.at(i)<<", "<< child->getdata().surface_checker_rows.at(i)<<endl;
    }
}
*/

int main(){
    Tree* root=new Tree;
    minimax(root,true,0);

    return 0;
}