#include "Skeleton.h"

void Skeleton::ArrowShot()
{
	int ArrowAtk = Atk * 1.2f;
	printf("화살 공격을 시전했습니다 : %d\n", ArrowAtk);
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
