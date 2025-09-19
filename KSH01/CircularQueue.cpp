#include "CircularQueue.h"

void CircularQueue::Enqueue(int InValue)
{
	if (isFull()) {
		printf("���� : ť�� ����á���ϴ�.\n");
		return;
	}
	if (isEmpty()) {
		Front = 0;
	}
	Rear = (Rear + 1) % MaxSize;
	Data[Rear] = InValue;
	printf("Enqueue�� �Ϸ�Ǿ����ϴ�.\n\n");
}

int CircularQueue::Dequeue()
{
	if (isEmpty()) {
		printf("���� : ť�� ������ϴ�..\n");
		return Empty;
	}
	int Result = Data[Front];
	if (Front!=Rear) {
		//Data[Front] = Empty;
		Front = (Front + 1) % MaxSize;
	}
	else {
		Front = Empty;
		Rear = Empty;
	}
	return Result;
}

void CircularQueue::TestPrintQueue()
{
	if (isEmpty()) {
		printf("ť�� ����ֽ��ϴ�.\n");
		return;
	}
	for (int i =Front; i <= Rear; i++) {
		printf("%d ", Data[i]);
	}
	printf("\n");
	printf("\n");

}
