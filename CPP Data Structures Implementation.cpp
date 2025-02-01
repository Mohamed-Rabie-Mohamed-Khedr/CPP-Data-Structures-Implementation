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

	std::cout << bst.getDepth(8) << std::endl;
	return 0;
}