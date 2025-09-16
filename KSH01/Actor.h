#pragma once
#include <string>
class Actor
{
public:
	inline const std::string GetName() const { return Name; }
	inline const int GetHP() const { return Health; }
	inline const int GetAtk() const { return Atk; }
	inline const int GetCoin() const { return coin; }
	

	Actor(std::string inName, int inHp, int inAtk);
	Actor();
	~Actor();

	void AttackDamage(Actor* Target);
	void TakeDamage(int inDamage);
	int CoinReward();

protected:
	std::string Name;
	int Health = 1;
	int Atk = 1;
	int coin = 0;

private:

};



