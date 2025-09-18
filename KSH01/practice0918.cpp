#include "practice0918.h"
#include "LinkedList.h"
#include "DoubleLinkedList.h"
#include <stdio.h>

void practice0918::TestSingleLinkedList()
{
	LinkedList MyList;


	printf("-----------------------------\n");
	MyList.Add(10);
	MyList.Add(20);
	MyList.Add(30);
	MyList.PrintList();

	printf("-----------------------------\n");
	MyList.InsertAt(40, 100);
	MyList.PrintList();
	MyList.InsertAt(5, 0);
	MyList.PrintList();
	MyList.InsertAt(15, 2);
	MyList.PrintList();
	printf("-----------------------------\n");
	MyList.Remove(20);
	MyList.PrintList();
	MyList.Remove(123);
	MyList.PrintList();


	printf("-----------------------------\n");
	MyList.RemoveAt(10);
	MyList.PrintList();
	MyList.RemoveAt(1);
	MyList.PrintList();
	printf("-----------------------------\n");

	ListNode* Found = MyList.Search(15);
	if (Found) {
		printf("찾았습니다.\n");
	}
	else {
		printf("못찾았습니다.\n");
	}
	Found = MyList.Search(999);
	if (Found) {

		printf("찾았습니다.\n");
	}
	else {
		printf("못찾았습니다.\n");

	}

}

void practice0918::TestDoubleLinkedList()
{
	DoubleLinkedList myDoubleList;
	printf("DLAdd함수-----------------------------\n");
	myDoubleList.DLAdd(10);
	myDoubleList.DLAdd(20);
	myDoubleList.DLAdd(30);
	myDoubleList.DLAdd(40);
	myDoubleList.DLAdd(50);
	myDoubleList.DLAdd(60);
	myDoubleList.DLAdd(70);
	myDoubleList.DLPrintList();
	printf("DLRemove함수-----------------------------\n");
	myDoubleList.DLRemove(10);
	myDoubleList.DLPrintList();
	myDoubleList.DLRemove(20);
	myDoubleList.DLPrintList();
    myDoubleList.DLRemove(30);
	myDoubleList.DLPrintList();
    myDoubleList.DLRemove(70);
	myDoubleList.DLPrintList();
	printf("InsertAt함수-----------------------------\n");
    myDoubleList.DLInsertAt(100,99);
	myDoubleList.DLPrintList();
    myDoubleList.DLInsertAt(200,0);
	myDoubleList.DLPrintList();
    myDoubleList.DLInsertAt(150,2);
	myDoubleList.DLPrintList();
	printf("RemoveAt함수-----------------------------\n");
	myDoubleList.DLRemoveAt(99);
	myDoubleList.DLPrintList();
	myDoubleList.DLRemoveAt(0);
	myDoubleList.DLPrintList();
	myDoubleList.DLRemoveAt(3);
	myDoubleList.DLPrintList();
}
