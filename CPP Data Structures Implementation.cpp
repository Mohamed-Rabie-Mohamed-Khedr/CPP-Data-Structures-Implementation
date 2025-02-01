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
	bst.add(63);
	bst.add(54);
	bst.add(33);
	bst.add(74);
	bst.add(68);
	bst.add(25);
	bst.add(45);
	bst.add(82);
	bst.add(23);

	std::cout << bst.getSubstitute(25) << std::endl;
	return 0;
}