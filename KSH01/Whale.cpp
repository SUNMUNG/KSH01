#include "Whale.h"

void Whale::Swim()
{
	printf("%s : ������ �մϴ�.\n", name.c_str());
	SetEnergy(Energy - 0.2f);
	printf("----------------------------\n");
}
