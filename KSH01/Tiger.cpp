#include "Tiger.h"

void Tiger::Hunt()
{
	printf("%s : ����� �մϴ�.\n",name.c_str());
	SetEnergy(Energy - 0.5f);
	printf("----------------------------\n");
}
void Tiger::Move() {
	printf("%s�� ��ȿ�մϴ�.\n", name.c_str());
	//Animal::Move();
}

void Tiger::MakeSound()
{
	printf("����\n");
	Animal::MakeSound();
}
