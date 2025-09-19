#include "DoubleLinkedList.h"
#include <stdio.h>
DoubleLinkedList::~DoubleLinkedList()
{
	DoubleListNode* Current = Head;
	while (Current != nullptr) {
		DoubleListNode* NodeToDelete = Current;
		Current = Current->Next;
		delete NodeToDelete;
		NodeToDelete = nullptr;

	}
}
void DoubleLinkedList::DLAdd(int32 Indata)
{
	DoubleListNode* DLlistnode = new DoubleListNode(Indata);

	if (DLisEmpty()) {
		Head = DLlistnode;
		Tail = DLlistnode;
	}
	else {
		Tail->Next = DLlistnode;
		DLlistnode->Prev = Tail;
		Tail = DLlistnode;
	}

	Size++;
}

void DoubleLinkedList::DLInsertAt(int32 Indata, uint32 Inposition)
{
	//�������� ������� ũ�� �׳� ���� ����
	if (Inposition > Size) {
		Inposition = Size;
	}
	if (Inposition == Size)
	{
		DLAdd(Indata);
		return;
	}
	DoubleListNode* InsertNode = new DoubleListNode(Indata);
	//�������� 0�̸� ��忡 ����
	
	if (Inposition == 0) {
		InsertNode->Next = Head;
		Head->Prev = InsertNode;
		Head = InsertNode;
	}
	else {
		//�����ڵ�
		//DoubleListNode* Current = Head;
		//for (uint32 i = 1; i < Inposition; i++) {
		//	Current = Current->Next;
		//}
		//InsertNode->Next = Current->Prev->Next;
		//Current->Prev->Next = InsertNode;
		//
		//InsertNode->Prev = Current->Next->Prev;
		////Current->Next->Prev = InsertNode;

		//������ ����ﶧ
		DoubleListNode* Current;
		if (Size / 2 < Inposition)
		{
			Current = Tail;
			for (uint32 i = Size; i > Inposition; i--) {
				Current = Current->Prev;
			}
		}
		else {
			//��忡 ����ﶧ
			Current = Head;
			for (uint32 i = 1; i < Inposition; i++) {
				Current = Current->Next;
			}
		}
		InsertNode->Next = Current->Prev->Next;
		Current->Prev->Next = InsertNode;

		InsertNode->Prev = Current->Next->Prev;

	}

	

	Size++;
}

void DoubleLinkedList::DLRemove(int32 Indata)
{
	if (DLisEmpty()) {
		return;
	}
	DoubleListNode* Current = Head;
	DoubleListNode* NodeToDelete = nullptr;
	//��嵥���Ͱ� �����ҵ������ΰ��
	if (Head->Data == Indata) {
		NodeToDelete = Head;
		Head->Next->Prev = nullptr;
		Head = Head->Next;
		if (DLisEmpty()) {
			Tail = nullptr;
		}
		delete NodeToDelete;
		NodeToDelete = nullptr;
		Size--;
		return;
	}
	//��尡 �ƴҰ��
	while (Current != nullptr) {
		if (Current->Data == Indata) {
			NodeToDelete = Current;
			Current->Prev->Next = Current->Next;
			
			if (NodeToDelete == Tail) {
				Tail = Current->Prev;
			}
			else {
				Current->Next->Prev = Current->Prev;
			}
			break;
		}
		else {
				Current = Current->Next;
		}
	}
	if (NodeToDelete != nullptr) {
		delete NodeToDelete;
		NodeToDelete = nullptr;
		Size--;
	}
	

}

void DoubleLinkedList::DLRemoveAt(uint32 Position)
{
	if (Position >= Size) {
		printf("����: %u��ġ�� ������ ������ϴ�.\n",Position);
		return;
	}

	DoubleListNode* NodeToDelete = nullptr;
	DoubleListNode* Current;
	//������ġ�� ����϶�
	if (Position == 0) {
		NodeToDelete = Head;
		Head->Next->Prev = nullptr;
		Head = Head->Next;
		if (DLisEmpty()) {
			Tail = nullptr;
		}
		delete NodeToDelete;
		NodeToDelete = nullptr;
		Size--;
		return;
	}
	else {
		if (Size / 2 < Position) {
			Current = Tail;
			for (uint32 i = Size; i > Position; i--) {
				Current = Current->Prev;
			}
		}
		else {
			Current = Head;
			for (uint32 i = 1; i < Position; i++) {
				Current = Current->Next;
			}
		}
		
		NodeToDelete = Current;
		Current->Prev->Next = Current->Next;
		if (NodeToDelete == Tail) {
			Tail = Current->Prev;
		}
		else {
			Current->Next->Prev = Current->Prev;
		}
	}
	Size--;
	delete NodeToDelete;
	NodeToDelete = nullptr;

}

DoubleListNode* DoubleLinkedList::DLSearch(int32 Indata) const
{
	DoubleListNode* Result = nullptr;
	DoubleListNode* Current = Head;
	while (Current != nullptr) {
		if (Current->Data == Indata) {
			Result = Current;
			break;
		}
		else {
			Current = Current->Next;
		}
	}

	return Result;
}

void DoubleLinkedList::DLPrintList()
{
	DoubleListNode* current = Head;
	if (DLisEmpty())
	{
		printf("����Ʈ�� ����ֽ��ϴ�.\n");
		return;
	}
	while (current != nullptr) {
		printf("%d -> ", current->Data);
		current = current->Next;
	}
	printf("nullptr\n");

}

bool DoubleLinkedList::DLisEmpty()
{
	return Head == nullptr;
}
