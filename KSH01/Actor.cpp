#include "Actor.h"


Actor::Actor(std::string inName, int inHp, int inAtk)
{
	this->Name = inName;
	this->Health = inHp;
	this->Atk = inAtk;
}
Actor::Actor()
{
}

Actor::~Actor()
{
}

void Actor::AttackDamage(IBattle* Target)
{
	int Damage = 0;
	int SkillChance = rand()%10;
	Damage = rand() % this->Atk + 1;
	if (this->Name != "플레이어" && SkillChance <= 3) {
		SkillAttack(Target);
	}
	else {
		Target->TakeDamage(Damage);
	}
	
	
}

void Actor::TakeDamage(int inDamage)
{
	this->Health -= inDamage;
	printf("%s가 %d 데미지를 받았습니다.\n", this->Name.c_str(), inDamage);
	
}

int Actor::CoinReward()
{
	int coin = 0;

	if (this->Name == "몬스터") {
		coin = 10;
	}
	else if(this->Name == "오크") {
		coin = 50;
	}
	else if (this->Name == "좀비") {
		coin = 20;
	}
	else if (this->Name == "스켈레톤") {
		coin = 25;
	}
	else if (this->Name == "고블린") {
		coin = 20;
	}
	return coin;
}
