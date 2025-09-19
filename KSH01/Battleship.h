#pragma once
class Battleship
{
public:
	Battleship(int inSize)
		:Size(inSize) {
	}
	//~Battleship();

public:
	int PosX = 0;
	int PosY = 0;
	int Size = 0; //2//3//4//5
};

