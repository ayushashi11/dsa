#include <iostream>
#include <iomanip>
template <typename T>
struct Node
{
	T data;
	Node<T> *addr = nullptr;
	Node<T>() {}//it was solved as soon as i added this
	Node<T>(T dat)
	{ //This wasn't the actual problem
		this->data = dat;
	}
	std::ostream operator <<(std::ostream stream){
		stream<<(this->data);
	}
};
template <typename T>
struct LList
{
	Node<T> *first = nullptr;
	LList<T>() {}
	void prepend(Node<T> *node)
	{
		if (this->first == nullptr)
		{
			this->first = node;
		}
		else
		{
			node->addr = this->first;
			this->first = node;
		}
	}
	bool has(T dat){
		Node<T> *curr = this->first;
		while(curr != nullptr){
			if(curr->data == dat){
				return true;
			}
			curr = curr->addr;
		}
		return false;
	}
	void prepend(T dat)
	{
		Node<T> *node = new Node<T>(dat);
		this->prepend(node);
	}
	Node<T> *pop()
	{
		Node<T> *node = this->first;
		this->first = this->first->addr;
		return node;
	}
	void print()
	{
		Node<T> *node = this->first;
		std::cout << "[\n";
		while (node != nullptr)
		{
			std::cout << std::setw(4) << (node->data) << '\n';
			node = node->addr;
		}
		std::cout << "]\n";
	}
};