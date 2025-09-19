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
	//포지션이 사이즈보다 크면 그냥 끝에 삽입
	if (Inposition > Size) {
		Inposition = Size;
	}
	if (Inposition == Size)
	{
		DLAdd(Indata);
		return;
	}
	DoubleListNode* InsertNode = new DoubleListNode(Indata);
	//포지션이 0이면 헤드에 삽입
	
	if (Inposition == 0) {
		InsertNode->Next = Head;
		Head->Prev = InsertNode;
		Head = InsertNode;
	}
	else {
		//이전코드
		//DoubleListNode* Current = Head;
		//for (uint32 i = 1; i < Inposition; i++) {
		//	Current = Current->Next;
		//}
		//InsertNode->Next = Current->Prev->Next;
		//Current->Prev->Next = InsertNode;
		//
		//InsertNode->Prev = Current->Next->Prev;
		////Current->Next->Prev = InsertNode;

		//꼬리에 가까울때
		DoubleListNode* Current;
		if (Size / 2 < Inposition)
		{
			Current = Tail;
			for (uint32 i = Size; i > Inposition; i--) {
				Current = Current->Prev;
			}
		}
		else {
			//헤드에 가까울때
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
	//헤드데이터가 삭제할데이터인경우
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
	//헤드가 아닐경우
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
		printf("오류: %u위치는 범위를 범어났습니다.\n",Position);
		return;
	}

	DoubleListNode* NodeToDelete = nullptr;
	DoubleListNode* Current;
	//삭제위치가 헤드일때
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
		printf("리스트가 비어있습니다.\n");
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
