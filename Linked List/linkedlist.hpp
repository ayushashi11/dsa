#include<iostream>
#include<iomanip>
template <typename T>
struct Node
{
	T data;
	Node<T> *addr = NULL;
	Node<T>();
	Node<T>(T dat);
	std::ostream operator <<(std::ostream stream);
};
template <typename T>
struct LList
{
	Node<T> *first = NULL;
	LList<T>();
	void prepend(Node<T> *node);
	void prepend(T dat);
	Node<T> *pop();
	void print();
	bool has(T dat);
};