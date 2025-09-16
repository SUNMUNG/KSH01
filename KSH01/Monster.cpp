#include "Monster.h"

Monster::Monster(std::string inName, int inHp, int inAtk)
{
	this->Name = inName;
	this->Health = inHp;
	this->Atk = inAtk;
}

Monster::Monster(std::string inName)
{
	this->Name = inName;
}


Monster::Monster()
{
}

Monster::~Monster()
{
}