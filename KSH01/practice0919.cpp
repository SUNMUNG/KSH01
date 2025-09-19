#include "practice0919.h"
#include "FIxedStack.h"
#include <stdio.h>
void practice0919::TestFixedStack()
{
	FIxedStack stack;

	if (stack.isEmpty()) {
		printf("스택이 비었습니다.\n");
	}
	printf("현재 스택의 사이즈 : %d\n",stack.GetSize());

	stack.Push(10);
	printf("Top 에 있는 값 : %d\n", stack.Top());
	printf("현재 스택 사이즈 : %d\n", stack.GetSize());
	
	stack.Push(20);
	printf("Top 에 있는 값 : %d\n", stack.Top());
	printf("현재 스택 사이즈 : %d\n", stack.GetSize());

	stack.Push(30);
	printf("Top 에 있는 값 : %d\n", stack.Top());
	printf("현재 스택 사이즈 : %d\n", stack.GetSize());
	
	stack.Pop();
	printf("POP 한번 시행후 Top 에 있는 값 : %d\n", stack.Top());
	printf("현재 스택 사이즈 : %d\n", stack.GetSize());

	stack.Push(40);
	stack.Push(50);
	stack.Push(60);
	stack.Push(70);
	stack.Push(80);
	stack.Push(90);
	stack.Push(100);

	printf("현재 스택의 사이즈 : %d\n",stack.GetSize());
	
	stack.Push(110);

	printf("현재 스택의 사이즈 : %d\n",stack.GetSize());

	stack.Push(110);
	printf("현재 스택의 사이즈 : %d\n",stack.GetSize());

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
	printf("현재 스택의 사이즈 : %d\n",stack.GetSize());
	stack.Pop();
	printf("현재 스택의 사이즈 : %d\n",stack.GetSize());
}
