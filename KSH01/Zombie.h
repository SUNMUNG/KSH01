#pragma once
#include "Monster.h"
class Zombie : public Monster
{
public:
	void HealthRegen();
	virtual void SkillAttack(IBattle* Target) override;
	Zombie(std::string inName, int inHp, int inAtk);
	Zombie(std::string inName);
};

