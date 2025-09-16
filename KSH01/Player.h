#pragma once
#include <string>
#include "Actor.h"
class Player : public Actor
{
public:
	inline const int GetPlayerHP() const { return Health; }
	inline const int GetPlayerAtk() const { return Atk; }
	inline const int GetPlayerCoin() const { return coin; }
	inline const int GetPlayerXPos() const { return Xpos; }
	inline const int GetPlayerYPos() const { return Ypos; }
	inline void SetPlayerPosXY(int inPosX, int inPosY) {
		this->Xpos += inPosX;
		this->Ypos += inPosY;
	}
	inline void SetPlayerHealth(int addHP) {
		if (this->Health > 100) {
			this->Health = 100;
		}
		this->Health += addHP;
	}
	inline void SetPlayerBattleEnd(int inHP) {
		this->Health = inHP;
	}
	inline void SetPlayerCoin(int addCoin) {
		this->coin += addCoin;
	}
	Player();
	~Player();

	Player(std::string inName, int inHp, int inAtk);
	Player(std::string inName);
protected:

	int Xpos = 1;
	int Ypos = 1;
	

private:

};



