#include "practice_0908.h"
#include <stdio.h>
#include <cstring>
#include <random>
#include <string>
#include <iostream>
#include <limits.h>

void practice09081()
{
	int array1[5] = {0,1,2,3,4};

	printf("%d %d %d %d %d\n", array1[0], array1[1], array1[2], array1[3], array1[4]);
}

void practice09082()
{
	int array[5];
	int sum = 0;
	float avg = 0;
	printf("���� �Է��ϼ��� ũ��: 5\n");
	for (int i = 0; i < sizeof(array) / sizeof(int); i++) {
		std::cin >> array[i];
		sum += array[i];
	}
	avg = static_cast<float>(sum) / (sizeof(array) / sizeof(int));

	printf("�Էµ� ������ ����� : %.2f\n",avg);
	
	

}

void practice09083()
{
	int array[5];
	int Max = INT_MIN;
	int Min = INT_MAX;
	printf("���� �Է��ϼ��� ũ��: 5\n");
	for (int i = 0; i < sizeof(array) / sizeof(int); i++) {
		std::cin >> array[i];
	}

	for (int i = 0; i < (sizeof(array) / sizeof(int)); i++) {

		if (Max < array[i]) {
			Max = array[i];
		}
	}

	for (int i = 0; i < (sizeof(array) / sizeof(int)); i++) {
		
		if (Min > array[i]) {
			Min = array[i];
		}
	}
	printf("�ִ밪�� : %d\n�ּҰ��� : %d\n", Max,Min);
}

void practice09084()
{

	int array[5] = {1,2,3,4,5};
	Shuffle(array,5);
}

void Shuffle(int array[],int length)
{
	srand(time(0));

	for (int i = length - 1; i > 0; i--) {
		int j = rand() % (i + 1);
		int tmp;
		tmp = array[i];
		array[i] = array[j];
		array[j] = tmp;
	}	
}
void TestRef(int& data) {
	data *= 2;
}

void practice09085()
{ 
	int num=10;
	int& Ref = num;

	TestRef(num);
}


//6��ü �ֻ����� 100���� ������ �� ���� ���� ��� ���Դ��� ī�����ϱ�
//6��ü �ֻ����� ������ �Լ� �����

void practice09086()
{
	srand(time(0));
	RollDice1();
}

void RollDice1()
{
	int Count1 = 0;
	int Count2 = 0;
	int Count3 = 0;
	int Count4 = 0;
	int Count5 = 0;
	int Count6 = 0;

	for (int i = 0; i < 1000000; i++) {
		int Dice = rand() % 6 + 1;

		if (Dice == 1) {
			Count1++;
		}
		else if (Dice == 2) {
			Count2++;
		}
		else if (Dice == 3) {
			Count3++;
		}
		else if (Dice == 4) {
			Count4++;
		}
		else if (Dice == 5) {
			Count5++;
		}
		else {
			Count6++;
		}
	}
	

	printf("1 : %d 2: %d 3: %d\n", Count1, Count2, Count3);
	printf("4 : %d 5: %d 6: %d\n", Count4, Count5, Count6);
}

//�迭�� ����� ���� �Ųٷ� ������ �Լ� �����
//�Ķ���� int Array[], int Size

void practice09087()
{
	srand(time(0));
	int Array[5] = {1,2,3,4,5};

	ReverseArray(Array, 5);
}
void ReverseArray(int Array[], int length)
{
	for (int i = 0; i < length / 2; i++) {
		int tmp;
		tmp = Array[i];
		Array[i] = Array[length - i-1];
		Array[length - i-1]=tmp;
	}

	for (int i = 0; i < length; i++) {
		printf("%d ",Array[i]);
	}
}

//�ζ� ��ȣ ������
//��ü ���� ���� : 1������ 45������.
//����� �ϴ� ���� ���� : 6��.

void practice09088()
{
	srand(time(0));
	int LottoNumber[45];

	for (int i = 0; i < 45; i++) {
		LottoNumber[i] = i + 1;
	}

	Shuffle1(LottoNumber, 46);

}

void Shuffle1(int LottoNumber[], int length)
{
	int LottoSelectNumber[6];
	int PlayerNumber[6];

	for (int i = length - 1; i > 0; i--) {
		int j = rand() % (i + 1);
		int tmp;
		tmp = LottoNumber[i];
		LottoNumber[i] = LottoNumber[j];
		LottoNumber[j] = tmp;
	}

	for (int i = 0; i < length; i++) {
		LottoSelectNumber[i]=LottoNumber[i];
	}
	printf("�ζ� ��ȣ�� �����Ǿ����ϴ�.\n");
	printf("6���� ���ڸ� �Է����ּ���.\n");
	for (int i = 0; i < length; i++) {
		std::cin >> PlayerNumber[i];
	}

	for (int i = 0; i < length; i++) {

		if (PlayerNumber[i] == LottoSelectNumber[i]) {
			printf("%d��° ���ڰ� ��ġ�մϴ�.\n",i+1);
		}
		else {
			printf("%d��° ���ڰ� ����ġ�մϴ�.\n",i + 1);
		}
	}
	
	
}
//2���� �迭�� Ȱ���Ͽ� �ؽ�Ʈ ��� �̷� Ż�� ������ ����.
//�̷��� ����
//10�� 20���� 2���� �迭
//���� ���
//��(0) : '. '���� ǥ��
//��(1) : '# '���� ǥ��
//������(2) : 'S '�� ǥ��
//�ⱸ(3) : 'E '�� ǥ��
void practice09089()
{
	Miro();
}

void Miro()
{
	// �̷� ũ��
	const int MazeHeight = 10;
	const int MazeWidth = 20;
	int PlayerPosX = 1;
	int PlayerPosY = 1;
	int EndPosX = 18;
	int EndPosY = 7;
	char PlayerMove;
	

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

		//�̵����� ���� ���
		printf("w(W): ��, s(S): �Ʒ�, a(A): ����, d(D): ������\n");
		printf("�̵� ������ ���� : ");
		if (Maze[PlayerPosY	+1][PlayerPosX] == 0) {
			printf("s(S): �Ʒ�, ");
		}
		if(Maze[PlayerPosY -1][PlayerPosX] == 0){
			printf("w(W): ��, ");
		}
		if (Maze[PlayerPosY][PlayerPosX-1] == 0) {
			printf("a(A): ����, ");
		}
		if (Maze[PlayerPosY][PlayerPosX+1] == 0) {
			printf("d(D): ������ ");
		}
		
		printf("\n�̵� ������ �Է��ϼ���.\n");
		std::cin >> PlayerMove;

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
			if (Maze[PlayerPosY +1][PlayerPosX] == 1) {
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