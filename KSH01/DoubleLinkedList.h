#pragma once
#include <stdint.h>

using uint32 = uint32_t;
using int32 = int32_t;
struct DoubleListNode
{
	int32 Data = 0;
	DoubleListNode* Next = nullptr;
	DoubleListNode* Prev = nullptr;

	DoubleListNode(int32 Indata) : Data(Indata) {};
};

class DoubleLinkedList
{
public:
	DoubleLinkedList() = default;
	~DoubleLinkedList();

	void DLAdd(int32 Indata);

	void DLInsertAt(int32 Indata, uint32 Inposition);

	void DLRemove(int32 Indata);

	void DLRemoveAt(uint32 Position);

	DoubleListNode* DLSearch(int32 Indata)const;

	void DLPrintList();

	bool DLisEmpty();
private:
	DoubleListNode* Head = nullptr;
	DoubleListNode* Tail = nullptr;
	uint32 Size = 0;
};




