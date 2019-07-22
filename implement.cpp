#include "board.h"
#include "tree.h"
using namespace std;


int main(){
    Tree* root=new Tree();
    set_children_boards(root);
    set_tree(root);

    return 0;
}