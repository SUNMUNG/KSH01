#include "CircularQueue2.h"

CircularQueue2::CircularQueue2(int Size)
{
	MaxSize = Size;
	Data = new int[MaxSize]();
}

CircularQueue2::~CircularQueue2()
{
	delete Data;
	Data = nullptr;
}

//CircularQueue2(const CircularQueue2&) = delete;
//CircularQueue2& operator=(const CircularQueue2&) = delete;

void CircularQueue2::Enqueue(int InValue)
{
	if (isFull()) {
		printf("오류 : 큐가 가득찼습니다.\n");
		return;
	}
	if (isEmpty()) {
		Front = 0;
	}
	Rear = (Rear + 1) % MaxSize;
	Data[Rear] = InValue;
	printf("Enqueue가 완료되었습니다.\n\n");
}

int CircularQueue2::Dequeue()
{
	if (isEmpty()) {
		printf("오류 : 큐가 비었습니다..\n");
		return Empty;
	}
	int Result = Data[Front];
	if (Front != Rear) {
		Data[Front] = Empty;
		Front = (Front + 1) % MaxSize;
	}
	else {
		Front = Empty;
		Rear = Empty;
	}
	return Result;
}

void CircularQueue2::TestPrintQueue()
{
	
	if (isEmpty()) {
		printf("큐가 비어있습니다.\n");
		return;
	}
	
	for (int i = Front; i <= Rear; i++) {
		printf("%d ", Data[i]);
	}
	printf("\n");
	printf("\n");

}
