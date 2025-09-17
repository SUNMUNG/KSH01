#pragma once
#include <string>
#include "Actor.h"
class Monster : public Actor
{
public:
	inline const int GetMonsterHP() const { return Health; }
	inline const int GetMonsterAtk() const { return Atk; }
	inline const int GetMonsterCoin() const { return coin; }
	virtual void SkillAttack(IBattle* Target) {};

	Monster(std::string inName,int inMaxHp,int inAtk);
	Monster(std::string inName);
	Monster();
	~Monster();
	
protected:

	inline void MonsterHit(int inhp) {
		if (Health <= 0) {
			Health = 0;
		}
		else {
			Health -= inhp;
		}
	}
	inline void SetAtk(int inAtk) {
		Atk = inAtk;
	}


private:

};


