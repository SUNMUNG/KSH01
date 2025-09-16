#pragma once
#include "Monster.h"
class Skeleton : public Monster
{
public:
	void ArrowShot();

	Skeleton(std::string inName, int inHp, int inAtk);
	Skeleton(std::string inName);
};

