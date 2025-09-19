#include "practice0919.h"
#include "FIxedStack.h"
#include <stdio.h>
void practice0919::TestFixedStack()
{
	FIxedStack stack;

	if (stack.isEmpty()) {
		printf("������ ������ϴ�.\n");
	}
	printf("���� ������ ������ : %d\n",stack.GetSize());

	stack.Push(10);
	printf("Top �� �ִ� �� : %d\n", stack.Top());
	printf("���� ���� ������ : %d\n", stack.GetSize());
	
	stack.Push(20);
	printf("Top �� �ִ� �� : %d\n", stack.Top());
	printf("���� ���� ������ : %d\n", stack.GetSize());

	stack.Push(30);
	printf("Top �� �ִ� �� : %d\n", stack.Top());
	printf("���� ���� ������ : %d\n", stack.GetSize());
	
	stack.Pop();
	printf("POP �ѹ� ������ Top �� �ִ� �� : %d\n", stack.Top());
	printf("���� ���� ������ : %d\n", stack.GetSize());

	stack.Push(40);
	stack.Push(50);
	stack.Push(60);
	stack.Push(70);
	stack.Push(80);
	stack.Push(90);
	stack.Push(100);

	printf("���� ������ ������ : %d\n",stack.GetSize());
	
	stack.Push(110);

	printf("���� ������ ������ : %d\n",stack.GetSize());

	stack.Push(110);
	printf("���� ������ ������ : %d\n",stack.GetSize());

	stack.Pop();
	stack.Pop();
	stack.Pop();
	stack.Pop();
	stack.Pop();
	stack.Pop();
	stack.Pop();
	stack.Pop();
	stack.Pop();
	stack.Pop();
	printf("���� ������ ������ : %d\n",stack.GetSize());
	stack.Pop();
	printf("���� ������ ������ : %d\n",stack.GetSize());
}
