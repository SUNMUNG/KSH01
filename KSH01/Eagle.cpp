#include "Eagle.h"

void Eagle::Fly()
{
	printf("%s : �ϴ��� ���ϴ�.\n",name.c_str());
	SetEnergy(Energy - 0.3f);
	printf("----------------------------\n");
}

void Eagle::Move() {
	//Animal::Move();
	printf("�������� ���ƴٴմϴ� .\n");
}

void Eagle::MakeSound()
{
	printf("��\n");
	Animal::MakeSound();
}
