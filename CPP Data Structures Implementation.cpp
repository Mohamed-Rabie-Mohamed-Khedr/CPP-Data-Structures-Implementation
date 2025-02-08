#include <iostream>
#include "Array.h"
#include "Stack.h"
#include "LinkedList.h"
#include "StackLinkedList.h"
#include "QueueLinkedList.h"
#include "DoublyLinkedList.h"
#include "BinarySearchTree.h"
#include "AVLTree.h"

int main()
{
	AVLTree avl;
	avl.add(40);
	avl.add(20);
	avl.add(10);
	avl.add(25);
	avl.add(30);
	avl.add(22);
	avl.add(50);

	int v = 50;
	int* paht = nullptr;
	int size = avl.getDepth(v, paht);

	std::cout << "........... the path ..........." << std::endl;
	for (int i = 0; i < size; ++i) std::cout << paht[i] << ", ";
	std::cout << std::endl;

	std::cout << "........... the depth ..........." << std::endl;
	std::cout << size << std::endl;
	
	avl.clean(avl.search(avl.root, v));
	return 0;
}