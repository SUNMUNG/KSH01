#include "Whale.h"

void Whale::Swim()
{
	printf("%s : ������ �մϴ�.\n", name.c_str());
	SetEnergy(Energy - 0.2f);
	printf("----------------------------\n");
}

void Whale::MakeSound()
{
	printf("��\n");
	Animal::MakeSound();
}

void Whale::Move()
{
	printf("���� ���Ĩ�ϴ�\n");
	//Animal::Move();
}
