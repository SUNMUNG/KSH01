#include "LinkedList.h"
#include <stdio.h>
void LinkedList::Add(int32 Indata)
{
	ListNode* listNode = new ListNode(Indata);

	if (isEmpty()) {
		Head = listNode;
	}
	else {
		Tail->Next=listNode;
	}
	
	Tail = listNode;
	 
	Size++;
}

void LinkedList::InsertAt(int32 Indata, uint32 Inposition)
{
    if (Inposition > Size) {
        Inposition = Size;
    }
    if (Inposition == Size)
    {
        Add(Indata);
        return;
    }

    ListNode* listnode = new ListNode(Indata);

    if (Inposition == 0) {
        listnode->Next = Head;
        Head = listnode;
    }
    else {
        ListNode* prev = Head;
        const uint32 TargetIndex = Inposition - 1;
        for (uint32 i = 0; i < TargetIndex; i++) {
            prev = prev->Next;
        }
        listnode->Next = prev->Next;
        prev->Next = listnode;
    }
    Size++;
}

void LinkedList::Remove(int32 Indata)
{
	/*ListNode* current = Head;
	ListNode* previous=nullptr;
	while (current != nullptr) {
		if (Head->Data==Indata) {
			Head = Head->Next;
			if (isEmpty()) {
				Tail = nullptr;
			}
			Size--;
		}
		else if (current->Data == Indata) {
			previous->Next = current->Next;
			delete current;
			current = nullptr;
			Size--;
		}
		else {
			previous = current;
			current = current->Next;

		}
		
	}*/
    if (isEmpty())  // 비어있으면 무조건 없으니 그냥 끝낸다.
        return;

    ListNode* NodeToDelete = nullptr;   // 삭제할 노드
    ListNode* PrevNode = nullptr;       // 삭제할 노드의 앞 노드

    if (Head->Data == Indata)
    {
        // 삭제할 데이터가 Head다
        NodeToDelete = Head;    // 삭제할 데이터로 Head를 설정
        Head = Head->Next;      // Head를 Head의 다음 노드로 설정
        if (isEmpty())
        {
            Tail = nullptr;     // Head의 삭제 결과 리스트가 비게 되면 Tail로 nullptr로 설정
        }
    }
    else
    {
        // 삭제할 데이터가 Head가 아니다.
        PrevNode = Head;        // PrevNode를 찾기. Head에서 시작해서 계속 다음으로 전진하며 찾는다.
        while (PrevNode->Next != nullptr            // Prev의 다음 노드가 비어있지 않다.
            && PrevNode->Next->Data != Indata)      // 그리고 Prev의 다음 노드의 데이터가 찾는 데이터가 아니다.
        {
            PrevNode = PrevNode->Next;
        }

        if (PrevNode->Next != nullptr)
        {
            // PrevNode를 찾았다면
            NodeToDelete = PrevNode->Next;          // Prev의 다음 노드를 삭제할 노드로 설정
            PrevNode->Next = NodeToDelete->Next;    // Prev의 다음 노드를 삭제할 노드의 다음 노드로 설정
            if (NodeToDelete == Tail)
                Tail = PrevNode;        // 삭제할 노드가 마지막 노드면 Prev가 새로운 마지막 노드
        }
    }

    if (NodeToDelete)   // if(NodeToDelete != nullptr)
    {
        delete NodeToDelete;        // NodeToDelete를 찾았으면 delete
        NodeToDelete = nullptr;
        Size--;                     // Size 1 줄이기
    }
    else
    {
        // NodeToDelete를 못 찾았으면 에러 출력
        printf("오류 : %d값을 가진 노드가 없습니다.\n", Indata);
    }
}

void LinkedList::RemoveAt(uint32 inPosition)
{
    if (inPosition >= Size) {
        printf("오류 : %u위치는 범위를 벗어났습니다. 현재크기 : %u\n",inPosition,Size);
        return;
    }

    ListNode* NodeToDelete = nullptr;
    
    if (inPosition == 0) {
        NodeToDelete = Head;
        Head = Head->Next;
        if (isEmpty()) {
            Tail = nullptr;
        }
    }
    else {
        ListNode* prev = Head;
        const uint32 TargetIndex = inPosition - 1;
        for (uint32 i = 0; i < TargetIndex; i++) {
            prev = prev->Next;
        }
        NodeToDelete = prev->Next;
        prev->Next = NodeToDelete->Next;
        if (NodeToDelete == Tail)
        {
            Tail = prev;
        }
    }
    delete NodeToDelete;
    NodeToDelete = nullptr;
    Size--;
}

ListNode* LinkedList::Search(int32 Indata) const
{
    ListNode* Result = nullptr;
    ListNode* Current = Head;
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

void LinkedList::PrintList()
{
    ListNode* current = Head;
    if (isEmpty())
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

bool LinkedList::isEmpty()
{
	return Head == nullptr;
}

LinkedList::~LinkedList()
{
    ListNode* Current = Head;
        while (Current != nullptr) {
            ListNode* NodeToDelete=Current;
            Current = Current->Next;
            delete NodeToDelete;
            NodeToDelete = nullptr;

        }
}