#pragma once
#include <iostream>
template <class T, size_t size>
class Stack
{
	T* items;
	size_t top;
public:
	Stack()
	{
		top = 0;
		items = new T[size];
	}
	void push(T value)
	{
		if (getLength() == getSize()) throw std::out_of_range("Stack is full");
		items[top++] = value;
	}
	T& pop()
	{
		if (getLength() == 0) throw std::out_of_range("Stack is empty");
		return items[--top];
	}
	T& peek()
	{
		if (getLength() == 0) throw std::out_of_range("Stack is empty");
		return items[top - 1];
	}
	int search(T value)
	{
		for (int i = 0; i < getLength(); ++i) if (items[i] == value) return i;
		return -1;
	}
	size_t getLength()
	{
		return top;
	}
	size_t getSize()
	{
		return size;
	}
	bool isFull()
	{
		return getLength() == getSize();
	}
	~Stack()
	{
		delete[] items;
	}
};