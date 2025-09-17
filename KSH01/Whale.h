#pragma once
#include "Animal.h"
#include "ISwimable.h"
class Whale : public Animal,public ISwimable
{
public:
	virtual void Swim() override;
	virtual void MakeSound()override;
	virtual void Move() override;
public:
	Whale() = default;
	Whale(std::string inname)
		:Animal(inname)
	{
	}
};

