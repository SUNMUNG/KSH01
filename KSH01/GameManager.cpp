#define _CRT_SECURE_NO_WARNINGS
#include "GameManager.h"
#include <stdio.h>
#include <iostream>
#include <fstream>
#include <string>
#include "Player.h"
#include "Monster.h"
#include "Zombie.h"
#include "Skeleton.h"
#include "Goblin.h"
#include "Oak.h"


void GameManager::InitializeMaze()
{
	std::string Data;
	ReadMapFile("MapData.txt", Data);
	ParseMapData(Data);
}

bool GameManager::ReadMapFile(const char* MapFileName, std::string& OutDataRef)
{
	char FilePath[256];
	strcpy(FilePath, DirName);
	strcat(FilePath, MapFileName);

	std::ifstream InputFile(FilePath);
	if (!InputFile.is_open()) {
		printf("파일을 열수 없습니다.\n");
		printf("[%s] 경로를 확인하세요..\n", FilePath);
		return false;
	}

	std::string DataRef(
		(std::istreambuf_iterator<char>(InputFile)),
		std::istreambuf_iterator<char>());
	OutDataRef = DataRef;
	return true;
}

bool GameManager::ParseMapData(std::string& DataString)
{
	char Source[512];
	char* Current = Source;

	strcpy(Source, DataString.c_str());

	//라인분리 \n
	//첫째줄처리
	char* Lineptr = NextLine(&Current);
	int SizeNumbers[2] = { 0 };
	//라인파싱하기
	Parselinedata(Lineptr, 2, SizeNumbers);

	MazeWidth = SizeNumbers[0];
	MazeHeight = SizeNumbers[1];


	Maze = new int* [MazeHeight];
	for (int i = 0; i < MazeHeight; i++) {
		Maze[i] = new int[MazeWidth];
	}


	int HeightIndex = 0;
	while ((*Current) != '\0')
	{
		Lineptr = NextLine(&Current);
		Parselinedata(Lineptr, MazeWidth, Maze[HeightIndex]);
		HeightIndex++;

		if (HeightIndex >= MazeHeight) {
			break;
		}
	}

	return true;
}

char* GameManager::NextLine(char** Source)
{
	char* Result = (*Source);
	int Index = FindCharIndex((*Source), '\n');
	if (Index == -1) {
		(*Source) += FindCharIndex(*(Source), '\0');
	}
	else {
		*((*Source) + Index) = '\0';
		(*Source) += Index + 1;
	}


	return Result;
}

int GameManager::FindCharIndex(const char* TargetString, const char TargetCharacter)
{
	int Index = 0;
	bool IsFind = false;
	while (TargetString[Index] != '\0')
	{
		if (TargetString[Index] == TargetCharacter)
		{
			IsFind = true;
			break;
		}
		Index++;
	}

	if (!IsFind)
	{
		Index = -1;
	}
	return Index;
}

void GameManager::Parselinedata(const char* linedata, int Arraysize, int* outArray)
{
	//라인쪼개기 ,
	const char* LinePointer = linedata;
	int SizeIndex = 0;
	while ((*LinePointer) != '\0')
	{
		int Result = 0;
		while ((*LinePointer) != ',' && (*LinePointer) != '\0')
		{
			Result = Result * 10 + (*LinePointer) - '0';
			LinePointer++;
		}
		outArray[SizeIndex] = Result;
		SizeIndex++;

		if (Arraysize <= SizeIndex)
			break;

		if (*LinePointer < '0' || *LinePointer > '9') {
			LinePointer++;
		}
	}
}

void GameManager::PrintMaze(int PlayerX, int PlayerY)
{
	for (int y = 0; y < MazeHeight; y++)
	{
		for (int x = 0; x < MazeWidth; x++)
		{
			if (PlayerX == x && PlayerY == y)
			{
				printf("P ");
			}
			else if (Maze[y][x] == 1)
			{
				printf("# ");
			}
			else if (Maze[y][x] == 0)
			{
				printf(". ");
			}
			else if (Maze[y][x] == 2)
			{
				printf("S ");
			}
			else if (Maze[y][x] == 3)
			{
				printf("E ");
			}
			else
			{
				// 절대 들어오면 안되는 곳 == 맵 데이터가 잘못된 것
			}
		}
		printf("\n");
	}
}

void GameManager::Battle(Player* player)
{
	srand(time(0));
	int RandMob = rand() % 4;
	Monster* monster[4];

	monster[0] = new Zombie("좀비", 30, 10);
	monster[1] = new Skeleton("스켈레톤", 20, 15);
	monster[2] = new Oak("오크", 30, 7);
	monster[3] = new Goblin("고블린", 15, 10);

	int PlayercritRate; // 0~9까지 굴려서 10개의 숫자 중 5면 1/10
	int EnemycritRate; // 0~9까지 굴려서 10개의 숫자 중 5면 1/10
	printf("턴제 전투 게임을 시작합니다.\n");
	printf("%s 이(가)나타났습니다.\n", monster[RandMob]->GetName().c_str());
	while (player->GetHP() > 0 && monster[RandMob]->GetHP() > 0) {
		printf("현재 나의 체력 : %d\n", player->GetHP());
		printf("현재 적의 체력 : %d\n", monster[RandMob]->GetHP());

		printf("전투를 시작합니다. 엔터를 누르면 시작.\n");
		getchar();
		player->AttackDamage(monster[RandMob]);

		/*if (monster[RandMob]->GetHP() <= 0) {
			printf("%s이(가) 사망했습니다\n", monster[RandMob]->GetName().c_str());
			player->SetPlayerCoin(monster[RandMob]->GetMonsterCoin());
			printf("현재 보유한 코인 : %d\n", player->GetCoin());
			break;
		}
		monster[RandMob]->AttackDamage(player);
		getchar();

		if (player->GetHP() <= 0) {
			printf("%s가 사망했습니다\n", player->GetName().c_str());
			break;
		}*/

	}

	for (int i = 0; i < 4; i++) {
		delete monster[i];
		monster[i] = nullptr;
	}
}


void GameManager::MazeEscape()
{
	// 미로 크기
	//Player player; 
	Player player = Player("플레이어", 100, 20);
	const int MazeHeight = 10;
	const int MazeWidth = 20;
	int PlayerPosX = 1;
	int PlayerPosY = 1;
	int EndPosX = 18;
	int EndPosY = 7;
	char PlayerMove;
	int isBattle = -1;


	//현재상황 미로 출력
	while (Maze[player.GetPlayerYPos()][player.GetPlayerXPos()] != Maze[EndPosY][EndPosX]) {

		isBattle = rand() % 10;
		PrintMaze(player.GetPlayerXPos(), player.GetPlayerYPos());

		//이동가능 방향 출력
		printf("w(W): 위, s(S): 아래, a(A): 왼쪽, d(D): 오른쪽\n");
		printf("이동 가능한 방향 : ");
		if (Maze[player.GetPlayerYPos() + 1][player.GetPlayerXPos()] == 0) {
			printf("s(S): 아래, ");
		}
		if (Maze[player.GetPlayerYPos() - 1][player.GetPlayerXPos()] == 0) {
			printf("w(W): 위, ");
		}
		if (Maze[player.GetPlayerYPos()][player.GetPlayerXPos() - 1] == 0) {
			printf("a(A): 왼쪽, ");
		}
		if (Maze[player.GetPlayerYPos()][player.GetPlayerXPos() + 1] == 0) {
			printf("d(D): 오른쪽 ");
		}

		printf("\n이동 방향을 입력하세요.\n");
		std::cin >> PlayerMove;

		//벽 판단 로직 없으면 좌표이동
		if (PlayerMove == 'W' || PlayerMove == 'w') {
			if (Maze[player.GetPlayerYPos() - 1][player.GetPlayerXPos()] == 1) {
				printf("이동할수 없습니다.\n");
			}
			else {
				Maze[player.GetPlayerYPos()][player.GetPlayerXPos()] = 0;
				player.SetPlayerPosXY(0, -1);
				//player.Ypos -= 1;
			}
		}
		else if (PlayerMove == 'S' || PlayerMove == 's') {
			if (Maze[player.GetPlayerYPos() + 1][player.GetPlayerXPos()] == 1) {
				printf("이동할수 없습니다.\n");
			}
			else {
				Maze[player.GetPlayerYPos()][player.GetPlayerXPos()] = 0;
				player.SetPlayerPosXY(0, +1);
				//player.Ypos += 1;
			}
		}
		else if (PlayerMove == 'A' || PlayerMove == 'a') {
			if (Maze[player.GetPlayerYPos()][player.GetPlayerXPos() - 1] == 1) {
				printf("이동할수 없습니다.\n");
			}
			else {
				Maze[player.GetPlayerYPos()][player.GetPlayerXPos()] = 0;
				player.SetPlayerPosXY(-1, 0);
				//player.Xpos -= 1;
			}
		}
		else if (PlayerMove == 'D' || PlayerMove == 'd') {
			if (Maze[player.GetPlayerYPos()][player.GetPlayerXPos() + 1] == 1) {
				printf("이동할수 없습니다.\n");
			}
			else {
				Maze[player.GetPlayerYPos()][player.GetPlayerXPos()] = 0;
				player.SetPlayerPosXY(+1, 0);
				//player.Xpos += 1;
			}
		}
		else {
			printf("다른키를 입력하였습니다.\n");
		}
		//이동한 좌표로 플레이어 이동
		Maze[player.GetPlayerYPos()][player.GetPlayerXPos()] = 4;

		if (player.GetCoin() > 100) {
			printf("100코인을 사용하여 회복하시겠습니까?\n1.Y 2.N\n");
			int PlayerSelect;
			std::cin >> PlayerSelect;
			if (PlayerSelect > 2 || PlayerSelect <= 0) {
				PlayerSelect = 2;
			}
			switch (PlayerSelect) {
			case 1:
				printf("보유한 보상을 사용하여 체력을 회복했습니다. +10\n");
				player.SetPlayerHealth(10);
				printf("현재 HP : %d\n", player.GetPlayerHP());
				player.SetPlayerCoin(-100);
				break;
			case 2:printf("계속합니다.\n");
				break;
			default:
				break;

			}


		}
		//4 가 플레이어

		if (isBattle == 5 || isBattle == 3) {
			Battle(&player);
		}
		printf("플레이어 현재 체력 : %d\n", player.GetHP());
		if (player.GetHP() <= 0) {
			printf("플레이어가 사망했습니다.\n");
			return;
		}

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

void GameManager::ClearMaze()
{
	if (Maze != nullptr) {
		for (int i = 0; i < MazeHeight; i++) {
			delete[] Maze[i];
			Maze[i] = nullptr;
		}
		delete[] Maze;
		Maze = nullptr;
	}
}


