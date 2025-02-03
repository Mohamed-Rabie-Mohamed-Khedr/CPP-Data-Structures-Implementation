#pragma once
#include <iostream>
struct BSTNode
{
	int value;
	BSTNode* left;
	BSTNode* right;
	BSTNode(int& v)
	{
		value = v;
		left = right = nullptr;
	}
};
class BinarySearchTree
{
	BSTNode* newNode = nullptr;
	int* allValues = nullptr;
	size_t count = 0, indexOfValues;
	void readValues(BSTNode*& r)
	{
		if (r == nullptr) return;
		readValues(r->left);
		allValues[indexOfValues++] = r->value;
		readValues(r->right);
	}
public:
	BSTNode* root = nullptr;
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
						newNode->left = new BSTNode(value);
						break;
					}
					newNode = newNode->left;
				}
				else
				{
					if (newNode->right == nullptr)
					{
						newNode->right = new BSTNode(value);
						break;
					}
					newNode = newNode->right;
				}
			}
		}
		else root = new BSTNode(value);
		++count;
	}
	BSTNode* getMinValue()
	{
		return getMinValue(root);
	}
	BSTNode*& getMinValue(BSTNode*& r)
	{
		if (r == nullptr || r->left == nullptr) return r;
		else return getMinValue(r->left);
	}
	BSTNode* getMaxValue()
	{
		return getMaxValue(root);
	}
	BSTNode*& getMaxValue(BSTNode*& r)
	{
		if (r == nullptr || r->right == nullptr) return r;
		else return getMaxValue(r->right);
	}
	BSTNode* search(int value)
	{
		return search(root, value);
	}
	BSTNode*& search(BSTNode*& r, int& value)
	{
		if (r == nullptr || value == r->value) return r;
		else if (value < r->value) search(r->left, value);
		else search(r->right, value);
	}
	int getSubstitute(int value)
	{
		BSTNode*& n = search(root, value);
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
	int getHeight(BSTNode*& r)
	{
		if (r == nullptr) return -1;

		int le = 1 + getHeight(r->left);
		int ri = 1 + getHeight(r->right);
		return le > ri ? le : ri;
	}
	void remove(int value)
	{
		BSTNode*& n = search(root, value);
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
				BSTNode* n2 = n;
				n = n->left;
				delete n2;
				n2 = nullptr;
			}
			else if (n->left == nullptr && n->right != nullptr)
			{
				BSTNode* n2 = n;
				n = n->right;
				delete n2;
				n2 = nullptr;
			}
			else
			{
				BSTNode*& n2 = getMinValue(n->right);
				n->value = n2->value;
				delete n2;
				n2 = nullptr;
			}
			--count;
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
	void cleaning(BSTNode*& r)
	{
		if (r->left != nullptr) cleaning(r->left);
		if (r->right != nullptr) cleaning(r->right);
		delete r;
		r = nullptr;
	}
	size_t getCount() const
	{
		return count;
	}
	~BinarySearchTree()
	{
		delete[] allValues;
		allValues = nullptr;
		cleaning(root);
	}
};