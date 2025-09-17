#include "Zombie.h"

void Zombie::HealthRegen()
{
	this->Health += 10;
	printf("%s�� HP�� 10��ŭ ȸ���߽��ϴ�.\n",this->Name.c_str());
}

void Zombie::SkillAttack(IBattle* Target)
{
	HealthRegen();
}

Zombie::Zombie(std::string inName, int inHp, int inAtk)
{
	Name = inName;
	Health = inHp;
	Atk = inAtk;
}

Zombie::Zombie(std::string inName)
	:Monster(inName)
{
}
