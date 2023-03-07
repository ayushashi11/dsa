#include <iostream>
using namespace std;

struct Node{
    int dat;
    Node *left=nullptr, *right=nullptr;
    int nChildren=0;
};

void insert(Node* &root, int dat){
    if(root==nullptr){
        root = new Node;
        root->dat = dat;
    }
    else if(root->dat>dat){
        int temp = root->dat;
        
    }
}
