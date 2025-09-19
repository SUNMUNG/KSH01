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

void practice0919::TestCircularQueue()
{
	CircularQueue CQueue;
	int Select = -1;
	int Num = 0;
	while (Select!=5)
	{
		printf("���ϴ� �޴��� ��ȣ�� �Է��ϼ��� . \n");
		printf("1.Enqueue\n2.Dequeue\n3.Peek\n4.TestPrintQueue\n");;
		std::cin >> Select;
		switch (Select)
		{
		case 1:
			printf("ť�� Enqueue�� ���� �Է��ϼ��� : \n");
			std::cin >> Num;
			CQueue.Enqueue(Num);
			break;
		case 2:
			printf("ť : Dequeue�մϴ�. : \n");
			printf("Dequeue �� �� : %d\n", CQueue.Dequeue());
			break;
		case 3:
			printf("Peek : ���� ť�� Front : %d\n", CQueue.Peek());
			break;
		case 4:
			CQueue.TestPrintQueue();
			break;
		case 5:
			printf("�����մϴ�.\n");
			break;
		default:
			break;
		}
	}
	
}

void practice0919::TestCircularQueue2()
{
	int Maxsize = 0;
	printf("���ϴ� ť�� ũ�⸦ �Է��ϼ��� : \n");
	std::cin >> Maxsize;
	CircularQueue2 CQueue2(Maxsize);
	int Select = -1;
	int Num = 0;
	
	while (Select != 5)
	{
		printf("���ϴ� �޴��� ��ȣ�� �Է��ϼ��� . \n");
		printf("1.Enqueue\n2.Dequeue\n3.Peek\n4.TestPrintQueue\n");;
		std::cin >> Select;
		switch (Select)
		{
		case 1:
			printf("ť�� Enqueue�� ���� �Է��ϼ��� : \n");
			std::cin >> Num;
			CQueue2.Enqueue(Num);
			break;
		case 2:
			printf("ť : Dequeue�մϴ�. : \n");
			printf("Dequeue �� �� : %d\n", CQueue2.Dequeue());
			break;
		case 3:
			printf("Peek : ���� ť�� Front : %d\n", CQueue2.Peek());
			break;
		case 4:
			CQueue2.TestPrintQueue();
			break;
		case 5:
			printf("�����մϴ�.\n");
			break;
		default:
			break;
		}
	}
}
