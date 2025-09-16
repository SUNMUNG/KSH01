#include "Eagle.h"

void Eagle::Fly()
{
	printf("%s : «œ¥√¿ª ≥≥¥œ¥Ÿ.\n",name.c_str());
	SetEnergy(Energy - 0.3f);
	printf("----------------------------\n");
}
