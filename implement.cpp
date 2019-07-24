#include "board.h"
#include "tree.h"
using namespace std;

//7-24-2019

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
        cout <<"3. Minimax Search\n";      //alpha-beta and minimax are very similar, they will return the same steps
        cout <<"4. Alpha-beta Pruning\n";  //however, alpha-beta searched less nodes to achieve the result
        cout <<"5. IDDFS\n";
        cout <<"6. Exit\n";
        cout <<endl<<"Please select: ";
        cin >> user_input;
        cout <<endl;

        if(user_input=="1"){

        }
        else if (user_input=="2"){
            Tree* root=new Tree;
            BFS(root);
        }
        else if (user_input=="3"){
            Tree* root=new Tree;
            minimax(root,true,0);
        }
        else if (user_input=="4"){
            Tree* root=new Tree;
            alphabeta(root,true,0,-1000,1000);
        }
        else if (user_input=="5"){

        }

    }


    return 0;
}