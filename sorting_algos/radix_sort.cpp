#include <iostream>
#include <cmath>
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

void radixSort(int arr[], int n){
    int radix=10,d=0,r2=1;
    for(int i=0; i<n; i++){
        if(log10(arr[i])>d) d = (int)log10(arr[i]);
    }
    for(int i=0;i<d;i++){
        Node *lis[10]={nullptr};
        for(int j=0;j<n;j++){
            insert(lis[arr[i]%radix-arr[i]%r2], arr[i]);
        }
        radix*=10; r2*=10;
        int k=0;
        for(int j=0;j<10;){
            if(lis[j]!=nullptr) arr[k++]=pop(lis[j]);
            else j++;
        }
    }
}

int main(){
    
}
