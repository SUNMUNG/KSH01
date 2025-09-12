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

bool ParseMapData(std::string& DataString)
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
				// 절대 들어오면 안되는 곳 == 맵 데이터가 잘못된 것
			}
		}
		printf("\n");
	}
}


void MiroEscape()
{
	// 미로 크기
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
	
	
	//현재상황 미로 출력
	while (Maze[player.Ypos][player.Xpos] != Maze[EndPosY][EndPosX]) {

		isBattle = rand() % 10;
		PrintMaze(player.Xpos, player.Ypos);

		//이동가능 방향 출력
		printf("w(W): 위, s(S): 아래, a(A): 왼쪽, d(D): 오른쪽\n");
		printf("이동 가능한 방향 : ");
		if (Maze[player.Ypos + 1][player.Xpos] == 0) {
			printf("s(S): 아래, ");
		}
		if (Maze[player.Ypos - 1][player.Xpos] == 0) {
			printf("w(W): 위, ");
		}
		if (Maze[player.Ypos][player.Xpos - 1] == 0) {
			printf("a(A): 왼쪽, ");
		}
		if (Maze[player.Ypos][player.Xpos + 1] == 0) {
			printf("d(D): 오른쪽 ");
		}

		printf("\n이동 방향을 입력하세요.\n");
		std::cin >> PlayerMove;

		//벽 판단 로직 없으면 좌표이동
		if (PlayerMove == 'W' || PlayerMove == 'w') {
			if (Maze[player.Ypos - 1][player.Xpos] == 1) {
				printf("이동할수 없습니다.\n");
			}
			else {
				Maze[player.Ypos][player.Xpos] = 0;
				player.Ypos -= 1;
			}
		}
		else if (PlayerMove == 'S' || PlayerMove == 's') {
			if (Maze[player.Ypos + 1][player.Xpos] == 1) {
				printf("이동할수 없습니다.\n");
			}
			else {
				Maze[player.Ypos][player.Xpos] = 0;
				player.Ypos += 1;
			}
		}
		else if (PlayerMove == 'A' || PlayerMove == 'a') {
			if (Maze[player.Ypos][player.Xpos - 1] == 1) {
				printf("이동할수 없습니다.\n");
			}
			else {
				Maze[player.Ypos][player.Xpos] = 0;
				player.Xpos -= 1;
			}
		}
		else if (PlayerMove == 'D' || PlayerMove == 'd') {
			if (Maze[player.Ypos][player.Xpos + 1] == 1) {
				printf("이동할수 없습니다.\n");
			}
			else {
				Maze[player.Ypos][player.Xpos] = 0;
				player.Xpos += 1;
			}
		}
		else {
			printf("다른키를 입력하였습니다.\n");
		}
		//이동한 좌표로 플레이어 이동
		Maze[player.Ypos][player.Xpos] = 4; 
		if (player.reward > 0) {
			printf("보유한 보상을 사용하여 체력을 회복했습니다. +10\n");
			player.PlayerHp += 10;
			printf("현재 HP : %d\n", player.PlayerHp);
			player.reward--;
		}
		//4 가 플레이어

		if (isBattle == 5 || isBattle == 3) {
			Battle(&player);
		}
		printf("플레이어 현재 체력 : %d\n",player.PlayerHp);

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
	// 미로 배열
	int Maze[MHeight][MWidth] = { 1 };
	
	RandomStartXPos = RandomStartPosXDecide(MWidth);
	RandomStarYPos = RandomStartPosXDecide(MHeight);

	RoadSearch(RandomStartXPos, RandomStarYPos);
}
//1. 무작위로 한 곳을 선택합니다.
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
//2. 선택된 위치에서, 인접한 곳(상, 하, 좌, 우)을 랜덤하게 탐색합니다.
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

	//해당 방향으로 이동했을때 이미 길이나 벽이 만들어져있던가, 범위 벗어나면 실행
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
//3. 탐색한 곳의 벽이 전부 막혔다면 뚫고 그 장소로 이동합니다.
//
//4. 인접한 곳에 이동할 곳이 없다면, 이전 위치로 돌아 갑니다.
//
//5. 위 내용을 반복하여 모든 장소를 방문하면 미로가 완성 됩니다.
