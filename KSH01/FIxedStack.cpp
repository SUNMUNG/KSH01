#include "FIxedStack.h"
#include <stdio.h>

void FIxedStack::Push(int Invalue)
{
	if (isFull()) {
		printf("���� : ������ ���� á���ϴ�.\n");
		return;
	}
	TopIndex++;
	Data[TopIndex] = Invalue;

}

int FIxedStack::Pop()
{
	if (isEmpty()) {
		printf("���� : ������ ������ϴ�.\n");
		return Empty;
	}
	int Result=Data[TopIndex];
	TopIndex--;


	return Result;
}

int FIxedStack::Top()
{
	if (isEmpty()) {
		printf("���� : ������ ������ϴ�.\n");
		return Empty;
	}

	return Data[TopIndex];
}
