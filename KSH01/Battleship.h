#pragma once
class Battleship
{
public:
	Battleship(int inSize,int shipNumber)
		:Size(inSize),ShipNumber(shipNumber),HP(inSize){
	}
	//~Battleship();
	bool SunkCheck();
public:
	int PosX = 0;
	int PosY = 0;
	int Size = 0; //2//3//4//5
	int ShipNumber=-1;
	int HP = 0;

	bool isSunk = false;
};

