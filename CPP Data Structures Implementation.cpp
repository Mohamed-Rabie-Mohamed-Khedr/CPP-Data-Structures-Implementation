#include <iostream>
#include "Array.h"
#include "Stack.h"
#include "LinkedList.h"
#include "StackLinkedList.h"
#include "QueueLinkedList.h"
#include "DoublyLinkedList.h"
#include "BinarySearchTree.h"

int main()
{
	BinarySearchTree bst;
	bst.add(15);
	bst.add(6);
	bst.add(3);
	bst.add(9);
	bst.add(8);
	bst.add(20);
	bst.add(25);

	std::cout << ".......... the depth or level ..........." << std::endl;
	std::cout << bst.getDepth(8) << std::endl;

	std::cout << ".......... the path ..........." << std::endl;
	int* path = nullptr;
	int size = bst.getDepth(8, path);
	for (int i = 0; i < size; ++i)
		std::cout << path[i] << std::endl;

	return 0;
}