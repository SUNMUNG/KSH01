#include "Weekend0920.h"
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include "Battleship.h"


void Weekend0920::InitializeMap(Battleship destroyer, Battleship cruiser, Battleship aircraftCarrier, Battleship battleship)
{
	/*Battleship cruiser(3,1002);
	Battleship destroyer(2,1001);
	Battleship aircraftCarrier(4,1003);
	Battleship battleship(5,1004);*/
	
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
		
		Angle = canPlace(inship.PosX, inship.PosY, inship.Size);//��������� ��������
		if (Angle == cant) {
			isDecide = false;
		}
		else {
			PlaceShip(inship, Angle);
			isDecide = true;
		}

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
			Map[inship.PosY][inship.PosX+i] = inship.ShipNumber;
		}
	}
	else if (angle == XMinus) {
		for (int i = 0; i < inship.Size; i++) {
			Map[inship.PosY][inship.PosX-i] = inship.ShipNumber;
		}
	}
	else if (angle == YPlus) {
		for (int i = 0; i < inship.Size; i++) {
			Map[inship.PosY+i][inship.PosX] = inship.ShipNumber;
		}
	}
	else if (angle == YMinus) {
		for (int i = 0; i < inship.Size; i++) {
			Map[inship.PosY - i][inship.PosX] = inship.ShipNumber;
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
			if (Map[inposY - i][inposX] > 1000) {
				isPlacedYMinus = false;
			}
		}
	}
	
	if (isPlacedYPlus) {
		for (int i = 0; i < shipSize; i++) {
			if (Map[inposY + i][inposX] > 1000) {
				isPlacedYPlus = false;
			}
		}
	}
	
	if (isPlacedXMinus) {
		for (int i = 0; i < shipSize; i++) {
			if (Map[inposY][inposX - i] > 1000) {
				isPlacedXMinus = false;
			}
		}
	}
	
	if (isPlacedXPlus) {
		for (int i = 0; i < shipSize; i++) {
			if (Map[inposY][inposX + i] > 1000) {
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

void Weekend0920::BattlePhase(Battleship indestroyer, Battleship incruiser, Battleship inaircraftCarrier, Battleship inbattleship)
{
	int playerHP=50;
	int Attack[2];
	int RemainShip = 4;
	printf("BattleShip ������ �����մϴ� \n");
	printf("������ Ƚ���ȿ� �Լ��� ��ħ��Ű����! \n");
	
	enum ShipNumber
	{
		destroyer = 1001,
		cruiser = 1002,
		aircraftCarrier = 1003,
		battleship = 1004,
	};
	enum PosName
	{
		IsWater = 3,
		IshitSucces = 5,
		IshitFail = 6
	};
	
	while (playerHP > 0 && RemainShip > 0)
	{
		PrintHideMap();
		printf("���� �� ��ǥ�� �Է��ϼ��� . (X Y)\n");
		printf("���� ��ȸ : %d\n", playerHP);
		printf("���� �Լ� : %d\n", RemainShip);
		
		for (int i = 0; i < 2; i++) {
			std::cin >> Attack[i];
		}

		if (AttackCheck(Attack[0], Attack[1])==true) {
			if (Map[Attack[1]][Attack[0]] == destroyer) {
				indestroyer.HP--;
				Map[Attack[1]][Attack[0]] = IshitSucces;
				if (indestroyer.SunkCheck()) {
					printf("destroyer �� ��ħ�Ǿ����ϴ�.\n");
					RemainShip--;
					indestroyer.isSunk = false;
				}
			}else if (Map[Attack[1]][Attack[0]] == cruiser) {
				incruiser.HP--;
				Map[Attack[1]][Attack[0]] = IshitSucces;
				if (incruiser.SunkCheck()) {
					printf("cruiser �� ��ħ�Ǿ����ϴ�.\n");
					RemainShip--;
					indestroyer.isSunk = false;
				}
			}
			else if (Map[Attack[1]][Attack[0]] == aircraftCarrier) {
				inaircraftCarrier.HP--;
				Map[Attack[1]][Attack[0]] = IshitSucces;
				if (inaircraftCarrier.SunkCheck()) {
					printf("aircraftCarrier �� ��ħ�Ǿ����ϴ�.\n");
					RemainShip--;
					indestroyer.isSunk = false;
				}
			}
			else if (Map[Attack[1]][Attack[0]] == battleship) {
				inbattleship.HP--;
				Map[Attack[1]][Attack[0]] = IshitSucces;
				if (inbattleship.SunkCheck()) {
					printf("battleship �� ��ħ�Ǿ����ϴ�.\n");
					RemainShip--;
					indestroyer.isSunk = false;
				}
			}
			playerHP--;
		}
		else {
			printf("������ ��ȿ���� �ʾҽ��ϴ� . \n");
		}
		
		
	}

	printf("������ ����Ǿ����ϴ�.\n");
	PrintAllMap();
	
}

bool Weekend0920::AttackCheck(int AtkX, int AtkY)
{
	enum PosName
	{
		IsWater = 3,
		IshitSucces =5,
		IshitFail =6
	};
	
	//shipnumber 1001������
	if (Map[AtkY][AtkX] > 1000) { //���ݾȹ��� �Լ��� �ش�Ǵ� ��Ʈ
		printf("������ �����߽��ϴ�!\n");
		return true;
	}
	else if (Map[AtkY][AtkX] == IsWater) { //���ݾȹ��� �ٴٿ� �ش�Ǵ� ��Ʈ
		printf("������ �����߽��ϴ�.\n");
		Map[AtkY][AtkX] = IshitFail;
		return true;
	}
	else if (Map[AtkY][AtkX] == IshitFail || Map[AtkY][AtkX] == IshitSucces) {
		printf("�̹� ������ ���Դϴ�.\n");
		return false;
	}
	else {
		printf("��ȿ���� ���� ��ǥ �Դϴ�.\n");
		return false;
	}
}


void Weekend0920::PrintHideMap()
{
	printf("  ");
	for (int i = 0; i < MapWidth; i++) {
		printf("%d ", i);
	}
		printf("\n");
	for (int y = 0; y < MapHeight; y++) {
		printf("%d ", y);
		for (int x = 0; x < MapWidth; x++) {
			//�Լ��� ��ġ�������� ���� Ÿ�ݽ�
			if (Map[y][x] == 6) {
				printf("0 ");
			}
			//���� ������ �Լ�
			else if (Map[y][x] == 5) {
				printf("X ");
			}
			//�� or ������ �Լ�
			else if(Map[y][x] == 3 || Map[y][x] > 1000){
				printf(". ");
			}
		}
		printf("\n");
	}
}

void Weekend0920::PrintAllMap()
{
	printf("  ");
	for (int i = 0; i < MapWidth; i++) {
		printf("%d ", i);
	}
	printf("\n");
	for (int y = 0; y < MapHeight; y++) {
		printf("%d ", y);
		for (int x = 0; x < MapWidth; x++) {
			if (Map[y][x] == 6 || Map[y][x] == 3) {
				printf(". ");
			}
			else if (Map[y][x] == 5 || Map[y][x] > 1000) {
				printf("X ");
			}
		}
		printf("\n");
	}
}
