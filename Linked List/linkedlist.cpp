#include <iostream>
using namespace std;
struct Node{
	int dat;
	Node* next=nullptr;
};

void insert(Node* &head, int dat){
	if(head==nullptr){
		head = new Node;
		head->dat = dat;
	}
	else{
		insert(head->next, dat);
	}
}

int pop(Node* &head){
	Node temp = *head;
	head = head->next;
	return temp.dat;
}

void display(Node *head){
	if(head==nullptr) cerr<<"flat"<<endl;
	while(head!=nullptr){
		cout<<head->dat<<endl;
		head=head->next;
	}
}

void merge(Node *h1, Node *h2){
	auto curr = h1, curr2 = h2;
	while(curr!=nullptr){
		if(curr2!=nullptr){
			auto temp = curr->next, temp2 = curr2->next;
			curr->next=curr2;
			curr2->next=temp;
			curr=temp;
			curr2=temp2;
		}
		else{
			curr=curr->next;
		}
	}
}

int main(){
	Node *head1 = nullptr, *head2 = nullptr;
	int n1, n2;
	cin>>n1>>n2;
	for(int i=0; i<n1; i++){
		cout<<"Enter :";
		int t;
		cin>>t;
		insert(head1, t);
	}
	for(int i=0; i<n2; i++){
		cout<<"Enter :";
		int t;
		cin>>t;
		insert(head2, t);
	}
	merge(head1,head2);
	display(head1);
}