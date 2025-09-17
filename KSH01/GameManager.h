#pragma once
#include <string>
#include "Player.h"
class GameManager
{
public:


	void InitializeMaze();
	bool ReadMapFile(const char* MapFileName, std::string& OutDataRef);
	bool ParseMapData(std::string& DataString);
	char* NextLine(char** Source);
	int FindCharIndex(const char* TargetString, const char TargetCharacter);
	void Parselinedata(const char* linedata, int Arraysize, int* outArray);
	void PrintMaze(int PlayerX, int PlayerY);
	void Battle(Player* player);

	void MazeEscape();
	void ClearMaze();

	GameManager()=default;
	virtual ~GameManager() {};

private:
	const char* DirName = ".\\Data\\";
	int MazeHeight=0;
	int MazeWidth=0;
	int** Maze;
};
