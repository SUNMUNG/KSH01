#include "Tiger.h"

void Tiger::Hunt()
{
	printf("%s : ����� �մϴ�.\n",name.c_str());
	SetEnergy(Energy - 0.5f);
	printf("----------------------------\n");
}
