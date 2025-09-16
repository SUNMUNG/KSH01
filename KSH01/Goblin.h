#pragma once
#include "Monster.h"
class Goblin : public Monster
{
public:
	void MultiHit();

	Goblin(std::string inName, int inHp, int inAtk);
	Goblin(std::string inName);
};

