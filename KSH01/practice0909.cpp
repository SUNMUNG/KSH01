#include "practice0909.h"
#include <stdio.h>
#include <iostream>
#include <cstring>
#include <random>
#include <string>
#include <limits.h>
#include "practice0910.h"

void practice09091()
{
	int Number = 10;
	int* p = nullptr;
	float Number2 = 12.1f;
	float* p2 = nullptr;


	p = &Number;
	p2 = &Number2;

	(*p) = 50;
	(*p2) = 123.1f;


	printf("%d\n", Number);

	pointerparameter(&Number);

	printf("%d\n", Number);

	printf("%.2f\n", Number2);

	pointerTest(p, p2);

	printf("%d\n", Number);

	printf("%.2f\n", Number2);

	float* test = p2;
	p2++;

}

void pointerparameter(int* pNumber) {
	(*pNumber) *= 2;
}

void pointerTest(int* pNumberI, float* pNumberF)
{
	(*pNumberI) += 3;
	//(*pNumberF) /= 2;
	(*pNumberF) *= 0.5f;
}


void practice09092()
{
	int Array[5] = { 10,20,30,40,50 };
	int* pArray = Array;
	int* pArray2 = &Array[0];

	*(pArray2 + 2) = 300;

	for (int data : Array) {
		printf("%d ", data);
	}
	printf("\n");

	for (int i = 0; i < 5; i++) {
		printf("%d ", Array[i]);
	}
	printf("\n");
}

void practice09093()
{
	int Size = 5;
	int* Array = nullptr;
	Array=(int*)malloc(sizeof(int) * Size);
	free(Array);
	Array = nullptr;

	int* data=nullptr;
	int* Array2 = nullptr;

	data = new int(5);
	Array2 = new int[5];

	Array2[2] = 20;

	*(Array2 + 3) = 30;
	
	*(data) = 1;

	delete data;
	delete[] Array2;

	data = nullptr;
	Array2 = nullptr;

}



void practice09094()
{
	int CurrentSize = 0;
	int Size = 3;
	int* Array = nullptr;
	int* Array2 = nullptr;
	int num;
	bool isTrue = true;
	
	Array =	new int[Size];
	Array2 = new int[Size];

		for (int i = 0; i < Size; i++) {
			if (Size > CurrentSize) {
				printf("���� �Է��ϼ��� : \n");
				std::cin >> num;
				*(Array + i) = num;
				CurrentSize++;
			}	
		}
		while (num != 0) {
			printf("�� �Է��ϰ������ 1�� �Է��ϼ��� �ƴϸ� 0�� �Է��ϼ���: \n");
			std::cin >> num;
			switch (num) {
			case 1:
				printf("���� �Է��ϼ��� : \n");
				std::cin >> num;
				if (isTrue == true) {
					//�ʱ�ȭ
					delete[] Array2;
					Array2 = nullptr;
					//�迭ũ�� +1
					CurrentSize++;
					Array2 = new int[CurrentSize];

					//�����۾�
					for (int i = 0; i < CurrentSize - 1; i++) {
						Array2[i] = Array[i];
					}
					//���ο 
					Array2[CurrentSize - 1] = num;
					//�ʿ���� �迭�ʱ�ȭ
					delete[] Array;
					Array = nullptr;
					isTrue = false;
				}
				else if (isTrue == false) {
					//�ʱ�ȭ
					delete[] Array;
					Array = nullptr;
					//�迭ũ�� +1
					CurrentSize++;
					Array = new int[CurrentSize];

					//�����۾�
					for (int i = 0; i < CurrentSize - 1; i++) {
						Array[i] = Array2[i];
					}
					//���ο 
					Array[CurrentSize - 1] = num;
					//�ʿ���� �迭�ʱ�ȭ
					delete[] Array2;
					Array2 = nullptr;
					isTrue = true;
				}
				break;
			case 0:
				break;
			default:
				break;
			}
		}

	
		if (isTrue==true) {
			for (int i = 0; i < CurrentSize; i++) {
				printf("%d ", Array[i]);
			}printf("\n");
		}
		else {
			for (int i = 0; i < CurrentSize; i++) {
				printf("%d ", Array2[i]);
			}printf("\n");
		}
		
	

	delete[] Array2;

	Array2 = nullptr;

	delete[] Array;

	Array = nullptr;
}

void NewArray(int* arr,int size)
{
	arr = new int[size];
}

void practice09095()
{
	printArray();
}

void printArray()
{
	int Width=0;
	int Height=0;
	int count = 0;
	int* Array = nullptr;
	
	printf("���ο� ���θ� �Է����ּ��� : \n");
	std::cin >> Width;
	std::cin >> Height;
	
	const int Full = Width * Height;
	Array = new int[Full];

	for (int i = 0; i < Full; i++) {
		Array[i] = i;
	}
	for (int i = 0; i < Height; i++) {
		for (int j = 0; j < Width; j++) {
			printf("%d ",Array[count]);
			count++;
		}
		printf("\n");
	}


	delete[] Array;

	Array = nullptr;

}


void practice09096()
{
	HighLow();
}

void HighLow()
{
	    //3��

		srand(time(0));
		int player_num=-1;
		int com_num = rand() % 100 + 1;
		int PlayerPushNum[5] = { 0 };
		int count = 5;


		while (count > 0) {
			printf("�����ϴ� ���ڸ� �Է��ϼ��� : ");
			std::cin >> player_num;
			PlayerPushNum[5 - count]= player_num;

			if (player_num == com_num) {
				printf("�����Դϴ�");
				break;
			}
			else if (player_num > com_num) {
				printf("�� ����\n");
				count--;
				printf("��ȸ�� %d�� ���ҽ��ϴ�.\n",count);
			}
			else if (player_num < com_num) {
				printf("�� ����\n");
				count--;
				printf("��ȸ�� %d�� ���ҽ��ϴ�.\n",count);
			}
			else {
				printf("�����Դϴ�.\n");
			}
		}
		printf("��ȸ�� �����Ǿ����ϴ�.\n");
		printf("������ϴ� ���� : %d �����ϴ�.\n",com_num);
		printf("�÷��̾ �Է��Ѽ� : ");
		for (int i = 0; i < 5; i++) {
			printf("%d ", PlayerPushNum[i]);
		}
		printf("\n");
}

void practice09097()
{
	Miro2();
}
int PlayerHealthPoint = 100;
int EnemyHealthPoint = 100;
void Miro2()
{
	// �̷� ũ��
	
	int& PHP = PlayerHealthPoint;
	int& EHP = EnemyHealthPoint;


	const int MazeHeight = 10;
	const int MazeWidth = 20;
	int PlayerPosX = 1;
	int PlayerPosY = 1;
	int EndPosX = 18;
	int EndPosY = 7;
	char PlayerMove;
	int isBattle = -1;


	// �̷� �迭
	int Maze[MazeHeight][MazeWidth] =
	{
		{1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
		{1,2,0,0,0,1,0,0,0,0,1,0,0,1,0,0,0,1,0,1},
		{1,1,1,1,0,1,0,1,1,0,1,0,1,1,0,1,0,1,0,1},
		{1,0,0,1,0,0,0,1,0,0,0,0,0,0,0,1,0,0,0,1},
		{1,0,1,1,1,1,0,1,1,1,0,1,1,1,0,1,1,1,0,1},
		{1,0,0,0,0,1,0,0,0,1,0,0,0,1,0,0,0,1,0,1},
		{1,1,1,1,0,1,1,1,0,1,1,1,0,1,1,1,0,1,1,1},
		{1,0,0,1,0,0,0,1,0,0,0,1,0,0,0,1,0,0,3,1},
		{1,0,1,1,1,1,0,1,1,1,0,1,1,1,0,1,1,1,0,1},
		{1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1}
	};


	//�����Ȳ �̷� ���
	while (Maze[PlayerPosY][PlayerPosX] != Maze[EndPosY][EndPosX]) {

		for (int i = 0; i < MazeHeight; i++) {
			for (int j = 0; j < MazeWidth; j++) {
				if (Maze[i][j] == 1) {
					printf("# ");
				}
				else if (Maze[i][j] == 0) {
					printf(". ");
				}
				else if (Maze[i][j] == 2) {
					printf("S ");
				}
				else if (Maze[i][j] == 3) {
					printf("E ");
				}
				else if (Maze[i][j] == 4) {
					printf("P ");
				}
				else {
					printf("@ ");
				}
			}
			printf("\n");
		}
		//20%Ȯ���� ����
		if ((isBattle == 5) ||(isBattle == 9) ) {
			Battle(PlayerHealthPoint, EnemyHealthPoint);
		}
		else if (isBattle == 3) {
			PlayerHealthPoint += 100;
		}

		//�̵����� ���� ���
		printf("w(W): ��, s(S): �Ʒ�, a(A): ����, d(D): ������\n");
		printf("�̵� ������ ���� : ");
		if (Maze[PlayerPosY + 1][PlayerPosX] == 0) {
			printf("s(S): �Ʒ�, ");
		}
		if (Maze[PlayerPosY - 1][PlayerPosX] == 0) {
			printf("w(W): ��, ");
		}
		if (Maze[PlayerPosY][PlayerPosX - 1] == 0) {
			printf("a(A): ����, ");
		}
		if (Maze[PlayerPosY][PlayerPosX + 1] == 0) {
			printf("d(D): ������ ");
		}

		printf("\n�̵� ������ �Է��ϼ���.\n");
		std::cin >> PlayerMove;
		isBattle = rand() % 10;

		//�� �Ǵ� ���� ������ ��ǥ�̵�
		if (PlayerMove == 'W' || PlayerMove == 'w') {
			if (Maze[PlayerPosY - 1][PlayerPosX] == 1) {
				printf("�̵��Ҽ� �����ϴ�.\n");
			}
			else {
				Maze[PlayerPosY][PlayerPosX] = 0;
				PlayerPosY -= 1;
			}
		}
		else if (PlayerMove == 'S' || PlayerMove == 's') {
			if (Maze[PlayerPosY + 1][PlayerPosX] == 1) {
				printf("�̵��Ҽ� �����ϴ�.\n");
			}
			else {
				Maze[PlayerPosY][PlayerPosX] = 0;
				PlayerPosY += 1;
			}
		}
		else if (PlayerMove == 'A' || PlayerMove == 'a') {
			if (Maze[PlayerPosY][PlayerPosX - 1] == 1) {
				printf("�̵��Ҽ� �����ϴ�.\n");
			}
			else {
				Maze[PlayerPosY][PlayerPosX] = 0;
				PlayerPosX -= 1;
			}
		}
		else if (PlayerMove == 'D' || PlayerMove == 'd') {
			if (Maze[PlayerPosY][PlayerPosX + 1] == 1) {
				printf("�̵��Ҽ� �����ϴ�.\n");
			}
			else {
				Maze[PlayerPosY][PlayerPosX] = 0;
				PlayerPosX += 1;
			}
		}
		else {
			printf("�ٸ�Ű�� �Է��Ͽ����ϴ�.\n");
		}
		//�̵��� ��ǥ�� �÷��̾� �̵�
		Maze[PlayerPosY][PlayerPosX] = 4; //4 �� �÷��̾�
	}


	//������ �̷θ�� ����Ʈ
	for (int i = 0; i < MazeHeight; i++) {
		for (int j = 0; j < MazeWidth; j++) {
			if (Maze[i][j] == 1) {
				printf("# ");
			}
			else if (Maze[i][j] == 0) {
				printf(". ");
			}
			else if (Maze[i][j] == 2) {
				printf("S ");
			}
			else if (Maze[i][j] == 3) {
				printf("E ");
			}
			else if (Maze[i][j] == 4) {
				printf("P ");
			}
			else {
				printf("@ ");
			}
		}
		printf("\n");
	}
	printf("�ⱸ�� �����Ͽ����ϴ�.\n");
}

void Battle(int PlayerHp,int EnemyHp)
{
	srand(time(0));
	int PlayerHealth = PlayerHp;
	int EnemyHealth = EnemyHp;
	int PlayerDamage;
	int EnemyDamage;
	int PlayercritRate; // 0~9���� ������ 10���� ���� �� 5�� 1/10
	int EnemycritRate; // 0~9���� ������ 10���� ���� �� 5�� 1/10
	printf("���� ���� ������ �����մϴ�.\n");
	printf("���� ���� ü�� : %d\n", PlayerHealth);
	printf("���� ���� ü�� : %d\n", EnemyHealth);

	printf("������ �����մϴ�. ���͸� ������ ����.\n");
	getchar();

		PlayerDamage = rand() % 11 + 5;
		EnemyDamage = rand() % 11 + 5;
		PlayercritRate = rand() % 10;
		EnemycritRate = rand() % 10;



		//�÷��̾� ũ��Ƽ�� �߻� ����
		if (PlayercritRate == 5) {
			PlayerDamage *= 2;
			printf("ũ��Ƽ���� �߻��Ͽ����ϴ� : �÷��̾�\n");
		}


		// ü���� ������ �������°� ����
		EnemyHealth -= PlayerDamage;
		if (EnemyHealth <= 0) {
			EnemyHealth = 0;
		}
		printf("�� ���� %d �� �������� �־����ϴ�.\n", PlayerDamage);
		printf("���� ���� HP : %d\n�÷��̾� ���� HP : %d\n", EnemyHealth, PlayerHealth);
		printf("����Ϸ��� ����\n");
		getchar();

		if (PlayerHealth <= 0) {
			printf("�÷��̾ �й��߽��ϴ�.\n");		
		}
		else if (EnemyHealth <= 0) {
			printf("�÷��̾ �¸��߽��ϴ�.\n");	
		}


		//�� ũ��Ƽ�� �߻� ����
		if (EnemycritRate == 5) {
			EnemyDamage *= 2;
			printf("ũ��Ƽ���� �߻��Ͽ����ϴ� : �÷��̾�\n");
		}

		// ü���� ������ �������°� ����
		PlayerHealth -= EnemyDamage;
		if (PlayerHealth <= 0) {
			PlayerHealth = 0;
		}
		printf("�÷��̾ %d �� �������� �޾ҽ��ϴ�.\n", EnemyDamage);
		printf("���� ���� HP : %d\n�÷��̾� ���� HP : %d\n", EnemyHealth, PlayerHealth);
		printf("����Ϸ��� ����\n");
		getchar();

		if (PlayerHealth <= 0) {
			printf("�÷��̾ �й��߽��ϴ�.\n");
		
		}
		else if (EnemyHealth <= 0) {
			printf("�÷��̾ �¸��߽��ϴ�.\n");
		
		}


		PlayerHealthPoint = PlayerHealth;
		EnemyHealthPoint = EnemyHealth;

}

void Miro3()
{
	enum List
	{
		Road,
		Wall,
		Player,
		End,
		Start
	};

	srand(time(0));

	const int MazeHeight = 10;
	const int MazeWidth = 20;

	int StartPosX = rand() % 20;
	int StartPosY = rand() % 10;

	bool isTop = false;
	bool isBottom = false;
	bool isRight = false;
	bool isLeft = false;

	int Maze[MazeHeight][MazeWidth] = { 1 };

	Maze[StartPosY][StartPosX] = 4; // ������ ����


	if (StartPosX > 0 || StartPosX < MazeWidth) {
		if ((Maze[StartPosX - 1][StartPosX] == 1)) {
			isTop = true;
		}
		else isTop = false;

		if ((Maze[StartPosX + 1][StartPosX] == 1)) {
			isBottom = true;
		}
		else isBottom = false;
	}
	

	if (StartPosY > 0 || StartPosY < MazeHeight) {
		if ((Maze[StartPosY + 1][StartPosX] == 1)) {
			isBottom = true;
		}
		else isBottom = false;

		if ((Maze[StartPosY + 1][StartPosX] == 1)) {
			isBottom = true;
		}
		else isBottom = false;
	}
}





//1. �������� �� ���� �����մϴ�.
//
//2. ���õ� ��ġ����, ������ ��(��, ��, ��, ��)�� �����ϰ� Ž���մϴ�.
//
//3. Ž���� ���� ���� ���� �����ٸ� �հ� �� ��ҷ� �̵��մϴ�.
//
//4. ������ ���� �̵��� ���� ���ٸ�, ���� ��ġ�� ���� ���ϴ�.
//
//5. �� ������ �ݺ��Ͽ� ��� ��Ҹ� �湮�ϸ� �̷ΰ� �ϼ� �˴ϴ�.