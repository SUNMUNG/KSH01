#include "FIxedStack.h"
#include <stdio.h>

void FIxedStack::Push(int Invalue)
{
	if (isFull()) {
		printf("오류 : 스택이 가득 찼습니다.\n");
		return;
	}
	TopIndex++;
	Data[TopIndex] = Invalue;

}

int FIxedStack::Pop()
{
	if (isEmpty()) {
		printf("오류 : 스택이 비었습니다.\n");
		return Empty;
	}
	int Result=Data[TopIndex];
	TopIndex--;


	return Result;
}

int FIxedStack::Top()
{
	if (isEmpty()) {
		printf("오류 : 스택이 비었습니다.\n");
		return Empty;
	}

	return Data[TopIndex];
}
