#include "practice0919.h"
#include "FIxedStack.h"
#include "CircularQueue.h"
#include "CircularQueue2.h"
#include <stdio.h>
#include <iostream>
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

void practice0919::TestCircularQueue()
{
	CircularQueue CQueue;
	int Select = -1;
	int Num = 0;
	while (Select!=5)
	{
		printf("원하는 메뉴의 번호를 입력하세요 . \n");
		printf("1.Enqueue\n2.Dequeue\n3.Peek\n4.TestPrintQueue\n");;
		std::cin >> Select;
		switch (Select)
		{
		case 1:
			printf("큐에 Enqueue할 수를 입력하세요 : \n");
			std::cin >> Num;
			CQueue.Enqueue(Num);
			break;
		case 2:
			printf("큐 : Dequeue합니다. : \n");
			printf("Dequeue 한 수 : %d\n", CQueue.Dequeue());
			break;
		case 3:
			printf("Peek : 현재 큐의 Front : %d\n", CQueue.Peek());
			break;
		case 4:
			CQueue.TestPrintQueue();
			break;
		case 5:
			printf("종료합니다.\n");
			break;
		default:
			break;
		}
	}
	
}

void practice0919::TestCircularQueue2()
{
	int Maxsize = 0;
	printf("원하는 큐의 크기를 입력하세요 : \n");
	std::cin >> Maxsize;
	CircularQueue2 CQueue2(Maxsize);
	int Select = -1;
	int Num = 0;
	
	while (Select != 5)
	{
		printf("원하는 메뉴의 번호를 입력하세요 . \n");
		printf("1.Enqueue\n2.Dequeue\n3.Peek\n4.TestPrintQueue\n");;
		std::cin >> Select;
		switch (Select)
		{
		case 1:
			printf("큐에 Enqueue할 수를 입력하세요 : \n");
			std::cin >> Num;
			CQueue2.Enqueue(Num);
			break;
		case 2:
			printf("큐 : Dequeue합니다. : \n");
			printf("Dequeue 한 수 : %d\n", CQueue2.Dequeue());
			break;
		case 3:
			printf("Peek : 현재 큐의 Front : %d\n", CQueue2.Peek());
			break;
		case 4:
			CQueue2.TestPrintQueue();
			break;
		case 5:
			printf("종료합니다.\n");
			break;
		default:
			break;
		}
	}
}
