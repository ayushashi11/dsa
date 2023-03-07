#include <iostream>
using namespace std;

struct Node{
    int dat;
    Node *next=nullptr;
};

void insert(Node* &root, int dat){
    if(root==nullptr){
        root = new Node;
        root->dat = dat;
    }
    else if(root->dat>dat){
        Node *temp = root;
        root = new Node;
        root->dat = dat;
        root->next = temp; 
    }
    else{
        insert(root->next, dat);
    }
}

int pop(Node* &root){
    if(root==nullptr) return INT32_MIN;
    int ret = root->dat;
    root = root->next;
    return ret;
}


