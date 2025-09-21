#pragma once
#include "Battleship.h"
class Weekend0920
{
public:
	void PrintMap();
	void InitializeMap();
	void DecidePos(Battleship inship);
	void PlaceShip(Battleship inship,int angle);

	int canPlace(int inposX,int inposY,int shipSize);
	void BattlePhase();

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
