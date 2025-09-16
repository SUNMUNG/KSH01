#include "Horse.h"

void Horse::Ride()
{
	printf("%s : ¿ª ≈¿Ω¿¥œ¥Ÿ.\n",name.c_str());
	SetEnergy(Energy - 0.6f);
	printf("----------------------------\n");
}
