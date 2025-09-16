#include "Oak.h"

void Oak::Giant()
{
	Health *= 1.5f;
	printf("오크가 몸집이 커졌습니다. : HP : %d \n",Health);
}

Oak::Oak(std::string inName, int inHp, int inAtk)
{
	Name = inName;
	Health = inHp;
	Atk = inAtk;
}

Oak::Oak(std::string inName)
	:Monster(inName)
{
}
