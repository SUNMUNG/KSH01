#include "Weekend0920.h"
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <iostream>
#include <fstream>
#include <string>
#include "Battleship.h"


void Weekend0920::InitializeMap()
{
	Battleship cruiser(3);
	Battleship destroyer(2);
	Battleship aircraftCarrier(4);
	Battleship battleship(5);
	
	DecidePos(destroyer);
	DecidePos(cruiser);
	DecidePos(aircraftCarrier);
	DecidePos(battleship);




}

void Weekend0920::DecidePos(Battleship inship)
{
	bool isDecide = false;
	int Angle = -1;
	enum CanXY
	{
		XPlus,
		XMinus,
		YPlus,
		YMinus,
		cant
	};
	do
	{
		inship.PosX = rand() % MapWidth;
		inship.PosY = rand() % MapHeight;
		
		//int Angle = rand() % 2;

		Angle = canPlace(inship.PosX, inship.PosY, inship.Size);//어느방향이 가능한지
		if (Angle == cant) {
			isDecide = false;
		}
		else {
			PlaceShip(inship, Angle);
			isDecide = true;
		}
		

		/*if (Angle == 0) {
			if (inship.PosX + inship.Size >= MapWidth && inship.PosX - inship.Size < 0) {
				inship.PosX = rand() % MapWidth;
			}
			else {
				if (inship.PosX + inship.Size >= MapWidth) {
					for (int i = 0; i < inship.Size; i++) {
						if (Map[inship.PosY][inship.PosX-i] == 1) {
							Angle = 1;
						}
					}
					Map[inship.PosY][inship.PosX] = 1;
					for (int i = 1; i < inship.Size; i++) {
						Map[inship.PosY][inship.PosX - i] = 1;
					}
					isDecide = true;

				}
				else {
					for (int i = 0; i < inship.Size; i++) {
						if (Map[inship.PosY][inship.PosX + i-1] == 1) {
							Angle = 1;
						}
					}
					Map[inship.PosY][inship.PosX] = 1;
					for (int i = 1; i < inship.Size; i++) {
						Map[inship.PosY][inship.PosX + i] = 1;
					}
					isDecide = true;
				}
			}
		}
		
		if (Angle == 1) {
			if (inship.PosY + inship.Size >= MapWidth && inship.PosY - inship.Size < 0) {
				inship.PosY = rand() % MapWidth;
			}
			else {
				if (inship.PosY + inship.Size >= MapWidth) {
					for (int i = 0; i < inship.Size; i++) {
						if (Map[inship.PosY-i][inship.PosX] == 1) {
							inship.PosY = rand() % MapHeight;
						}
					}
					Map[inship.PosY][inship.PosX] = 1;
					for (int i = 1; i < inship.Size; i++) {
						Map[inship.PosY - i][inship.PosX] = 1;
					}
					isDecide = true;

				}
				else {
					for (int i = 0; i < inship.Size; i++) {
						if (Map[inship.PosY + i -1][inship.PosX] == 1) {
							inship.PosY = rand() % MapHeight;
						}
					}
					Map[inship.PosY][inship.PosX] = 1;
					for (int i = 1; i < inship.Size; i++) {
						Map[inship.PosY + i][inship.PosX] = 1;
					}
					isDecide = true;
				}
			}
		}*/
		

	} while (!isDecide);
	
}

void Weekend0920::PlaceShip(Battleship inship,int angle)
{
	enum CanXY
	{
		XPlus,
		XMinus,
		YPlus,
		YMinus,
		cant
	};

	if (angle== XPlus) {
		for (int i = 0; i < inship.Size; i++) {
			Map[inship.PosY][inship.PosX+i] = 1;
		}
	}
	else if (angle == XMinus) {
		for (int i = 0; i < inship.Size; i++) {
			Map[inship.PosY][inship.PosX-i] = 1;
		}
	}
	else if (angle == YPlus) {
		for (int i = 0; i < inship.Size; i++) {
			Map[inship.PosY+i][inship.PosX] = 1;
		}
	}
	else if (angle == YMinus) {
		for (int i = 0; i < inship.Size; i++) {
			Map[inship.PosY - i][inship.PosX] = 1;
		}
	}
	
}


int Weekend0920::canPlace(int inposX, int inposY, int shipSize)
{
	bool isPlacedXPlus = true;
	bool isPlacedXMinus = true;
	bool isPlacedYPlus = true;
	bool isPlacedYMinus = true;

	enum CanXY
	{
		XPlus,
		XMinus,
		YPlus,
		YMinus,
		cant
	};
	if (inposY + shipSize >= MapHeight) {
		isPlacedYPlus = false;
	}
	if (inposY - shipSize < 0) {
		isPlacedYMinus = false;
	}
	if (inposX + shipSize >= MapWidth) {
		isPlacedXPlus = false;
	}
	if (inposX - shipSize < 0) {
		isPlacedXMinus = false;
	}

	if (isPlacedYMinus) {
		for (int i = 0; i < shipSize; i++) {
			if (Map[inposY - i][inposX] == 1) {
				isPlacedYMinus = false;
			}
		}
	}
	
	if (isPlacedYPlus) {
		for (int i = 0; i < shipSize; i++) {
			if (Map[inposY + i][inposX] == 1) {
				isPlacedYPlus = false;
			}
		}
	}
	
	if (isPlacedXMinus) {
		for (int i = 0; i < shipSize; i++) {
			if (Map[inposY][inposX - i] == 1) {
				isPlacedXMinus = false;
			}
		}
	}
	
	if (isPlacedXPlus) {
		for (int i = 0; i < shipSize; i++) {
			if (Map[inposY][inposX + i] == 1) {
				isPlacedXPlus = false;
			}
		}
	}
	

	if (isPlacedYPlus) {
		return YPlus;
	}
	else if (isPlacedYMinus) {
		return YMinus;
	}
	else if (isPlacedXPlus) {
		return XPlus;
	}
	else if (isPlacedXMinus) {
		return XMinus;
	}
	else {
		return cant;
	}
	
	
}

void Weekend0920::BattlePhase()
{
	int HP=10;

	printf("BattleShip 게임을 시작합니다 \n");
	printf("지정된 횟수안에 함선을 격침시키세요! \n");


}


void Weekend0920::PrintMap()
{
	bool isHit = false;
	printf("  ");
	for (int i = 0; i < MapWidth; i++) {
		printf("%d ", i);
	}
		printf("\n");
	for (int y = 0; y < MapHeight; y++) {
		printf("%d ", y);
		for (int x = 0; x < MapWidth; x++) {
			
			if (Map[y][x] == 0 && isHit == true) {
				printf("0 ");
			}else if (Map[y][x] == 1 && isHit == true) {
				printf("X ");
			}
			else if(Map[y][x] == 3 || isHit == false){
				printf(". ");
			}
		}
		printf("\n");
	}
}
