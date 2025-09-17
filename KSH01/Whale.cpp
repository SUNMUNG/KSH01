#include "Whale.h"

void Whale::Swim()
{
	printf("%s : 수영을 합니다.\n", name.c_str());
	SetEnergy(Energy - 0.2f);
	printf("----------------------------\n");
}

void Whale::MakeSound()
{
	printf("고래\n");
	Animal::MakeSound();
}

void Whale::Move()
{
	printf("고래가 헤엄칩니다\n");
	//Animal::Move();
}
