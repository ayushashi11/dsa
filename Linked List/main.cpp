#include<iostream>
#include<iomanip>
#include"linkedlist.hpp"
int main()
{
	Node<int> *n1 = new Node<int>(),
			  *n2 = new Node<int>(0),
			  *n3 = new Node<int>(3);
	n1->data = 1;
	n2->data = 2;
	LList<int> *ll = new LList<int>();
	LList<char*> *ll_s = new LList<char*>();
	ll->prepend(0);
	ll->prepend(n1);
	ll->prepend(n2);
	ll->prepend(n3);
	ll_s->prepend("***o");
	ll_s->prepend("**l");
	ll_s->prepend("**l");
	ll_s->prepend("**e");
	ll_s->prepend("***h");
	std::cout << "List initialised:";
	ll->print();
	std::cout <<"\n";
	ll_s->print();
	Node<int> *nout = ll->pop();
	Node<char*> *nout_s = ll_s->pop();
	std::cout<<std::setw(10) << "Data that was popped:" << std::setw(6)<<nout->data <<" "<< nout_s->data << "\n"
			  << "List after popping:";
	ll->print();
	std::cout<<"\n";
	ll_s->print();
}