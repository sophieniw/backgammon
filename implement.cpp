#include "board.h"
#include "tree.h"
using namespace std;


int main(){

    Tree* root = new Tree();
    minimax(root,true,0);

    

    return 0;
}