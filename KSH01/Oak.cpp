#include "Oak.h"

void Oak::Giant()
{
	Health *= 1.5f;
	printf("��ũ�� ������ Ŀ�����ϴ�. : HP : %d \n",Health);
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
