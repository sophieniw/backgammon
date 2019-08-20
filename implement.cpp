#include "board.h"
#include "tree.h"
using namespace std;

int main(){
    //construct a main menu
    string user_input;

    while(true){
        if(user_input=="3"){
            break;
        }
        cout <<endl;
        cout <<"============================"<<endl;        
        cout <<"        Backgammon"<<endl;
        cout <<"============================" <<endl;
        cout <<"1. BFS\n";  //run very long 
        cout <<"2. Minimax Search\n";      //alpha-beta and minimax are very similar, they will return the same steps
        //3.DFS - in progress
        cout <<"3. Exit\n";
        cout <<endl<<"Please select: ";
        cin >> user_input;
        cout <<endl;

        Tree* root=new Tree();

        if(user_input=="1"){
            BFS(root);
        }
        else if (user_input=="2"){
            minimax(root,true,0);
        }
    }


    return 0;
}