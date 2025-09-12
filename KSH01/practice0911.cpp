#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <iostream>
#include <cstring>
#include <random>
#include <string>
#include <limits.h>
#include <direct.h>
#include <fstream>
#include "practice0911.h"
#include "practice0910.h"
#include "practice0909.h"

int MazeHeight = 10;
int MazeWidth = 20;
int** Maze = nullptr;

void practice09111()
{
	InitializeMaze();

	MiroEscape();

	ClearMaze();

}
const char* DirName = ".\\Data\\";
bool ReadMapFile(const char* MapFileName,std::string& OutDataRef)
{

	char FilePath[256];
	strcpy(FilePath,DirName);
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

bool ParseMapData(std::string& DataString)
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

char* NextLine(char** Source)
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

void Parselinedata(const char* linedata, int Arraysize, int* outArray) {
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

void ClearMaze()
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

void InitializeMaze()
{
	std::string Data;
	ReadMapFile("MapData.txt", Data);
	ParseMapData(Data);
}


void PrintMaze(int PlayerX, int PlayerY)
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


void MiroEscape()
{
	// �̷� ũ��
	Player player;
	Enemy2 enemy;
	const int MazeHeight = 10;
	const int MazeWidth = 20;
	int PlayerPosX = 1;
	int PlayerPosY = 1;
	int EndPosX = 18;
	int EndPosY = 7;
	char PlayerMove;
	int isBattle = -1;
	
	
	//�����Ȳ �̷� ���
	while (Maze[player.Ypos][player.Xpos] != Maze[EndPosY][EndPosX]) {

		isBattle = rand() % 10;
		PrintMaze(player.Xpos, player.Ypos);

		//�̵����� ���� ���
		printf("w(W): ��, s(S): �Ʒ�, a(A): ����, d(D): ������\n");
		printf("�̵� ������ ���� : ");
		if (Maze[player.Ypos + 1][player.Xpos] == 0) {
			printf("s(S): �Ʒ�, ");
		}
		if (Maze[player.Ypos - 1][player.Xpos] == 0) {
			printf("w(W): ��, ");
		}
		if (Maze[player.Ypos][player.Xpos - 1] == 0) {
			printf("a(A): ����, ");
		}
		if (Maze[player.Ypos][player.Xpos + 1] == 0) {
			printf("d(D): ������ ");
		}

		printf("\n�̵� ������ �Է��ϼ���.\n");
		std::cin >> PlayerMove;

		//�� �Ǵ� ���� ������ ��ǥ�̵�
		if (PlayerMove == 'W' || PlayerMove == 'w') {
			if (Maze[player.Ypos - 1][player.Xpos] == 1) {
				printf("�̵��Ҽ� �����ϴ�.\n");
			}
			else {
				Maze[player.Ypos][player.Xpos] = 0;
				player.Ypos -= 1;
			}
		}
		else if (PlayerMove == 'S' || PlayerMove == 's') {
			if (Maze[player.Ypos + 1][player.Xpos] == 1) {
				printf("�̵��Ҽ� �����ϴ�.\n");
			}
			else {
				Maze[player.Ypos][player.Xpos] = 0;
				player.Ypos += 1;
			}
		}
		else if (PlayerMove == 'A' || PlayerMove == 'a') {
			if (Maze[player.Ypos][player.Xpos - 1] == 1) {
				printf("�̵��Ҽ� �����ϴ�.\n");
			}
			else {
				Maze[player.Ypos][player.Xpos] = 0;
				player.Xpos -= 1;
			}
		}
		else if (PlayerMove == 'D' || PlayerMove == 'd') {
			if (Maze[player.Ypos][player.Xpos + 1] == 1) {
				printf("�̵��Ҽ� �����ϴ�.\n");
			}
			else {
				Maze[player.Ypos][player.Xpos] = 0;
				player.Xpos += 1;
			}
		}
		else {
			printf("�ٸ�Ű�� �Է��Ͽ����ϴ�.\n");
		}
		//�̵��� ��ǥ�� �÷��̾� �̵�
		Maze[player.Ypos][player.Xpos] = 4; 
		if (player.reward > 0) {
			printf("������ ������ ����Ͽ� ü���� ȸ���߽��ϴ�. +10\n");
			player.PlayerHp += 10;
			printf("���� HP : %d\n", player.PlayerHp);
			player.reward--;
		}
		//4 �� �÷��̾�

		if (isBattle == 5 || isBattle == 3) {
			Battle(&player);
		}
		printf("�÷��̾� ���� ü�� : %d\n",player.PlayerHp);

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

const int MHeight = 10;
const int MWidth = 20;

void backtrackingMain()
{
	
	int PlayerPosX = 1;
	int PlayerPosY = 1;
	int EndPosX = 18;
	int EndPosY = 7;
	char PlayerMove;

	int RandomStartXPos;
	int RandomStarYPos;
	// �̷� �迭
	int Maze[MHeight][MWidth] = { 1 };
	
	RandomStartXPos = RandomStartPosXDecide(MWidth);
	RandomStarYPos = RandomStartPosXDecide(MHeight);

	RoadSearch(RandomStartXPos, RandomStarYPos);
}
//1. �������� �� ���� �����մϴ�.
// 
int RandomStartPosXDecide(int MWidth)
{
	int PosX = -1;
	PosX = rand() % MWidth;
	return PosX;
}
int RandomStartPosYDecide(int MHeight)
{
	int PosY = -1;
	PosY = rand() % MHeight; 
	return PosY;
}

//
//2. ���õ� ��ġ����, ������ ��(��, ��, ��, ��)�� �����ϰ� Ž���մϴ�.
//
void RoadSearch(int RandomStartXPos, int RandomStarYPos)
{
	int Xpos= RandomStartXPos;
	int Ypos = RandomStarYPos;
	bool canMove = false;
	enum Dir
	{
		UP,
		Down,
		Right,
		Left
	};
	Maze[RandomStarYPos][RandomStartXPos] == 4;
	do
	{
		int randir = rand() % 4; //Dir Enum

		if (Outboundary(randir, Xpos, Ypos) == true) {
			if (randir == UP) {
				Ypos -= 1;
				Maze[Ypos][Xpos] = 0;
				canMove = true;
			}
			if (randir == Down) {
				Ypos += 1;
				canMove = true;
			}
			if (randir == Right) {
				Xpos += 1;
				canMove = true;
			}
			if (randir == Left) {
				Xpos -= 1;
				canMove = true;
			}
		}
	} while (canMove == false);
	canMove = false;


	

	
	if (Maze[Ypos][Xpos] == -1) {

	}
}
bool Outboundary(int dir,int Xpos,int Ypos)
{
	enum Dir
	{
		UP,
		Down,
		Right,
		Left
	};

	//�ش� �������� �̵������� �̹� ���̳� ���� ��������ִ���, ���� ����� ����
	if (dir == UP) {
		if ((0 > Ypos - 1)||Maze[Ypos-1][Xpos]!=-1) {
			return false;
		}
	}
	if (dir == Down) {
		if (MHeight < Ypos + 1 || Maze[Ypos + 1][Xpos] != -1) {
			return false;
		}
	}
	if (dir == Right) {
		if (MWidth < Xpos + 1 || Maze[Ypos][Xpos + 1] != -1) {
			return false;
		}
	}if (dir == Left) {
		if ((MWidth < Xpos - 1) || Maze[Ypos][Xpos - 1] != -1){
			return false;
		}

		return true;
	}
}
// 
//3. Ž���� ���� ���� ���� �����ٸ� �հ� �� ��ҷ� �̵��մϴ�.
//
//4. ������ ���� �̵��� ���� ���ٸ�, ���� ��ġ�� ���� ���ϴ�.
//
//5. �� ������ �ݺ��Ͽ� ��� ��Ҹ� �湮�ϸ� �̷ΰ� �ϼ� �˴ϴ�.
