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

void Actor::AttackDamage(Actor* Target)
{
	int Damage=0;
	Damage = rand() % this->Atk + 1;

	Target->TakeDamage(Damage);
	
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
