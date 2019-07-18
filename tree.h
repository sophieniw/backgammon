#ifndef __TREE_H__
#define __TREE_H__

#include "board.h"

using namespace std;

class Node{
    private:
        size_t numChildren;
        //size_t capChildren;
        Node* parent;
        Node** children;
        Board<string> data;

    public:
        Node(); //in cpp file
        Node(Node& source); //in cpp file
        Node(size_t inNumChildren=0, Node* inP=NULL); //in cpp file

        void setParent(Node* inP){parent=inP;}
        Node* getParent(){return parent;}

        void setChild(Node* inC, size_t arr_pos){children[arr_pos]=inC;}
        Node* getChild(size_t pos){return children[pos];}
        Node** getChildren(){return children;}
        void addChild(Node* inC); //in cpp file
        void addChildren(Node** inChildren){children=inChildren;}

        size_t getNumChildren(){return numChildren;}
        void setNumChildren(size_t num){numChildren=num;}

        void setData(Board<string> entry){data=entry;}
        Board<string> getData(){return data;}
        void printData(){data.print();}
};

#include "tree.cpp"
#endif
