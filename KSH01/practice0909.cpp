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
				printf("수를 입력하세요 : \n");
				std::cin >> num;
				*(Array + i) = num;
				CurrentSize++;
			}	
		}
		while (num != 0) {
			printf("더 입력하고싶으면 1을 입력하세요 아니면 0을 입력하세요: \n");
			std::cin >> num;
			switch (num) {
			case 1:
				printf("수를 입력하세요 : \n");
				std::cin >> num;
				if (isTrue == true) {
					//초기화
					delete[] Array2;
					Array2 = nullptr;
					//배열크기 +1
					CurrentSize++;
					Array2 = new int[CurrentSize];

					//복사작업
					for (int i = 0; i < CurrentSize - 1; i++) {
						Array2[i] = Array[i];
					}
					//새로운값 
					Array2[CurrentSize - 1] = num;
					//필요없는 배열초기화
					delete[] Array;
					Array = nullptr;
					isTrue = false;
				}
				else if (isTrue == false) {
					//초기화
					delete[] Array;
					Array = nullptr;
					//배열크기 +1
					CurrentSize++;
					Array = new int[CurrentSize];

					//복사작업
					for (int i = 0; i < CurrentSize - 1; i++) {
						Array[i] = Array2[i];
					}
					//새로운값 
					Array[CurrentSize - 1] = num;
					//필요없는 배열초기화
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
	
	printf("가로와 세로를 입력해주세요 : \n");
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
	    //3번

		srand(time(0));
		int player_num=-1;
		int com_num = rand() % 100 + 1;
		int PlayerPushNum[5] = { 0 };
		int count = 5;


		while (count > 0) {
			printf("생각하는 숫자를 입력하세요 : ");
			std::cin >> player_num;
			PlayerPushNum[5 - count]= player_num;

			if (player_num == com_num) {
				printf("정답입니다");
				break;
			}
			else if (player_num > com_num) {
				printf("더 낮게\n");
				count--;
				printf("기회가 %d번 남았습니다.\n",count);
			}
			else if (player_num < com_num) {
				printf("더 높게\n");
				count--;
				printf("기회가 %d번 남았습니다.\n",count);
			}
			else {
				printf("오류입니다.\n");
			}
		}
		printf("기회가 소진되었습니다.\n");
		printf("맞춰야하는 수는 : %d 였습니다.\n",com_num);
		printf("플레이어가 입력한수 : ");
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
	// 미로 크기
	
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
		//20%확률로 전투
		if ((isBattle == 5) ||(isBattle == 9) ) {
			Battle(PlayerHealthPoint, EnemyHealthPoint);
		}
		else if (isBattle == 3) {
			PlayerHealthPoint += 100;
		}

		//이동가능 방향 출력
		printf("w(W): 위, s(S): 아래, a(A): 왼쪽, d(D): 오른쪽\n");
		printf("이동 가능한 방향 : ");
		if (Maze[PlayerPosY + 1][PlayerPosX] == 0) {
			printf("s(S): 아래, ");
		}
		if (Maze[PlayerPosY - 1][PlayerPosX] == 0) {
			printf("w(W): 위, ");
		}
		if (Maze[PlayerPosY][PlayerPosX - 1] == 0) {
			printf("a(A): 왼쪽, ");
		}
		if (Maze[PlayerPosY][PlayerPosX + 1] == 0) {
			printf("d(D): 오른쪽 ");
		}

		printf("\n이동 방향을 입력하세요.\n");
		std::cin >> PlayerMove;
		isBattle = rand() % 10;

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
			if (Maze[PlayerPosY + 1][PlayerPosX] == 1) {
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

void Battle(int PlayerHp,int EnemyHp)
{
	srand(time(0));
	int PlayerHealth = PlayerHp;
	int EnemyHealth = EnemyHp;
	int PlayerDamage;
	int EnemyDamage;
	int PlayercritRate; // 0~9까지 굴려서 10개의 숫자 중 5면 1/10
	int EnemycritRate; // 0~9까지 굴려서 10개의 숫자 중 5면 1/10
	printf("턴제 전투 게임을 시작합니다.\n");
	printf("현재 나의 체력 : %d\n", PlayerHealth);
	printf("현재 적의 체력 : %d\n", EnemyHealth);

	printf("전투를 시작합니다. 엔터를 누르면 시작.\n");
	getchar();

		PlayerDamage = rand() % 11 + 5;
		EnemyDamage = rand() % 11 + 5;
		PlayercritRate = rand() % 10;
		EnemycritRate = rand() % 10;



		//플레이어 크리티컬 발생 유무
		if (PlayercritRate == 5) {
			PlayerDamage *= 2;
			printf("크리티컬이 발생하였습니다 : 플레이어\n");
		}


		// 체력이 음수로 떨어지는것 조정
		EnemyHealth -= PlayerDamage;
		if (EnemyHealth <= 0) {
			EnemyHealth = 0;
		}
		printf("적 에게 %d 의 데미지를 주었습니다.\n", PlayerDamage);
		printf("적의 남은 HP : %d\n플레이어 남은 HP : %d\n", EnemyHealth, PlayerHealth);
		printf("계속하려면 엔터\n");
		getchar();

		if (PlayerHealth <= 0) {
			printf("플레이어가 패배했습니다.\n");		
		}
		else if (EnemyHealth <= 0) {
			printf("플레이어가 승리했습니다.\n");	
		}


		//적 크리티컬 발생 유무
		if (EnemycritRate == 5) {
			EnemyDamage *= 2;
			printf("크리티컬이 발생하였습니다 : 플레이어\n");
		}

		// 체력이 음수로 떨어지는것 조정
		PlayerHealth -= EnemyDamage;
		if (PlayerHealth <= 0) {
			PlayerHealth = 0;
		}
		printf("플레이어가 %d 의 데미지를 받았습니다.\n", EnemyDamage);
		printf("적의 남은 HP : %d\n플레이어 남은 HP : %d\n", EnemyHealth, PlayerHealth);
		printf("계속하려면 엔터\n");
		getchar();

		if (PlayerHealth <= 0) {
			printf("플레이어가 패배했습니다.\n");
		
		}
		else if (EnemyHealth <= 0) {
			printf("플레이어가 승리했습니다.\n");
		
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

	Maze[StartPosY][StartPosX] = 4; // 시작점 랜덤


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





//1. 무작위로 한 곳을 선택합니다.
//
//2. 선택된 위치에서, 인접한 곳(상, 하, 좌, 우)을 랜덤하게 탐색합니다.
//
//3. 탐색한 곳의 벽이 전부 막혔다면 뚫고 그 장소로 이동합니다.
//
//4. 인접한 곳에 이동할 곳이 없다면, 이전 위치로 돌아 갑니다.
//
//5. 위 내용을 반복하여 모든 장소를 방문하면 미로가 완성 됩니다.