#pragma once
#include <iostream>
template <class T>
class QueueLinkedList
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
	Node* front = nullptr;
	Node* back = nullptr;
	Node* newNode = nullptr;
	size_t count = 0;
public:
	void enqueue(T value)
	{
		newNode = new Node(value);
		if (getCount() > 0)
		{
			back->next = newNode;
			back = newNode;
		}
		else front = back = newNode;
		++count;
	}
	T& dequeue()
	{
		if (getCount() == 0) throw std::out_of_range("List is empty");
		T value = front->value;
		newNode = front;
		front = front->next;
		delete newNode;
		newNode = nullptr;
		--count;
		return value;
	}
	T& peek()
	{
		if (getCount() == 0) throw std::out_of_range("List is empty");
		return front->value;
	}
	int search(T value)
	{
		newNode = front;
		int c = 0;
		while (newNode != nullptr)
		{
			if (newNode->value == value) return c;
			else
			{
				newNode = newNode->next;
				++c;
			}
		}
		return -1;
	}
	size_t getCount() const
	{
		return count;
	}
	~QueueLinkedList()
	{
		for (size_t i = getCount(); i > 0; --i)
		{
			newNode = front;
			front = front->next;
			delete newNode;
			newNode = nullptr;
		}
	}
};