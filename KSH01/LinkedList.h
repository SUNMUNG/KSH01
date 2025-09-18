#pragma once
#include <stdint.h>
using uint32 = uint32_t;
using int32 = int32_t;
struct ListNode
{
	int32 Data = 0;
	ListNode* Next = nullptr;

	ListNode(int32 Indata) : Data(Indata) {};
};

class LinkedList
{
public:
	LinkedList() = default;
	~LinkedList();

	void Add(int32 Indata);

	void InsertAt(int32 Indata,uint32 Inposition);

	void Remove(int32 Indata);

	void RemoveAt(uint32 Position);

	ListNode* Search(int32 Indata)const;

	void PrintList();

	bool isEmpty();
private:
	ListNode* Head = nullptr;
	ListNode* Tail = nullptr;
	uint32 Size = 0;
};

