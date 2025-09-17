#include "Goblin.h"

void Goblin::MultiHit()
{
	
	printf("%s가 멀티히트를 시전했습니다",this->Name.c_str());
}

void Goblin::SkillAttack(IBattle* Target)
{
	int MultiHitAtk = Atk * 0.5f;
	Target->TakeDamage(MultiHitAtk*3);
	printf(":% d씩 세번\n", MultiHitAtk);
	
}

Goblin::Goblin(std::string inName, int inHp, int inAtk)
{
	Name = inName;
	Health = inHp;
	Atk = inAtk;
}

Goblin::Goblin(std::string inName)
	:Monster(inName)
{
}
