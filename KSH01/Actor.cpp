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
	if (this->Name != "�÷��̾�" && SkillChance <= 3) {
		SkillAttack(Target);
	}
	else {
		Target->TakeDamage(Damage);
	}
	
	
}

void Actor::TakeDamage(int inDamage)
{
	this->Health -= inDamage;
	printf("%s�� %d �������� �޾ҽ��ϴ�.\n", this->Name.c_str(), inDamage);
	
}

int Actor::CoinReward()
{
	int coin = 0;

	if (this->Name == "����") {
		coin = 10;
	}
	else if(this->Name == "��ũ") {
		coin = 50;
	}
	else if (this->Name == "����") {
		coin = 20;
	}
	else if (this->Name == "���̷���") {
		coin = 25;
	}
	else if (this->Name == "���") {
		coin = 20;
	}
	return coin;
}
