#include "Whale.h"

void Whale::Swim()
{
	printf("%s : 수영을 합니다.\n", name.c_str());
	SetEnergy(Energy - 0.2f);
	printf("----------------------------\n");
}
