#include "Horse.h"

void Horse::Ride()
{
	printf("%s : �� �����ϴ�.\n",name.c_str());
	SetEnergy(Energy - 0.6f);
	printf("----------------------------\n");
}
