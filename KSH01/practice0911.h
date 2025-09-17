#pragma once

extern int MazeHeight;
extern int MazeWidth;
extern int** Maze;


void practice09111();

void MiroEscape();

bool ReadMapFile(const char* MapFileName, std::string& OutDataRef);

bool ParseMapData(std::string& DataString);

char* NextLine(char** InOutSource);

void Parselinedata(const char* linedata, int Arraysize, int* outArray);

void ClearMaze();

void InitializeMaze();

void PrintMaze(int PlayerX, int PlayerY);





//backtracking

void backtrackingMain();

int RandomStartPosXDecide(int);

int RandomStartPosYDecide(int);

void RoadSearch(int,int);

bool Outboundary(int dir, int Xpos, int Ypos);