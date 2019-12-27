#include<iostream>
#include"circular_linked_list.hpp"
int main(int argc,char* const argv[])
{
	CList *cl=new CList();
	cl->push(0);cl->push(1);cl->push(2);cl->push(3);
	cl->printlis();
	std::cout<<cl->pop()<<"\n";
	cl->printlis();
}