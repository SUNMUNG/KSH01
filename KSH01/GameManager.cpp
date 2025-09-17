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
		printf("������ ���� �����ϴ�.\n");
		printf("[%s] ��θ� Ȯ���ϼ���..\n", FilePath);
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

	//���κи� \n
	//ù°��ó��
	char* Lineptr = NextLine(&Current);
	int SizeNumbers[2] = { 0 };
	//�����Ľ��ϱ�
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
	//�����ɰ��� ,
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
				// ���� ������ �ȵǴ� �� == �� �����Ͱ� �߸��� ��
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

	monster[0] = new Zombie("����", 30, 10);
	monster[1] = new Skeleton("���̷���", 20, 15);
	monster[2] = new Oak("��ũ", 30, 7);
	monster[3] = new Goblin("���", 15, 10);

	int PlayercritRate; // 0~9���� ������ 10���� ���� �� 5�� 1/10
	int EnemycritRate; // 0~9���� ������ 10���� ���� �� 5�� 1/10
	printf("���� ���� ������ �����մϴ�.\n");
	printf("%s ��(��)��Ÿ�����ϴ�.\n", monster[RandMob]->GetName().c_str());
	while (player->GetHP() > 0 && monster[RandMob]->GetHP() > 0) {
		printf("���� ���� ü�� : %d\n", player->GetHP());
		printf("���� ���� ü�� : %d\n", monster[RandMob]->GetHP());

		printf("������ �����մϴ�. ���͸� ������ ����.\n");
		getchar();
		player->AttackDamage(monster[RandMob]);

		/*if (monster[RandMob]->GetHP() <= 0) {
			printf("%s��(��) ����߽��ϴ�\n", monster[RandMob]->GetName().c_str());
			player->SetPlayerCoin(monster[RandMob]->GetMonsterCoin());
			printf("���� ������ ���� : %d\n", player->GetCoin());
			break;
		}
		monster[RandMob]->AttackDamage(player);
		getchar();

		if (player->GetHP() <= 0) {
			printf("%s�� ����߽��ϴ�\n", player->GetName().c_str());
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
	// �̷� ũ��
	//Player player; 
	Player player = Player("�÷��̾�", 100, 20);
	const int MazeHeight = 10;
	const int MazeWidth = 20;
	int PlayerPosX = 1;
	int PlayerPosY = 1;
	int EndPosX = 18;
	int EndPosY = 7;
	char PlayerMove;
	int isBattle = -1;


	//�����Ȳ �̷� ���
	while (Maze[player.GetPlayerYPos()][player.GetPlayerXPos()] != Maze[EndPosY][EndPosX]) {

		isBattle = rand() % 10;
		PrintMaze(player.GetPlayerXPos(), player.GetPlayerYPos());

		//�̵����� ���� ���
		printf("w(W): ��, s(S): �Ʒ�, a(A): ����, d(D): ������\n");
		printf("�̵� ������ ���� : ");
		if (Maze[player.GetPlayerYPos() + 1][player.GetPlayerXPos()] == 0) {
			printf("s(S): �Ʒ�, ");
		}
		if (Maze[player.GetPlayerYPos() - 1][player.GetPlayerXPos()] == 0) {
			printf("w(W): ��, ");
		}
		if (Maze[player.GetPlayerYPos()][player.GetPlayerXPos() - 1] == 0) {
			printf("a(A): ����, ");
		}
		if (Maze[player.GetPlayerYPos()][player.GetPlayerXPos() + 1] == 0) {
			printf("d(D): ������ ");
		}

		printf("\n�̵� ������ �Է��ϼ���.\n");
		std::cin >> PlayerMove;

		//�� �Ǵ� ���� ������ ��ǥ�̵�
		if (PlayerMove == 'W' || PlayerMove == 'w') {
			if (Maze[player.GetPlayerYPos() - 1][player.GetPlayerXPos()] == 1) {
				printf("�̵��Ҽ� �����ϴ�.\n");
			}
			else {
				Maze[player.GetPlayerYPos()][player.GetPlayerXPos()] = 0;
				player.SetPlayerPosXY(0, -1);
				//player.Ypos -= 1;
			}
		}
		else if (PlayerMove == 'S' || PlayerMove == 's') {
			if (Maze[player.GetPlayerYPos() + 1][player.GetPlayerXPos()] == 1) {
				printf("�̵��Ҽ� �����ϴ�.\n");
			}
			else {
				Maze[player.GetPlayerYPos()][player.GetPlayerXPos()] = 0;
				player.SetPlayerPosXY(0, +1);
				//player.Ypos += 1;
			}
		}
		else if (PlayerMove == 'A' || PlayerMove == 'a') {
			if (Maze[player.GetPlayerYPos()][player.GetPlayerXPos() - 1] == 1) {
				printf("�̵��Ҽ� �����ϴ�.\n");
			}
			else {
				Maze[player.GetPlayerYPos()][player.GetPlayerXPos()] = 0;
				player.SetPlayerPosXY(-1, 0);
				//player.Xpos -= 1;
			}
		}
		else if (PlayerMove == 'D' || PlayerMove == 'd') {
			if (Maze[player.GetPlayerYPos()][player.GetPlayerXPos() + 1] == 1) {
				printf("�̵��Ҽ� �����ϴ�.\n");
			}
			else {
				Maze[player.GetPlayerYPos()][player.GetPlayerXPos()] = 0;
				player.SetPlayerPosXY(+1, 0);
				//player.Xpos += 1;
			}
		}
		else {
			printf("�ٸ�Ű�� �Է��Ͽ����ϴ�.\n");
		}
		//�̵��� ��ǥ�� �÷��̾� �̵�
		Maze[player.GetPlayerYPos()][player.GetPlayerXPos()] = 4;

		if (player.GetCoin() > 100) {
			printf("100������ ����Ͽ� ȸ���Ͻðڽ��ϱ�?\n1.Y 2.N\n");
			int PlayerSelect;
			std::cin >> PlayerSelect;
			if (PlayerSelect > 2 || PlayerSelect <= 0) {
				PlayerSelect = 2;
			}
			switch (PlayerSelect) {
			case 1:
				printf("������ ������ ����Ͽ� ü���� ȸ���߽��ϴ�. +10\n");
				player.SetPlayerHealth(10);
				printf("���� HP : %d\n", player.GetPlayerHP());
				player.SetPlayerCoin(-100);
				break;
			case 2:printf("����մϴ�.\n");
				break;
			default:
				break;

			}


		}
		//4 �� �÷��̾�

		if (isBattle == 5 || isBattle == 3) {
			Battle(&player);
		}
		printf("�÷��̾� ���� ü�� : %d\n", player.GetHP());
		if (player.GetHP() <= 0) {
			printf("�÷��̾ ����߽��ϴ�.\n");
			return;
		}

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


