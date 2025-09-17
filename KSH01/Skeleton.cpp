#include "Skeleton.h"

void Skeleton::ArrowShot()
{
	printf("%s��(��) ȭ�� ������ �����߽��ϴ�\n",this->Name.c_str());
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
