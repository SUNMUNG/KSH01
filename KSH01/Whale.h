#pragma once
#include "Animal.h"
class Whale : public Animal
{
public:
	void Swim();
public:
	Whale() = default;
	Whale(std::string inname)
		:Animal(inname)
	{
	}
};

