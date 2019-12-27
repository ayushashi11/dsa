#include<iostream>
struct Node{
    int dat;
    Node *next=NULL;
    Node();
    Node(int dat);
    std::ostream operator <<(std::ostream out);
};
struct CList{
    Node *head=NULL,*tail=NULL;
    void push(int dat);
    void printlis();
    int pop(int index=0);
};