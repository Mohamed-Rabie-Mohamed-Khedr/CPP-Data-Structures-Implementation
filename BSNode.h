#pragma once
struct BSNode
{
	int value;
	BSNode* left;
	BSNode* right;
	BSNode(int& v)
	{
		value = v;
		left = right = nullptr;
	}
};