#include "Goblin.h"

void Goblin::MultiHit()
{
	int MultiHitAtk = Atk * 0.5f;
	printf("멀티히트를 시전했습니다 : %d씩 세번\n", MultiHitAtk);
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
