#pragma once
#include <iostream>
template <class T>
class StackLinkedList
{
	struct Node
	{
		T value;
		Node* next = nullptr;
		Node(T& v)
		{
			value = v;
		}
	};
	Node* top = nullptr;
	Node* newNode = nullptr;
	size_t count = 0;
public:
	void push(T value)
	{
		newNode = new Node(value);
		if (getCount() > 0)	newNode->next = top;
		top = newNode;
		++count;
	}
	T& pop()
	{
		if (getCount() == 0) throw std::out_of_range("List is empty");
		T value = top->value;
		newNode = top;
		top = top->next;
		delete newNode;
		newNode = nullptr;
		--count;
		return value;
	}
	T& peek()
	{
		if (getCount() == 0) throw std::out_of_range("List is empty");
		return top->value;
	}
	int search(T value)
	{
		newNode = top;
		int c = getCount();
		while (newNode != nullptr)
		{
			if (newNode->value == value) return c-1;
			else
			{
				newNode = newNode->next;
				--c;
			}
		}
		return -1;
	}
	size_t getCount() const
	{
		return count;
	}
	~StackLinkedList()
	{
		for (size_t i = getCount(); i > 0; --i)
		{
			newNode = top;
			top = top->next;
			delete newNode;
			newNode = nullptr;
		}
	}
};