#include "Horse.h"

void Horse::Ride()
{
	printf("%s : �� �����ϴ�.\n",name.c_str());
	SetEnergy(Energy - 0.6f);
	printf("----------------------------\n");
}

void Horse::MakeSound()
{
	printf("����\n");
	Animal::MakeSound();
}

void Horse::Move()
{
	printf("���� �޸��ϴ�\n");
	//Animal::Move();
}
