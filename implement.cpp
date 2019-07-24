#include "board.h"
#include "tree.h"
using namespace std;

//7-24-2019

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
    //construct a main menu
    string user_input;

    while(true){
        if(user_input=="6"){
            break;
        }
        cout <<endl;
        cout <<"============================"<<endl;        
        cout <<"        Backgammon"<<endl;
        cout <<"============================" <<endl;
        cout <<"1. DFS\n";
        cout <<"2. BFS\n";
        cout <<"3. Minimax Search\n";
        cout <<"4. IDDFS\n";
        cout <<"5. Alpha-beta Pruning\n";
        cout <<"6. Exit\n";
        cout <<endl<<"Please select: ";
        cin >> user_input;
        cout <<endl;

        if(user_input=="1"){
            Tree* root=new Tree;
            minimax(root,true,0);
        }
        else if (user_input=="2"){

        }
        else if (user_input=="3"){

        }
        else if (user_input=="4"){

        }
        else if (user_input=="5"){

        }

    }


    return 0;
}