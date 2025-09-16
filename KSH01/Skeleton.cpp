#include "Skeleton.h"

void Skeleton::ArrowShot()
{
	int ArrowAtk = Atk * 1.2f;
	printf("ȭ�� ������ �����߽��ϴ� : %d\n", ArrowAtk);
}

Skeleton::Skeleton(std::string inName, int inHp, int inAtk)
{
	Name = inName;
	Health = inHp;
	Atk = inAtk;
}

Skeleton::Skeleton(std::string inName)
	:Monster(inName)
{
}
