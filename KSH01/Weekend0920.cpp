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
	do
	{
		inship.PosX = rand() % MapWidth;
		inship.PosY = rand() % MapHeight;
		

		if (canPlace(inship.PosX, inship.PosY, inship.Size) == true) {
			//함선배치
			PlaceShip(inship);
			isDecide = true;
		}
		else {
			isDecide = false;
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

void Weekend0920::PlaceShip(Battleship inship)
{
	bool abc = true;
	for (int i = 0; i < inship.Size; i++) {
		if (Map[inship.PosY][inship.PosX - i] == 1 && Map[inship.PosY][inship.PosX + i] == 1) {
			abc = false;
		}
	}

	if (abc) {
		//배치
		if (PosXCan(inship)) {
			for (int i = 0; i < inship.Size; i++) {
				Map[inship.PosY][inship.PosX + i] = 1;
			}
		
		}
		else {
			for (int i = 0; i < inship.Size; i++) {
				Map[inship.PosY][inship.PosX - i] = 1;
			}
		
		}
	}
	else{
		for (int i = 0; i < inship.Size; i++) {
			if (Map[inship.PosY - i][inship.PosX] == 1 && Map[inship.PosY + i][inship.PosX] == 1) {
				abc = false;
			}
		}
			
		//배치
		if (PosYCan(inship)) {
			for (int i = 0; i < inship.Size; i++) {
				Map[inship.PosY + i][inship.PosX] = 1;
			}
		}
		else {
			for (int i = 0; i < inship.Size; i++) {
				Map[inship.PosY - i][inship.PosX] = 1;
			}
		}

		
	}
	
		
			

	
}
bool Weekend0920::PosXCan(Battleship inship)
{
	//true +방향가능
	//false -방향가능
	for (int i = 0; i < inship.Size; i++) {
		if (Map[inship.PosY][inship.PosX+i] == 1)return true;
	}

	return false;
}

bool Weekend0920::PosYCan(Battleship inship)
{
	//true +방향가능
	//false -방향가능
	for (int i = 0; i < inship.Size; i++) {
		if (Map[inship.PosY+i][inship.PosX] == 1)return true;
	}
	return false;
}

bool Weekend0920::canPlace(int inposX, int inposY, int shipSize)
{
	bool isPlaceX;
	bool isPlaceY;
	if (inposX + shipSize >= MapWidth && inposX - shipSize < 0) {
		isPlaceX = false;
	}
	else {
		isPlaceX = true;
	}

	if (inposY + shipSize >= MapHeight && inposY - shipSize < 0) {
		isPlaceY = false;
	}
	else {
		isPlaceY = true;
	}

	if (isPlaceX || isPlaceY) { return true; }
	else { return false; }
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
			
			if (Map[y][x] == 0 || isHit == true) {
				printf("0 ");
			}else if (Map[y][x] == 1 || isHit == true) {
				printf("X ");
			}
			else if(Map[y][x] == 3){
				printf(". ");
			}
		}
		printf("\n");
	}
}
