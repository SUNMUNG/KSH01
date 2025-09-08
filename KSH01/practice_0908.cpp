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
	printf("값을 입력하세요 크기: 5\n");
	for (int i = 0; i < sizeof(array) / sizeof(int); i++) {
		std::cin >> array[i];
		sum += array[i];
	}
	avg = static_cast<float>(sum) / (sizeof(array) / sizeof(int));

	printf("입력된 값들의 평균은 : %.2f\n",avg);
	
	

}

void practice09083()
{
	int array[5];
	int Max = INT_MIN;
	int Min = INT_MAX;
	printf("값을 입력하세요 크기: 5\n");
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
	printf("최대값은 : %d\n최소값은 : %d\n", Max,Min);
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


//6면체 주사위를 100만번 던져서 각 눈의 수가 몇번 나왔는지 카운팅하기
//6면체 주사위를 돌리는 함수 만들기

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

//배열에 저장된 값을 거꾸로 뒤집는 함수 만들기
//파라메터 int Array[], int Size

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

//로또 번호 생성기
//전체 숫자 범위 : 1번부터 45번까지.
//맞춰야 하는 숫자 개수 : 6개.

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
	printf("로또 번호가 생성되었습니다.\n");
	printf("6개의 숫자를 입력해주세요.\n");
	for (int i = 0; i < length; i++) {
		std::cin >> PlayerNumber[i];
	}

	for (int i = 0; i < length; i++) {

		if (PlayerNumber[i] == LottoSelectNumber[i]) {
			printf("%d번째 숫자가 일치합니다.\n",i+1);
		}
		else {
			printf("%d번째 숫자가 불일치합니다.\n",i + 1);
		}
	}
	
	
}
//2차원 배열을 활용하여 텍스트 기반 미로 탈출 게임을 구현.
//미로의 구성
//10행 20열의 2차원 배열
//저장 방식
//길(0) : '. '으로 표시
//벽(1) : '# '으로 표시
//시작점(2) : 'S '로 표시
//출구(3) : 'E '로 표시
void practice09089()
{
	Miro();
}

void Miro()
{
	// 미로 크기
	const int MazeHeight = 10;
	const int MazeWidth = 20;
	int PlayerPosX = 1;
	int PlayerPosY = 1;
	int EndPosX = 18;
	int EndPosY = 7;
	char PlayerMove;
	

	// 미로 배열
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

	
	//현재상황 미로 출력
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

		//이동가능 방향 출력
		printf("w(W): 위, s(S): 아래, a(A): 왼쪽, d(D): 오른쪽\n");
		printf("이동 가능한 방향 : ");
		if (Maze[PlayerPosY	+1][PlayerPosX] == 0) {
			printf("s(S): 아래, ");
		}
		if(Maze[PlayerPosY -1][PlayerPosX] == 0){
			printf("w(W): 위, ");
		}
		if (Maze[PlayerPosY][PlayerPosX-1] == 0) {
			printf("a(A): 왼쪽, ");
		}
		if (Maze[PlayerPosY][PlayerPosX+1] == 0) {
			printf("d(D): 오른쪽 ");
		}
		
		printf("\n이동 방향을 입력하세요.\n");
		std::cin >> PlayerMove;

		//벽 판단 로직 없으면 좌표이동
		if (PlayerMove == 'W' || PlayerMove == 'w') {
			if (Maze[PlayerPosY - 1][PlayerPosX] == 1) {
				printf("이동할수 없습니다.\n");
			}
			else {
				Maze[PlayerPosY][PlayerPosX] = 0;
				PlayerPosY -= 1;
			}
		}
		else if (PlayerMove == 'S' || PlayerMove == 's') {
			if (Maze[PlayerPosY +1][PlayerPosX] == 1) {
				printf("이동할수 없습니다.\n");
			}
			else {
				Maze[PlayerPosY][PlayerPosX] = 0;
				PlayerPosY += 1;
			}
		}
		else if (PlayerMove == 'A' || PlayerMove == 'a') {
			if (Maze[PlayerPosY][PlayerPosX - 1] == 1) {
				printf("이동할수 없습니다.\n");
			}
			else {
				Maze[PlayerPosY][PlayerPosX] = 0;
				PlayerPosX -= 1;
			}
		}
		else if (PlayerMove == 'D' || PlayerMove == 'd') {
			if (Maze[PlayerPosY][PlayerPosX + 1] == 1) {
				printf("이동할수 없습니다.\n");
			}
			else {
				Maze[PlayerPosY][PlayerPosX] = 0;
				PlayerPosX += 1;
			}
		}
		else {
			printf("다른키를 입력하였습니다.\n");
		}
		//이동한 좌표로 플레이어 이동
		Maze[PlayerPosY][PlayerPosX] = 4; //4 가 플레이어
	}


	//마지막 미로모양 프린트
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
	printf("출구에 도착하였습니다.\n");
}