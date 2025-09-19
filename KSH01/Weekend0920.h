#pragma once
#include "Battleship.h"
class Weekend0920
{
public:
	void PrintMap();
	void InitializeMap();
	void DecidePos(Battleship inship);
	void PlaceShip(Battleship inship);
	bool PosXCan(Battleship inship);
	bool PosYCan(Battleship inship);

	bool canPlace(int inposX,int inposY,int shipSize);

	Weekend0920() = default;
	virtual ~Weekend0920() {};

private:
	static constexpr int MapHeight = 10;
	static constexpr int MapWidth = 10;
	int Map[MapHeight][MapWidth] = { 
		{3,3,3,3,3,3,3,3,3,3},
		{3,3,3,3,3,3,3,3,3,3},
		{3,3,3,3,3,3,3,3,3,3},
		{3,3,3,3,3,3,3,3,3,3},
		{3,3,3,3,3,3,3,3,3,3},
		{3,3,3,3,3,3,3,3,3,3},
		{3,3,3,3,3,3,3,3,3,3},
		{3,3,3,3,3,3,3,3,3,3},
		{3,3,3,3,3,3,3,3,3,3},
		{3,3,3,3,3,3,3,3,3,3}
	};
};
