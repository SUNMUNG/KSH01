#include "Player.h"

Player::Player(std::string inName, int inHp, int inAtk)
{
	this->Name = inName;
	this->Health = inHp;
	this->Atk = inAtk;
}

Player::Player(std::string inName)
{
	this->Name = inName;
}

Player::Player()
{
}

Player::~Player()
{
}