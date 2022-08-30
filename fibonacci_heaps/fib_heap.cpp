#include <iostream>
#include <vector>
#include <hash_map>

using namespace std;

class Node{
    public: int data;
    private: vector<Node*> children; int length;
    public:
    Node(int data){
        this->data=data;
        this->children=*(new vector<Node*>());
        this->length=0;
    }
    void insert(Node *n){
        this->children.push_back(n);
        this->length++;
    }
}

class FibHeap{
    private: vector<Node*> heads;
}