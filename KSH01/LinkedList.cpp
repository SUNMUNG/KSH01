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
    if (isEmpty())  // ��������� ������ ������ �׳� ������.
        return;

    ListNode* NodeToDelete = nullptr;   // ������ ���
    ListNode* PrevNode = nullptr;       // ������ ����� �� ���

    if (Head->Data == Indata)
    {
        // ������ �����Ͱ� Head��
        NodeToDelete = Head;    // ������ �����ͷ� Head�� ����
        Head = Head->Next;      // Head�� Head�� ���� ���� ����
        if (isEmpty())
        {
            Tail = nullptr;     // Head�� ���� ��� ����Ʈ�� ��� �Ǹ� Tail�� nullptr�� ����
        }
    }
    else
    {
        // ������ �����Ͱ� Head�� �ƴϴ�.
        PrevNode = Head;        // PrevNode�� ã��. Head���� �����ؼ� ��� �������� �����ϸ� ã�´�.
        while (PrevNode->Next != nullptr            // Prev�� ���� ��尡 ������� �ʴ�.
            && PrevNode->Next->Data != Indata)      // �׸��� Prev�� ���� ����� �����Ͱ� ã�� �����Ͱ� �ƴϴ�.
        {
            PrevNode = PrevNode->Next;
        }

        if (PrevNode->Next != nullptr)
        {
            // PrevNode�� ã�Ҵٸ�
            NodeToDelete = PrevNode->Next;          // Prev�� ���� ��带 ������ ���� ����
            PrevNode->Next = NodeToDelete->Next;    // Prev�� ���� ��带 ������ ����� ���� ���� ����
            if (NodeToDelete == Tail)
                Tail = PrevNode;        // ������ ��尡 ������ ���� Prev�� ���ο� ������ ���
        }
    }

    if (NodeToDelete)   // if(NodeToDelete != nullptr)
    {
        delete NodeToDelete;        // NodeToDelete�� ã������ delete
        NodeToDelete = nullptr;
        Size--;                     // Size 1 ���̱�
    }
    else
    {
        // NodeToDelete�� �� ã������ ���� ���
        printf("���� : %d���� ���� ��尡 �����ϴ�.\n", Indata);
    }
}

void LinkedList::RemoveAt(uint32 inPosition)
{
    if (inPosition >= Size) {
        printf("���� : %u��ġ�� ������ ������ϴ�. ����ũ�� : %u\n",inPosition,Size);
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
        printf("����Ʈ�� ����ֽ��ϴ�.\n");
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