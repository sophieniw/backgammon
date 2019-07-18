#ifndef __TREE_CPP__
#define __TREE_CPP__

#include "board.h"
#include "tree.h"

using namespace std;

Node::Node(){  //default constr
    numChildren=6;
    children=new Node*[numChildren];
    parent=NULL;
    data=Board<string>();
} 

Node::Node(Node& source){ //copy constr
    numChildren=source.numChildren;
    parent=source.parent;
    children=source.children;
    data=source.data;
} 

Node::Node(size_t inNumChildren, Node* inP){ //custom constr
    numChildren=inNumChildren;
    parent=inP;
    children=new Node*[inNumChildren];
} 


void Node::addChild(Node* inC){
    children[numChildren]=inC;
    numChildren++;
}


#endif