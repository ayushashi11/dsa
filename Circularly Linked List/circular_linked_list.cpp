#include<iostream>
struct Node{
	int dat;
	Node* next=NULL;
	Node(){}
	Node(int dat){
		this->dat=dat;
	}
	std::ostream operator <<(std::ostream out){
		out<<(this->dat);
	}
};
struct CList{
	Node *head=NULL,*tail=NULL;
	void push(int dat){
		if(!this->head){
			this->head=new Node(dat);
			this->tail=this->head;
			this->head->next=this->tail;
		}
		else{
			this->tail->next=new Node(dat);
			this->tail=this->tail->next;
			this->tail->next=this->head;
		}
	}
	int pop(int index=0){
		int count=0;
		Node *curr=this->head,*prev;
		if(index==0){
			this->head=curr->next;
			this->tail->next=this->head;
			return curr->dat;
		}
		for(count=0;count<index;count+=1){
			prev=curr;
			curr=curr->next;
		}
		prev->next=curr->next;
		return curr->dat;
	}
	void printlis(){
		std::cout<<this->head->dat<<"<-\n  |\n\\/|\n";
		Node *curr=this->head->next;
		while(curr->next!=this->head){
			std::cout<<curr->dat<<" |\n  |\n\\/|\n";
			curr=curr->next;
		}
		std::cout<<curr->dat<<"--\n";
	}
};