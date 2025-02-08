#pragma once
#include <iostream>
#include "BSNode.h"
class AVLTree
{
	BSNode* newNode = nullptr;
	int* allValues = nullptr;
	size_t count = 0, indexOfValues;
	void readValues(BSNode*& r)
	{
		if (r == nullptr) return;
		readValues(r->left);
		allValues[indexOfValues++] = r->value;
		readValues(r->right);
	}
	void balanced(BSNode*& r)
	{
		if (r == nullptr) return;

		int balancedFactor = getHeight(r->left) - getHeight(r->right);
		if (balancedFactor > -2 && balancedFactor < 2)
		{
			balanced(r->left);
			balanced(r->right);
		}
		else
		{
			BSNode* cLeft = nullptr, * cRight = nullptr;
			if (balancedFactor > 1)
			{
				if (r->left->left == nullptr)
				{
					cLeft = r->left->right->left;
					cRight = r->left->right->right;
					newNode = r->left;
					r->left = r->left->right;
					r->left->left = newNode;
					r->left->left->right = nullptr;
				}
				newNode = r;
				r = r->left;
				r->right = newNode;
				r->right->left = cRight;
				r->left->right = cLeft;
			}
			else
			{
				if (r->right->right == nullptr)
				{
					cLeft = r->right->left->right;
					cRight = r->right->left->left;
					newNode = r->right;
					r->right = r->right->left;
					r->right->right = newNode;
					r->right->right->left = nullptr;
				}
				newNode = r;
				r = r->right;
				r->left = newNode;
				r->left->right = cRight;
				r->right->left = cLeft;
			}
		}
	}
	void cleaning(BSNode*& r)
	{
		if (r->left != nullptr) cleaning(r->left);
		if (r->right != nullptr) cleaning(r->right);
		delete r;
		r = nullptr;
	}
public:
	BSNode* root = nullptr;
	void add(int value)
	{
		if (getCount() > 0)
		{
			newNode = root;
			while (true)
			{
				if (value < newNode->value)
				{
					if (newNode->left == nullptr)
					{
						newNode->left = new BSNode(value);
						break;
					}
					newNode = newNode->left;
				}
				else
				{
					if (newNode->right == nullptr)
					{
						newNode->right = new BSNode(value);
						break;
					}
					newNode = newNode->right;
				}
			}
		}
		else root = new BSNode(value);
		++count;
		balanced(root);
	}
	BSNode* getMinValue()
	{
		return getMinValue(root);
	}
	BSNode*& getMinValue(BSNode*& r)
	{
		if (r == nullptr || r->left == nullptr) return r;
		else return getMinValue(r->left);
	}
	BSNode* getMaxValue()
	{
		return getMaxValue(root);
	}
	BSNode*& getMaxValue(BSNode*& r)
	{
		if (r == nullptr || r->right == nullptr) return r;
		else return getMaxValue(r->right);
	}
	BSNode* search(int value)
	{
		return search(root, value);
	}
	BSNode*& search(BSNode*& r, int& value)
	{
		if (r == nullptr || value == r->value) return r;
		else if (value < r->value) return search(r->left, value);
		else return search(r->right, value);
	}
	int getSubstitute(int value)
	{
		BSNode*& n = search(root, value);
		if (n == nullptr || n->left == nullptr && n->right == nullptr)
			return -1;
		else if (n->left != nullptr && n->right == nullptr)
			return n->left->value;
		else if (n->left == nullptr && n->right != nullptr)
			return n->right->value;
		else return getMinValue(n->right)->value;
	}
	int getDepth(int value)
	{
		int d = 0;
		newNode = root;
		while (newNode != nullptr)
		{
			if (value == newNode->value) return d;
			else
			{
				if (value < newNode->value) newNode = newNode->left;
				else newNode = newNode->right;
				++d;
			}
		}
		return -1;
	}
	int getDepth(int value, int*& path)
	{
		int size = getDepth(value);
		if (size < 0) return NULL;
		else
		{
			path = new int[size];
			newNode = root;
			for (size_t i = 0; i < size; ++i)
			{
				path[i] = newNode->value;
				if (value < newNode->value) newNode = newNode->left;
				else newNode = newNode->right;
			}
		}
		return size;
	}
	int getHeight()
	{
		return getHeight(root);
	}
	int getHeight(BSNode*& r)
	{
		if (r == nullptr) return -1;

		int le = getHeight(r->left);
		int ri = getHeight(r->right);
		return 1 + (le > ri ? le : ri);
	}
	void remove(int value)
	{
		BSNode*& n = search(root, value);
		if (n == nullptr) return;
		else
		{
			if (n->left == nullptr && n->right == nullptr)
			{
				delete n;
				n = nullptr;
			}
			else if (n->left != nullptr && n->right == nullptr)
			{
				BSNode* n2 = n;
				n = n->left;
				delete n2;
				n2 = nullptr;
			}
			else if (n->left == nullptr && n->right != nullptr)
			{
				BSNode* n2 = n;
				n = n->right;
				delete n2;
				n2 = nullptr;
			}
			else
			{
				BSNode*& n2 = getMinValue(n->right);
				n->value = n2->value;
				delete n2;
				n2 = nullptr;
			}
			--count;
			balanced(root);
		}
	}
	int* getValues()
	{
		if (getCount() == 0) throw std::out_of_range("tree is empty");
		delete[] allValues;
		allValues = new int[getCount()];
		indexOfValues = 0;
		readValues(root);
		return allValues;
	}
	void clean(BSNode*& r)
	{
		cleaning(r);
		balanced(root);
	}
	size_t getCount() const
	{
		return count;
	}
	~AVLTree()
	{
		delete[] allValues;
		allValues = nullptr;
		cleaning(root);
	}
};