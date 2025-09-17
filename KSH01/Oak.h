#pragma once
#include "Monster.h"
class Oak : public Monster
{
public:
	void Giant();
	virtual void SkillAttack(IBattle* Target) override;
	Oak(std::string inName, int inHp, int inAtk);
	Oak(std::string inName);
protected:
	
};

