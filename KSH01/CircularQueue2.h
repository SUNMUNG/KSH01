#pragma once
#include <stdio.h>
class CircularQueue2
{
public:
	CircularQueue2(int Size);
	~CircularQueue2();

	void Enqueue(int InValue);
	int Dequeue();

	void TestPrintQueue();

	inline bool isFull() const {
		return (Rear + 1) % MaxSize == Front;
	}
	inline bool isEmpty() const {
		return Front == Empty;
	}
	inline int Peek() const {
		if (isEmpty()) {
			printf("오류 : 큐가 비었습니다\n");
			return Empty;
		}
		return Data[Front];
	}
	inline int GetSize() const {
		return ((Rear + MaxSize) - Front) % MaxSize + 1;
	}
private:
	static constexpr int Empty = -1;
	unsigned int MaxSize;
	int Front = Empty;
	int Rear = Empty;
	int* Data;
};
