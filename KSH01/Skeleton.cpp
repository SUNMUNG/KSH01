#include "Skeleton.h"

void Skeleton::ArrowShot()
{
	printf("%s이(가) 화살 공격을 시전했습니다\n",this->Name.c_str());
}

void Skeleton::SkillAttack(IBattle* Target)
{
	int ArrowAtk = Atk * 1.2f;
	ArrowShot();
	Target->TakeDamage(ArrowAtk);
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
