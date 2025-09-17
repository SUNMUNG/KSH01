#include "Horse.h"

void Horse::Ride()
{
	printf("%s : 을 탔습니다.\n",name.c_str());
	SetEnergy(Energy - 0.6f);
	printf("----------------------------\n");
}

void Horse::MakeSound()
{
	printf("이힝\n");
	Animal::MakeSound();
}

void Horse::Move()
{
	printf("말이 달립니다\n");
	//Animal::Move();
}
