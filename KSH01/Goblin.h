#pragma once
#include "Monster.h"
class Goblin : public Monster
{
public:
	void MultiHit();
	virtual void SkillAttack(IBattle* Target) override;
	Goblin(std::string inName, int inHp, int inAtk);
	Goblin(std::string inName);
};

