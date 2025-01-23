#include <iostream>
#include "Array.h"
#include "Stack.h"
#include "LinkedList.h"
#include "StackLinkedList.h"
#include "QueueLinkedList.h"
#include "BinarySearchTree.h"

int main()
{
    Array<int> a(2);
	a[0] = 55;
    a[1] = 78;
    Array<int> a2(3);
    a2[0] = 899;
    a2[1] = 54;
    a2[2] = 58;
    std::cout << "item 0: " << a[0] << "\n";
	std::cout << "array size: " << a.getSize() << "\n";
    std::cout << "...............\n";

    a += a2;
    for (int i = 0; i < a.getSize(); i++)
		std::cout << a[i] << "\n";
    std::cout << "...............\n";
    
    a = a2;
    std::cout << "item 0: " << a[0] << "\n";
    std::cout << "item 1: " << a[1] << "\n";
    std::cout << "array size: " << a.getSize() << "\n";
    std::cout << "...............\n";

    /*Stack<int, 3> s;
    s.push(55);
    std::cout << s.peek() << "\n";
    std::cout << s.pop() << "\n";
    std::cout << s.isFull() << "\n";
    std::cout << s.getSize() << "\n";
    std::cout << s.getLength() << "\n";
    std::cout << "...............\n";

    LinkedList<char> lls;
    lls.add('a');
    lls.add('b');
    lls.add('c');
    lls.insert('A', 1);
    lls.insert('B', 3);
    lls.insert('C', 5);

    for (size_t i = 0; i < lls.getCount(); ++i) std::cout << lls[i] << "\n";
    std::cout << "...............\n";
    std::cout << lls.search('c') << "\n";
    std::cout << "...............\n";

    lls.remove(0);
    lls.remove(1);
    lls.remove(2);
    for (size_t i = 0; i < lls.getCount(); ++i) std::cout << lls[i] << "\n";
    std::cout << "...............\n";

    lls[0] = '0';
    lls[1] = '1';
    lls[2] = '2';
    for (size_t i = 0; i < lls.getCount(); ++i) std::cout << lls[i] << "\n";
    std::cout << "...............\n";

    StackLinkedList<int> sll;
	sll.push(55);
	sll.push(78);
    sll.push(90);
	sll.push(100);

    std::cout << sll.search(55) << "\n";
    std::cout << sll.peek() << "\n";
    for (size_t i=0, j=sll.getCount(); i<j; ++i)
        std::cout << sll.pop() << "\n";
    std::cout << "...............\n";

    QueueLinkedList<int> qll;
	qll.enqueue(55);
	qll.enqueue(78);
	qll.enqueue(90);
    qll.enqueue(100);

    std::cout << qll.search(100) << "\n";
    std::cout << qll.peek() << "\n";
    for (size_t i = 0, j = qll.getCount(); i < j; ++i)
        std::cout << qll.dequeue() << "\n";
    std::cout << "...............\n";

    BinarySearchTree bst;
    bst.add(45);
    bst.add(15);
    bst.add(79);
    bst.add(90);
    bst.add(10);
    bst.add(55);
    bst.add(12);
    bst.add(20);
    bst.add(50);
    int* arr = bst.getValues();
    for (size_t i = 0; i < bst.getCount(); ++i) std::cout << arr[i] << "\n";
    std::cout << "...............\n";
    
    if (bst.search(12) == nullptr) std::cout << "item not found\n";
    else std::cout << "item found\n";
    std::cout << "...............\n";
    
    std::cout << bst.getMin()->value << "\n";
    std::cout << bst.getMax()->value << "\n";
    std::cout << "...............\n";

    bst.remove(90);
    int* arr2 = bst.getValues();
    for (size_t i = 0; i < bst.getCount(); ++i) std::cout << arr2[i] << "\n";
    std::cout << "...............\n";*/
}