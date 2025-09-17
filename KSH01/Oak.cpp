#include "Oak.h"

void Oak::Giant()
{
	Health *= 1.5f;
	printf("%s가 몸집이 커졌습니다. : HP : %d \n",this->Name.c_str(), Health);
}

void Oak::SkillAttack(IBattle* Target)
{
	Giant();
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
