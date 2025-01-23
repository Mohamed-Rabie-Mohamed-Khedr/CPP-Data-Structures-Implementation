#pragma once
#include <iostream>
template <class T>
class Array
{
	T* arrayItems;
	size_t size;
public:
	Array(T* items, size_t arraySize)
	{
		size = arraySize;
		arrayItems = new T[size];
		for (int i = 0; i < size; ++i) arrayItems[i] = items[i];
	}
	Array(size_t arraySize)
	{
		size = arraySize;
		arrayItems = new T[size];
	}
	int search(T value)
	{
		for (int i = 0; i < size; ++i) if (arrayItems[i] == value) return i;
		return -1;
	}
	size_t getSize() const
	{
		return size;
	}
	T& operator[](size_t index)
	{
		if (index < size) return arrayItems[index];
		throw std::out_of_range("index out of range");
	}
	void operator=(Array& a)
	{
		if (this != &a)
		{
			T* arrP = arrayItems;
			arrayItems = new T[a.getSize()];
			for (int i = 0; i < a.getSize(); ++i) arrayItems[i] = a[i];
			size = a.getSize();
			delete[]arrP;
			arrP = nullptr;
		}
		else throw std::exception("no self assignment");
	}
	void operator+=(Array& a)
	{
		T* arrP = arrayItems;
		arrayItems = new T[size + a.getSize()];
		for (int i = 0; i < size; ++i) arrayItems[i] = arrP[i];
		delete[]arrP;
		arrP = nullptr;
		for (int i = 0; i < a.getSize(); ++i) arrayItems[i+ getSize()] = a[i];
		size += a.getSize();
	}
	~Array()
	{
		delete[] arrayItems;
		arrayItems = nullptr;
	}
};