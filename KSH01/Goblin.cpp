#include "Goblin.h"

void Goblin::MultiHit()
{
	
	printf("%s�� ��Ƽ��Ʈ�� �����߽��ϴ�",this->Name.c_str());
}

void Goblin::SkillAttack(IBattle* Target)
{
	int MultiHitAtk = Atk * 0.5f;
	Target->TakeDamage(MultiHitAtk*3);
	printf(":% d�� ����\n", MultiHitAtk);
	
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
