#include "practice_0905.h"
#include <stdio.h>
#include <cstring>
#include <random>
#include <string>
#include <iostream>

//Ư�� �������� ������ ���� �����ϴ� �Լ�
//int �Ķ���Ͱ� 2��
//int ����
int Random_int_Return(int minRange, int maxRange)
{
	srand(time(0));
	int Random_Number = rand() % (maxRange - minRange + 1)+minRange;

	return Random_Number;
}
void practice_0905_1()
{
	printf("%d\n",Random_int_Return(1, 10));
}

//������� ���̸� �Է��� �ּ��� : �� �� ������� 00�� �Դϴ١�
//int �Ķ���� 1��


void practice_0905_2()
{
	int age;
	printf("����� ���̸� �Է��� �ּ��� : \n");
	std::cin >> age;

	YourAge(age);

}

int YourAge(int age)
{
	printf("����� %d�� �Դϴ�.",age);

	return 0;
	
}

//���� �������� �Է� �ް� ���� ���ϱ�
//float �Ķ���� 1��
//float ����

void practice_0905_3()
{
	int radius;
	printf("�������� �Է����ּ��� : \n");
	std::cin >> radius;

	printf("���� ���̴� %.2f �Դϴ�\n",CircleResult(radius));
}

float CircleResult(float radius)
{
	float res = 0.0f;

	res = radius * radius * 3.141592f;

	return res;
}



//���ڸ� �Է¹޾� Ȧ������ ¦������ �Ǵ��ϴ� �Լ�
//int �Ķ���� 1��
//bool ����(true�� Ȧ��, false�� ¦��)

void practice_0905_4()
{
	int OddEven_Num;
	printf("���� �Է����ּ��� : \n");
	std::cin >> OddEven_Num;

	if (OddEvenResult(OddEven_Num) == true) {
		printf("Ȧ�� �Դϴ�.\n");
	}
	else {
		printf("¦�� �Դϴ�.\n");
	}
	
}

bool OddEvenResult(int OddEven_Num)
{
	if (OddEven_Num % 2 != 0) {
		return true;
	}

	return false;
}



//���� �з� �Լ�(A~F)
//int �Ķ���� 1��
//int ����(enum��)

void practice_0905_5()
{
	int Student_Score;
	printf("������ �Է����ּ��� : \n");
	std::cin >> Student_Score;
	switch (RankSelect(Student_Score)) {
		case 0:
			printf("����� A�Դϴ�.\n");
			break;
		case 1:
			printf("����� B�Դϴ�.\n");
			break;
		case 2:
			printf("����� C�Դϴ�.\n");
			break;
		case 3:
			printf("����� D�Դϴ�.\n");
			break;
		case 4:
			printf("����� E�Դϴ�.\n");
			break;
		case 5:
			printf("����� F�Դϴ�.\n");
			break;
		default:
			printf("�����Դϴ�.\n");
	}
	
}

int RankSelect(int score)
{
	enum Rank
	{
		A,
		B,
		C,
		D,
		E,
		F
	};

	if (score >= 90) {
		return A;
	}
	else if (score >= 80) {
		return B;
	}
	else if (score >= 70) {
		return C;
	}
	else if (score >= 60) {
		return D;
	}
	else if (score >= 50) {
		return E;
	}
	else{
		return F;
	}



	return 0;
}

//������ ����, ������ ����, ������ ��ۿ� �Լ� �� 3��
//��Ʈ �÷��� �κ��丮 �ڵ� ����
//int �Ķ���� �ΰ�(Inventory, ��Ʈ�÷��׿� enum)



void practice_0905_6()
{
	int PlayerSelectNumber=-1;
	int PlayerItemSelectNumber = -1;
	int PlayerInventory=0;
	enum Item_List
	{
		Axe = 1,
		Evidence =2,
		Flash =3,
		Wirelessset=4
	};

	while (PlayerSelectNumber < 5) {
		printf("�޴��� ���� ���ڸ� �Է����ּ��� .\n");
		printf("[ 1.������ ���� 2. ������ ���� 3.������ ��� 4.�κ��丮 Ȯ�� 5.���� ] .\n");
		std::cin >> PlayerSelectNumber;

		switch (PlayerSelectNumber) {
			case 1: 
				printf("�������� �����մϴ�\n");
				printf("[ 1.���� 2.���� 3.�÷��� 4.������ ] .\n");
				std::cin >> PlayerItemSelectNumber;
				PlayerInventory = ItemInventoryAdd(PlayerInventory,PlayerItemSelectNumber);
				break;
			case 2:
				printf("�������� �����մϴ�\n");
				printf("[ 1.���� 2.���� 3.�÷��� 4.������ ] .\n");
				std::cin >> PlayerItemSelectNumber;
				PlayerInventory = ItemInventoryDelete(PlayerInventory,PlayerItemSelectNumber);
				break;
			case 3:
				printf("�������� ����մϴ�\n");
				printf("[ 1.���� 2.���� 3.�÷��� 4.������ ] .\n");
				std::cin >> PlayerItemSelectNumber;
				PlayerInventory =ItemInventoryToggle(PlayerInventory,PlayerItemSelectNumber);
				break;
			case 4:printf("���� �κ��丮�� �������� .. %d\n",PlayerInventory);
			default:
				break;

		}
	}

}

int ItemInventoryAdd(int PlayerInventory, int ItemNum)
{
	int playerinv = 0;

	switch (ItemNum) {
		case 1:  (playerinv = PlayerInventory |1); //0000 | 0001
			break;
		case 2: (playerinv = PlayerInventory |2); //0000 | 0010
			break;
		case 3:  (playerinv = PlayerInventory |4); //0000 | 0100
			break;
		case 4: (playerinv = PlayerInventory |8); //0000| 1000
			break;
		default: printf("�ش��ϴ� ��ȣ�� �������� �����ϴ�..\n");
			break;
	}
	
	printf("������ �߰��� �Ϸ��߽��ϴ�.\n");
	return playerinv;
}	

int ItemInventoryDelete(int PlayerInventory, int ItemNum)
{
	int playerinv = 0;

	switch (ItemNum) {
	case 1:  (playerinv = PlayerInventory - 0b0001); 
		break;
	case 2: (playerinv = PlayerInventory - 0b0010); //0110 & 0010 
		break;
	case 3:  (playerinv = PlayerInventory - 0b0100);//0110 & 0100  = 0010
		break;
	case 4: (playerinv = PlayerInventory - 0b1000);
		break;
	default: printf("�ش��ϴ� ��ȣ�� �������� �����ϴ�..\n");
		break;
	}

	printf("������ ���Ÿ� �Ϸ��߽��ϴ�.\n");
	return playerinv;
}

int ItemInventoryToggle(int PlayerInventory, int ItemNum)
{
	int playerinv = 0;

	switch (ItemNum) {
	case 1:  (playerinv = PlayerInventory ^ 1);
		break;
	case 2: (playerinv = PlayerInventory ^ 2);
		break;
	case 3:  (playerinv = PlayerInventory ^ 4);
		break;
	case 4: (playerinv = PlayerInventory ^ 8);
		break;
	default: printf("�ش��ϴ� ��ȣ�� �������� �����ϴ�..\n");
		break;
	}


	printf("������ ����� �Ϸ��߽��ϴ�.\n");
	return playerinv;
}

//�Ƕ�̵� ��� �Լ�
//int �Ķ���� 1��

void practice_0905_7()
{
	int Pyramid_Num;
	printf("������ �Է����ּ��� : \n");
	std::cin >> Pyramid_Num;

	PyramidMake(Pyramid_Num);

}

void PyramidMake(int num)
{
	for (int i = 0; i < num; i++) {
		for (int j = 0; j < num-i; j++) {
			printf(" ");
		}
		for (int k = 0; k < 2 * i + 1; k++) {
			printf("*");
		}
		printf("\n");
	}
}

void practice09059()
{	
	int FactorialNumber;
	printf("�� ���丮���� ���ұ��? : \n");
	std::cin >> FactorialNumber;

	printf("%d", Factorial(FactorialNumber));
}
int res=1;
int Factorial(int num) {
	if (num == 1) return 1;
	else return num * Factorial(num - 1);
}

//����Լ��� �̿��ؼ� ���丮�� ���� ����� �Լ� �����
//5���丮�� = 5 * 4 * 3 * 2 * 1


