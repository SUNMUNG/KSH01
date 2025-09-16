#include "Zombie.h"

void Zombie::HealthRegen()
{
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
