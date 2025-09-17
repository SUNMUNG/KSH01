#pragma once
#include "IBattle.h"
#include <string>
class Actor : public IBattle
{
public:
	inline const std::string GetName() const { return Name; }
	inline const int GetHP() const { return Health; }
	inline const int GetAtk() const { return Atk; }
	inline const int GetCoin() const { return coin; }
	

	Actor(std::string inName, int inHp, int inAtk);
	Actor();
	virtual ~Actor();

	virtual void AttackDamage(IBattle* Target);
	virtual void SkillAttack(IBattle* Target)=0;
	virtual void TakeDamage(int inDamage);
	int CoinReward();

protected:
	std::string Name;
	int Health = 1;
	int Atk = 1;
	int coin = 0;

private:

};



