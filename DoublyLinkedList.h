#pragma once
#include <iostream>
template <class T>
class DoublyLinkedList
{
	struct Node
	{
		T value;
		Node* next = nullptr;
		Node* back = nullptr;
		Node(T& v)
		{
			value = v;
		}
	};
	Node* first = nullptr;
	Node* last = nullptr;
	Node* newNode = nullptr;
	size_t count = 0;
public:
	void add(T value)
	{
		newNode = new Node(value);
		if (getCount() == 0)
		{
			last = first = newNode;
		}
		else
		{
			last->next = newNode;
			newNode->back = last;
			last = newNode;
		}
		++count;
	}
	void insert(T value, size_t index)
	{
		if (index > getCount()) throw std::out_of_range("index out of range");
		else if (index == getCount()) add(value);
		else if (index == 0)
		{
			newNode = new Node(value);
			newNode->next = first;
			first->back = newNode;
			first = newNode;
			++count;
		}
		else
		{
			--index;
			newNode = first;
			size_t c = 0;
			while (true)
			{
				if (c == index)
				{
					Node* nNode = new Node(value);
					newNode->next->back = nNode;
					nNode->next = newNode->next;
					newNode->next = nNode;
					nNode->back = newNode;
					++count;
					break;
				}
				else
				{
					newNode = newNode->next;
					++c;
				}
			}
		}
	}
	void remove(size_t index)
	{
		if (getCount() == 0 || index > getCount() - 1)
			throw std::out_of_range("index out of range");
		else if (index == getCount() - 1)
		{
			newNode = last;
			last = last->back;
			delete newNode;
			last->next = nullptr;
		}
		else if (index == 0)
		{
			newNode = first;
			first = first->next;
			delete newNode;
			first->back = nullptr;
		}
		else
		{
			--index;
			newNode = first;
			size_t c = 0;
			while (true)
			{
				if (c == index)
				{
					Node* nNode = newNode->next;
					newNode->next = newNode->next->next;
					newNode->next->back = newNode;
					delete nNode;
					nNode = nullptr;
					break;
				}
				else
				{
					newNode = newNode->next;
					++c;
				}
			}
		}
		--count;
	}
	int search(T value)
	{
		newNode = first;
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
	void reverse()
	{
		if (getCount() > 1)
		{
			Node* tPtr;
			newNode = first;
			do
			{
				tPtr = newNode->next;
				newNode->next = newNode->back;
				newNode->back = tPtr;
				newNode = newNode->back;
			} while (newNode != nullptr);
			tPtr = first;
			first = last;
			last = tPtr;
		}
	}
	size_t getCount() const
	{
		return count;
	}
	T& operator[](size_t index)
	{
		newNode = first;
		size_t c = 0;
		while (newNode != nullptr)
		{
			if (c == index) return newNode->value;
			else
			{
				newNode = newNode->next;
				++c;
			}
		}
		throw std::out_of_range("index out of range");
	}
	~DoublyLinkedList()
	{
		for (size_t i = 0; i < getCount(); ++i)
		{
			newNode = first;
			first = first->next;
			delete newNode;
			newNode = nullptr;
		}
	}
};