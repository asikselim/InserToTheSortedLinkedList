#include <iostream>

using namespace std;

#include "LinkedList.h"

int main()
{
    LinkedList *ls = new LinkedList();

    ls->InsertToTheSortedLinkedList(1, 98);
    ls->InsertToTheSortedLinkedList(4, 87);
    ls->InsertToTheSortedLinkedList(6, 79);
    ls->InsertToTheSortedLinkedList(9, 86);
    ls->InsertToTheSortedLinkedList(3, 70);
    ls->InsertToTheSortedLinkedList(5, 100);
    ls->InsertToTheSortedLinkedList(7, 88);
	///////////////////////////////////////
	ls->InsertToTheSortedLinkedList(8, 62);
	ls->InsertToTheSortedLinkedList(2, 32);
	ls->InsertToTheSortedLinkedList(7, 99);
    ls->PrintLinkedList();

    return 0;
}

