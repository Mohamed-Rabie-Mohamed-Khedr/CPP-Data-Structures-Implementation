#include <iostream>
#include "Array.h"
#include "Stack.h"
#include "LinkedList.h"
#include "StackLinkedList.h"
#include "QueueLinkedList.h"
#include "BinarySearchTree.h"

int main()
{
	LinkedList<int> lls;
	lls.add(10);
	lls.add(20);
	lls.add(30);
	lls.add(40);
	lls.add(50);

	for (int i = 0; i < lls.getCount(); ++i)
		std::cout << lls[i] << " ";
	std::cout << std::endl;

	lls.reverse();
	
	for (int i = 0; i < lls.getCount(); ++i)
		std::cout << lls[i] << " ";
	std::cout << std::endl;

	return 0;
}